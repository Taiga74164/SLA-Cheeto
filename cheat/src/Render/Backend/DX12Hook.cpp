#include "DX12Hook.h"

#include "HookManager.h"
#include "Utils.h"

typedef HRESULT(APIENTRY* IDXGISwapChainPresent)(IDXGISwapChain3* pSwapChain, UINT SyncInterval, UINT Flags);
typedef void(APIENTRY* DrawInstanced)(ID3D12GraphicsCommandList* dCommandList, UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation);
typedef void(APIENTRY* DrawIndexedInstanced)(ID3D12GraphicsCommandList* dCommandList, UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation);
typedef void(APIENTRY* ExecuteCommandLists)(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists);

namespace Backend
{
	struct DirectX12MainFunctions {
		IDXGISwapChainPresent presentFunc;
		DrawInstanced drawInstancedFunc;
		DrawIndexedInstanced drawIndexedInstancedFunc;
		ExecuteCommandLists executeCommandListFunc;
	};

	namespace DirectX12Interface {
		ID3D12Device* Device = nullptr;
		ID3D12DescriptorHeap* DescriptorHeapBackBuffers;
		ID3D12DescriptorHeap* DescriptorHeapImGuiRender;
		ID3D12GraphicsCommandList* CommandList;
		ID3D12CommandQueue* CommandQueue;

		struct _FrameContext {
			ID3D12CommandAllocator* CommandAllocator;
			ID3D12Resource* Resource;
			D3D12_CPU_DESCRIPTOR_HANDLE DescriptorHandle;
		};

		UINT BuffersCounts = -1;
		_FrameContext* FrameContext;
	}
	
	DX12Hook* DX12Hook::m_instance = nullptr;
	WNDCLASSEX windowClass;
	HWND windowHwnd;

	DX12Hook::DX12Hook()
	{
		m_instance = this;
	}

	DX12Hook::~DX12Hook()
	{
		m_instance = nullptr;
	}

	DX12Hook* DX12Hook::GetInstance()
	{
		if (!m_instance)
			m_instance = new DX12Hook();
		return m_instance;
	}

	HRESULT __stdcall DX12Hook::PresentHook(IDXGISwapChain3* pSwapChain, UINT syncInterval, UINT flags)
	{
		if (!m_instance) return E_UNEXPECTED;
		
		static bool init = false;
		if (!init && m_instance->OnInit)
		{
			const auto result = (HRESULT)pSwapChain->GetDevice(__uuidof(DirectX12Interface::Device), reinterpret_cast<void**>(&DirectX12Interface::Device));
			LOG(xorstr("Result of GetDevice: %x"), HRESULT_CODE(result));
			if (SUCCEEDED(result))
			{
				DXGI_SWAP_CHAIN_DESC desc;
				pSwapChain->GetDesc(&desc);
				desc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
				desc.Windowed = (GetWindowLongPtr(desc.OutputWindow, GWL_STYLE) & WS_POPUP) == 0;

				DirectX12Interface::BuffersCounts = desc.BufferCount;
				DirectX12Interface::FrameContext = new DirectX12Interface::_FrameContext[DirectX12Interface::BuffersCounts];

				D3D12_DESCRIPTOR_HEAP_DESC descriptorImGuiRender = {};
				descriptorImGuiRender.Type = D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV;
				descriptorImGuiRender.NumDescriptors = DirectX12Interface::BuffersCounts;
				descriptorImGuiRender.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE;

				if (DirectX12Interface::Device->CreateDescriptorHeap(&descriptorImGuiRender, IID_PPV_ARGS(&DirectX12Interface::DescriptorHeapImGuiRender)) != S_OK)
					return CALL_ORIGIN(PresentHook, pSwapChain, syncInterval, flags);

				ID3D12CommandAllocator* allocator;
				if (DirectX12Interface::Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&allocator)) != S_OK)
					return CALL_ORIGIN(PresentHook, pSwapChain, syncInterval, flags);

				for (size_t i = 0; i < DirectX12Interface::BuffersCounts; i++)
					DirectX12Interface::FrameContext[i].CommandAllocator = allocator;

				if (DirectX12Interface::Device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, allocator, NULL, IID_PPV_ARGS(&DirectX12Interface::CommandList)) != S_OK ||
					DirectX12Interface::CommandList->Close() != S_OK)
					return CALL_ORIGIN(PresentHook, pSwapChain, syncInterval, flags);

				D3D12_DESCRIPTOR_HEAP_DESC descriptorBackBuffers;
				descriptorBackBuffers.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
				descriptorBackBuffers.NumDescriptors = DirectX12Interface::BuffersCounts;
				descriptorBackBuffers.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;
				descriptorBackBuffers.NodeMask = 1;

				if (DirectX12Interface::Device->CreateDescriptorHeap(&descriptorBackBuffers, IID_PPV_ARGS(&DirectX12Interface::DescriptorHeapBackBuffers)) != S_OK)
					return CALL_ORIGIN(PresentHook, pSwapChain, syncInterval, flags);

				const auto rtvDescriptorSize = DirectX12Interface::Device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
				D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle = DirectX12Interface::DescriptorHeapBackBuffers->GetCPUDescriptorHandleForHeapStart();

				for (uint32_t i = 0; i < DirectX12Interface::BuffersCounts; i++)
				{
					ID3D12Resource* pBackBuffer = nullptr;
					DirectX12Interface::FrameContext[i].DescriptorHandle = rtvHandle;
					pSwapChain->GetBuffer(i, IID_PPV_ARGS(&pBackBuffer));
					DirectX12Interface::Device->CreateRenderTargetView(pBackBuffer, nullptr, rtvHandle);
					DirectX12Interface::FrameContext[i].Resource = pBackBuffer;
					rtvHandle.ptr += rtvDescriptorSize;
				}

				m_instance->OnInit(desc.OutputWindow, DirectX12Interface::Device, DirectX12Interface::BuffersCounts, DirectX12Interface::DescriptorHeapImGuiRender);
				
				init = true;
			}
		}

		if (!init || DirectX12Interface::CommandQueue == nullptr)
			return CALL_ORIGIN(PresentHook, pSwapChain, syncInterval, flags);

		m_instance->OnPreRender();

		DirectX12Interface::_FrameContext& CurrentFrameContext = DirectX12Interface::FrameContext[pSwapChain->GetCurrentBackBufferIndex()];
		CurrentFrameContext.CommandAllocator->Reset();

		D3D12_RESOURCE_BARRIER Barrier;
		Barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
		Barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
		Barrier.Transition.pResource = CurrentFrameContext.Resource;
		Barrier.Transition.Subresource = D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES;
		Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_PRESENT;
		Barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_RENDER_TARGET;

		DirectX12Interface::CommandList->Reset(CurrentFrameContext.CommandAllocator, nullptr);
		DirectX12Interface::CommandList->ResourceBarrier(1, &Barrier);
		DirectX12Interface::CommandList->OMSetRenderTargets(1, &CurrentFrameContext.DescriptorHandle, FALSE, nullptr);
		DirectX12Interface::CommandList->SetDescriptorHeaps(1, &DirectX12Interface::DescriptorHeapImGuiRender);

		m_instance->OnPostRender(DirectX12Interface::CommandList);

		Barrier.Transition.StateBefore = D3D12_RESOURCE_STATE_RENDER_TARGET;
		Barrier.Transition.StateAfter = D3D12_RESOURCE_STATE_PRESENT;
		DirectX12Interface::CommandList->ResourceBarrier(1, &Barrier);
		DirectX12Interface::CommandList->Close();
		DirectX12Interface::CommandQueue->ExecuteCommandLists(1, reinterpret_cast<ID3D12CommandList* const*>(&DirectX12Interface::CommandList));

		return CALL_ORIGIN(PresentHook, pSwapChain, syncInterval, flags);
	}

	void DX12Hook::ExecuteCommandListsHook(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists)
	{
		if (!DirectX12Interface::CommandQueue)
			DirectX12Interface::CommandQueue = queue;

		return CALL_ORIGIN(ExecuteCommandListsHook, queue, NumCommandLists, ppCommandLists);
	}

	bool InitWindow()
	{
		windowClass.cbSize = sizeof(WNDCLASSEX);
		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = DefWindowProc;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = 0;
		windowClass.hInstance = GetModuleHandle(nullptr);
		windowClass.hIcon = nullptr;
		windowClass.hCursor = nullptr;
		windowClass.hbrBackground = nullptr;
		windowClass.lpszMenuName = nullptr;
		windowClass.lpszClassName = "T";
		windowClass.hIconSm = nullptr;
		RegisterClassEx(&windowClass);
		windowHwnd = CreateWindow(windowClass.lpszClassName, "DirectX Window", WS_OVERLAPPEDWINDOW, 0, 0, 100, 100, NULL, NULL, windowClass.hInstance, NULL);
		if (windowHwnd == nullptr)
			return false;
		
		return true;
	}

	bool DeleteWindow()
	{
		DestroyWindow(windowHwnd);
		UnregisterClass(windowClass.lpszClassName, windowClass.hInstance);
		if (windowHwnd != nullptr) return false;
		return true;
	}

	bool FindFunctions(DirectX12MainFunctions& functions)
	{
		if (!InitWindow()) return false;

		const HMODULE dxgiModule = GetModuleHandle("dxgi.dll");
		const HMODULE d3d12Module = GetModuleHandle("d3d12.dll");
		if (!d3d12Module || !dxgiModule)
		{
			DeleteWindow();
			return false;
		}

		const auto createDXGIFactory = GetProcAddress(dxgiModule, "CreateDXGIFactory");
		if (!createDXGIFactory)
		{
			DeleteWindow();
			return false;
		}

		IDXGIFactory* dxgiFactory;
		if (FAILED(((HRESULT(__stdcall*)(REFIID, void**))createDXGIFactory)(__uuidof(IDXGIFactory), reinterpret_cast<void**>(&dxgiFactory))))
		{
			DeleteWindow();
			return false;
		}

		IDXGIAdapter* dxgiAdapter;
		if (FAILED(dxgiFactory->EnumAdapters(0, &dxgiAdapter)))
		{
			DeleteWindow();
			return false;
		}

		const auto d3d12CreateDevice = GetProcAddress(d3d12Module, "D3D12CreateDevice");
		if (!d3d12CreateDevice)
		{
			DeleteWindow();
			return false;
		}

		ID3D12Device* d3d12Device;
		if (FAILED(((HRESULT(__stdcall*)(IUnknown*, D3D_FEATURE_LEVEL, REFIID, void**))d3d12CreateDevice)(dxgiAdapter, D3D_FEATURE_LEVEL_11_0, __uuidof(ID3D12Device), reinterpret_cast<void**>(&d3d12Device))))
		{
			DeleteWindow();
			return false;
		}

		const D3D12_COMMAND_QUEUE_DESC queueDesc = { D3D12_COMMAND_LIST_TYPE_DIRECT, 0, D3D12_COMMAND_QUEUE_FLAG_NONE, 0 };

		ID3D12CommandQueue* commandQueue;
		if (FAILED(d3d12Device->CreateCommandQueue(&queueDesc, __uuidof(ID3D12CommandQueue), reinterpret_cast<void**>(&commandQueue))))
		{
			DeleteWindow();
			return false;
		}

		ID3D12CommandAllocator* commandAllocator;
		if (FAILED(d3d12Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, __uuidof(ID3D12CommandAllocator), reinterpret_cast<void**>(&commandAllocator))))
		{
			DeleteWindow();
			return false;
		}

		ID3D12GraphicsCommandList* commandList;
		if (FAILED(d3d12Device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, commandAllocator, NULL, __uuidof(ID3D12GraphicsCommandList), reinterpret_cast<void**>(&commandList))))
		{
			DeleteWindow();
			return false;
		}

		DXGI_RATIONAL refreshRate = { 60, 1 };
		const DXGI_MODE_DESC bufferDesc = {
			100,
			100,
			refreshRate,
			DXGI_FORMAT_R8G8B8A8_UNORM,
			DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED,
			DXGI_MODE_SCALING_UNSPECIFIED
		};
		const DXGI_SAMPLE_DESC sampleDesc = { 1, 0 };
		DXGI_SWAP_CHAIN_DESC swapChainDesc = {
			bufferDesc,
			sampleDesc,
			DXGI_USAGE_RENDER_TARGET_OUTPUT,
			2,
			windowHwnd,
			true,
			DXGI_SWAP_EFFECT_FLIP_DISCARD,
			DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH
		};

		IDXGISwapChain* swapChain;
		if (FAILED(dxgiFactory->CreateSwapChain(commandQueue, &swapChainDesc, &swapChain)))
		{
			DeleteWindow();
			return false;
		}

		const auto methodTable = (uint64_t*)::calloc(150, sizeof(uint64_t));
		memcpy(methodTable, *(uint64_t**)d3d12Device, 44 * sizeof(uint64_t));
		memcpy(methodTable + 44, *(uint64_t**)commandQueue, 19 * sizeof(uint64_t));
		memcpy(methodTable + 44 + 19, *(uint64_t**)commandAllocator, 9 * sizeof(uint64_t));
		memcpy(methodTable + 44 + 19 + 9, *(uint64_t**)commandList, 60 * sizeof(uint64_t));
		memcpy(methodTable + 44 + 19 + 9 + 60, *(uint64_t**)swapChain, 18 * sizeof(uint64_t));

		free(methodTable);

		d3d12Device->Release();
		d3d12Device = nullptr;
		commandQueue->Release();
		commandQueue = nullptr;
		commandAllocator->Release();
		commandAllocator = nullptr;
		commandList->Release();
		commandList = nullptr;
		swapChain->Release();
		swapChain = nullptr;
		DeleteWindow();
		return true;
	}

	void DX12Hook::InitializeHooks()
	{
		LOG(xorstr("Initialized DX12Hook."));
		
		DirectX12MainFunctions functions;
		if (!FindFunctions(functions))
		{
			LOG(xorstr("Failed to find Present function for DX12."));
			return;
		}

		LOG(xorstr("IDXGISwapChainPresent: 0x%p"), functions.presentFunc);
		LOG(xorstr("DrawInstanced: 0x%p"), functions.drawInstancedFunc);
		LOG(xorstr("DrawIndexedInstanced: 0x%p"), functions.drawIndexedInstancedFunc);
		LOG(xorstr("ExecuteCommandLists: 0x%p"), functions.executeCommandListFunc);

		HookManager::install(functions.presentFunc, PresentHook);
		HookManager::install(functions.executeCommandListFunc, ExecuteCommandListsHook);
		
		LOG(xorstr("D3D12 Hooks installed."));
	}
	
}
