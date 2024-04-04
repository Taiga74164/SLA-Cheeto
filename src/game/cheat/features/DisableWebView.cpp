#include "DisableWebView.h"
#include "HookManager.h"
#include "Utils.h"
#include "game-utils.hpp"
#include "events.h"

namespace Cheat::Features
{
	DisableWebView::DisableWebView()
	{
		HookManager::install(app::WebViewDialog_Show, WebViewDialog_Show_Hook);
		HookManager::install(app::WebViewUI_RefreshSize, WebViewUI_RefreshSize_Hook);
	}

	void DisableWebView::WebViewDialog_Show_Hook(void* __this, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();
		if (!vars.DisableWebView.value() || IsInLoginScene())
			CALL_ORIGIN(WebViewDialog_Show_Hook, __this, method);

		return;
	}

	void DisableWebView::WebViewUI_RefreshSize_Hook(void* __this, MethodInfo* method)
	{
		auto& vars = Vars::GetInstance();
		if (!vars.DisableWebView.value() || IsInLoginScene())
			CALL_ORIGIN(WebViewUI_RefreshSize_Hook, __this, method);

		return;
	}
}
