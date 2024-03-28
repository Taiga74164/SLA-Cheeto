#pragma once
#include <Windows.h>
#include "imgui.h"

namespace Renderer
{
	enum class DXVersion {
		D3D11,
		D3D12
	};
	
	void Init(DXVersion version = DXVersion::D3D11);
	void InitTheme();
}
