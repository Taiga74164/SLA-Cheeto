// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.2.0+

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************
using namespace app;

DO_APP_FUNC(0x00455F30, void, GameFrameWork_Update, (void/*GameFrameWork*/* __this, MethodInfo* method));
DO_APP_FUNC(0x00DF1DA0, void, InputManager_Update, (void/*InputManager*/* __this, MethodInfo* method));
DO_APP_FUNC(0x02C18F90, void, InputManager_1_Update, (void/*InputManager_1*/* __this, MethodInfo* method));

DO_APP_FUNC(0x0208ABF0, String*, Marshal_PtrToStringAnsi, (void* ptr, MethodInfo* method));
DO_APP_FUNC(0x0208AC10, String*, Marshal_PtrToStringUni, (void* ptr, MethodInfo* method));

// FovChanger
DO_APP_FUNC(0x030797E0, void, Camera_set_fieldOfView, (void* __this, float value, MethodInfo* method));

// FPSUnlock
DO_APP_FUNC(0x03072580, int, Application_get_targetFrameRate, (MethodInfo* method));
DO_APP_FUNC(0x03072CA0, void, Application_set_targetFrameRate, (int value, MethodInfo* method));

DO_APP_FUNC(0x03096A60, void, QualitySettings_set_vSyncCount, (int value, MethodInfo* method));

// TimeScale
DO_APP_FUNC(0x030CF0A0, float, Time_get_timeScale, (MethodInfo * method));
DO_APP_FUNC(0x030CF190, void, Time_set_timeScale, (float value, MethodInfo * method));

// Unity & C# Stuff
DO_APP_FUNC(0x030BE050, GameObject*, GameObject_Find, (String* name, MethodInfo* method));
DO_APP_FUNC(0x030BBE00, GameObject*, Component_get_gameObject, (Component* __this, MethodInfo* method));
DO_APP_FUNC(0x030BE2A0, Component*, GameObject_GetComponent, (GameObject* __this, Type* type, MethodInfo* method));
DO_APP_FUNC(0x030BF0A0, Transform*, GameObject_get_transform, (GameObject* __this, MethodInfo* method));
DO_APP_FUNC(0x010B2BD0, GameObject*, GameObject_get_gameObject, (GameObject* __this, MethodInfo* method));
DO_APP_FUNC(0x021BFF00, Type*, Type_GetType_3, (String* typeName, MethodInfo* method));
DO_APP_FUNC(0x020A21F0, Type*, Assembly_GetType, (Assembly* __this, String* name, MethodInfo* method));
DO_APP_FUNC(0x020A2310, Assembly*, Assembly_LoadWithPartialName, (String* partialName, MethodInfo* method));
DO_APP_FUNC(0x030B8BB0, Vector3, Vector3_Lerp, (Vector3 a, Vector3 b, float t, MethodInfo* method));
DO_APP_FUNC(0x030B8940, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo* method));
DO_APP_FUNC(0x030C4320, String*, Object_1_get_name, (Object_1* __this, MethodInfo* method));
DO_APP_FUNC(0x030C23D0, void, Object_1_Destroy_1, (Object_1* obj, MethodInfo* method));
DO_APP_FUNC(0x030C2E40, Object_1__Array*, Object_1_FindObjectsOfType_1, (Type* type, bool includeInactive, MethodInfo* method));
DO_APP_FUNC(0x030D3C30, Vector3, Transform_get_position, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D44A0, void, Transform_set_position, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x030D3900, Vector3, Transform_get_localPosition, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D4200, void, Transform_set_localPosition, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x030D0CA0, Vector3, Transform_GetLocalEulerAngles, (Transform* __this, RotationOrder__Enum order, MethodInfo* method));
DO_APP_FUNC(0x030D25E0, void, Transform_SetLocalEulerAngles, (Transform* __this, Vector3 euler, RotationOrder__Enum order, MethodInfo* method));
DO_APP_FUNC(0x030D2690, void, Transform_SetLocalEulerHint, (Transform* __this, Vector3 euler, MethodInfo* method));
DO_APP_FUNC(0x030D3560, Vector3, Transform_get_eulerAngles, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D3FB0, void, Transform_set_eulerAngles, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x030D37D0, Vector3, Transform_get_localEulerAngles, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D4110, void, Transform_set_localEulerAngles, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x030D3C80, Vector3, Transform_get_right, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D44F0, void, Transform_set_right, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x030D3DF0, Vector3, Transform_get_up, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D4640, void, Transform_set_up, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x030D3640, Vector3, Transform_get_forward, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D4050, void, Transform_set_forward, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x030D3DA0, Quaternion, Transform_get_rotation, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D45F0, void, Transform_set_rotation, (Transform* __this, Quaternion value, MethodInfo* method));
DO_APP_FUNC(0x030D39A0, Quaternion, Transform_get_localRotation, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030D42A0, void, Transform_set_localRotation, (Transform* __this, Quaternion value, MethodInfo* method));
DO_APP_FUNC(0x030D3520, int32_t, Transform_get_childCount, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x030ECDC0, String*, Scene_GetNameInternal, (int32_t sceneHandle, MethodInfo* method));
DO_APP_FUNC(0x030EB790, Scene, SceneManager_GetActiveScene, (MethodInfo* method));
DO_APP_FUNC(0x03069410, float, Animator_get_speed, (Animator* __this, MethodInfo* method));
DO_APP_FUNC(0x03069E70, void, Animator_set_speed, (Animator* __this, float value, MethodInfo* method));

// No Cooldown
DO_APP_FUNC(0x008546C0, void/*KAAIFMKPKAG*/*, KAAIFMKPKAG_IOFMGMJCCFO, (KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method));
// Damage Hack
DO_APP_FUNC(0x00830370, void, PIPHNBOBFEF_KBCIIEFLPGB, (PIPHNBOBFEF* __this, ESpecialState__Enum OCKAHFDGNEL, int64_t MGFPJFANLBG, int64_t DIACKALMMKH, int64_t PBAPBJGDAPJ, String* DLOACPLHGMP, MethodInfo* method));
// God Mode
DO_APP_FUNC(0x009D6CB0, int32_t, GHINOEFFMPN_EKHGIHBHEPL, (SkillIdentity* EKPKPIJBPKE, void/*IEnumerable_1_UnityEngine_Component_*/* FKJDKGJBGOD, TargetHitData* COFCDKGCOGJ, MethodInfo* method));
// Dumb Enemies
DO_APP_FUNC(0x00A65FC0, void, EvadeProxy_Init, (EvadeProxy* __this, ENNEJEPMJLJ* IGBKKNODEGM, EvadePenetration* DHPMEMDBDMC, MethodInfo* method));

// EntityManager
DO_APP_FUNC(0x00865E30, void, ENHPKNIEKMI_MIFDFEHDDDD, (ENHPKNIEKMI* __this, MethodInfo* method));
DO_APP_FUNC(0x00A3C540, ENHPKNIEKMI*, ENNEJEPMJLJ_FIGHFBNIDJA, (ENNEJEPMJLJ* __this, MethodInfo* method));
DO_APP_FUNC(0x00A32AE0, bool, PCILGJOEPJM_PPAKPBOJLIP, (ENNEJEPMJLJ* IGBKKNODEGM, MethodInfo* method)); // Check if Entity is alive????

// Mission Time
DO_APP_FUNC(0x00E40850, void, StageReadyPage_EnterUI, (StageReadyPage* __this, MethodInfo* method));
DO_APP_FUNC(0x00E42FE0, void, StoryQuestChapterPage_EnterUI, (StoryQuestChapterPage* __this,MethodInfo* method));
// Intro Movie
DO_APP_FUNC(0x00B40AC0, void, GameMovie_Update, (GameMovie* __this, MethodInfo* method));
DO_APP_FUNC(0x00B44FE0, void, IntroMovie_Update, (IntroMovie* __this, MethodInfo* method));
// Disable Web View
DO_APP_FUNC(0x022E4BE0, void, WebViewDialog_Show, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x022E6950, void, WebViewUI_RefreshSize, (void* __this, MethodInfo* method));

//DO_APP_FUNC(0x00430040, EGLGAPIAANF__Enum, JIBDAHKJHOG_PCLINKFFGNE, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837FE0, void, JIBDAHKJHOG_KPDGECAFJKA, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837510, void, JIBDAHKJHOG_HLLNLMAECBD, (JIBDAHKJHOG* __this, void* JONOLJGMLBE, void* BHMPNNCBFGN, MethodInfo* method)); // EnterBattleReq
//DO_APP_FUNC(0x00836650, void, JIBDAHKJHOG_EJLDBPGJGPN, (JIBDAHKJHOG* __this, MethodInfo* method)); // NextStageBattle
//DO_APP_FUNC(0x00836410, void, JIBDAHKJHOG_COLDHPFDOHG, (JIBDAHKJHOG* __this, MethodInfo* method)); // StageStart

// Shadow Cooldown And Limit
DO_APP_FUNC(0x00A57810, void, JLLMICINIDA_LFCGJLAFFOM, (JLLMICINIDA* __this, MethodInfo* method));

// Singletons
DO_APP_FUNC(0x00345D80, void*, TSingleton_GetInstance, (MethodInfo* method)); // Search for this in IDA. Seems to be Singleton<T> class
DO_APP_FUNC(0x0042D0E0, Object*, TSingleton_1_System_Object__get_Instance, (MethodInfo* method)); // Get the instance of the singleton
// DO_APP_FUNC_METHODINFO(0x04038380, TSingleton_1_JIBDAHKJHOG__get_Instance__MethodInfo);
// DO_APP_FUNC_METHODINFO(0x0403AC70, TSingleton_1_PJKMAOEINNH__get_Instance__MethodInfo); // Probably EntityManager or something similar