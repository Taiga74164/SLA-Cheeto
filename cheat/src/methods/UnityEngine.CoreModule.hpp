#include <UnityResolve.hpp>

namespace methods
{
	struct Application
	{
		static int GetTargetFrameRate()
		{
			static UnityResolve::Method* method;
			if (!method) method = UnityResolve::Get("UnityEngine.CoreModule.dll")->Get("Application")->Get<UnityResolve::Method>("get_targetFrameRate");
			if (method) return method->Invoke<int>();
			return 0;
		}

		static void SetTargetFrameRate(int value)
		{
			static UnityResolve::Method* method;
			if (!method) method = UnityResolve::Get("UnityEngine.CoreModule.dll")->Get("Application")->Get<UnityResolve::Method>("set_targetFrameRate");
			if (method) method->Invoke<void>(value);
		}
	};

	struct QualitySettings
	{
		static void SetVSyncCount(int value)
		{
			static UnityResolve::Method* method;
			if (!method) method = UnityResolve::Get("UnityEngine.CoreModule.dll")->Get("QualitySettings")->Get<UnityResolve::Method>("set_vSyncCount");
			if (method) method->Invoke<void>(value);
		}
	};
}