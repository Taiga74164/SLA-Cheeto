// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.2.0+

// ******************************************************************************
// * IL2CPP application-specific method definition addresses and signatures
// ******************************************************************************
using namespace app;


DO_APP_FUNC(0x00785F00, void, GameFrameWork_Update, (GameFrameWork* __this, MethodInfo* method));
DO_APP_FUNC(0x02F05F10, String*, Marshal_PtrToStringAnsi, (void* ptr, MethodInfo* method)); 
DO_APP_FUNC(0x02F05F30, String*, Marshal_PtrToStringUni, (void* ptr, MethodInfo* method));

// FovChanger
DO_APP_FUNC(0x04010900, void, Camera_set_fieldOfView, (Camera* __this, float value, MethodInfo* method));

// C# methods
DO_APP_FUNC(0x0303F700, Type*, Type_GetType_3, (String* typeName, MethodInfo* method));
DO_APP_FUNC(0x02EC02D0, Type*, Assembly_GetType, (Assembly* __this, String* name, MethodInfo* method));
DO_APP_FUNC(0x02F1A3D0, Assembly*, Assembly_LoadWithPartialName, (String* partialName, MethodInfo* method));

// Unity methods
DO_APP_FUNC(0x04009790, int32_t, Application_get_targetFrameRate, (MethodInfo* method)); 
DO_APP_FUNC(0x04009EB0, void, Application_set_targetFrameRate, (int32_t value, MethodInfo* method)); 
DO_APP_FUNC(0x0406A4E0, Vector3, Vector3_Lerp, (Vector3 a, Vector3 b, float t, MethodInfo* method));
DO_APP_FUNC(0x0406A280, float, Vector3_Distance, (Vector3 a, Vector3 b, MethodInfo* method));
DO_APP_FUNC(0x04055180, Transform*, GameObject_get_transform, (GameObject* __this, MethodInfo* method)); 
DO_APP_FUNC(0x04054130, GameObject*, GameObject_Find, (String* name, MethodInfo* method)); 
DO_APP_FUNC(0x04059DE0, String*, Object_1_get_name, (Object_1* __this, MethodInfo* method));
DDO_APP_FUNC(0x04062260, void, Time_4_set_timeScale, (float value, MethodInfo* method));
DO_APP_FUNC(0x04066570, Vector3, Transform_get_position, (Transform* __this, MethodInfo* method)); 
DO_APP_FUNC(0x04067150, void, Transform_set_position, (Transform* __this, Vector3 value, MethodInfo* method)); 
DO_APP_FUNC(0x040665C0, Vector3, Transform_get_right, (Transform* __this, MethodInfo* method)); 
DO_APP_FUNC(0x040671A0, void, Transform_set_right, (Transform* __this, Vector3 value, MethodInfo* method)); 
DO_APP_FUNC(0x04066890, Vector3, Transform_get_up, (Transform* __this, MethodInfo* method)); 
DO_APP_FUNC(0x04067320, void, Transform_set_up, (Transform* __this, Vector3 value, MethodInfo* method)); 
DO_APP_FUNC(0x04065DE0, Vector3, Transform_get_forward, (Transform* __this, MethodInfo* method)); 
DO_APP_FUNC(0x04066C70, void, Transform_set_forward, (Transform* __this, Vector3 value, MethodInfo* method)); 
DO_APP_FUNC(0x04065C80, int32_t, Transform_get_childCount, (Transform* __this, MethodInfo* method));
DO_APP_FUNC(0x04080600, String*, Scene_GetNameInternal, (int32_t sceneHandle, MethodInfo* method));
DO_APP_FUNC(0x0407EFD0, Scene, SceneManager_GetActiveScene, (MethodInfo* method));
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
