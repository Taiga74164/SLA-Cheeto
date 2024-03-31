#pragma once
#include <d3d12.h>
#include <dxgi1_4.h>
#include <functional>

namespace Backend
{
	class DX12Hook
	{
	public:
		DX12Hook();
		~DX12Hook();

		static DX12Hook* GetInstance();

		static void InitializeHooks();
		// static void Shutdown();

		std::function<void(HWND hWnd, ID3D12Device* pDevice, UINT buffferCount, ID3D12DescriptorHeap* pDescriptorHeap)> OnInit;
		std::function<void()> OnPreRender;
		std::function<void(ID3D12GraphicsCommandList* pCommandList)> OnPostRender;

	private:
		static HRESULT __stdcall PresentHook(IDXGISwapChain3* pSwapChain, UINT syncInterval, UINT flags);
		static void ExecuteCommandListsHook(ID3D12CommandQueue* queue, UINT NumCommandLists, ID3D12CommandList* ppCommandLists);
		
		static DX12Hook* m_instance;
	};
}
