#include "Renderer.h"

#include "backends/imgui_impl_dx11.h"
#pragma comment(lib, "dxgi")
#include "backends/imgui_impl_dx12.h"

#include "backends/imgui_impl_win32.h"

#include "Backend/DX11Hook.h"
#include "Backend/DX12Hook.h"
#include "Utils.h"
#include "Gui/gui.h"
#include "Gui/fonts/DejaVuSansMono.hpp"
#include "Gui/fonts/cousine.hpp"
#include "Gui/fonts/Rubik.hpp"

namespace Renderer
{
#pragma region DX11

	ID3D11RenderTargetView* mainRenderTargetView;

	void OnInitDX11(HWND hWnd, ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain)
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImFontConfig fontConfig;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ImeWindowHandle = hWnd;
		io.Fonts->AddFontFromMemoryCompressedTTF(Rubik_compressed_data, *Rubik_compressed_data, 15.0f, &fontConfig);

		ImGui_ImplWin32_Init(hWnd);
		ImGui_ImplDX11_Init(pDevice, pContext);

		ID3D11Texture2D* pBackBuffer;
		pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<LPVOID*>(&pBackBuffer));
		pDevice->CreateRenderTargetView(pBackBuffer, nullptr, &mainRenderTargetView);
		pBackBuffer->Release();

		io.SetPlatformImeDataFn = nullptr;
	}

	void OnRenderDX11(ID3D11DeviceContext* pContext)
	{
		auto& gui = Gui::GetInstance();
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();
		InitTheme();

		if (gui.IsOpen())
			gui.Render();

		// TODO: Key Rebind
		if (Utils::KeyPressed(VK_INSERT))
			gui.Toggle();

		ImGui::EndFrame();
		ImGui::Render();

		pContext->OMSetRenderTargets(1, &mainRenderTargetView, nullptr);
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
	}

#pragma endregion

#pragma region DX12

	void OnInitDX12(HWND hWnd, ID3D12Device* pDevice, UINT buffferCount, ID3D12DescriptorHeap* pDescriptorHeap)
	{
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO(); (void)io;
		ImFontConfig fontConfig;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ImeWindowHandle = hWnd;


		ImGui_ImplWin32_Init(hWnd);
		ImGui_ImplDX12_Init(pDevice, buffferCount, DXGI_FORMAT_R8G8B8A8_UNORM, pDescriptorHeap, pDescriptorHeap->GetCPUDescriptorHandleForHeapStart(), pDescriptorHeap->GetGPUDescriptorHandleForHeapStart());
		ImGui_ImplDX12_CreateDeviceObjects();
	}

	void OnPreRenderDX12()
	{
		ImGui_ImplDX12_NewFrame();
		ImGui_ImplWin32_NewFrame();

		ImGui::NewFrame();
		InitTheme();

		ImGui::Render();
	}

	void OnPostRenderDX12(ID3D12GraphicsCommandList* pCommandList)
	{
		ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), pCommandList);
	}

#pragma endregion

	void Init(DXVersion version)
	{
		switch (version)
		{
		case DXVersion::D3D11:
			Backend::DX11Hook::GetInstance()->OnInit = [](HWND hWnd, ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain) {
				OnInitDX11(hWnd, pDevice, pContext, pSwapChain);
			};

			Backend::DX11Hook::GetInstance()->OnRender = [](ID3D11DeviceContext* pContext) {
				OnRenderDX11(pContext);
			};

			Backend::DX11Hook::InitializeHooks();
			break;
		case DXVersion::D3D12:
			Backend::DX12Hook::GetInstance()->OnInit = [](HWND hWnd, ID3D12Device* pDevice, UINT buffferCount, ID3D12DescriptorHeap* pDescriptorHeap) {
				OnInitDX12(hWnd, pDevice, buffferCount, pDescriptorHeap);
			};

			Backend::DX12Hook::GetInstance()->OnPreRender = []() {
				OnPreRenderDX12();
			};

			Backend::DX12Hook::GetInstance()->OnPostRender = [](ID3D12GraphicsCommandList* pCommandList) {
				OnPostRenderDX12(pCommandList);
			};

			Backend::DX12Hook::InitializeHooks();
			break;
		}
	}

	void InitTheme()
	{
		ImGuiStyle& Style = ImGui::GetStyle();
		auto colors = Style.Colors;
		Style.WindowPadding = ImVec2(10, 10);              // Padding within a window
		Style.WindowMinSize = ImVec2(600, 420);            // Minimum window size
		Style.WindowRounding = 5.0f;                       // Radius of window corners rounding. Set to 0.0f to have rectangular windows
		Style.WindowTitleAlign = ImVec2(0.5f, 0.5f);       // Alignment for title bar text
		Style.FramePadding = ImVec2(3, 3);                 // Padding within a framed rectangle (used by most widgets)
		Style.FrameRounding = 4.0f;                        // Radius of frame corners rounding. Set to 0.0f to have rectangular frames (used by most widgets).
		Style.ChildRounding = 1.0f;
		Style.ItemSpacing = ImVec2(4, 4);                  // Horizontal and vertical spacing between widgets/lines
		Style.ItemInnerSpacing = ImVec2(5, 5);             // Horizontal and vertical spacing between within elements of a composed widget (e.g. a slider and its label)
		Style.TouchExtraPadding = ImVec2(0, 0);            // Expand reactive bounding box for touch-based system where touch position is not accurate enough. Unfortunately we don't sort widgets so priority on overlap will always be given to the first widget. So don't grow this too much!
		Style.IndentSpacing = 20.0f;                       // Horizontal spacing when e.g. entering a tree node. Generally == (FontSize + FramePadding.x*2).
		Style.ColumnsMinSpacing = 2.0f;                    // Minimum horizontal spacing between two columns
		Style.ScrollbarSize = 9.0f;                        // Width of the vertical scrollbar, Height of the horizontal scrollbar
		Style.ScrollbarRounding = 9.0f;                    // Radius of grab corners rounding for scrollbar
		Style.GrabMinSize = 9.0f;                         // Minimum width/height of a grab box for slider/scrollbar
		Style.GrabRounding = 3.0f;                         // Radius of grabs corners rounding. Set to 0.0f to have rectangular slider grabs.
		Style.ButtonTextAlign = ImVec2(0.5f, 0.5f);        // Alignment of button text when button is larger than text.
		Style.DisplayWindowPadding = ImVec2(22, 22);       // Window positions are clamped to be is_visible within the display area by at least this amount. Only covers regular windows.
		Style.DisplaySafeAreaPadding = ImVec2(4, 4);       // If you cannot see the edge of your screen (e.g. on a TV) increase the safe area padding. Covers popups/tooltips as well regular windows.
		Style.AntiAliasedLines = true;                    // Enable anti-aliasing on lines/borders. Disable if you are really short on CPU/GPU.
		Style.CurveTessellationTol = 1.5f;                 // Tessellation tolerance. Decrease for highly tessellated curves (higher quality, more polygons), increase to reduce qual
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.34f, 0.34f, 0.34f, 0.10f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
		colors[ImGuiCol_Border] = ImVec4(0.08f, 0.08f, 0.08f, 0.50f);//
		colors[ImGuiCol_BorderShadow] = ImVec4(0.01f, 0.01f, 0.01f, 0.01f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.60f, 0.60f, 0.60f, 0.06f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.60f, 0.60f, 0.60f, 0.06f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.07f, 0.07f, 0.07f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.07f, 0.07f, 0.07f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.25f, 0.25f, 0.25f, 0.86f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.07f, 0.07f, 0.07f, 0.08f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.07f, 0.07f, 0.07f, 0.08f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(0.60f, 0.05f, 0.05f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.60f, 0.05f, 0.05f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.80f, 0.10f, 0.10f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.55f, 0.55f, 0.55f, 1.00f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.80f, 0.80f, 0.80f, 1.00f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.32f, 0.32f, 0.32f, 1.00f);//
		colors[ImGuiCol_Header] = ImVec4(0.06f, 0.06f, 0.06f, 0.50f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.06f, 0.06f, 0.06f, 0.50f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.06f, 0.06f, 0.06f, 0.50f);
		colors[ImGuiCol_Separator] = ImVec4(0.10f, 0.10f, 0.10f, 0.20f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.10f, 0.10f, 0.10f, 0.20f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.10f, 0.10f, 0.10f, 0.10f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(1.00f, 1.00f, 1.00f, 0.30f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
		colors[ImGuiCol_Tab] = ImVec4(0.05f, 0.05f, 0.05f, 0.48f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.40f, 0.08f, 0.08f, 1.00f);
		colors[ImGuiCol_TabActive] = ImVec4(0.07f, 0.07f, 0.07f, 1.00f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		// colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
		// colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.05f, 0.05f, 0.05f, 0.50f);
		// colors[ImGuiCol_TableBorderLight]       = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
		// colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		// colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
		// colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.82f, 0.16f, 0.16f, 0.20f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.59f, 0.24f, 0.24f, 0.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.18f, 0.18f, 0.18f, 0.50f);
	}
}
