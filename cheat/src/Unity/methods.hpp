#include "global.h"

namespace methods
{
	const auto coreModule = UnityResolve::Get("UnityEngine.CoreModule.dll");
	const auto pTransform = coreModule->Get("GameObject");
}