#pragma once
#include "Singleton.h"
#include "global.h"

namespace Cheat::Features
{
	class DisableWebView : public Singleton<DisableWebView>
	{
	public:
		DisableWebView();

	private:
		static void WebViewDialog_Show_Hook(void* __this, MethodInfo* method);
		static void WebViewUI_RefreshSize_Hook(void* __this, MethodInfo* method);
	};
}
