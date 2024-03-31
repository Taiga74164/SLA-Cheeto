#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <functional>

namespace Backend
{
	class DX11Hook
	{
	public:
		DX11Hook();
		~DX11Hook();

		static DX11Hook* GetInstance();

		static void InitializeHooks();
		// static void Shutdown();

		std::function<void(HWND hWnd, ID3D11Device* pDevice, ID3D11DeviceContext* pContext, IDXGISwapChain* pSwapChain)> OnInit;
		std::function<void(ID3D11DeviceContext* pContext)> OnRender;

	private:
		static HRESULT __stdcall PresentHook(IDXGISwapChain* pSwapChain, UINT syncInterval, UINT flags);

		static DX11Hook* m_instance;
	};
}