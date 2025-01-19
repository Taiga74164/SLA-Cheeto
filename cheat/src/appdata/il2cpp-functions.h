// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.2.0+

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************
using namespace app;

DO_APP_FUNC(0x00777BA0, void, GameFrameWork_Update, (void/*GameFrameWork*/* __this, MethodInfo* method));

DO_APP_FUNC(0x02EAC330, String*, Marshal_PtrToStringAnsi, (void* ptr, MethodInfo* method));
DO_APP_FUNC(0x02EAC350, String*, Marshal_PtrToStringUni, (void* ptr, MethodInfo* method));

// FovChanger
DO_APP_FUNC(0x03F44C60, void, Camera_set_fieldOfView, (void* __this, float value, MethodInfo* method));

// C# methods
DO_APP_FUNC(0x02FE4260, Type*, Type_GetType_3, (String* typeName, MethodInfo* method));
DO_APP_FUNC(0x02EC02D0, Type*, Assembly_GetType, (Assembly* __this, String* name, MethodInfo* method));
DO_APP_FUNC(0x02EC07F0, Assembly*, Assembly_LoadWithPartialName, (String* partialName, MethodInfo* method));
// Unity methods
DO_APP_FUNC(0x03F3DAF0, int32_t, Application_get_targetFrameRate, (MethodInfo* method));
DO_APP_FUNC(0x03F3E210, void, Application_set_targetFrameRate, (int32_t value, MethodInfo* method));
DO_APP_FUNC(0x03F9E810, Vector3, Vector3_Lerp, (Vector3 a, Vector3 b, float t, MethodInfo* method));
DO_APP_FUNC(0x03F9E5B0, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo* method));
DO_APP_FUNC(0x03F89490, Transform*, GameObject_get_transform, (GameObject* __this, MethodInfo* method));
DO_APP_FUNC(0x03F88440, GameObject*, GameObject_Find, (String* name, MethodInfo* method));
DO_APP_FUNC(0x03F8E0F0, String*, Object_1_get_name, (Object_1* __this, MethodInfo* method));
DO_APP_FUNC(0x03F96570, void, Time_4_set_timeScale, (float value, MethodInfo* method));
DO_APP_FUNC(0x03F9A8A0, Vector3, Transform_get_position, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03F9B480, void, Transform_set_position, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03F9A8F0, Vector3, Transform_get_right, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03F9B4D0, void, Transform_set_right, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03F9ABC0, Vector3, Transform_get_up, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03F9B650, void, Transform_set_up, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03F9A110, Vector3, Transform_get_forward, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03F9AFA0, void, Transform_set_forward, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03F99FB0, int32_t, Transform_get_childCount, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03FB44B0, String*, Scene_GetNameInternal, (int32_t sceneHandle, MethodInfo* method));
DO_APP_FUNC(0x03FB2E80, Scene, SceneManager_GetActiveScene, (MethodInfo* method));

// No Cooldown
DO_APP_FUNC(0x00CE5BF0, void/*KAAIFMKPKAG*/*, KAAIFMKPKAG_IOFMGMJCCFO, (KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method));
// Damage Hack
DO_APP_FUNC(0x00CBD6F0, void, PIPHNBOBFEF_KBCIIEFLPGB, (PIPHNBOBFEF* __this, ESpecialState__Enum OCKAHFDGNEL, int64_t MGFPJFANLBG, int64_t DIACKALMMKH, int64_t PBAPBJGDAPJ, String* DLOACPLHGMP, MethodInfo* method));
// God Mode
DO_APP_FUNC(0x0106D7D0, int32_t, GHINOEFFMPN_EKHGIHBHEPL, (SkillIdentity* EKPKPIJBPKE, void/*IEnumerable_1_UnityEngine_Component_*/* FKJDKGJBGOD, TargetHitData* COFCDKGCOGJ, MethodInfo* method));
// Dumb Enemies
DO_APP_FUNC(0x01119690, void, EvadeProxy_Init, (EvadeProxy* __this, ENNEJEPMJLJ* IGBKKNODEGM, EvadePenetration* DHPMEMDBDMC, MethodInfo* method));

// EntityManager
DO_APP_FUNC(0x00CF0220, void, ENHPKNIEKMI_MIFDFEHDDDD, (ENHPKNIEKMI* __this, MethodInfo* method));
DO_APP_FUNC(0x00765390, ENHPKNIEKMI*, ENNEJEPMJLJ_FIGHFBNIDJA, (ENNEJEPMJLJ* __this, MethodInfo* method));
DO_APP_FUNC(0x010B6630, bool, PCILGJOEPJM_PPAKPBOJLIP, (ENNEJEPMJLJ* IGBKKNODEGM, MethodInfo* method)); // Check if Entity is alive????

// Mission Time
DO_APP_FUNC(0x007E0560, void, StageReadyPage_EnterUI, (StageReadyPage* __this, MethodInfo* method));
DO_APP_FUNC(0x007E7E60, void, StoryQuestChapterPage_EnterUI, (StoryQuestChapterPage* __this, MethodInfo* method));
// Intro Movie
DO_APP_FUNC(0x0122ADC0, void, IntroMovie_Update, (IntroMovie* __this, MethodInfo* method));
// Disable Web View
DO_APP_FUNC(0x031AC300, void, WebViewDialog_Show, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x031AE340, void, WebViewUI_RefreshSize, (void* __this, MethodInfo* method));

//DO_APP_FUNC(0x00430040, EGLGAPIAANF__Enum, JIBDAHKJHOG_PCLINKFFGNE, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837FE0, void, JIBDAHKJHOG_KPDGECAFJKA, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837510, void, JIBDAHKJHOG_HLLNLMAECBD, (JIBDAHKJHOG* __this, void* JONOLJGMLBE, void* BHMPNNCBFGN, MethodInfo* method)); // EnterBattleReq
//DO_APP_FUNC(0x00836650, void, JIBDAHKJHOG_EJLDBPGJGPN, (JIBDAHKJHOG* __this, MethodInfo* method)); // NextStageBattle
//DO_APP_FUNC(0x00836410, void, JIBDAHKJHOG_COLDHPFDOHG, (JIBDAHKJHOG* __this, MethodInfo* method)); // StageStart

// Shadow Cooldown And Limit
DO_APP_FUNC(0x010D3600, void, JLLMICINIDA_LFCGJLAFFOM, (JLLMICINIDA* __this, MethodInfo* method));

// Singletons
// DO_APP_FUNC(0x00384E60, void*, TSingleton_GetInstance, (MethodInfo* method)); // Search for this in IDA. Seems to be Singleton<T> class
DO_APP_FUNC(0x00489AE0, Object*, TSingleton_1_System_Object__get_Instance, (MethodInfo* method)); // Get the instance of the singleton
// DO_APP_FUNC_METHODINFO(0x04038380, TSingleton_1_JIBDAHKJHOG__get_Instance__MethodInfo);
// DO_APP_FUNC_METHODINFO(0x0403AC70, TSingleton_1_PJKMAOEINNH__get_Instance__MethodInfo); // Probably EntityManager or something similar