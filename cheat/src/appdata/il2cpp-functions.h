// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.2.0+

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************
using namespace app;

DO_APP_FUNC(0x00789940, void, GameFrameWork_Update, (void/*GameFrameWork*/* __this, MethodInfo* method));

DO_APP_FUNC(0x02BE6D40, String*, Marshal_PtrToStringAnsi, (void* ptr, MethodInfo* method));
DO_APP_FUNC(0x02BE6D60, String*, Marshal_PtrToStringUni, (void* ptr, MethodInfo* method));

// FovChanger
DO_APP_FUNC(0x03C966F0, void, Camera_set_fieldOfView, (void* __this, float value, MethodInfo* method));

// C# methods
DO_APP_FUNC(0x02D20640, Type*, Type_GetType_3, (String* typeName, MethodInfo* method));
DO_APP_FUNC(0x02BFACE0, Type*, Assembly_GetType, (Assembly* __this, String* name, MethodInfo* method));
DO_APP_FUNC(0x02BFB200, Assembly*, Assembly_LoadWithPartialName, (String* partialName, MethodInfo* method));
// Unity methods
DO_APP_FUNC(0x03C8F580, int32_t, Application_get_targetFrameRate, (MethodInfo* method));
DO_APP_FUNC(0x03C8FCA0, void, Application_set_targetFrameRate, (int32_t value, MethodInfo* method));
DO_APP_FUNC(0x03CEEF80, Vector3, Vector3_Lerp, (Vector3 a, Vector3 b, float t, MethodInfo* method));
DO_APP_FUNC(0x03CEED20, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo* method));
DO_APP_FUNC(0x03CD93D0, Transform*, GameObject_get_transform, (GameObject* __this, MethodInfo* method));
DO_APP_FUNC(0x03CD8380, GameObject*, GameObject_Find, (String* name, MethodInfo* method));
DO_APP_FUNC(0x03CDE030, String*, Object_1_get_name, (Object_1* __this, MethodInfo* method));
DO_APP_FUNC(0x03CE6CE0, void, Time_4_set_timeScale, (float value, MethodInfo* method));
DO_APP_FUNC(0x03CEB010, Vector3, Transform_get_position, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03CEBBF0, void, Transform_set_position, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03CEB060, Vector3, Transform_get_right, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03CEBC40, void, Transform_set_right, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03CEB330, Vector3, Transform_get_up, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03CEBDC0, void, Transform_set_up, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03CEA880, Vector3, Transform_get_forward, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03CEB710, void, Transform_set_forward, (Transform* __this, Vector3 value, MethodInfo* method));
DO_APP_FUNC(0x03CEA720, int32_t, Transform_get_childCount, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x03D04AF0, String*, Scene_GetNameInternal, (int32_t sceneHandle, MethodInfo* method));
DO_APP_FUNC(0x03D034C0, Scene, SceneManager_GetActiveScene, (MethodInfo* method));

// No Cooldown
DO_APP_FUNC(0x00A7C280, void/*KAAIFMKPKAG*/*, KAAIFMKPKAG_IOFMGMJCCFO, (KAAIFMKPKAG* __this, bool DEJNILEHENL, MethodInfo* method));
// Damage Hack
DO_APP_FUNC(0xa52c50, void, PIPHNBOBFEF_KBCIIEFLPGB, (PIPHNBOBFEF* __this, ESpecialState__Enum OCKAHFDGNEL, int64_t MGFPJFANLBG, int64_t DIACKALMMKH, int64_t PBAPBJGDAPJ, String* DLOACPLHGMP, MethodInfo* method));
// God Mode
DO_APP_FUNC(0xd7ca10, int32_t, GHINOEFFMPN_EKHGIHBHEPL, (SkillIdentity* EKPKPIJBPKE, void/*IEnumerable_1_UnityEngine_Component_*/* FKJDKGJBGOD, TargetHitData* COFCDKGCOGJ, MethodInfo* method));
// Dumb Enemies
DO_APP_FUNC(0x00E1DCA0, void, EvadeProxy_Init, (EvadeProxy* __this, ENNEJEPMJLJ* IGBKKNODEGM, EvadePenetration* DHPMEMDBDMC, MethodInfo* method));

// EntityManager
DO_APP_FUNC(0xaa24e0, void, ENHPKNIEKMI_MIFDFEHDDDD, (ENHPKNIEKMI* __this, MethodInfo* method));
DO_APP_FUNC(0x00527830, ENHPKNIEKMI*, ENNEJEPMJLJ_FIGHFBNIDJA, (ENNEJEPMJLJ* __this, MethodInfo* method));
DO_APP_FUNC(0xdd08e0, bool, PCILGJOEPJM_PPAKPBOJLIP, (ENNEJEPMJLJ* IGBKKNODEGM, MethodInfo* method)); // Check if Entity is alive????

// Mission Time
DO_APP_FUNC(0x005F8890, void, StageReadyPage_EnterUI, (StageReadyPage* __this, MethodInfo* method));
DO_APP_FUNC(0x005FBDB0, void, StoryQuestChapterPage_EnterUI, (StoryQuestChapterPage* __this, MethodInfo* method));
// Intro Movie
DO_APP_FUNC(0x00F15230, void, IntroMovie_Update, (IntroMovie* __this, MethodInfo* method));
// Disable Web View
DO_APP_FUNC(0x02ED0DB0, void, WebViewDialog_Show, (void* __this, MethodInfo* method));
DO_APP_FUNC(0x02EE4E00, void, WebViewUI_RefreshSize, (void* __this, MethodInfo* method));

//DO_APP_FUNC(0x00430040, EGLGAPIAANF__Enum, JIBDAHKJHOG_PCLINKFFGNE, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837FE0, void, JIBDAHKJHOG_KPDGECAFJKA, (JIBDAHKJHOG* __this, MethodInfo* method));
//DO_APP_FUNC(0x00837510, void, JIBDAHKJHOG_HLLNLMAECBD, (JIBDAHKJHOG* __this, void* JONOLJGMLBE, void* BHMPNNCBFGN, MethodInfo* method)); // EnterBattleReq
//DO_APP_FUNC(0x00836650, void, JIBDAHKJHOG_EJLDBPGJGPN, (JIBDAHKJHOG* __this, MethodInfo* method)); // NextStageBattle
//DO_APP_FUNC(0x00836410, void, JIBDAHKJHOG_COLDHPFDOHG, (JIBDAHKJHOG* __this, MethodInfo* method)); // StageStart

// Shadow Cooldown And Limit
DO_APP_FUNC(0xde6580, void, JLLMICINIDA_LFCGJLAFFOM, (JLLMICINIDA* __this, MethodInfo* method));

// Singletons
// DO_APP_FUNC(0x00384E60, void*, TSingleton_GetInstance, (MethodInfo* method)); // Search for this in IDA. Seems to be Singleton<T> class
DO_APP_FUNC(0x248f120, Object*, TSingleton_1_System_Object__get_Instance, (MethodInfo* method)); // Get the instance of the singleton
// DO_APP_FUNC_METHODINFO(0x04038380, TSingleton_1_JIBDAHKJHOG__get_Instance__MethodInfo);
// DO_APP_FUNC_METHODINFO(0x0403AC70, TSingleton_1_PJKMAOEINNH__get_Instance__MethodInfo); // Probably EntityManager or something similar