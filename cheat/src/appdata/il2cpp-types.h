
// Generated C++ file by Il2CppInspector - http://www.djkaty.com - https://github.com/djkaty
// Target Unity version: 2021.2.0+

#if defined(_GHIDRA_) || defined(_IDA_)
typedef unsigned __int8 uint8_t;
typedef unsigned __int16 uint16_t;
typedef unsigned __int32 uint32_t;
typedef unsigned __int64 uint64_t;
typedef __int8 int8_t;
typedef __int16 int16_t;
typedef __int32 int32_t;
typedef __int64 int64_t;
#endif

#if defined(_GHIDRA_)
typedef __int64 size_t;
typedef size_t intptr_t;
typedef size_t uintptr_t;
#endif

#if !defined(_GHIDRA_) && !defined(_IDA_)
#define _CPLUSPLUS_
#endif

#pragma region Il2Cpp Core

// ******************************************************************************
// * IL2CPP internal types
// ******************************************************************************

typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppType Il2CppType;
typedef struct EventInfo EventInfo;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppArray Il2CppArray;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppProfiler Il2CppProfiler;
typedef struct Il2CppObject Il2CppObject;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppReflectionType Il2CppReflectionType;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppThread Il2CppThread;
typedef struct Il2CppAsyncResult Il2CppAsyncResult;
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef struct Il2CppCustomAttrInfo Il2CppCustomAttrInfo;
typedef enum
{
	IL2CPP_PROFILE_NONE = 0,
	IL2CPP_PROFILE_APPDOMAIN_EVENTS = 1 << 0,
	IL2CPP_PROFILE_ASSEMBLY_EVENTS = 1 << 1,
	IL2CPP_PROFILE_MODULE_EVENTS = 1 << 2,
	IL2CPP_PROFILE_CLASS_EVENTS = 1 << 3,
	IL2CPP_PROFILE_JIT_COMPILATION = 1 << 4,
	IL2CPP_PROFILE_INLINING = 1 << 5,
	IL2CPP_PROFILE_EXCEPTIONS = 1 << 6,
	IL2CPP_PROFILE_ALLOCATIONS = 1 << 7,
	IL2CPP_PROFILE_GC = 1 << 8,
	IL2CPP_PROFILE_THREADS = 1 << 9,
	IL2CPP_PROFILE_REMOTING = 1 << 10,
	IL2CPP_PROFILE_TRANSITIONS = 1 << 11,
	IL2CPP_PROFILE_ENTER_LEAVE = 1 << 12,
	IL2CPP_PROFILE_COVERAGE = 1 << 13,
	IL2CPP_PROFILE_INS_COVERAGE = 1 << 14,
	IL2CPP_PROFILE_STATISTICAL = 1 << 15,
	IL2CPP_PROFILE_METHOD_EVENTS = 1 << 16,
	IL2CPP_PROFILE_MONITOR_EVENTS = 1 << 17,
	IL2CPP_PROFILE_IOMAP_EVENTS = 1 << 18,
	IL2CPP_PROFILE_GC_MOVES = 1 << 19,
	IL2CPP_PROFILE_FILEIO = 1 << 20
} Il2CppProfileFlags;
typedef enum
{
	IL2CPP_PROFILE_FILEIO_WRITE = 0,
	IL2CPP_PROFILE_FILEIO_READ
} Il2CppProfileFileIOKind;
typedef enum
{
	IL2CPP_GC_EVENT_START,
	IL2CPP_GC_EVENT_MARK_START,
	IL2CPP_GC_EVENT_MARK_END,
	IL2CPP_GC_EVENT_RECLAIM_START,
	IL2CPP_GC_EVENT_RECLAIM_END,
	IL2CPP_GC_EVENT_END,
	IL2CPP_GC_EVENT_PRE_STOP_WORLD,
	IL2CPP_GC_EVENT_POST_STOP_WORLD,
	IL2CPP_GC_EVENT_PRE_START_WORLD,
	IL2CPP_GC_EVENT_POST_START_WORLD
} Il2CppGCEvent;
typedef enum
{
	IL2CPP_GC_MODE_DISABLED = 0,
	IL2CPP_GC_MODE_ENABLED = 1,
	IL2CPP_GC_MODE_MANUAL = 2
} Il2CppGCMode;
typedef enum
{
	IL2CPP_STAT_NEW_OBJECT_COUNT,
	IL2CPP_STAT_INITIALIZED_CLASS_COUNT,
	IL2CPP_STAT_METHOD_COUNT,
	IL2CPP_STAT_CLASS_STATIC_DATA_SIZE,
	IL2CPP_STAT_GENERIC_INSTANCE_COUNT,
	IL2CPP_STAT_GENERIC_CLASS_COUNT,
	IL2CPP_STAT_INFLATED_METHOD_COUNT,
	IL2CPP_STAT_INFLATED_TYPE_COUNT,
} Il2CppStat;
typedef enum
{
	IL2CPP_UNHANDLED_POLICY_LEGACY,
	IL2CPP_UNHANDLED_POLICY_CURRENT
} Il2CppRuntimeUnhandledExceptionPolicy;
typedef struct Il2CppStackFrameInfo
{
	const MethodInfo* method;
	uintptr_t raw_ip;
	int sourceCodeLineNumber;
	int ilOffset;
	const char* filePath;
} Il2CppStackFrameInfo;
typedef void(*Il2CppMethodPointer)();
typedef struct Il2CppMethodDebugInfo
{
	Il2CppMethodPointer methodPointer;
	int32_t code_size;
	const char* file;
} Il2CppMethodDebugInfo;
typedef struct
{
	void* (*malloc_func)(size_t size);
	void* (*aligned_malloc_func)(size_t size, size_t alignment);
	void (*free_func)(void* ptr);
	void (*aligned_free_func)(void* ptr);
	void* (*calloc_func)(size_t nmemb, size_t size);
	void* (*realloc_func)(void* ptr, size_t size);
	void* (*aligned_realloc_func)(void* ptr, size_t size, size_t alignment);
} Il2CppMemoryCallbacks;
typedef struct
{
	const char* name;
	void(*connect)(const char* address);
	int(*wait_for_attach)(void);
	void(*close1)(void);
	void(*close2)(void);
	int(*send)(void* buf, int len);
	int(*recv)(void* buf, int len);
} Il2CppDebuggerTransport;
typedef uint16_t Il2CppChar;
typedef char Il2CppNativeChar;
typedef void (*il2cpp_register_object_callback)(Il2CppObject** arr, int size, void* userdata);
typedef void* (*il2cpp_liveness_reallocate_callback)(void* ptr, size_t size, void* userdata);
typedef void (*Il2CppFrameWalkFunc) (const Il2CppStackFrameInfo* info, void* user_data);
typedef void (*Il2CppProfileFunc) (Il2CppProfiler* prof);
typedef void (*Il2CppProfileMethodFunc) (Il2CppProfiler* prof, const MethodInfo* method);
typedef void (*Il2CppProfileAllocFunc) (Il2CppProfiler* prof, Il2CppObject* obj, Il2CppClass* klass);
typedef void (*Il2CppProfileGCFunc) (Il2CppProfiler* prof, Il2CppGCEvent event, int generation);
typedef void (*Il2CppProfileGCResizeFunc) (Il2CppProfiler* prof, int64_t new_size);
typedef void (*Il2CppProfileFileIOFunc) (Il2CppProfiler* prof, Il2CppProfileFileIOKind kind, int count);
typedef void (*Il2CppProfileThreadFunc) (Il2CppProfiler* prof, unsigned long tid);
typedef const Il2CppNativeChar* (*Il2CppSetFindPlugInCallback)(const Il2CppNativeChar*);
typedef void (*Il2CppLogCallback)(const char*);
typedef size_t(*Il2CppBacktraceFunc) (Il2CppMethodPointer* buffer, size_t maxSize);
typedef struct Il2CppManagedMemorySnapshot Il2CppManagedMemorySnapshot;
typedef uintptr_t il2cpp_array_size_t;
typedef void (*SynchronizationContextCallback)(intptr_t arg);
typedef void (*CultureInfoChangedCallback)(const Il2CppChar* arg);
typedef uint16_t Il2CppMethodSlot;
static const uint16_t kInvalidIl2CppMethodSlot = 65535;
static const int ipv6AddressSize = 16;
typedef int32_t il2cpp_hresult_t;
typedef enum
{
	IL2CPP_TOKEN_MODULE = 0x00000000,
	IL2CPP_TOKEN_TYPE_REF = 0x01000000,
	IL2CPP_TOKEN_TYPE_DEF = 0x02000000,
	IL2CPP_TOKEN_FIELD_DEF = 0x04000000,
	IL2CPP_TOKEN_METHOD_DEF = 0x06000000,
	IL2CPP_TOKEN_PARAM_DEF = 0x08000000,
	IL2CPP_TOKEN_INTERFACE_IMPL = 0x09000000,
	IL2CPP_TOKEN_MEMBER_REF = 0x0a000000,
	IL2CPP_TOKEN_CUSTOM_ATTRIBUTE = 0x0c000000,
	IL2CPP_TOKEN_PERMISSION = 0x0e000000,
	IL2CPP_TOKEN_SIGNATURE = 0x11000000,
	IL2CPP_TOKEN_EVENT = 0x14000000,
	IL2CPP_TOKEN_PROPERTY = 0x17000000,
	IL2CPP_TOKEN_MODULE_REF = 0x1a000000,
	IL2CPP_TOKEN_TYPE_SPEC = 0x1b000000,
	IL2CPP_TOKEN_ASSEMBLY = 0x20000000,
	IL2CPP_TOKEN_ASSEMBLY_REF = 0x23000000,
	IL2CPP_TOKEN_FILE = 0x26000000,
	IL2CPP_TOKEN_EXPORTED_TYPE = 0x27000000,
	IL2CPP_TOKEN_MANIFEST_RESOURCE = 0x28000000,
	IL2CPP_TOKEN_GENERIC_PARAM = 0x2a000000,
	IL2CPP_TOKEN_METHOD_SPEC = 0x2b000000,
} Il2CppTokenType;
typedef int32_t TypeIndex;
typedef int32_t TypeDefinitionIndex;
typedef int32_t FieldIndex;
typedef int32_t DefaultValueIndex;
typedef int32_t DefaultValueDataIndex;
typedef int32_t CustomAttributeIndex;
typedef int32_t ParameterIndex;
typedef int32_t MethodIndex;
typedef int32_t GenericMethodIndex;
typedef int32_t PropertyIndex;
typedef int32_t EventIndex;
typedef int32_t GenericContainerIndex;
typedef int32_t GenericParameterIndex;
typedef int16_t GenericParameterConstraintIndex;
typedef int32_t NestedTypeIndex;
typedef int32_t InterfacesIndex;
typedef int32_t VTableIndex;
typedef int32_t RGCTXIndex;
typedef int32_t StringIndex;
typedef int32_t StringLiteralIndex;
typedef int32_t GenericInstIndex;
typedef int32_t ImageIndex;
typedef int32_t AssemblyIndex;
typedef int32_t InteropDataIndex;
typedef int32_t TypeFieldIndex;
typedef int32_t TypeMethodIndex;
typedef int32_t MethodParameterIndex;
typedef int32_t TypePropertyIndex;
typedef int32_t TypeEventIndex;
typedef int32_t TypeInterfaceIndex;
typedef int32_t TypeNestedTypeIndex;
typedef int32_t TypeInterfaceOffsetIndex;
typedef int32_t GenericContainerParameterIndex;
typedef int32_t AssemblyTypeIndex;
typedef int32_t AssemblyExportedTypeIndex;
static const TypeIndex kTypeIndexInvalid = -1;
static const TypeDefinitionIndex kTypeDefinitionIndexInvalid = -1;
static const DefaultValueDataIndex kDefaultValueIndexNull = -1;
static const CustomAttributeIndex kCustomAttributeIndexInvalid = -1;
static const EventIndex kEventIndexInvalid = -1;
static const FieldIndex kFieldIndexInvalid = -1;
static const MethodIndex kMethodIndexInvalid = -1;
static const PropertyIndex kPropertyIndexInvalid = -1;
static const GenericContainerIndex kGenericContainerIndexInvalid = -1;
static const GenericParameterIndex kGenericParameterIndexInvalid = -1;
static const RGCTXIndex kRGCTXIndexInvalid = -1;
static const StringLiteralIndex kStringLiteralIndexInvalid = -1;
static const InteropDataIndex kInteropDataIndexInvalid = -1;
static const int kPublicKeyByteLength = 8;
typedef struct Il2CppMethodSpec
{
	MethodIndex methodDefinitionIndex;
	GenericInstIndex classIndexIndex;
	GenericInstIndex methodIndexIndex;
} Il2CppMethodSpec;
typedef enum Il2CppRGCTXDataType
{
	IL2CPP_RGCTX_DATA_INVALID,
	IL2CPP_RGCTX_DATA_TYPE,
	IL2CPP_RGCTX_DATA_CLASS,
	IL2CPP_RGCTX_DATA_METHOD,
	IL2CPP_RGCTX_DATA_ARRAY,
	IL2CPP_RGCTX_DATA_CONSTRAINED,
} Il2CppRGCTXDataType;
typedef union Il2CppRGCTXDefinitionData
{
	int32_t rgctxDataDummy;
	MethodIndex __methodIndex;
	TypeIndex __typeIndex;
} Il2CppRGCTXDefinitionData;
typedef struct Il2CppRGCTXConstrainedData
{
	TypeIndex __typeIndex;
	uint32_t __encodedMethodIndex;
} Il2CppRGCTXConstrainedData;
typedef struct Il2CppRGCTXDefinition
{
	Il2CppRGCTXDataType type;
	const void* data;
} Il2CppRGCTXDefinition;
typedef struct
{
	MethodIndex methodIndex;
	MethodIndex invokerIndex;
	MethodIndex adjustorThunkIndex;
} Il2CppGenericMethodIndices;
typedef struct Il2CppGenericMethodFunctionsDefinitions
{
	GenericMethodIndex genericMethodIndex;
	Il2CppGenericMethodIndices indices;
} Il2CppGenericMethodFunctionsDefinitions;
static inline uint32_t GetTokenType(uint32_t token)
{
	return token & 0xFF000000;
}
static inline uint32_t GetTokenRowId(uint32_t token)
{
	return token & 0x00FFFFFF;
}
typedef const struct ___Il2CppMetadataImageHandle* Il2CppMetadataImageHandle;
typedef const struct ___Il2CppMetadataCustomAttributeHandle* Il2CppMetadataCustomAttributeHandle;
typedef const struct ___Il2CppMetadataTypeHandle* Il2CppMetadataTypeHandle;
typedef const struct ___Il2CppMetadataMethodHandle* Il2CppMetadataMethodDefinitionHandle;
typedef const struct ___Il2CppMetadataGenericContainerHandle* Il2CppMetadataGenericContainerHandle;
typedef const struct ___Il2CppMetadataGenericParameterHandle* Il2CppMetadataGenericParameterHandle;
typedef uint32_t EncodedMethodIndex;
typedef enum Il2CppMetadataUsage
{
	kIl2CppMetadataUsageInvalid,
	kIl2CppMetadataUsageTypeInfo,
	kIl2CppMetadataUsageIl2CppType,
	kIl2CppMetadataUsageMethodDef,
	kIl2CppMetadataUsageFieldInfo,
	kIl2CppMetadataUsageStringLiteral,
	kIl2CppMetadataUsageMethodRef,
} Il2CppMetadataUsage;
typedef enum Il2CppInvalidMetadataUsageToken
{
	kIl2CppInvalidMetadataUsageNoData = 0,
	kIl2CppInvalidMetadataUsageAmbiguousMethod = 1,
} Il2CppInvalidMetadataUsageToken;
typedef struct Il2CppInterfaceOffsetPair
{
	TypeIndex interfaceTypeIndex;
	int32_t offset;
} Il2CppInterfaceOffsetPair;
typedef struct Il2CppTypeDefinition
{
	StringIndex nameIndex;
	StringIndex namespaceIndex;
	TypeIndex byvalTypeIndex;
	TypeIndex declaringTypeIndex;
	TypeIndex parentIndex;
	TypeIndex elementTypeIndex;
	GenericContainerIndex genericContainerIndex;
	uint32_t flags;
	FieldIndex fieldStart;
	MethodIndex methodStart;
	EventIndex eventStart;
	PropertyIndex propertyStart;
	NestedTypeIndex nestedTypesStart;
	InterfacesIndex interfacesStart;
	VTableIndex vtableStart;
	InterfacesIndex interfaceOffsetsStart;
	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;
	uint32_t bitfield;
	uint32_t token;
} Il2CppTypeDefinition;
typedef struct Il2CppFieldDefinition
{
	StringIndex nameIndex;
	TypeIndex typeIndex;
	uint32_t token;
} Il2CppFieldDefinition;
typedef struct Il2CppFieldDefaultValue
{
	FieldIndex fieldIndex;
	TypeIndex typeIndex;
	DefaultValueDataIndex dataIndex;
} Il2CppFieldDefaultValue;
typedef struct Il2CppFieldMarshaledSize
{
	FieldIndex fieldIndex;
	TypeIndex typeIndex;
	int32_t size;
} Il2CppFieldMarshaledSize;
typedef struct Il2CppFieldRef
{
	TypeIndex typeIndex;
	FieldIndex fieldIndex;
} Il2CppFieldRef;
typedef struct Il2CppParameterDefinition
{
	StringIndex nameIndex;
	uint32_t token;
	TypeIndex typeIndex;
} Il2CppParameterDefinition;
typedef struct Il2CppParameterDefaultValue
{
	ParameterIndex parameterIndex;
	TypeIndex typeIndex;
	DefaultValueDataIndex dataIndex;
} Il2CppParameterDefaultValue;
typedef struct Il2CppMethodDefinition
{
	StringIndex nameIndex;
	TypeDefinitionIndex declaringType;
	TypeIndex returnType;
	ParameterIndex parameterStart;
	GenericContainerIndex genericContainerIndex;
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint16_t parameterCount;
} Il2CppMethodDefinition;
typedef struct Il2CppEventDefinition
{
	StringIndex nameIndex;
	TypeIndex typeIndex;
	MethodIndex add;
	MethodIndex remove;
	MethodIndex raise;
	uint32_t token;
} Il2CppEventDefinition;
typedef struct Il2CppPropertyDefinition
{
	StringIndex nameIndex;
	MethodIndex get;
	MethodIndex set;
	uint32_t attrs;
	uint32_t token;
} Il2CppPropertyDefinition;
typedef struct Il2CppStringLiteral
{
	uint32_t length;
	StringLiteralIndex dataIndex;
} Il2CppStringLiteral;
typedef struct Il2CppAssemblyNameDefinition
{
	StringIndex nameIndex;
	StringIndex cultureIndex;
	StringIndex publicKeyIndex;
	uint32_t hash_alg;
	int32_t hash_len;
	uint32_t flags;
	int32_t major;
	int32_t minor;
	int32_t build;
	int32_t revision;
	uint8_t public_key_token[8];
} Il2CppAssemblyNameDefinition;
typedef struct Il2CppImageDefinition
{
	StringIndex nameIndex;
	AssemblyIndex assemblyIndex;
	TypeDefinitionIndex typeStart;
	uint32_t typeCount;
	TypeDefinitionIndex exportedTypeStart;
	uint32_t exportedTypeCount;
	MethodIndex entryPointIndex;
	uint32_t token;
	CustomAttributeIndex customAttributeStart;
	uint32_t customAttributeCount;
} Il2CppImageDefinition;
typedef struct Il2CppAssemblyDefinition
{
	ImageIndex imageIndex;
	uint32_t token;
	int32_t referencedAssemblyStart;
	int32_t referencedAssemblyCount;
	Il2CppAssemblyNameDefinition aname;
} Il2CppAssemblyDefinition;
typedef struct Il2CppCustomAttributeDataRange
{
	uint32_t token;
	uint32_t startOffset;
} Il2CppCustomAttributeDataRange;
typedef struct Il2CppMetadataRange
{
	int32_t start;
	int32_t length;
} Il2CppMetadataRange;
typedef struct Il2CppGenericContainer
{
	int32_t ownerIndex;
	int32_t type_argc;
	int32_t is_method;
	GenericParameterIndex genericParameterStart;
} Il2CppGenericContainer;
typedef struct Il2CppGenericParameter
{
	GenericContainerIndex ownerIndex;
	StringIndex nameIndex;
	GenericParameterConstraintIndex constraintsStart;
	int16_t constraintsCount;
	uint16_t num;
	uint16_t flags;
} Il2CppGenericParameter;
typedef struct Il2CppWindowsRuntimeTypeNamePair
{
	StringIndex nameIndex;
	TypeIndex typeIndex;
} Il2CppWindowsRuntimeTypeNamePair;
#pragma pack(push, p1,4)
typedef struct Il2CppGlobalMetadataHeader
{
	int32_t sanity;
	int32_t version;
	int32_t stringLiteralOffset;
	int32_t stringLiteralCount;
	int32_t stringLiteralDataOffset;
	int32_t stringLiteralDataCount;
	int32_t stringOffset;
	int32_t stringCount;
	int32_t eventsOffset;
	int32_t eventsCount;
	int32_t propertiesOffset;
	int32_t propertiesCount;
	int32_t methodsOffset;
	int32_t methodsCount;
	int32_t parameterDefaultValuesOffset;
	int32_t parameterDefaultValuesCount;
	int32_t fieldDefaultValuesOffset;
	int32_t fieldDefaultValuesCount;
	int32_t fieldAndParameterDefaultValueDataOffset;
	int32_t fieldAndParameterDefaultValueDataCount;
	int32_t fieldMarshaledSizesOffset;
	int32_t fieldMarshaledSizesCount;
	int32_t parametersOffset;
	int32_t parametersCount;
	int32_t fieldsOffset;
	int32_t fieldsCount;
	int32_t genericParametersOffset;
	int32_t genericParametersCount;
	int32_t genericParameterConstraintsOffset;
	int32_t genericParameterConstraintsCount;
	int32_t genericContainersOffset;
	int32_t genericContainersCount;
	int32_t nestedTypesOffset;
	int32_t nestedTypesCount;
	int32_t interfacesOffset;
	int32_t interfacesCount;
	int32_t vtableMethodsOffset;
	int32_t vtableMethodsCount;
	int32_t interfaceOffsetsOffset;
	int32_t interfaceOffsetsCount;
	int32_t typeDefinitionsOffset;
	int32_t typeDefinitionsCount;
	int32_t imagesOffset;
	int32_t imagesCount;
	int32_t assembliesOffset;
	int32_t assembliesCount;
	int32_t fieldRefsOffset;
	int32_t fieldRefsCount;
	int32_t referencedAssembliesOffset;
	int32_t referencedAssembliesCount;
	int32_t attributeDataOffset;
	int32_t attributeDataCount;
	int32_t attributeDataRangeOffset;
	int32_t attributeDataRangeCount;
	int32_t unresolvedVirtualCallParameterTypesOffset;
	int32_t unresolvedVirtualCallParameterTypesCount;
	int32_t unresolvedVirtualCallParameterRangesOffset;
	int32_t unresolvedVirtualCallParameterRangesCount;
	int32_t windowsRuntimeTypeNamesOffset;
	int32_t windowsRuntimeTypeNamesSize;
	int32_t windowsRuntimeStringsOffset;
	int32_t windowsRuntimeStringsSize;
	int32_t exportedTypeDefinitionsOffset;
	int32_t exportedTypeDefinitionsCount;
} Il2CppGlobalMetadataHeader;
#pragma pack(pop, p1)
typedef struct Il2CppMetadataField
{
	uint32_t offset;
	uint32_t typeIndex;
	const char* name;
	uint8_t isStatic;
} Il2CppMetadataField;
typedef enum Il2CppMetadataTypeFlags
{
	kNone = 0,
	kValueType = 1 << 0,
	kArray = 1 << 1,
	kArrayRankMask = 0xFFFF0000
} Il2CppMetadataTypeFlags;
typedef struct Il2CppMetadataType
{
	Il2CppMetadataTypeFlags flags;
	Il2CppMetadataField* fields;
	uint32_t fieldCount;
	uint32_t staticsSize;
	uint8_t* statics;
	uint32_t baseOrElementTypeIndex;
	char* name;
	const char* assemblyName;
	uint64_t typeInfoAddress;
	uint32_t size;
} Il2CppMetadataType;
typedef struct Il2CppMetadataSnapshot
{
	uint32_t typeCount;
	Il2CppMetadataType* types;
} Il2CppMetadataSnapshot;
typedef struct Il2CppManagedMemorySection
{
	uint64_t sectionStartAddress;
	uint32_t sectionSize;
	uint8_t* sectionBytes;
} Il2CppManagedMemorySection;
typedef struct Il2CppManagedHeap
{
	uint32_t sectionCount;
	Il2CppManagedMemorySection* sections;
} Il2CppManagedHeap;
typedef struct Il2CppStacks
{
	uint32_t stackCount;
	Il2CppManagedMemorySection* stacks;
} Il2CppStacks;
typedef struct NativeObject
{
	uint32_t gcHandleIndex;
	uint32_t size;
	uint32_t instanceId;
	uint32_t classId;
	uint32_t referencedNativeObjectIndicesCount;
	uint32_t* referencedNativeObjectIndices;
} NativeObject;
typedef struct Il2CppGCHandles
{
	uint32_t trackedObjectCount;
	uint64_t* pointersToObjects;
} Il2CppGCHandles;
typedef struct Il2CppRuntimeInformation
{
	uint32_t pointerSize;
	uint32_t objectHeaderSize;
	uint32_t arrayHeaderSize;
	uint32_t arrayBoundsOffsetInHeader;
	uint32_t arraySizeOffsetInHeader;
	uint32_t allocationGranularity;
} Il2CppRuntimeInformation;
typedef struct Il2CppManagedMemorySnapshot
{
	Il2CppManagedHeap heap;
	Il2CppStacks stacks;
	Il2CppMetadataSnapshot metadata;
	Il2CppGCHandles gcHandles;
	Il2CppRuntimeInformation runtimeInformation;
	void* additionalUserInformation;
} Il2CppManagedMemorySnapshot;
typedef enum Il2CppTypeEnum
{
	IL2CPP_TYPE_END = 0x00,
	IL2CPP_TYPE_VOID = 0x01,
	IL2CPP_TYPE_BOOLEAN = 0x02,
	IL2CPP_TYPE_CHAR = 0x03,
	IL2CPP_TYPE_I1 = 0x04,
	IL2CPP_TYPE_U1 = 0x05,
	IL2CPP_TYPE_I2 = 0x06,
	IL2CPP_TYPE_U2 = 0x07,
	IL2CPP_TYPE_I4 = 0x08,
	IL2CPP_TYPE_U4 = 0x09,
	IL2CPP_TYPE_I8 = 0x0a,
	IL2CPP_TYPE_U8 = 0x0b,
	IL2CPP_TYPE_R4 = 0x0c,
	IL2CPP_TYPE_R8 = 0x0d,
	IL2CPP_TYPE_STRING = 0x0e,
	IL2CPP_TYPE_PTR = 0x0f,
	IL2CPP_TYPE_BYREF = 0x10,
	IL2CPP_TYPE_VALUETYPE = 0x11,
	IL2CPP_TYPE_CLASS = 0x12,
	IL2CPP_TYPE_VAR = 0x13,
	IL2CPP_TYPE_ARRAY = 0x14,
	IL2CPP_TYPE_GENERICINST = 0x15,
	IL2CPP_TYPE_TYPEDBYREF = 0x16,
	IL2CPP_TYPE_I = 0x18,
	IL2CPP_TYPE_U = 0x19,
	IL2CPP_TYPE_FNPTR = 0x1b,
	IL2CPP_TYPE_OBJECT = 0x1c,
	IL2CPP_TYPE_SZARRAY = 0x1d,
	IL2CPP_TYPE_MVAR = 0x1e,
	IL2CPP_TYPE_CMOD_REQD = 0x1f,
	IL2CPP_TYPE_CMOD_OPT = 0x20,
	IL2CPP_TYPE_INTERNAL = 0x21,
	IL2CPP_TYPE_MODIFIER = 0x40,
	IL2CPP_TYPE_SENTINEL = 0x41,
	IL2CPP_TYPE_PINNED = 0x45,
	IL2CPP_TYPE_ENUM = 0x55,
	IL2CPP_TYPE_IL2CPP_TYPE_INDEX = 0xff
} Il2CppTypeEnum;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppArrayType
{
	const Il2CppType* etype;
	uint8_t rank;
	uint8_t numsizes;
	uint8_t numlobounds;
	int* sizes;
	int* lobounds;
} Il2CppArrayType;
typedef struct Il2CppGenericInst
{
	uint32_t type_argc;
	const Il2CppType** type_argv;
} Il2CppGenericInst;
typedef struct Il2CppGenericContext
{
	const Il2CppGenericInst* class_inst;
	const Il2CppGenericInst* method_inst;
} Il2CppGenericContext;
typedef struct Il2CppGenericClass
{
	const Il2CppType* type;
	Il2CppGenericContext context;
	Il2CppClass* cached_class;
} Il2CppGenericClass;
typedef struct Il2CppGenericMethod
{
	const MethodInfo* methodDefinition;
	Il2CppGenericContext context;
} Il2CppGenericMethod;
typedef struct Il2CppType
{
	union
	{
		void* dummy;
		TypeDefinitionIndex __klassIndex;
		Il2CppMetadataTypeHandle typeHandle;
		const Il2CppType* type;
		Il2CppArrayType* array;
		GenericParameterIndex __genericParameterIndex;
		Il2CppMetadataGenericParameterHandle genericParameterHandle;
		Il2CppGenericClass* generic_class;
	} data;
	unsigned int attrs : 16;
	Il2CppTypeEnum type : 8;
	unsigned int num_mods : 5;
	unsigned int byref : 1;
	unsigned int pinned : 1;
	unsigned int valuetype : 1;
} Il2CppType;
typedef struct Il2CppMetadataFieldInfo
{
	const Il2CppType* type;
	const char* name;
	uint32_t token;
} Il2CppMetadataFieldInfo;
typedef struct Il2CppMetadataMethodInfo
{
	Il2CppMetadataMethodDefinitionHandle handle;
	const char* name;
	const Il2CppType* return_type;
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint16_t parameterCount;
} Il2CppMetadataMethodInfo;
typedef struct Il2CppMetadataParameterInfo
{
	const char* name;
	uint32_t token;
	const Il2CppType* type;
} Il2CppMetadataParameterInfo;
typedef struct Il2CppMetadataPropertyInfo
{
	const char* name;
	const MethodInfo* get;
	const MethodInfo* set;
	uint32_t attrs;
	uint32_t token;
} Il2CppMetadataPropertyInfo;
typedef struct Il2CppMetadataEventInfo
{
	const char* name;
	const Il2CppType* type;
	const MethodInfo* add;
	const MethodInfo* remove;
	const MethodInfo* raise;
	uint32_t token;
} Il2CppMetadataEventInfo;
typedef struct Il2CppInterfaceOffsetInfo
{
	const Il2CppType* interfaceType;
	int32_t offset;
} Il2CppInterfaceOffsetInfo;
typedef struct Il2CppGenericParameterInfo
{
	Il2CppMetadataGenericContainerHandle containerHandle;
	const char* name;
	uint16_t num;
	uint16_t flags;
} Il2CppGenericParameterInfo;
typedef enum Il2CppCallConvention
{
	IL2CPP_CALL_DEFAULT,
	IL2CPP_CALL_C,
	IL2CPP_CALL_STDCALL,
	IL2CPP_CALL_THISCALL,
	IL2CPP_CALL_FASTCALL,
	IL2CPP_CALL_VARARG
} Il2CppCallConvention;
typedef enum Il2CppCharSet
{
	CHARSET_ANSI,
	CHARSET_UNICODE,
	CHARSET_NOT_SPECIFIED
} Il2CppCharSet;
typedef struct Il2CppHString__
{
	int unused;
} Il2CppHString__;
typedef Il2CppHString__* Il2CppHString;
typedef struct Il2CppHStringHeader
{
	union
	{
		void* Reserved1;
		char Reserved2[24];
	} Reserved;
} Il2CppHStringHeader;
typedef struct Il2CppGuid
{
	uint32_t data1;
	uint16_t data2;
	uint16_t data3;
	uint8_t data4[8];
} Il2CppGuid;
typedef struct Il2CppSafeArrayBound
{
	uint32_t element_count;
	int32_t lower_bound;
} Il2CppSafeArrayBound;
typedef struct Il2CppSafeArray
{
	uint16_t dimension_count;
	uint16_t features;
	uint32_t element_size;
	uint32_t lock_count;
	void* data;
	Il2CppSafeArrayBound bounds[1];
} Il2CppSafeArray;
typedef struct Il2CppWin32Decimal
{
	uint16_t reserved;
	union
	{
		struct
		{
			uint8_t scale;
			uint8_t sign;
		} s;
		uint16_t signscale;
	} u;
	uint32_t hi32;
	union
	{
		struct
		{
			uint32_t lo32;
			uint32_t mid32;
		} s2;
		uint64_t lo64;
	} u2;
} Il2CppWin32Decimal;
typedef int16_t IL2CPP_VARIANT_BOOL;
typedef enum Il2CppVarType
{
	IL2CPP_VT_EMPTY = 0,
	IL2CPP_VT_NULL = 1,
	IL2CPP_VT_I2 = 2,
	IL2CPP_VT_I4 = 3,
	IL2CPP_VT_R4 = 4,
	IL2CPP_VT_R8 = 5,
	IL2CPP_VT_CY = 6,
	IL2CPP_VT_DATE = 7,
	IL2CPP_VT_BSTR = 8,
	IL2CPP_VT_DISPATCH = 9,
	IL2CPP_VT_ERROR = 10,
	IL2CPP_VT_BOOL = 11,
	IL2CPP_VT_VARIANT = 12,
	IL2CPP_VT_UNKNOWN = 13,
	IL2CPP_VT_DECIMAL = 14,
	IL2CPP_VT_I1 = 16,
	IL2CPP_VT_UI1 = 17,
	IL2CPP_VT_UI2 = 18,
	IL2CPP_VT_UI4 = 19,
	IL2CPP_VT_I8 = 20,
	IL2CPP_VT_UI8 = 21,
	IL2CPP_VT_INT = 22,
	IL2CPP_VT_UINT = 23,
	IL2CPP_VT_VOID = 24,
	IL2CPP_VT_HRESULT = 25,
	IL2CPP_VT_PTR = 26,
	IL2CPP_VT_SAFEARRAY = 27,
	IL2CPP_VT_CARRAY = 28,
	IL2CPP_VT_USERDEFINED = 29,
	IL2CPP_VT_LPSTR = 30,
	IL2CPP_VT_LPWSTR = 31,
	IL2CPP_VT_RECORD = 36,
	IL2CPP_VT_INT_PTR = 37,
	IL2CPP_VT_UINT_PTR = 38,
	IL2CPP_VT_FILETIME = 64,
	IL2CPP_VT_BLOB = 65,
	IL2CPP_VT_STREAM = 66,
	IL2CPP_VT_STORAGE = 67,
	IL2CPP_VT_STREAMED_OBJECT = 68,
	IL2CPP_VT_STORED_OBJECT = 69,
	IL2CPP_VT_BLOB_OBJECT = 70,
	IL2CPP_VT_CF = 71,
	IL2CPP_VT_CLSID = 72,
	IL2CPP_VT_VERSIONED_STREAM = 73,
	IL2CPP_VT_BSTR_BLOB = 0xfff,
	IL2CPP_VT_VECTOR = 0x1000,
	IL2CPP_VT_ARRAY = 0x2000,
	IL2CPP_VT_BYREF = 0x4000,
	IL2CPP_VT_RESERVED = 0x8000,
	IL2CPP_VT_ILLEGAL = 0xffff,
	IL2CPP_VT_ILLEGALMASKED = 0xfff,
	IL2CPP_VT_TYPEMASK = 0xfff,
} Il2CppVarType;
typedef struct Il2CppVariant Il2CppVariant;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppVariant
{
	union
	{
		struct __tagVARIANT
		{
			uint16_t type;
			uint16_t reserved1;
			uint16_t reserved2;
			uint16_t reserved3;
			union
			{
				int64_t llVal;
				int32_t lVal;
				uint8_t bVal;
				int16_t iVal;
				float fltVal;
				double dblVal;
				IL2CPP_VARIANT_BOOL boolVal;
				int32_t scode;
				int64_t cyVal;
				double date;
				Il2CppChar* bstrVal;
				Il2CppIUnknown* punkVal;
				void* pdispVal;
				Il2CppSafeArray* parray;
				uint8_t* pbVal;
				int16_t* piVal;
				int32_t* plVal;
				int64_t* pllVal;
				float* pfltVal;
				double* pdblVal;
				IL2CPP_VARIANT_BOOL* pboolVal;
				int32_t* pscode;
				int64_t* pcyVal;
				double* pdate;
				Il2CppChar* pbstrVal;
				Il2CppIUnknown** ppunkVal;
				void** ppdispVal;
				Il2CppSafeArray** pparray;
				struct Il2CppVariant* pvarVal;
				void* byref;
				char cVal;
				uint16_t uiVal;
				uint32_t ulVal;
				uint64_t ullVal;
				int intVal;
				unsigned int uintVal;
				Il2CppWin32Decimal* pdecVal;
				char* pcVal;
				uint16_t* puiVal;
				uint32_t* pulVal;
				uint64_t* pullVal;
				int* pintVal;
				unsigned int* puintVal;
				struct __tagBRECORD
				{
					void* pvRecord;
					void* pRecInfo;
				} n4;
			} n3;
		} n2;
		Il2CppWin32Decimal decVal;
	} n1;
} Il2CppVariant;
typedef struct Il2CppFileTime
{
	uint32_t low;
	uint32_t high;
} Il2CppFileTime;
typedef struct Il2CppStatStg
{
	Il2CppChar* name;
	uint32_t type;
	uint64_t size;
	Il2CppFileTime mtime;
	Il2CppFileTime ctime;
	Il2CppFileTime atime;
	uint32_t mode;
	uint32_t locks;
	Il2CppGuid clsid;
	uint32_t state;
	uint32_t reserved;
} Il2CppStatStg;
typedef enum Il2CppWindowsRuntimeTypeKind
{
	kTypeKindPrimitive = 0,
	kTypeKindMetadata,
	kTypeKindCustom
} Il2CppWindowsRuntimeTypeKind;
typedef struct Il2CppWindowsRuntimeTypeName
{
	Il2CppHString typeName;
	enum Il2CppWindowsRuntimeTypeKind typeKind;
} Il2CppWindowsRuntimeTypeName;
typedef void (*PInvokeMarshalToNativeFunc)(void* managedStructure, void* marshaledStructure);
typedef void (*PInvokeMarshalFromNativeFunc)(void* marshaledStructure, void* managedStructure);
typedef void (*PInvokeMarshalCleanupFunc)(void* marshaledStructure);
typedef struct Il2CppIUnknown* (*CreateCCWFunc)(Il2CppObject* obj);
typedef struct Il2CppInteropData
{
	Il2CppMethodPointer delegatePInvokeWrapperFunction;
	PInvokeMarshalToNativeFunc pinvokeMarshalToNativeFunction;
	PInvokeMarshalFromNativeFunc pinvokeMarshalFromNativeFunction;
	PInvokeMarshalCleanupFunc pinvokeMarshalCleanupFunction;
	CreateCCWFunc createCCWFunction;
	const Il2CppGuid* guid;
	const Il2CppType* type;
} Il2CppInteropData;
typedef struct Il2CppCodeGenModule Il2CppCodeGenModule;
typedef struct Il2CppMetadataRegistration Il2CppMetadataRegistration;
typedef struct Il2CppCodeRegistration Il2CppCodeRegistration;
typedef struct Il2CppClass Il2CppClass;
typedef struct Il2CppGuid Il2CppGuid;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppAppDomain Il2CppAppDomain;
typedef struct Il2CppAppDomainSetup Il2CppAppDomainSetup;
typedef struct Il2CppDelegate Il2CppDelegate;
typedef struct Il2CppAppContext Il2CppAppContext;
typedef struct Il2CppNameToTypeHandleHashTable Il2CppNameToTypeHandleHashTable;
typedef struct Il2CppCodeGenModule Il2CppCodeGenModule;
typedef struct Il2CppMetadataRegistration Il2CppMetadataRegistration;
typedef struct Il2CppCodeRegistration Il2CppCodeRegistration;
typedef struct VirtualInvokeData
{
	Il2CppMethodPointer methodPtr;
	const MethodInfo* method;
} VirtualInvokeData;
typedef enum Il2CppTypeNameFormat
{
	IL2CPP_TYPE_NAME_FORMAT_IL,
	IL2CPP_TYPE_NAME_FORMAT_REFLECTION,
	IL2CPP_TYPE_NAME_FORMAT_FULL_NAME,
	IL2CPP_TYPE_NAME_FORMAT_ASSEMBLY_QUALIFIED
} Il2CppTypeNameFormat;
typedef struct Il2CppDefaults
{
	Il2CppImage* corlib;
	Il2CppImage* corlib_gen;
	Il2CppClass* object_class;
	Il2CppClass* byte_class;
	Il2CppClass* void_class;
	Il2CppClass* boolean_class;
	Il2CppClass* sbyte_class;
	Il2CppClass* int16_class;
	Il2CppClass* uint16_class;
	Il2CppClass* int32_class;
	Il2CppClass* uint32_class;
	Il2CppClass* int_class;
	Il2CppClass* uint_class;
	Il2CppClass* int64_class;
	Il2CppClass* uint64_class;
	Il2CppClass* single_class;
	Il2CppClass* double_class;
	Il2CppClass* char_class;
	Il2CppClass* string_class;
	Il2CppClass* enum_class;
	Il2CppClass* array_class;
	Il2CppClass* delegate_class;
	Il2CppClass* multicastdelegate_class;
	Il2CppClass* asyncresult_class;
	Il2CppClass* manualresetevent_class;
	Il2CppClass* typehandle_class;
	Il2CppClass* fieldhandle_class;
	Il2CppClass* methodhandle_class;
	Il2CppClass* systemtype_class;
	Il2CppClass* monotype_class;
	Il2CppClass* exception_class;
	Il2CppClass* threadabortexception_class;
	Il2CppClass* thread_class;
	Il2CppClass* internal_thread_class;
	Il2CppClass* appdomain_class;
	Il2CppClass* appdomain_setup_class;
	Il2CppClass* member_info_class;
	Il2CppClass* field_info_class;
	Il2CppClass* method_info_class;
	Il2CppClass* property_info_class;
	Il2CppClass* event_info_class;
	Il2CppClass* stringbuilder_class;
	Il2CppClass* stack_frame_class;
	Il2CppClass* stack_trace_class;
	Il2CppClass* marshal_class;
	Il2CppClass* typed_reference_class;
	Il2CppClass* marshalbyrefobject_class;
	Il2CppClass* generic_ilist_class;
	Il2CppClass* generic_icollection_class;
	Il2CppClass* generic_ienumerable_class;
	Il2CppClass* generic_ireadonlylist_class;
	Il2CppClass* generic_ireadonlycollection_class;
	Il2CppClass* runtimetype_class;
	Il2CppClass* generic_nullable_class;
	Il2CppClass* il2cpp_com_object_class;
	Il2CppClass* attribute_class;
	Il2CppClass* customattribute_data_class;
	Il2CppClass* customattribute_typed_argument_class;
	Il2CppClass* customattribute_named_argument_class;
	Il2CppClass* version;
	Il2CppClass* culture_info;
	Il2CppClass* async_call_class;
	Il2CppClass* assembly_class;
	Il2CppClass* assembly_name_class;
	Il2CppClass* parameter_info_class;
	Il2CppClass* module_class;
	Il2CppClass* system_exception_class;
	Il2CppClass* argument_exception_class;
	Il2CppClass* wait_handle_class;
	Il2CppClass* safe_handle_class;
	Il2CppClass* sort_key_class;
	Il2CppClass* dbnull_class;
	Il2CppClass* error_wrapper_class;
	Il2CppClass* missing_class;
	Il2CppClass* value_type_class;
	Il2CppClass* threadpool_wait_callback_class;
	MethodInfo* threadpool_perform_wait_callback_method;
	Il2CppClass* mono_method_message_class;
	Il2CppClass* ireference_class;
	Il2CppClass* ireferencearray_class;
	Il2CppClass* ikey_value_pair_class;
	Il2CppClass* key_value_pair_class;
	Il2CppClass* windows_foundation_uri_class;
	Il2CppClass* windows_foundation_iuri_runtime_class_class;
	Il2CppClass* system_uri_class;
	Il2CppClass* system_guid_class;
	Il2CppClass* sbyte_shared_enum;
	Il2CppClass* int16_shared_enum;
	Il2CppClass* int32_shared_enum;
	Il2CppClass* int64_shared_enum;
	Il2CppClass* byte_shared_enum;
	Il2CppClass* uint16_shared_enum;
	Il2CppClass* uint32_shared_enum;
	Il2CppClass* uint64_shared_enum;
	Il2CppClass* il2cpp_fully_shared_type;
	Il2CppClass* il2cpp_fully_shared_struct_type;
} Il2CppDefaults;
extern Il2CppDefaults il2cpp_defaults;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct FieldInfo FieldInfo;
typedef struct Il2CppObject Il2CppObject;
typedef struct MemberInfo MemberInfo;
typedef struct CustomAttributesCache
{
	int count;
	Il2CppObject** attributes;
} CustomAttributesCache;
typedef struct FieldInfo
{
	const char* name;
	const Il2CppType* type;
	Il2CppClass* parent;
	int32_t offset;
	uint32_t token;
} FieldInfo;
typedef struct PropertyInfo
{
	Il2CppClass* parent;
	const char* name;
	const MethodInfo* get;
	const MethodInfo* set;
	uint32_t attrs;
	uint32_t token;
} PropertyInfo;
typedef struct EventInfo
{
	const char* name;
	const Il2CppType* eventType;
	Il2CppClass* parent;
	const MethodInfo* add;
	const MethodInfo* remove;
	const MethodInfo* raise;
	uint32_t token;
} EventInfo;
typedef void (*InvokerMethod)(Il2CppMethodPointer, const MethodInfo*, void*, void**, void*);
typedef enum MethodVariableKind
{
	kMethodVariableKind_This,
	kMethodVariableKind_Parameter,
	kMethodVariableKind_LocalVariable
} MethodVariableKind;
typedef enum SequencePointKind
{
	kSequencePointKind_Normal,
	kSequencePointKind_StepOut
} SequencePointKind;
typedef struct Il2CppMethodExecutionContextInfo
{
	TypeIndex typeIndex;
	int32_t nameIndex;
	int32_t scopeIndex;
} Il2CppMethodExecutionContextInfo;
typedef struct Il2CppMethodExecutionContextInfoIndex
{
	int32_t startIndex;
	int32_t count;
} Il2CppMethodExecutionContextInfoIndex;
typedef struct Il2CppMethodScope
{
	int32_t startOffset;
	int32_t endOffset;
} Il2CppMethodScope;
typedef struct Il2CppMethodHeaderInfo
{
	int32_t code_size;
	int32_t startScope;
	int32_t numScopes;
} Il2CppMethodHeaderInfo;
typedef struct Il2CppSequencePointSourceFile
{
	const char* file;
	uint8_t hash[16];
} Il2CppSequencePointSourceFile;
typedef struct Il2CppTypeSourceFilePair
{
	TypeDefinitionIndex __klassIndex;
	int32_t sourceFileIndex;
} Il2CppTypeSourceFilePair;
typedef struct Il2CppSequencePoint
{
	MethodIndex __methodDefinitionIndex;
	int32_t sourceFileIndex;
	int32_t lineStart, lineEnd;
	int32_t columnStart, columnEnd;
	int32_t ilOffset;
	SequencePointKind kind;
	int32_t isActive;
	int32_t id;
} Il2CppSequencePoint;
typedef struct Il2CppCatchPoint
{
	MethodIndex __methodDefinitionIndex;
	TypeIndex catchTypeIndex;
	int32_t ilOffset;
	int32_t tryId;
	int32_t parentTryId;
} Il2CppCatchPoint;
typedef struct Il2CppDebuggerMetadataRegistration
{
	Il2CppMethodExecutionContextInfo* methodExecutionContextInfos;
	Il2CppMethodExecutionContextInfoIndex* methodExecutionContextInfoIndexes;
	Il2CppMethodScope* methodScopes;
	Il2CppMethodHeaderInfo* methodHeaderInfos;
	Il2CppSequencePointSourceFile* sequencePointSourceFiles;
	int32_t numSequencePoints;
	Il2CppSequencePoint* sequencePoints;
	int32_t numCatchPoints;
	Il2CppCatchPoint* catchPoints;
	int32_t numTypeSourceFileEntries;
	Il2CppTypeSourceFilePair* typeSourceFiles;
	const char** methodExecutionContextInfoStrings;
} Il2CppDebuggerMetadataRegistration;
typedef union Il2CppRGCTXData
{
	void* rgctxDataDummy;
	const MethodInfo* method;
	const Il2CppType* type;
	Il2CppClass* klass;
} Il2CppRGCTXData;
typedef struct MethodInfo
{
	Il2CppMethodPointer methodPointer;
	Il2CppMethodPointer virtualMethodPointer;
	InvokerMethod invoker_method;
	const char* name;
	Il2CppClass* klass;
	const Il2CppType* return_type;
	const Il2CppType** parameters;
	union
	{
		const Il2CppRGCTXData* rgctx_data;
		Il2CppMetadataMethodDefinitionHandle methodMetadataHandle;
	};
	union
	{
		const Il2CppGenericMethod* genericMethod;
		Il2CppMetadataGenericContainerHandle genericContainerHandle;
	};
	uint32_t token;
	uint16_t flags;
	uint16_t iflags;
	uint16_t slot;
	uint8_t parameters_count;
	uint8_t is_generic : 1;
	uint8_t is_inflated : 1;
	uint8_t wrapper_type : 1;
	uint8_t has_full_generic_sharing_signature : 1;
	uint8_t indirect_call_via_invokers : 1;
} MethodInfo;
typedef struct Il2CppRuntimeInterfaceOffsetPair
{
	Il2CppClass* interfaceType;
	int32_t offset;
} Il2CppRuntimeInterfaceOffsetPair;
typedef struct Il2CppClass
{
	const Il2CppImage* image;
	void* gc_desc;
	const char* name;
	const char* namespaze;
	Il2CppType byval_arg;
	Il2CppType this_arg;
	Il2CppClass* element_class;
	Il2CppClass* castClass;
	Il2CppClass* declaringType;
	Il2CppClass* parent;
	Il2CppGenericClass* generic_class;
	Il2CppMetadataTypeHandle typeMetadataHandle;
	const Il2CppInteropData* interopData;
	Il2CppClass* klass;
	FieldInfo* fields;
	const EventInfo* events;
	const PropertyInfo* properties;
	const MethodInfo** methods;
	Il2CppClass** nestedTypes;
	Il2CppClass** implementedInterfaces;
	Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
	void* static_fields;
	const Il2CppRGCTXData* rgctx_data;
	struct Il2CppClass** typeHierarchy;
	void* unity_user_data;
	uint32_t initializationExceptionGCHandle;
	uint32_t cctor_started;
	uint32_t cctor_finished_or_no_cctor;
	__declspec(align(8)) size_t cctor_thread;
	Il2CppMetadataGenericContainerHandle genericContainerHandle;
	uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;
	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;
	uint8_t typeHierarchyDepth;
	uint8_t genericRecursionDepth;
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t naturalAligment;
	uint8_t packingSize;
	uint8_t initialized_and_no_error : 1;
	uint8_t initialized : 1;
	uint8_t enumtype : 1;
	uint8_t nullabletype : 1;
	uint8_t is_generic : 1;
	uint8_t has_references : 1;
	uint8_t init_pending : 1;
	uint8_t size_init_pending : 1;
	uint8_t size_inited : 1;
	uint8_t has_finalize : 1;
	uint8_t has_cctor : 1;
	uint8_t is_blittable : 1;
	uint8_t is_import_or_windows_runtime : 1;
	uint8_t is_vtable_initialized : 1;
	uint8_t is_byref_like : 1;
	VirtualInvokeData vtable[32];
} Il2CppClass;

typedef struct Il2CppClass_0
{
	const Il2CppImage* image;
	void* gc_desc;
	const char* name;
	const char* namespaze;
	Il2CppType byval_arg;
	Il2CppType this_arg;
	Il2CppClass* element_class;
	Il2CppClass* castClass;
	Il2CppClass* declaringType;
	Il2CppClass* parent;
	Il2CppGenericClass* generic_class;
	Il2CppMetadataTypeHandle typeMetadataHandle;
	const Il2CppInteropData* interopData;
	Il2CppClass* klass;
	FieldInfo* fields;
	const EventInfo* events;
	const PropertyInfo* properties;
	const MethodInfo** methods;
	Il2CppClass** nestedTypes;
	Il2CppClass** implementedInterfaces;
} Il2CppClass_0;

typedef struct Il2CppClass_1
{
	struct Il2CppClass** typeHierarchy;
	void* unity_user_data;
	uint32_t initializationExceptionGCHandle;
	uint32_t cctor_started;
	uint32_t cctor_finished_or_no_cctor;
#ifdef IS_32BIT
	uint32_t cctor_thread;
#else
	__declspec(align(8)) size_t cctor_thread;
#endif
	Il2CppMetadataGenericContainerHandle genericContainerHandle;
	uint32_t instance_size;
	uint32_t actualSize;
	uint32_t element_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
	int32_t thread_static_fields_offset;
	uint32_t flags;
	uint32_t token;
	uint16_t method_count;
	uint16_t property_count;
	uint16_t field_count;
	uint16_t event_count;
	uint16_t nested_type_count;
	uint16_t vtable_count;
	uint16_t interfaces_count;
	uint16_t interface_offsets_count;
	uint8_t typeHierarchyDepth;
	uint8_t genericRecursionDepth;
	uint8_t rank;
	uint8_t minimumAlignment;
	uint8_t naturalAligment;
	uint8_t packingSize;
	uint8_t initialized_and_no_error : 1;
	uint8_t initialized : 1;
	uint8_t enumtype : 1;
	uint8_t nullabletype : 1;
	uint8_t is_generic : 1;
	uint8_t has_references : 1;
	uint8_t init_pending : 1;
	uint8_t size_init_pending : 1;
	uint8_t size_inited : 1;
	uint8_t has_finalize : 1;
	uint8_t has_cctor : 1;
	uint8_t is_blittable : 1;
	uint8_t is_import_or_windows_runtime : 1;
	uint8_t is_vtable_initialized : 1;
	uint8_t is_byref_like : 1;
} Il2CppClass_1;

typedef struct __declspec(align(8)) Il2CppClass_Merged
{
	struct Il2CppClass_0 _0;
	Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
	void* static_fields;
	const Il2CppRGCTXData* rgctx_data;
	struct Il2CppClass_1 _1;
	VirtualInvokeData vtable[32];
} Il2CppClass_Merged;

typedef struct Il2CppTypeDefinitionSizes
{
	uint32_t instance_size;
	int32_t native_size;
	uint32_t static_fields_size;
	uint32_t thread_static_fields_size;
} Il2CppTypeDefinitionSizes;
typedef struct Il2CppDomain
{
	Il2CppAppDomain* domain;
	Il2CppAppDomainSetup* setup;
	Il2CppAppContext* default_context;
	const char* friendly_name;
	uint32_t domain_id;
	volatile int threadpool_jobs;
	void* agent_info;
} Il2CppDomain;
typedef struct Il2CppAssemblyName
{
	const char* name;
	const char* culture;
	const uint8_t* public_key;
	uint32_t hash_alg;
	int32_t hash_len;
	uint32_t flags;
	int32_t major;
	int32_t minor;
	int32_t build;
	int32_t revision;
	uint8_t public_key_token[8];
} Il2CppAssemblyName;
typedef struct Il2CppImage
{
	const char* name;
	const char* nameNoExt;
	Il2CppAssembly* assembly;
	uint32_t typeCount;
	uint32_t exportedTypeCount;
	uint32_t customAttributeCount;
	Il2CppMetadataImageHandle metadataHandle;
	Il2CppNameToTypeHandleHashTable* nameToClassHashTable;
	const Il2CppCodeGenModule* codeGenModule;
	uint32_t token;
	uint8_t dynamic;
} Il2CppImage;
typedef struct Il2CppAssembly
{
	Il2CppImage* image;
	uint32_t token;
	int32_t referencedAssemblyStart;
	int32_t referencedAssemblyCount;
	Il2CppAssemblyName aname;
} Il2CppAssembly;
typedef struct Il2CppCodeGenOptions
{
	uint8_t enablePrimitiveValueTypeGenericSharing;
	int maximumRuntimeGenericDepth;
	int recursiveGenericIterations;
} Il2CppCodeGenOptions;
typedef struct Il2CppRange
{
	int32_t start;
	int32_t length;
} Il2CppRange;
typedef struct Il2CppTokenRangePair
{
	uint32_t token;
	Il2CppRange range;
} Il2CppTokenRangePair;
typedef struct Il2CppTokenIndexMethodTuple
{
	uint32_t token;
	int32_t index;
	void** method;
	uint32_t __genericMethodIndex;
} Il2CppTokenIndexMethodTuple;
typedef struct Il2CppTokenAdjustorThunkPair
{
	uint32_t token;
	Il2CppMethodPointer adjustorThunk;
} Il2CppTokenAdjustorThunkPair;
typedef struct Il2CppWindowsRuntimeFactoryTableEntry
{
	const Il2CppType* type;
	Il2CppMethodPointer createFactoryFunction;
} Il2CppWindowsRuntimeFactoryTableEntry;
typedef struct Il2CppCodeGenModule
{
	const char* moduleName;
	const uint32_t methodPointerCount;
	const Il2CppMethodPointer* methodPointers;
	const uint32_t adjustorThunkCount;
	const Il2CppTokenAdjustorThunkPair* adjustorThunks;
	const int32_t* invokerIndices;
	const uint32_t reversePInvokeWrapperCount;
	const Il2CppTokenIndexMethodTuple* reversePInvokeWrapperIndices;
	const uint32_t rgctxRangesCount;
	const Il2CppTokenRangePair* rgctxRanges;
	const uint32_t rgctxsCount;
	const Il2CppRGCTXDefinition* rgctxs;
	const Il2CppDebuggerMetadataRegistration* debuggerMetadata;
	const Il2CppMethodPointer moduleInitializer;
	TypeDefinitionIndex* staticConstructorTypeIndices;
	const Il2CppMetadataRegistration* metadataRegistration;
	const Il2CppCodeRegistration* codeRegistaration;
} Il2CppCodeGenModule;
typedef struct Il2CppCodeRegistration
{
	uint32_t reversePInvokeWrapperCount;
	const Il2CppMethodPointer* reversePInvokeWrappers;
	uint32_t genericMethodPointersCount;
	const Il2CppMethodPointer* genericMethodPointers;
	const Il2CppMethodPointer* genericAdjustorThunks;
	uint32_t invokerPointersCount;
	const InvokerMethod* invokerPointers;
	uint32_t unresolvedVirtualCallCount;
	const Il2CppMethodPointer* unresolvedVirtualCallPointers;
	uint32_t interopDataCount;
	Il2CppInteropData* interopData;
	uint32_t windowsRuntimeFactoryCount;
	Il2CppWindowsRuntimeFactoryTableEntry* windowsRuntimeFactoryTable;
	uint32_t codeGenModulesCount;
	const Il2CppCodeGenModule** codeGenModules;
} Il2CppCodeRegistration;
typedef struct Il2CppMetadataRegistration
{
	int32_t genericClassesCount;
	Il2CppGenericClass* const* genericClasses;
	int32_t genericInstsCount;
	const Il2CppGenericInst* const* genericInsts;
	int32_t genericMethodTableCount;
	const Il2CppGenericMethodFunctionsDefinitions* genericMethodTable;
	int32_t typesCount;
	const Il2CppType* const* types;
	int32_t methodSpecsCount;
	const Il2CppMethodSpec* methodSpecs;
	FieldIndex fieldOffsetsCount;
	const int32_t** fieldOffsets;
	TypeDefinitionIndex typeDefinitionsSizesCount;
	const Il2CppTypeDefinitionSizes** typeDefinitionsSizes;
	const size_t metadataUsagesCount;
	void** const* metadataUsages;
} Il2CppMetadataRegistration;
typedef struct Il2CppPerfCounters
{
	uint32_t jit_methods;
	uint32_t jit_bytes;
	uint32_t jit_time;
	uint32_t jit_failures;
	uint32_t exceptions_thrown;
	uint32_t exceptions_filters;
	uint32_t exceptions_finallys;
	uint32_t exceptions_depth;
	uint32_t aspnet_requests_queued;
	uint32_t aspnet_requests;
	uint32_t gc_collections0;
	uint32_t gc_collections1;
	uint32_t gc_collections2;
	uint32_t gc_promotions0;
	uint32_t gc_promotions1;
	uint32_t gc_promotion_finalizers;
	uint32_t gc_gen0size;
	uint32_t gc_gen1size;
	uint32_t gc_gen2size;
	uint32_t gc_lossize;
	uint32_t gc_fin_survivors;
	uint32_t gc_num_handles;
	uint32_t gc_allocated;
	uint32_t gc_induced;
	uint32_t gc_time;
	uint32_t gc_total_bytes;
	uint32_t gc_committed_bytes;
	uint32_t gc_reserved_bytes;
	uint32_t gc_num_pinned;
	uint32_t gc_sync_blocks;
	uint32_t remoting_calls;
	uint32_t remoting_channels;
	uint32_t remoting_proxies;
	uint32_t remoting_classes;
	uint32_t remoting_objects;
	uint32_t remoting_contexts;
	uint32_t loader_classes;
	uint32_t loader_total_classes;
	uint32_t loader_appdomains;
	uint32_t loader_total_appdomains;
	uint32_t loader_assemblies;
	uint32_t loader_total_assemblies;
	uint32_t loader_failures;
	uint32_t loader_bytes;
	uint32_t loader_appdomains_uloaded;
	uint32_t thread_contentions;
	uint32_t thread_queue_len;
	uint32_t thread_queue_max;
	uint32_t thread_num_logical;
	uint32_t thread_num_physical;
	uint32_t thread_cur_recognized;
	uint32_t thread_num_recognized;
	uint32_t interop_num_ccw;
	uint32_t interop_num_stubs;
	uint32_t interop_num_marshals;
	uint32_t security_num_checks;
	uint32_t security_num_link_checks;
	uint32_t security_time;
	uint32_t security_depth;
	uint32_t unused;
	uint64_t threadpool_workitems;
	uint64_t threadpool_ioworkitems;
	unsigned int threadpool_threads;
	unsigned int threadpool_iothreads;
} Il2CppPerfCounters;
typedef struct Il2CppClass Il2CppClass;
typedef struct MethodInfo MethodInfo;
typedef struct PropertyInfo PropertyInfo;
typedef struct FieldInfo FieldInfo;
typedef struct EventInfo EventInfo;
typedef struct Il2CppType Il2CppType;
typedef struct Il2CppAssembly Il2CppAssembly;
typedef struct Il2CppException Il2CppException;
typedef struct Il2CppImage Il2CppImage;
typedef struct Il2CppDomain Il2CppDomain;
typedef struct Il2CppString Il2CppString;
typedef struct Il2CppReflectionMethod Il2CppReflectionMethod;
typedef struct Il2CppAsyncCall Il2CppAsyncCall;
typedef struct Il2CppIUnknown Il2CppIUnknown;
typedef struct Il2CppWaitHandle Il2CppWaitHandle;
typedef struct MonitorData MonitorData;
typedef struct Il2CppReflectionAssembly Il2CppReflectionAssembly;
typedef Il2CppClass Il2CppVTable;
typedef struct Il2CppObject
{
	union
	{
		Il2CppClass* klass;
		Il2CppVTable* vtable;
	};
	MonitorData* monitor;
} Il2CppObject;
typedef int32_t il2cpp_array_lower_bound_t;
typedef struct Il2CppArrayBounds
{
	il2cpp_array_size_t length;
	il2cpp_array_lower_bound_t lower_bound;
} Il2CppArrayBounds;
typedef struct Il2CppArray
{
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
} Il2CppArray;
typedef struct Il2CppArraySize
{
	Il2CppObject obj;
	Il2CppArrayBounds* bounds;
	il2cpp_array_size_t max_length;
	__declspec(align(8)) void* vector[32];
} Il2CppArraySize;
typedef struct Il2CppString
{
	Il2CppObject object;
	int32_t length;
	Il2CppChar chars[32];
} Il2CppString;
typedef struct Il2CppReflectionType
{
	Il2CppObject object;
	const Il2CppType* type;
} Il2CppReflectionType;
typedef struct Il2CppReflectionRuntimeType
{
	Il2CppReflectionType type;
	Il2CppObject* type_info;
	Il2CppObject* genericCache;
	Il2CppObject* serializationCtor;
} Il2CppReflectionRuntimeType;
typedef struct Il2CppReflectionMonoType
{
	Il2CppReflectionRuntimeType type;
} Il2CppReflectionMonoType;
typedef struct Il2CppReflectionEvent
{
	Il2CppObject object;
	Il2CppObject* cached_add_event;
} Il2CppReflectionEvent;
typedef struct Il2CppReflectionMonoEvent
{
	Il2CppReflectionEvent event;
	Il2CppReflectionType* reflectedType;
	const EventInfo* eventInfo;
} Il2CppReflectionMonoEvent;
typedef struct Il2CppReflectionMonoEventInfo
{
	Il2CppReflectionType* declaringType;
	Il2CppReflectionType* reflectedType;
	Il2CppString* name;
	Il2CppReflectionMethod* addMethod;
	Il2CppReflectionMethod* removeMethod;
	Il2CppReflectionMethod* raiseMethod;
	uint32_t eventAttributes;
	Il2CppArray* otherMethods;
} Il2CppReflectionMonoEventInfo;
typedef struct Il2CppReflectionField
{
	Il2CppObject object;
	Il2CppClass* klass;
	FieldInfo* field;
	Il2CppString* name;
	Il2CppReflectionType* type;
	uint32_t attrs;
} Il2CppReflectionField;
typedef struct Il2CppReflectionProperty
{
	Il2CppObject object;
	Il2CppClass* klass;
	const PropertyInfo* property;
} Il2CppReflectionProperty;
typedef struct Il2CppReflectionMethod
{
	Il2CppObject object;
	const MethodInfo* method;
	Il2CppString* name;
	Il2CppReflectionType* reftype;
} Il2CppReflectionMethod;
typedef struct Il2CppReflectionGenericMethod
{
	Il2CppReflectionMethod base;
} Il2CppReflectionGenericMethod;
typedef struct Il2CppMethodInfo
{
	Il2CppReflectionType* parent;
	Il2CppReflectionType* ret;
	uint32_t attrs;
	uint32_t implattrs;
	uint32_t callconv;
} Il2CppMethodInfo;
typedef struct Il2CppPropertyInfo
{
	Il2CppReflectionType* parent;
	Il2CppReflectionType* declaringType;
	Il2CppString* name;
	Il2CppReflectionMethod* get;
	Il2CppReflectionMethod* set;
	uint32_t attrs;
} Il2CppPropertyInfo;
typedef struct Il2CppReflectionParameter
{
	Il2CppObject object;
	uint32_t AttrsImpl;
	Il2CppReflectionType* ClassImpl;
	Il2CppObject* DefaultValueImpl;
	Il2CppObject* MemberImpl;
	Il2CppString* NameImpl;
	int32_t PositionImpl;
	Il2CppObject* MarshalAs;
} Il2CppReflectionParameter;
typedef struct Il2CppReflectionModule
{
	Il2CppObject obj;
	const Il2CppImage* image;
	Il2CppReflectionAssembly* assembly;
	Il2CppString* fqname;
	Il2CppString* name;
	Il2CppString* scopename;
	uint8_t is_resource;
	uint32_t token;
} Il2CppReflectionModule;
typedef struct Il2CppReflectionAssemblyName
{
	Il2CppObject obj;
	Il2CppString* name;
	Il2CppString* codebase;
	int32_t major, minor, build, revision;
	Il2CppObject* cultureInfo;
	uint32_t flags;
	uint32_t hashalg;
	Il2CppObject* keypair;
	Il2CppArray* publicKey;
	Il2CppArray* keyToken;
	uint32_t versioncompat;
	Il2CppObject* version;
	uint32_t processor_architecture;
	uint32_t contentType;
} Il2CppReflectionAssemblyName;
typedef struct Il2CppReflectionAssembly
{
	Il2CppObject object;
	const Il2CppAssembly* assembly;
	Il2CppObject* evidence;
	Il2CppObject* resolve_event_holder;
	Il2CppObject* minimum;
	Il2CppObject* optional;
	Il2CppObject* refuse;
	Il2CppObject* granted;
	Il2CppObject* denied;
	uint8_t from_byte_array;
	Il2CppString* name;
} Il2CppReflectionAssembly;
typedef struct Il2CppReflectionMarshal
{
	Il2CppObject object;
	int32_t count;
	int32_t type;
	int32_t eltype;
	Il2CppString* guid;
	Il2CppString* mcookie;
	Il2CppString* marshaltype;
	Il2CppObject* marshaltyperef;
	int32_t param_num;
	uint8_t has_size;
} Il2CppReflectionMarshal;
typedef struct Il2CppReflectionPointer
{
	Il2CppObject object;
	void* data;
	Il2CppReflectionType* type;
} Il2CppReflectionPointer;
typedef struct Il2CppThreadName
{
	Il2CppChar* chars;
	int32_t unused;
	int32_t length;
} Il2CppThreadName;
typedef struct
{
	uint32_t ref;
	void (*destructor)(void* data);
} Il2CppRefCount;
typedef struct
{
	Il2CppRefCount ref;
	void* synch_cs;
} Il2CppLongLivedThreadData;
typedef struct Il2CppInternalThread
{
	Il2CppObject obj;
	int lock_thread_id;
	void* handle;
	void* native_handle;
	Il2CppThreadName name;
	uint32_t state;
	Il2CppObject* abort_exc;
	int abort_state_handle;
	uint64_t tid;
	intptr_t debugger_thread;
	void** static_data;
	void* runtime_thread_info;
	Il2CppObject* current_appcontext;
	Il2CppObject* root_domain_thread;
	Il2CppArray* _serialized_principal;
	int _serialized_principal_version;
	void* appdomain_refs;
	int32_t interruption_requested;
	void* longlived;
	uint8_t threadpool_thread;
	uint8_t thread_interrupt_requested;
	int stack_size;
	uint8_t apartment_state;
	int critical_region_level;
	int managed_id;
	uint32_t small_id;
	void* manage_callback;
	intptr_t flags;
	void* thread_pinning_ref;
	void* abort_protected_block_count;
	int32_t priority;
	void* owned_mutexes;
	void* suspended;
	int32_t self_suspended;
	size_t thread_state;
	void* unused[3];
	void* last;
} Il2CppInternalThread;
typedef struct Il2CppIOSelectorJob
{
	Il2CppObject object;
	int32_t operation;
	Il2CppObject* callback;
	Il2CppObject* state;
} Il2CppIOSelectorJob;
typedef enum
{
	Il2Cpp_CallType_Sync = 0,
	Il2Cpp_CallType_BeginInvoke = 1,
	Il2Cpp_CallType_EndInvoke = 2,
	Il2Cpp_CallType_OneWay = 3
} Il2CppCallType;
typedef struct Il2CppMethodMessage
{
	Il2CppObject obj;
	Il2CppReflectionMethod* method;
	Il2CppArray* args;
	Il2CppArray* names;
	Il2CppArray* arg_types;
	Il2CppObject* ctx;
	Il2CppObject* rval;
	Il2CppObject* exc;
	Il2CppAsyncResult* async_result;
	uint32_t call_type;
} Il2CppMethodMessage;
typedef struct Il2CppAppDomainSetup
{
	Il2CppObject object;
	Il2CppString* application_base;
	Il2CppString* application_name;
	Il2CppString* cache_path;
	Il2CppString* configuration_file;
	Il2CppString* dynamic_base;
	Il2CppString* license_file;
	Il2CppString* private_bin_path;
	Il2CppString* private_bin_path_probe;
	Il2CppString* shadow_copy_directories;
	Il2CppString* shadow_copy_files;
	uint8_t publisher_policy;
	uint8_t path_changed;
	int loader_optimization;
	uint8_t disallow_binding_redirects;
	uint8_t disallow_code_downloads;
	Il2CppObject* activation_arguments;
	Il2CppObject* domain_initializer;
	Il2CppObject* application_trust;
	Il2CppArray* domain_initializer_args;
	uint8_t disallow_appbase_probe;
	Il2CppArray* configuration_bytes;
	Il2CppArray* serialized_non_primitives;
} Il2CppAppDomainSetup;
typedef struct Il2CppThread
{
	Il2CppObject obj;
	Il2CppInternalThread* internal_thread;
	Il2CppObject* start_obj;
	Il2CppException* pending_exception;
	Il2CppObject* principal;
	int32_t principal_version;
	Il2CppDelegate* delegate;
	Il2CppObject* executionContext;
	uint8_t executionContextBelongsToOuterScope;
} Il2CppThread;
typedef struct Il2CppException
{
	Il2CppObject object;
	Il2CppString* className;
	Il2CppString* message;
	Il2CppObject* _data;
	struct Il2CppException* inner_ex;
	Il2CppString* _helpURL;
	Il2CppArray* trace_ips;
	Il2CppString* stack_trace;
	Il2CppString* remote_stack_trace;
	int remote_stack_index;
	Il2CppObject* _dynamicMethods;
	il2cpp_hresult_t hresult;
	Il2CppString* source;
	Il2CppObject* safeSerializationManager;
	Il2CppArray* captured_traces;
	Il2CppArray* native_trace_ips;
	int32_t caught_in_unmanaged;
} Il2CppException;
typedef struct Il2CppSystemException
{
	Il2CppException base;
} Il2CppSystemException;
typedef struct Il2CppArgumentException
{
	Il2CppException base;
	Il2CppString* argName;
} Il2CppArgumentException;
typedef struct Il2CppTypedRef
{
	const Il2CppType* type;
	void* value;
	Il2CppClass* klass;
} Il2CppTypedRef;
typedef struct Il2CppDelegate
{
	Il2CppObject object;
	Il2CppMethodPointer method_ptr;
	Il2CppMethodPointer invoke_impl;
	Il2CppObject* target;
	const MethodInfo* method;
	void* delegate_trampoline;
	intptr_t extraArg;
	uint8_t** method_code;
	void* interp_method;
	void* interp_invoke_impl;
	Il2CppReflectionMethod* method_info;
	Il2CppReflectionMethod* original_method_info;
	Il2CppObject* data;
	uint8_t method_is_virtual;
} Il2CppDelegate;
typedef struct Il2CppMulticastDelegate
{
	Il2CppDelegate delegate;
	Il2CppArray* delegates;
} Il2CppMulticastDelegate;
typedef struct Il2CppMarshalByRefObject
{
	Il2CppObject obj;
	Il2CppObject* identity;
} Il2CppMarshalByRefObject;
typedef void* Il2CppFullySharedGenericAny;
typedef void* Il2CppFullySharedGenericStruct;
typedef struct Il2CppAppDomain
{
	Il2CppMarshalByRefObject mbr;
	Il2CppDomain* data;
} Il2CppAppDomain;
typedef struct Il2CppStackFrame
{
	Il2CppObject obj;
	int32_t il_offset;
	int32_t native_offset;
	uint64_t methodAddress;
	uint32_t methodIndex;
	Il2CppReflectionMethod* method;
	Il2CppString* filename;
	int32_t line;
	int32_t column;
	Il2CppString* internal_method_name;
} Il2CppStackFrame;
typedef struct Il2CppDateTimeFormatInfo
{
	Il2CppObject obj;
	Il2CppObject* CultureData;
	Il2CppString* Name;
	Il2CppString* LangName;
	Il2CppObject* CompareInfo;
	Il2CppObject* CultureInfo;
	Il2CppString* AMDesignator;
	Il2CppString* PMDesignator;
	Il2CppString* DateSeparator;
	Il2CppString* GeneralShortTimePattern;
	Il2CppString* GeneralLongTimePattern;
	Il2CppString* TimeSeparator;
	Il2CppString* MonthDayPattern;
	Il2CppString* DateTimeOffsetPattern;
	Il2CppObject* Calendar;
	uint32_t FirstDayOfWeek;
	uint32_t CalendarWeekRule;
	Il2CppString* FullDateTimePattern;
	Il2CppArray* AbbreviatedDayNames;
	Il2CppArray* ShortDayNames;
	Il2CppArray* DayNames;
	Il2CppArray* AbbreviatedMonthNames;
	Il2CppArray* MonthNames;
	Il2CppArray* GenitiveMonthNames;
	Il2CppArray* GenitiveAbbreviatedMonthNames;
	Il2CppArray* LeapYearMonthNames;
	Il2CppString* LongDatePattern;
	Il2CppString* ShortDatePattern;
	Il2CppString* YearMonthPattern;
	Il2CppString* LongTimePattern;
	Il2CppString* ShortTimePattern;
	Il2CppArray* YearMonthPatterns;
	Il2CppArray* ShortDatePatterns;
	Il2CppArray* LongDatePatterns;
	Il2CppArray* ShortTimePatterns;
	Il2CppArray* LongTimePatterns;
	Il2CppArray* EraNames;
	Il2CppArray* AbbrevEraNames;
	Il2CppArray* AbbrevEnglishEraNames;
	Il2CppArray* OptionalCalendars;
	uint8_t readOnly;
	int32_t FormatFlags;
	int32_t CultureID;
	uint8_t UseUserOverride;
	uint8_t UseCalendarInfo;
	int32_t DataItem;
	uint8_t IsDefaultCalendar;
	Il2CppArray* DateWords;
	Il2CppString* FullTimeSpanPositivePattern;
	Il2CppString* FullTimeSpanNegativePattern;
	Il2CppArray* dtfiTokenHash;
} Il2CppDateTimeFormatInfo;
typedef struct Il2CppNumberFormatInfo
{
	Il2CppObject obj;
	Il2CppArray* numberGroupSizes;
	Il2CppArray* currencyGroupSizes;
	Il2CppArray* percentGroupSizes;
	Il2CppString* positiveSign;
	Il2CppString* negativeSign;
	Il2CppString* numberDecimalSeparator;
	Il2CppString* numberGroupSeparator;
	Il2CppString* currencyGroupSeparator;
	Il2CppString* currencyDecimalSeparator;
	Il2CppString* currencySymbol;
	Il2CppString* ansiCurrencySymbol;
	Il2CppString* naNSymbol;
	Il2CppString* positiveInfinitySymbol;
	Il2CppString* negativeInfinitySymbol;
	Il2CppString* percentDecimalSeparator;
	Il2CppString* percentGroupSeparator;
	Il2CppString* percentSymbol;
	Il2CppString* perMilleSymbol;
	Il2CppArray* nativeDigits;
	int dataItem;
	int numberDecimalDigits;
	int currencyDecimalDigits;
	int currencyPositivePattern;
	int currencyNegativePattern;
	int numberNegativePattern;
	int percentPositivePattern;
	int percentNegativePattern;
	int percentDecimalDigits;
	int digitSubstitution;
	uint8_t readOnly;
	uint8_t useUserOverride;
	uint8_t isInvariant;
	uint8_t validForParseAsNumber;
	uint8_t validForParseAsCurrency;
} Il2CppNumberFormatInfo;
typedef struct NumberFormatEntryManaged
{
	int32_t currency_decimal_digits;
	int32_t currency_decimal_separator;
	int32_t currency_group_separator;
	int32_t currency_group_sizes0;
	int32_t currency_group_sizes1;
	int32_t currency_negative_pattern;
	int32_t currency_positive_pattern;
	int32_t currency_symbol;
	int32_t nan_symbol;
	int32_t negative_infinity_symbol;
	int32_t negative_sign;
	int32_t number_decimal_digits;
	int32_t number_decimal_separator;
	int32_t number_group_separator;
	int32_t number_group_sizes0;
	int32_t number_group_sizes1;
	int32_t number_negative_pattern;
	int32_t per_mille_symbol;
	int32_t percent_negative_pattern;
	int32_t percent_positive_pattern;
	int32_t percent_symbol;
	int32_t positive_infinity_symbol;
	int32_t positive_sign;
} NumberFormatEntryManaged;
typedef struct Il2CppCultureData
{
	Il2CppObject obj;
	Il2CppString* AMDesignator;
	Il2CppString* PMDesignator;
	Il2CppString* TimeSeparator;
	Il2CppArray* LongTimePatterns;
	Il2CppArray* ShortTimePatterns;
	uint32_t FirstDayOfWeek;
	uint32_t CalendarWeekRule;
} Il2CppCultureData;
typedef struct Il2CppCalendarData
{
	Il2CppObject obj;
	Il2CppString* NativeName;
	Il2CppArray* ShortDatePatterns;
	Il2CppArray* YearMonthPatterns;
	Il2CppArray* LongDatePatterns;
	Il2CppString* MonthDayPattern;
	Il2CppArray* EraNames;
	Il2CppArray* AbbreviatedEraNames;
	Il2CppArray* AbbreviatedEnglishEraNames;
	Il2CppArray* DayNames;
	Il2CppArray* AbbreviatedDayNames;
	Il2CppArray* SuperShortDayNames;
	Il2CppArray* MonthNames;
	Il2CppArray* AbbreviatedMonthNames;
	Il2CppArray* GenitiveMonthNames;
	Il2CppArray* GenitiveAbbreviatedMonthNames;
} Il2CppCalendarData;
typedef struct Il2CppCultureInfo
{
	Il2CppObject obj;
	uint8_t is_read_only;
	int32_t lcid;
	int32_t parent_lcid;
	int32_t datetime_index;
	int32_t number_index;
	int32_t default_calendar_type;
	uint8_t use_user_override;
	Il2CppNumberFormatInfo* number_format;
	Il2CppDateTimeFormatInfo* datetime_format;
	Il2CppObject* textinfo;
	Il2CppString* name;
	Il2CppString* englishname;
	Il2CppString* nativename;
	Il2CppString* iso3lang;
	Il2CppString* iso2lang;
	Il2CppString* win3lang;
	Il2CppString* territory;
	Il2CppArray* native_calendar_names;
	Il2CppString* compareinfo;
	const void* text_info_data;
	int dataItem;
	Il2CppObject* calendar;
	Il2CppObject* parent_culture;
	uint8_t constructed;
	Il2CppArray* cached_serialized_form;
	Il2CppObject* cultureData;
	uint8_t isInherited;
} Il2CppCultureInfo;
typedef struct Il2CppRegionInfo
{
	Il2CppObject obj;
	int32_t geo_id;
	Il2CppString* iso2name;
	Il2CppString* iso3name;
	Il2CppString* win3name;
	Il2CppString* english_name;
	Il2CppString* native_name;
	Il2CppString* currency_symbol;
	Il2CppString* iso_currency_symbol;
	Il2CppString* currency_english_name;
	Il2CppString* currency_native_name;
} Il2CppRegionInfo;
typedef struct Il2CppSafeHandle
{
	Il2CppObject base;
	void* handle;
	int state;
	uint8_t owns_handle;
	uint8_t fullyInitialized;
} Il2CppSafeHandle;
typedef struct Il2CppStringBuilder Il2CppStringBuilder;
typedef struct Il2CppStringBuilder
{
	Il2CppObject object;
	Il2CppArray* chunkChars;
	struct Il2CppStringBuilder* chunkPrevious;
	int chunkLength;
	int chunkOffset;
	int maxCapacity;
} Il2CppStringBuilder;
typedef struct Il2CppSocketAddress
{
	Il2CppObject base;
	int m_Size;
	Il2CppArray* data;
	uint8_t m_changed;
	int m_hash;
} Il2CppSocketAddress;
typedef struct Il2CppSortKey
{
	Il2CppObject base;
	Il2CppString* str;
	Il2CppArray* key;
	int32_t options;
	int32_t lcid;
} Il2CppSortKey;
typedef struct Il2CppErrorWrapper
{
	Il2CppObject base;
	int32_t errorCode;
} Il2CppErrorWrapper;
typedef struct Il2CppAsyncResult
{
	Il2CppObject base;
	Il2CppObject* async_state;
	Il2CppWaitHandle* handle;
	Il2CppDelegate* async_delegate;
	void* data;
	Il2CppAsyncCall* object_data;
	uint8_t sync_completed;
	uint8_t completed;
	uint8_t endinvoke_called;
	Il2CppObject* async_callback;
	Il2CppObject* execution_context;
	Il2CppObject* original_context;
} Il2CppAsyncResult;
typedef struct Il2CppAsyncCall
{
	Il2CppObject base;
	Il2CppMethodMessage* msg;
	MethodInfo* cb_method;
	Il2CppDelegate* cb_target;
	Il2CppObject* state;
	Il2CppObject* res;
	Il2CppArray* out_args;
} Il2CppAsyncCall;
typedef struct Il2CppExceptionWrapper Il2CppExceptionWrapper;
typedef struct Il2CppExceptionWrapper
{
	Il2CppException* ex;
} Il2CppExceptionWrapper;
typedef struct Il2CppIOAsyncResult
{
	Il2CppObject base;
	Il2CppDelegate* callback;
	Il2CppObject* state;
	Il2CppWaitHandle* wait_handle;
	uint8_t completed_synchronously;
	uint8_t completed;
} Il2CppIOAsyncResult;
typedef struct Il2CppSocketAsyncResult
{
	Il2CppIOAsyncResult base;
	Il2CppObject* socket;
	int32_t operation;
	Il2CppException* delayedException;
	Il2CppObject* endPoint;
	Il2CppArray* buffer;
	int32_t offset;
	int32_t size;
	int32_t socket_flags;
	Il2CppObject* acceptSocket;
	Il2CppArray* addresses;
	int32_t port;
	Il2CppObject* buffers;
	uint8_t reuseSocket;
	int32_t currentAddress;
	Il2CppObject* acceptedSocket;
	int32_t total;
	int32_t error;
	int32_t endCalled;
} Il2CppSocketAsyncResult;
typedef enum Il2CppResourceLocation
{
	IL2CPP_RESOURCE_LOCATION_EMBEDDED = 1,
	IL2CPP_RESOURCE_LOCATION_ANOTHER_ASSEMBLY = 2,
	IL2CPP_RESOURCE_LOCATION_IN_MANIFEST = 4
} Il2CppResourceLocation;
typedef struct Il2CppManifestResourceInfo
{
	Il2CppObject object;
	Il2CppReflectionAssembly* assembly;
	Il2CppString* filename;
	uint32_t location;
} Il2CppManifestResourceInfo;
typedef struct Il2CppAppContext
{
	Il2CppObject obj;
	int32_t domain_id;
	int32_t context_id;
	void* static_data;
} Il2CppAppContext;
typedef struct Il2CppDecimal
{
	uint16_t reserved;
	union
	{
		struct
		{
			uint8_t scale;
			uint8_t sign;
		} u;
		uint16_t signscale;
	} u;
	uint32_t Hi32;
	union
	{
		struct
		{
			uint32_t Lo32;
			uint32_t Mid32;
		} v;
		uint64_t Lo64;
	} v;
} Il2CppDecimal;
typedef struct Il2CppDouble
{
	uint32_t mantLo : 32;
	uint32_t mantHi : 20;
	uint32_t exp : 11;
	uint32_t sign : 1;
} Il2CppDouble;
typedef union Il2CppDouble_double
{
	Il2CppDouble s;
	double d;
} Il2CppDouble_double;
typedef enum Il2CppDecimalCompareResult
{
	IL2CPP_DECIMAL_CMP_LT = -1,
	IL2CPP_DECIMAL_CMP_EQ,
	IL2CPP_DECIMAL_CMP_GT
} Il2CppDecimalCompareResult;
typedef struct Il2CppSingle
{
	uint32_t mant : 23;
	uint32_t exp : 8;
	uint32_t sign : 1;
} Il2CppSingle;
typedef union Il2CppSingle_float
{
	Il2CppSingle s;
	float f;
} Il2CppSingle_float;
typedef struct Il2CppByReference
{
	intptr_t value;
} Il2CppByReference;

#pragma endregion

#pragma warning(disable : 4369)
#pragma warning(disable : 4309)
#pragma warning(disable : 4359)
#if !defined(_GHIDRA_) && !defined(_IDA_)
namespace app
{
#endif

	// ******************************************************************************
	// * Application types from method calls
	// ******************************************************************************

	struct Object__VTable
	{
		VirtualInvokeData Equals;
		VirtualInvokeData Finalize;
		VirtualInvokeData GetHashCode;
		VirtualInvokeData ToString;
	};

	struct Object__StaticFields
	{
	};

	struct Object__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct Object__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct Object__VTable vtable;
	};

	struct Type__VTable
	{
		VirtualInvokeData Equals;
		VirtualInvokeData Finalize;
		VirtualInvokeData GetHashCode;
		VirtualInvokeData ToString;
		VirtualInvokeData GetCustomAttributes;
		VirtualInvokeData GetCustomAttributes_1;
		VirtualInvokeData IsDefined;
		VirtualInvokeData get_MemberType;
		VirtualInvokeData __unknown;
		VirtualInvokeData get_DeclaringType;
		VirtualInvokeData get_ReflectedType;
		VirtualInvokeData get_Module;
		VirtualInvokeData __unknown_1;
		VirtualInvokeData __unknown_2;
		VirtualInvokeData __unknown_3;
		VirtualInvokeData get_MetadataToken;
		VirtualInvokeData IsEnumDefined;
		VirtualInvokeData GetEnumName;
		VirtualInvokeData GetEnumNames;
		VirtualInvokeData get_IsSerializable;
		VirtualInvokeData get_ContainsGenericParameters;
		VirtualInvokeData FindInterfaces;
		VirtualInvokeData IsSubclassOf;
		VirtualInvokeData IsAssignableFrom;
		VirtualInvokeData GetType;
		VirtualInvokeData __unknown_4;
		VirtualInvokeData __unknown_5;
		VirtualInvokeData __unknown_6;
		VirtualInvokeData __unknown_7;
		VirtualInvokeData __unknown_8;
		VirtualInvokeData get_DeclaringMethod;
		VirtualInvokeData __unknown_9;
		VirtualInvokeData get_IsArray;
		VirtualInvokeData __unknown_10;
		VirtualInvokeData get_IsByRef;
		VirtualInvokeData __unknown_11;
		VirtualInvokeData get_IsPointer;
		VirtualInvokeData __unknown_12;
		VirtualInvokeData get_IsConstructedGenericType;
		VirtualInvokeData get_IsGenericParameter;
		VirtualInvokeData get_IsGenericMethodParameter;
		VirtualInvokeData get_IsGenericType;
		VirtualInvokeData get_IsGenericTypeDefinition;
		VirtualInvokeData get_IsSZArray;
		VirtualInvokeData get_IsVariableBoundArray;
		VirtualInvokeData get_HasElementType;
		VirtualInvokeData __unknown_13;
		VirtualInvokeData __unknown_14;
		VirtualInvokeData GetArrayRank;
		VirtualInvokeData GetGenericTypeDefinition;
		VirtualInvokeData get_GenericTypeArguments;
		VirtualInvokeData GetGenericArguments;
		VirtualInvokeData get_GenericParameterPosition;
		VirtualInvokeData get_GenericParameterAttributes;
		VirtualInvokeData GetGenericParameterConstraints;
		VirtualInvokeData get_Attributes;
		VirtualInvokeData __unknown_15;
		VirtualInvokeData get_IsAbstract;
		VirtualInvokeData get_IsSealed;
		VirtualInvokeData get_IsSpecialName;
		VirtualInvokeData get_IsClass;
		VirtualInvokeData get_IsNestedAssembly;
		VirtualInvokeData get_IsNestedPublic;
		VirtualInvokeData get_IsNotPublic;
		VirtualInvokeData get_IsPublic;
		VirtualInvokeData get_IsExplicitLayout;
		VirtualInvokeData get_IsCOMObject;
		VirtualInvokeData __unknown_16;
		VirtualInvokeData get_IsContextful;
		VirtualInvokeData IsContextfulImpl;
		VirtualInvokeData get_IsCollectible;
		VirtualInvokeData get_IsEnum;
		VirtualInvokeData get_IsMarshalByRef;
		VirtualInvokeData IsMarshalByRefImpl;
		VirtualInvokeData get_IsPrimitive;
		VirtualInvokeData __unknown_17;
		VirtualInvokeData get_IsValueType;
		VirtualInvokeData IsValueTypeImpl;
		VirtualInvokeData get_IsSignatureType;
		VirtualInvokeData GetConstructor;
		VirtualInvokeData GetConstructor_1;
		VirtualInvokeData GetConstructor_2;
		VirtualInvokeData __unknown_18;
		VirtualInvokeData GetConstructors;
		VirtualInvokeData __unknown_19;
		VirtualInvokeData GetEvent;
		VirtualInvokeData __unknown_20;
		VirtualInvokeData __unknown_21;
		VirtualInvokeData GetField;
		VirtualInvokeData __unknown_22;
		VirtualInvokeData GetFields;
		VirtualInvokeData __unknown_23;
		VirtualInvokeData GetMember;
		VirtualInvokeData GetMember_1;
		VirtualInvokeData GetMember_2;
		VirtualInvokeData __unknown_24;
		VirtualInvokeData GetMethod;
		VirtualInvokeData GetMethod_1;
		VirtualInvokeData GetMethod_2;
		VirtualInvokeData GetMethod_3;
		VirtualInvokeData GetMethod_4;
		VirtualInvokeData GetMethod_5;
		VirtualInvokeData __unknown_25;
		VirtualInvokeData GetMethods;
		VirtualInvokeData __unknown_26;
		VirtualInvokeData __unknown_27;
		VirtualInvokeData GetProperty;
		VirtualInvokeData GetProperty_1;
		VirtualInvokeData GetProperty_2;
		VirtualInvokeData GetProperty_3;
		VirtualInvokeData GetProperty_4;
		VirtualInvokeData GetProperty_5;
		VirtualInvokeData __unknown_28;
		VirtualInvokeData GetProperties;
		VirtualInvokeData __unknown_29;
		VirtualInvokeData get_TypeHandle;
		VirtualInvokeData GetTypeCodeImpl;
		VirtualInvokeData __unknown_30;
		VirtualInvokeData __unknown_31;
		VirtualInvokeData InvokeMember;
		VirtualInvokeData __unknown_32;
		VirtualInvokeData GetInterface;
		VirtualInvokeData __unknown_33;
		VirtualInvokeData __unknown_34;
		VirtualInvokeData IsInstanceOfType;
		VirtualInvokeData IsEquivalentTo;
		VirtualInvokeData GetEnumUnderlyingType;
		VirtualInvokeData GetEnumValues;
		VirtualInvokeData MakeArrayType;
		VirtualInvokeData MakeArrayType_1;
		VirtualInvokeData MakeByRefType;
		VirtualInvokeData MakeGenericType;
		VirtualInvokeData MakePointerType;
		VirtualInvokeData Equals_1;
		VirtualInvokeData get_IsSzArray;
		VirtualInvokeData FormatTypeName;
		VirtualInvokeData get_IsInterface;
		VirtualInvokeData InternalGetNameIfAvailable;
	};

	struct Type__StaticFields
	{
		struct Binder* s_defaultBinder;
		uint16_t Delimiter;
		struct Type__Array* EmptyTypes;
		struct Object* Missing;
		struct MemberFilter* FilterAttribute;
		struct MemberFilter* FilterName;
		struct MemberFilter* FilterNameIgnoreCase;
	};

	struct Type__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct Type__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct Type__VTable vtable;
	};

	struct Object
	{
		struct Object__Class* klass;
		MonitorData* monitor;
	};

	struct RuntimeTypeHandle__VTable
	{
		VirtualInvokeData Equals;
		VirtualInvokeData Finalize;
		VirtualInvokeData GetHashCode;
		VirtualInvokeData ToString;
		VirtualInvokeData GetObjectData;
	};

	struct RuntimeTypeHandle__StaticFields
	{
	};

	struct RuntimeTypeHandle__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct RuntimeTypeHandle__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct RuntimeTypeHandle__VTable vtable;
	};

	struct Char__Array__VTable
	{
	};

	struct Char__Array__StaticFields
	{
	};

	struct Char__Array__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct Char__Array__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct Char__Array__VTable vtable;
	};

	struct __declspec(align(8)) Encoding__Fields
	{
		int32_t codePage;
		int32_t windows_code_page;
		bool is_readonly;
		struct DecoderFallback* decoder_fallback;
		struct EncoderFallback* encoder_fallback;
		struct String* body_name;
		struct String* encoding_name;
		struct String* header_name;
		bool is_mail_news_display;
		bool is_mail_news_save;
		bool is_browser_save;
		bool is_browser_display;
		struct String* web_name;
	};

	struct Encoding__VTable
	{
		VirtualInvokeData Equals;
		VirtualInvokeData Finalize;
		VirtualInvokeData GetHashCode;
		VirtualInvokeData ToString;
		VirtualInvokeData Clone;
		VirtualInvokeData __unknown;
		VirtualInvokeData GetByteCount;
		VirtualInvokeData GetByteCount_1;
		VirtualInvokeData __unknown_1;
		VirtualInvokeData GetBytes;
		VirtualInvokeData GetBytes_1;
		VirtualInvokeData GetBytes_2;
		VirtualInvokeData GetBytes_3;
		VirtualInvokeData __unknown_2;
		VirtualInvokeData __unknown_3;
		VirtualInvokeData GetChars;
		VirtualInvokeData GetChars_1;
		VirtualInvokeData GetDecoder;
		VirtualInvokeData Clone_1;
		VirtualInvokeData __unknown_4;
		VirtualInvokeData __unknown_5;
		VirtualInvokeData GetPreamble;
		VirtualInvokeData GetString;
		VirtualInvokeData GetString_1;
		VirtualInvokeData get_HeaderName;
		VirtualInvokeData get_WebName;
		VirtualInvokeData GetByteCount_2;
		VirtualInvokeData GetBytes_4;
	};

	struct Encoding__StaticFields
	{
		struct Assembly* i18nAssembly;
		bool i18nDisabled;
		struct EncodingInfo__Array* encoding_infos;
		struct Object__Array* encodings;
		struct Encoding* asciiEncoding;
		struct Encoding* bigEndianEncoding;
		struct Encoding* defaultEncoding;
		struct Encoding* utf7Encoding;
		struct Encoding* utf8EncodingWithMarkers;
		struct Encoding* utf8EncodingWithoutMarkers;
		struct Encoding* unicodeEncoding;
		struct Encoding* isoLatin1Encoding;
		struct Encoding* utf8EncodingUnsafe;
		struct Encoding* utf32Encoding;
		struct Encoding* bigEndianUTF32Encoding;
		struct Object* lockobj;
	};

	struct Encoding
	{
		struct Encoding__Class* klass;
		MonitorData* monitor;
		struct Encoding__Fields fields;
	};

	struct Encoding__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct Encoding__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct Encoding__VTable vtable;
	};

	struct Char__Array
	{
		struct Char__Array__Class* klass;
		MonitorData* monitor;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		uint16_t vector[32];
	};

	struct RuntimeTypeHandle
	{
		void* value;
	};

	struct RuntimeTypeHandle__Boxed
	{
		struct RuntimeTypeHandle__Class* klass;
		MonitorData* monitor;
		struct RuntimeTypeHandle fields;
	};



	struct __declspec(align(8)) Type__Fields
	{
		struct RuntimeTypeHandle _impl;
	};

	struct Type
	{
		struct Type__Class* klass;
		MonitorData* monitor;
		struct Type__Fields fields;
	};

	struct String__VTable
	{
		VirtualInvokeData Equals;
		VirtualInvokeData Finalize;
		VirtualInvokeData GetHashCode;
		VirtualInvokeData ToString;
		VirtualInvokeData GetTypeCode;
		VirtualInvokeData System_IConvertible_ToBoolean;
		VirtualInvokeData System_IConvertible_ToByte;
		VirtualInvokeData System_IConvertible_ToChar;
		VirtualInvokeData System_IConvertible_ToDateTime;
		VirtualInvokeData System_IConvertible_ToDecimal;
		VirtualInvokeData System_IConvertible_ToDouble;
		VirtualInvokeData System_IConvertible_ToInt16;
		VirtualInvokeData System_IConvertible_ToInt32;
		VirtualInvokeData System_IConvertible_ToInt64;
		VirtualInvokeData System_IConvertible_ToSByte;
		VirtualInvokeData System_IConvertible_ToSingle;
		VirtualInvokeData ToString_1;
		VirtualInvokeData System_IConvertible_ToType;
		VirtualInvokeData System_IConvertible_ToUInt16;
		VirtualInvokeData System_IConvertible_ToUInt32;
		VirtualInvokeData System_IConvertible_ToUInt64;
		VirtualInvokeData CompareTo;
		VirtualInvokeData System_Collections_IEnumerable_GetEnumerator;
		VirtualInvokeData Clone;
		VirtualInvokeData CompareTo_1;
		VirtualInvokeData Equals_1;
		VirtualInvokeData System_Collections_Generic_IEnumerable_char__GetEnumerator;
	};

	struct String__StaticFields
	{
		struct String* Empty;
		struct Char__Array* WhiteChars;
	};

	struct String__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct String__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct String__VTable vtable;
	};

	struct __declspec(align(8)) String__Fields
	{
		int32_t length;
		uint16_t start_char;
	};

	struct String
	{
		struct String__Class* klass;
		MonitorData* monitor;
		struct String__Fields fields;
	};

	struct IFormatProvider
	{
		struct IFormatProvider__Class* klass;
		MonitorData* monitor;
	};

	struct IFormatProvider__VTable
	{
		VirtualInvokeData GetFormat;
	};

	struct IFormatProvider__StaticFields
	{
	};

	struct IFormatProvider__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct IFormatProvider__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct IFormatProvider__VTable vtable;
	};

	struct Byte__Array__VTable
	{
	};

	struct Byte__Array__StaticFields
	{
	};

	struct Byte__Array__Class
	{
		Il2CppClass_0 _0;
		Il2CppRuntimeInterfaceOffsetPair* interfaceOffsets;
		struct Byte__Array__StaticFields* static_fields;
		const Il2CppRGCTXData* rgctx_data;
		Il2CppClass_1 _1;
		struct Byte__Array__VTable vtable;
	};

	struct Byte__Array
	{
		struct Byte__Array__Class* klass;
		MonitorData* monitor;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		uint8_t vector[32];
	};

	struct __declspec(align(8)) Object_1__Fields
	{
		void* m_CachedPtr;
	};

	struct Object_1
	{
		struct Object_1__Class* klass;
		MonitorData* monitor;
		struct Object_1__Fields fields;
	};

	struct Component__Fields
	{
		struct Object_1__Fields _;
	};

	struct Component
	{
		struct Component__Class* klass;
		MonitorData* monitor;
		struct Component__Fields fields;
	};

	struct ScriptableObject__Fields
	{
		struct Object_1__Fields _;
	};

	struct ScriptableObject
	{
		struct ScriptableObject__Class* klass;
		MonitorData* monitor;
		struct ScriptableObject__Fields fields;
	};

	enum class CursorLockMode__Enum : int32_t
	{
		None = 0x00000000,
		Locked = 0x00000001,
		Confined = 0x00000002,
	};

	struct Component_1__Fields
	{
		struct Object_1__Fields _;
	};

	struct Component_1
	{
		struct Component_1__Class* klass;
		MonitorData* monitor;
		struct Component_1__Fields fields;
	};

	struct Behaviour__Fields
	{
		struct Component_1__Fields _;
	};

	struct Behaviour
	{
		struct Behaviour__Class* klass;
		MonitorData* monitor;
		struct Behaviour__Fields fields;
	};

	struct Camera__Fields
	{
		struct Behaviour__Fields _;
	};

	struct Camera
	{
		struct Camera__Class* klass;
		MonitorData* monitor;
		struct Camera__Fields fields;
	};

	struct GameObject__Fields
	{
		struct Object_1__Fields _;
	};

	struct GameObject
	{
		struct GameObject__Class* klass;
		MonitorData* monitor;
		struct GameObject__Fields fields;
	};

	struct Transform__Fields
	{
		struct Component_1__Fields _;
	};

	struct Transform
	{
		struct Transform__Class* klass;
		MonitorData* monitor;
		struct Transform__Fields fields;
	};

	struct Vector2
	{
		float x;
		float y;
	};

	struct Vector3
	{
		float x;
		float y;
		float z;
	};

	struct Quaternion
	{
		float x;
		float y;
		float z;
		float w;
	};

	struct Nullable_1_UnityEngine_Vector3_
	{
		struct Vector3 value;
		bool has_value;
	};

	enum class RotationOrder__Enum : int32_t
	{
		OrderXYZ = 0x00000000,
		OrderXZY = 0x00000001,
		OrderYZX = 0x00000002,
		OrderYXZ = 0x00000003,
		OrderZXY = 0x00000004,
		OrderZYX = 0x00000005,
	};

	struct MonoBehaviour__Fields
	{
		struct Behaviour__Fields _;
	};

	struct MonoBehaviour
	{
		struct MonoBehaviour__Class* klass;
		MonitorData* monitor;
		struct MonoBehaviour__Fields fields;
	};

	struct SimplePlayerController__Fields
	{
		struct MonoBehaviour__Fields _;
		struct Camera* playerCamera;
		float walkSpeed;
		float runSpeed;
		float lookSpeed;
		float lookXLimit;
		float gravity;
		struct CharacterController* characterController;
		struct Vector3 moveDirection;
		float rotationX;
		bool canMove;
	};

	struct SimplePlayerController
	{
		struct SimplePlayerController__Class* klass;
		MonitorData* monitor;
		struct SimplePlayerController__Fields fields;
	};

	struct Collider__Fields
	{
		struct Component__Fields _;
	};

	struct Collider
	{
		struct Collider__Class* klass;
		MonitorData* monitor;
		struct Collider__Fields fields;
	};

	struct CharacterController__Fields
	{
		struct Collider__Fields _;
	};

	struct CharacterController
	{
		struct CharacterController__Class* klass;
		MonitorData* monitor;
		struct CharacterController__Fields fields;
	};

	struct PlayerController__Fields
	{
		struct MonoBehaviour__Fields _;
		struct CharacterController* thisCharacterController;
		struct Transform* cameraTransform;
		float InpVer;
		float InpHor;
		float jumpTimer;
		float yRotate;
		struct Vector3 direction;
		float sprint;
		float speed;
		float sprintMax;
		float jumpTime;
		float jumpSpeed;
		float gravity;
		float mouseSpeed;
	};

	struct PlayerController
	{
		struct PlayerController__Class* klass;
		MonitorData* monitor;
		struct PlayerController__Fields fields;
	};

	enum class eCharGroup__Enum : uint8_t
	{
		PLAYER = 0x00,
		ENEMY = 0x01,
		SUPPORTER_HUNTER = 0x02,
		PLAYERSIDE_NPC = 0x03,
		SUPPORTER_SHADOW = 0x04,
		NEUTRAL = 0x05,
		LOBBYINTER_NPC = 0x06,
		Max = 0x07,
	};

	enum class ECharacterType__Enum : int32_t
	{
		None = 0x00000000,
		Hunter = 0x00000001,
		Monster = 0x00000002,
		Shadow = 0x00000003,
		Object = 0x00000004,
		NPC = 0x00000005,
		Dialog = 0x00000006,
		MainPC = 0x00000007,
		SystemPlayHunter = 0x00000008,
		SystemPlayShadow = 0x00000009,
		SystemPlayPC = 0x0000000a,
		Part = 0x0000000b,
		Max = 0x0000000c,
	};

	enum class eCharDeadStep__Enum : uint8_t
	{
		None = 0x00,
		DeadAnimationWait = 0x01,
		DeadAction = 0x02,
		End = 0x03,
		Max = 0x04,
	};

	enum class EAffinityType__Enum : uint8_t
	{
		None = 0x00,
		Red = 0x01,
		Blue = 0x02,
		Green = 0x03,
		Empty = 0x04,
		Max = 0x05,
	};

	enum class EElementType__Enum : uint8_t
	{
		None = 0x00,
		Fire = 0x01,
		Water = 0x02,
		Wind = 0x03,
		Light = 0x04,
		Darkness = 0x05,
		Empty = 0x06,
		Max = 0x07,
	};

	enum class ESpecialState__Enum : int32_t
	{
		None = 0x00000000,
		DotMpChange = 0x00000001,
		Dispel = 0x00000002,
		MoveAnimationSpeed = 0x00000003,
		HPConditionBuffControl = 0x00000004,
		DamageReduce = 0x00000005,
		SkillDamageIncreaseOnBuffedTarget = 0x00000006,
		DotDamage = 0x00000007,
		DotPgChange = 0x00000008,
		DamageDistribution = 0x00000009,
		SkillCast = 0x0000000a,
		AfterCoolTimeSkill = 0x0000000b,
		DecreaseCoolTime = 0x0000000c,
		Barrier = 0x0000000d,
		HpRecovery = 0x0000000e,
		MpRecovery = 0x0000000f,
		Stigmatization = 0x00000010,
		AttackReactiveGiveBuff = 0x00000011,
		AttackGiveBuff = 0x00000012,
		CanNotTargetable = 0x00000013,
		Crash = 0x00000014,
		Stun = 0x00000015,
		BodyStop = 0x00000016,
		ForbidAll = 0x00000017,
		Invincible = 0x00000018,
		MesImmune = 0x00000019,
		ReactionImmune = 0x0000001a,
		ForcedMoveImmune = 0x0000001b,
		DamageImmune = 0x0000001c,
		SkillChange = 0x0000001d,
		OnlyProjectileDamageAble = 0x0000001e,
		PeriodGiveBuff = 0x0000001f,
		ElementResistanceWeak = 0x00000020,
		ElementResistanceStrong = 0x00000021,
		ElementResistanceImmune = 0x00000022,
		Suicide = 0x00000023,
		SkillMaxCoolReduce = 0x00000024,
		Shield = 0x00000025,
		FixDamage = 0x00000026,
		Undying = 0x00000027,
		ObjectSpawn = 0x00000028,
		PgRecovery = 0x00000029,
		ForcePlayerBuff = 0x0000002a,
		ForceCharBuff = 0x0000002b,
		EnhanceSkillDamage = 0x0000002c,
		BuffSubtitle = 0x0000002d,
		CrashImmune = 0x0000002e,
		StatConversion = 0x0000002f,
		PGGainRate = 0x00000030,
		FastRun = 0x00000031,
		DotBreak = 0x00000032,
		EvadeOff = 0x00000033,
		BlockExtremeAvoid = 0x00000034,
		DashMaxCount = 0x00000035,
		HideSkillIndicator = 0x00000036,
		EnhanceHpRecovery = 0x00000037,
		AddCG = 0x00000038,
		LimitSkillUseCount = 0x00000039,
		EnhanceMpRecovery = 0x0000003a,
		DecreaseHpRecovery = 0x0000003b,
		DecreaseMpRecovery = 0x0000003c,
		IncreaseDotDamage = 0x0000003d,
		ChangeDamageOnBuffTypeCount = 0x0000003e,
		ChangeDamageOnElementType = 0x0000003f,
		AddBuffInRange = 0x00000040,
		ForceApplyReactionOnAttack = 0x00000041,
		BaseStatConversion = 0x00000042,
		BuffStatAdd = 0x00000043,
		Stealth = 0x00000044,
		AbsorbElementDamage = 0x00000045,
		InstantBarrier = 0x00000046,
		ReflectDamage = 0x00000047,
		ReflectDebuff = 0x00000048,
		Fear = 0x00000049,
		MonsterGradeDamage = 0x0000004a,
		CriticalRate = 0x0000004b,
		MPUseAmount = 0x0000004c,
		DamageOnReaction = 0x0000004d,
		HPCheckLow = 0x0000004e,
		BaseStatConversionOnSkillDamage = 0x0000004f,
		BreakModifier = 0x00000050,
		BreakRecovery = 0x00000051,
		RemainHpDamageUp = 0x00000052,
		RemainHpHitDamageUp = 0x00000053,
		WeaknessElementDamage = 0x00000054,
		ForceCG = 0x00000055,
		DefPenOnSkill = 0x00000056,
		BuffGroupDuration = 0x00000057,
		EnhanceBackDamage = 0x00000058,
		EnhanceDotDamage = 0x00000059,
		IncreaseDamageByTargetBuff = 0x0000005a,
		DamageByDistance = 0x0000005b,
		EnhanceTypeDamage = 0x0000005c,
		MonsterGradeHitDamage = 0x0000005d,
		WeaknessElementSkillDamage = 0x0000005e,
		WeaknessElementBreakModifier = 0x0000005f,
		WeaknessElementCriRate = 0x00000060,
		WeaknessElementCriDamage = 0x00000061,
		CriRateOnBuffedTarget = 0x00000062,
		CriDamOnBuffedTarget = 0x00000063,
		IncreaseDamageByTargetSpecialState = 0x00000064,
		StackDispel = 0x00000065,
		PGGainRateAdd = 0x00000066,
		AddOrDispel = 0x00000067,
		AddShadowBuff = 0x00000068,
		ShadowStatIncrease = 0x00000069,
		SkillTypeMaxCoolReduce = 0x0000006a,
		EnhanceSkillTypeDamage = 0x0000006b,
		HPRateHitReceiveBuff = 0x0000006c,
		Resurrection = 0x0000006d,
		ShieldModifier = 0x0000006e,
		EnhanceSkillDamageByStat = 0x0000006f,
		HPRecoveryByDamegeRate = 0x00000070,
		CheckBuff = 0x00000071,
		DamageByDamageRate = 0x00000072,
		HPComparisonDamage = 0x00000073,
		IncreaseHitDamageBySkillType = 0x00000074,
		ManaLeak = 0x00000075,
		IncreaseMHP = 0x00000076,
		IncreaseMMP = 0x00000077,
		FixReaction = 0x00000078,
		DispelSpecialState = 0x00000079,
		ActiveQTESkill = 0x0000007a,
		Max = 0x0000007b,
		LBADFENHNJL = 0x0000007c,
	};

	struct ESpecialState__Enum__Array
	{
		struct ESpecialState__Enum__Array__Class* klass;
		MonitorData* monitor;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		ESpecialState__Enum vector[32];
	};

	struct KPBLHMGMKMK__Array
	{
		struct KPBLHMGMKMK__Array__Class* klass;
		MonitorData* monitor;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		struct KPBLHMGMKMK* vector[32];
	};

	struct __declspec(align(8)) List_1_KPBLHMGMKMK___Fields
	{
		struct KPBLHMGMKMK__Array* _items;
		int32_t _size;
		int32_t _version;
		struct Object* _syncRoot;
	};

	struct List_1_KPBLHMGMKMK_
	{
		struct List_1_KPBLHMGMKMK___Class* klass;
		MonitorData* monitor;
		struct List_1_KPBLHMGMKMK___Fields fields;
	};

	struct __declspec(align(8)) CharBattleInfoData__Fields
	{
		struct List_1_KPBLHMGMKMK_* m_startBuffDataList;
		int32_t m_ID;
		float m_SidewalkMinTime;
		float m_SidewalkMaxTime;
		float m_BackwalkMinTime;
		float m_BackwalkMaxTime;
		float m_DetectingRange;
		float m_BattleDistance;
		float m_WalkDistance;
		float m_CloseRangeJudgment;
		float m_ProbabilityCloseRangeAttack;
		float m_ProbabilityCloseRangeWander;
		float m_ProbabilityCloseRangeBackWalk;
		float m_ImpossibleWanderCloseRange;
		float m_ProbabilityLongRangeAttack;
		float m_ProbabilityLongRangeWander;
		float m_ProbabilityLongRangeBackWalk;
		float m_ImpossibleWanderLongRange;
		struct List_1_System_Int64_* m_StartBuffID;
		int32_t m_LockOnPriority;
		int32_t m_LockOnCameraIndex;
	};

	struct CharBattleInfoData
	{
		struct CharBattleInfoData__Class* klass;
		MonitorData* monitor;
		struct CharBattleInfoData__Fields fields;
	};

	struct __declspec(align(8)) CharCommonInfoData__Fields
	{
		struct CharBattleInfoData* m_pCharBattleInfo;
		int32_t m_ID;
		ECharacterType__Enum m_CharacterType;
		struct String* m_CharacterNameStringID;
		struct String* m_CharacterDescStringID;
		int32_t m_CharacterResourceID;
		int32_t m_nCharStatID;
		EAffinityType__Enum m_Affinitytype;
		EElementType__Enum m_ElementType;
		int32_t m_BattleInfoID;
		int32_t m_CommonReactionTimeLineID;
		int32_t m_ProductionTimeLineGroupID;
		bool m_MakeCircleShadow;
		float m_CharRenderRefSizeValue;
		struct String* m_DialogSetting;
		float m_CharUIScale;
		float m_CharUIScale2;
		float m_CharUIYOffSet;
		struct String* m_CharSelectEff;
		bool m_CanNotTargetable;
	};

	struct CharCommonInfoData
	{
		struct CharCommonInfoData__Class* klass;
		MonitorData* monitor;
		struct CharCommonInfoData__Fields fields;
	};

	enum class EHunterStatSize__Enum : uint8_t
	{
		VerySmall = 0x00,
		Small = 0x01,
		Normal = 0x02,
		Big = 0x03,
		VeryBig = 0x04,
		Huge = 0x05,
		EX = 0x06,
		Max = 0x07,
	};

	enum class EInCharBaseType__Enum : uint8_t
	{
		Hunter = 0x00,
		Monster = 0x01,
		Gimmick = 0x02,
		Max = 0x03,
	};

	struct __declspec(align(8)) CharResourceData__Fields
	{
		int32_t m_ID;
		struct String* m_ResourceName;
		int32_t m_ConfigData;
		struct String* m_IntroProduction;
		int32_t m_WalkSpeed;
		int32_t m_MoveSpd;
		float m_SidewalkSpeed;
		int32_t m_RotationFrame;
		float m_BackwalkSpeed;
		EHunterStatSize__Enum m_Size;
		float m_Weight;
		float m_Darg;
		float m_Mass;
		float m_Radius;
		struct String* m_AudioSet;
		struct String* m_AnimationSet;
		struct List_1_System_Single_* m_FBXScale;
		bool m_AfterDeadHitMotionDisable;
		EInCharBaseType__Enum m_InBaseType;
		bool m_UnusedLOD;
	};

	struct CharResourceData
	{
		struct CharResourceData__Class* klass;
		MonitorData* monitor;
		struct CharResourceData__Fields fields;
	};

	enum class ADKDDHHEOGP__Enum : int32_t
	{
		None = 0x00000000,
		SkillCharGroupHide = 0x00000001,
		CharGroupHide = 0x00000002,
		DialogPageCall = 0x00000004,
		DungeonPotal = 0x00000008,
		CharGroupHideCode = 0x00000010,
	};

	struct CharResourceContainer__Fields
	{
		struct MonoBehaviour__Fields _;
		struct Animator* m_pkAnimator;
		struct NavMeshAgent* m_pkNavAgent;
		struct CapsuleCollider* m_pkCollider;
		struct BehaviorTree* m_pkBehaviorTree;
		struct CapsuleCollider__Array* CHBACHOLCOI;
		struct List_1_UnityEngine_CapsuleCollider_* FOIDMHEDKLB;
		struct Transform* m_pApplyTranslateAxisY;
		struct CharCustomResourceObject* HJDDFMPNILE;
	};

	struct CharResourceContainer
	{
		struct CharResourceContainer__Class* klass;
		MonitorData* monitor;
		struct CharResourceContainer__Fields fields;
	};

	struct __declspec(align(8)) CCOAEFGKDKM__Fields
	{
		struct GameObject* HOAFECEANLC; // Character GameObject
		struct Dictionary_2_NCommon_eCharPivotType_UnityEngine_Transform_* BIPIHHBGDDK;
	};

	struct CCOAEFGKDKM
	{
		struct CCOAEFGKDKM__Class* klass;
		MonitorData* monitor;
		struct CCOAEFGKDKM__Fields fields;
	};

	struct __declspec(align(8)) CDCHBPIDJCD__Fields
	{
		struct ENNEJEPMJLJ* EJBODHBGPMG;
		struct GameObject* JOLJGBMKIFJ;
		struct GameObject* KGLDOGCNCKN;
		struct Char3DIdentity* KCGPELIKJKK;
		struct CharResourceContainer* BLHAMCDGFPB;
		struct ModelContainer* JOJBJOHCOAI;
		struct NPPEDAMJEJN* AAOCNMODFHJ;
		struct EvadeProxy__Array* IDEJDAPCFEG;
		struct Dictionary_2_System_Int32_NOCEDPLNEKJ_* HMDPJFGKCNO;
		struct Dictionary_2_System_Int32_LONIDPABIBC_* KAPAAHIFNKK;
		struct CCOAEFGKDKM* IALANALADIL;
		struct GEMHNHHBHLD* PHHOLCNPAPD;
		struct NeoLODDynamic* ALCLGACGIDC;
		struct String* MABAHPIELIM;
		bool EHNNGCOFBPO;
		ADKDDHHEOGP__Enum KMBBIGNMCFO;
	};

	struct CDCHBPIDJCD
	{
		struct CDCHBPIDJCD__Class* klass;
		MonitorData* monitor;
		struct CDCHBPIDJCD__Fields fields;
	};

	struct __declspec(align(8)) ENNEJEPMJLJ__Fields
	{
		struct EMECKMAKBDH* GICJDEIKDCI;
		eCharGroup__Enum FHNGHHPLPGD;
		ECharacterType__Enum AJEHLIOMMJN;
		struct CharCommonInfoData* KFIFBINFDPB;
		struct CharResourceData* PEFKKKBMDKN;
		bool NGLCGPAJJGK;
		bool DPJNONIOAFH;
		struct GBJHLCNJLOJ* ILDKBCNAELG;
		struct CDCHBPIDJCD* NKONPDBOBAG;
		struct PMDPIAPKIOH* KJCAKAHDGIH;
		struct LKEHFOAGHPC* DJAMFPCAKKL;
		struct CPLNAOCPILC* BNOBLLOLBPK;
		struct MHNMIDEBJOG* NEADOHAGIIB;
		struct HEAMLIPNKAI* JNMACLAOGDG;
		struct IPJKAKCEALG* MCDDMEINKKD;
		struct JKJNJFEMOGK* DDJONOKPFNF;
		struct HPELFDDJNNH* NJHLGEEIMGC;
		struct IDELGHEEFCJ* KMHKCIKOPKM;
		struct KEEKKFDLFLM* NMICALLHAOI;
		struct CCLEFLCJLDB* DMLPPHADKFF;
		struct KOFEGNAOBGF* KKLPJCDANGI;
		struct MFIINEADBCI* JFGDFOIJDJL;
		float KHFKEFJLCOF;
		float GJDMCFACNDL;
		float CLAAFELIGIC;
		eCharDeadStep__Enum KKFDEBKACEJ;
		eCharDeadStep__Enum BNJHNGLKFPL;
		float KEOJBAGNEEL;
		int32_t LICJAPCPLEB;
		int32_t JHHNIFHFEKM;
		struct NmssSvInt* HDOOADICLPI;
		bool BKIJFOEGAJI;
		struct List_1_NGame_SkillUnitIdentity_* DMMKIMMGCND;
		struct List_1_ENNEJEPMJLJ_* NEDACNMODEB;
		struct NPPEDAMJEJN* DLMMJPACLJA;
		bool GFDMJEPIKAI;
		int32_t FJNGPGFMHBC;
		int32_t PMLDLGALKKL;
		int32_t JPFAPNECDGA;
		struct GDGHJFBGAKC* FFDMOEIKOLA;
	};

	struct ENNEJEPMJLJ
	{
		struct ENNEJEPMJLJ__Class* klass;
		MonitorData* monitor;
		struct ENNEJEPMJLJ__Fields fields;
	};

	enum class ESkillType__Enum : uint8_t
	{
		None = 0x00,
		BaseAttack = 0x01,
		CoreAttack = 0x02,
		NormalSkill = 0x03,
		UltimateSkill = 0x04,
		Roll = 0x05,
		EmergencyAvoidSkill = 0x06,
		QTE = 0x07,
		ExtremeAvoidSkill = 0x08,
		Supporter = 0x09,
		SummonShadow = 0x0a,
		TriggerActive = 0x0b,
		HunterQTE = 0x0c,
		RuneAttack = 0x0d,
		Max = 0x0e,
	};

	enum class ESkillControlType__Enum : int32_t
	{
		None = 0x00000000,
		Magazine = 0x00000001,
		Channeling = 0x00000002,
		KeyHold = 0x00000003,
		Max = 0x00000004,
	};

	enum class ESkillSpecialType__Enum : int32_t
	{
		None = 0x00000000,
		QTE_Airborne = 0x00000001,
		QTE_Down = 0x00000002,
		QTE_ExtremeDash = 0x00000003,
		Suppoter = 0x00000004,
		QTE_BuffGroup = 0x00000005,
		HunterQTE = 0x00000006,
		SpecialCancel = 0x00000007,
		Max = 0x00000008,
	};

	enum class ePCSkillSlotType__Enum : int32_t
	{
		Active1 = 0x00000000,
		Active2 = 0x00000001,
		USkill = 0x00000002,
		Max = 0x00000003,
	};

	enum class ECooldownType__Enum : int32_t
	{
		Normal = 0x00000000,
		AfterCool = 0x00000001,
		AfterBuffCool = 0x00000002,
		Max = 0x00000003,
	};

	struct __declspec(align(8)) OIAMFLMIEGP__Fields
	{
		int64_t _JPEAOEPAFMA_k__BackingField;
		int64_t _FJGGBBAKIIG_k__BackingField;
		ESkillType__Enum _CMBACPMAHHB_k__BackingField;
		struct List_1_System_Int32_* _LIIEIENHADE_k__BackingField;
		ESkillControlType__Enum _GAPILFEKGDJ_k__BackingField;
		ESkillSpecialType__Enum _CGCEOEFAECA_k__BackingField;
		ePCSkillSlotType__Enum _IFOCIAJGNFL_k__BackingField;
		EElementType__Enum _GKABKMADCGD_k__BackingField;
		int32_t _OGCHCCBDEHK_k__BackingField;
		int32_t _LKCDCADIBBJ_k__BackingField;
		struct String* _JFBMFDPMOJB_k__BackingField;
		struct String* _DBIKMNPPPEE_k__BackingField;
		bool _KMDAAMMLEGP_k__BackingField;
		int32_t _JFONMDNMHKA_k__BackingField;
		int32_t _HFMCMNOCJGB_k__BackingField;
		int32_t _IIDECIIJMMI_k__BackingField;
		int32_t _HEFHDKCIFJD_k__BackingField;
		int32_t _HAGHJIHNDEA_k__BackingField;
		int32_t _BCBKKNGJOKJ_k__BackingField;
		int32_t _JLMMDMFECAJ_k__BackingField;
		ECooldownType__Enum _NNLELLGDMIF_k__BackingField;
		float _IDCNBMNPAJI_k__BackingField;
		int32_t _GEPNEOEHMCO_k__BackingField;
		float _BCKEJKNJOAN_k__BackingField;
		float _LJOJMLLDONJ_k__BackingField;
		float _ELMPBGOALGP_k__BackingField;
		float _HBPDDJGEGPC_k__BackingField;
		float _PPHJHMJILEC_k__BackingField;
		float _CCDKHGHOPFK_k__BackingField;
		float _CBBNJBAOOHK_k__BackingField;
		float _OEEEPNOLCAH_k__BackingField;
		int64_t _CPGILGKNKPJ_k__BackingField;
		int64_t _NOBNNKJLKAE_k__BackingField;
		struct Dictionary_2_System_Int32_System_Int64_* NNHLFGEHFKL;
		struct List_1_System_Int64_* _KOGPAGFMHPL_k__BackingField;
		struct List_1_System_Int64_* _NLACGPPNNBK_k__BackingField;
		float _DNBGEDEBBKP_k__BackingField;
		int32_t _BLOGAHIANHO_k__BackingField;
		struct Int64__Array* _GKLAOHBLBJJ_k__BackingField;
		bool _EOPIKKKEHOJ_k__BackingField;
		bool _HCHJLIDEDJD_k__BackingField;
		int32_t _LKNEBDEACBH_k__BackingField;
		int32_t _IDANHHIDFLL_k__BackingField;
		float _JNGECPDNKEG_k__BackingField;
		float _HGFKCGJBFKE_k__BackingField;
		int32_t _BDCEDKCELHC_k__BackingField;
		int32_t _GJCLKHLJIPL_k__BackingField;
		bool _NMHJBBINBBC_k__BackingField;
		bool _IOAOMHGAAAL_k__BackingField;
		float _EPDAFHLKLIK_k__BackingField;
		int32_t _PMJJMKEFNBO_k__BackingField;
		bool _MNFPAGGFLGJ_k__BackingField;
		bool _AFLEBMBOANH_k__BackingField;
		bool _HPIMMEFBJCN_k__BackingField;
		bool _GFJKLFJAMGK_k__BackingField;
		int32_t _EHCJNOEGAMB_k__BackingField;
		bool _AGIDKKFMCFM_k__BackingField;
		bool _KONKEIKMECK_k__BackingField;
		float _AAMHKEPEMCK_k__BackingField;
		float _NHGJMOOHBKP_k__BackingField;
		bool _NHOCLILHABG_k__BackingField;
		bool _ACIAJIGCMBP_k__BackingField;
	};

	struct OIAMFLMIEGP
	{
		struct OIAMFLMIEGP__Class* klass;
		MonitorData* monitor;
		struct OIAMFLMIEGP__Fields fields;
	};
	
	// new DAICCIIPJPK__Fields
	struct __declspec(align(8)) KAAIFMKPKAG__Fields
	{
		struct ENNEJEPMJLJ* KCBLLGODKIE;
		struct OIAMFLMIEGP* EGIPHDFEGFO;
		struct GameObject* LPIKHHCMOJJ;
		struct IHENELMLJGP* PNOAEGFFPHK;
		struct OKDBDHFKIKF* LIMALOMLOMH;
		struct IPAHKHEAPBO* IMNOKDBJPND;
		struct KAAIFMKPKAG* OMIEFLPNPDK;
		struct KAAIFMKPKAG* DOMNOPDJEPC;
		struct IEMMDCPLCIC* CDHEEFJLIOD;
		struct ENNDLFNPHKE* MGMEDKOAOLA;
		struct KKHFNJMNIJN* HKAKPCCIHBH;
		float HPHOOEPCBOJ; // Cooldown Time Check
		float JCJJDJGOBJL; // Cooldown Time
		int32_t GBNEJKEANGN;
		struct Action* LJEICDBFGNL;
		bool EJOBFNNCGAC;
		bool PAGHHJJPOJO;
		bool KHLLDINELFH;
		float FPLBGOCHMAK;
		int32_t FPCKHEHAIGM;
		struct Action_1_KAAIFMKPKAG_* FJENNOLHABI;
		struct Action_1_KAAIFMKPKAG_* EPIEMBIBOCO;
		float GHKFFBDDMNA;
		float FKIMFNIJNDP;
		int32_t OJDPJNNNPGP;
		int32_t OEBHEBJDKNF;
		int32_t ADCBINDDGEE;
		bool MBPGPPKOLLF;
		bool CKHELDOLPJO;
		struct SkillIdentity* EBLLAHNANKP;
		struct SkillCameraImpulse* NOMIEPBLAOK;
		struct CameraPriorityControl__Array* BHPOEHJKCEK;
		struct ControlTrack* NHNGJHFLFKP;
		struct SkillCameraTrackIdentifier* JIBMGPCBIEF;
		struct CinemachineVirtualCameraBase* BGFPPMLHANG;
		struct Dictionary_2_System_Int32_UnityEngine_Timeline_ControlTrack_* HBPMEBGMOPB;
		int32_t NACNBBGHIBH;
		int32_t GPNJKFBOCBL;
		struct List_1_System_Int32_* GCDCEJDMCOE;
		struct Dictionary_2_System_Int32_List_1_System_Int32_* BEHLMIFAAKE;
		struct IJIAGCJJCJC* _DBFNJAMNBNI_k__BackingField;
	};

	// new DAICCIIPJPK
	struct KAAIFMKPKAG
	{
		struct KAAIFMKPKAG__Class* klass;
		MonitorData* monitor;
		struct KAAIFMKPKAG__Fields fields;
	};

	struct __declspec(align(8)) PHAMLKDDCGJ__Fields
	{
		struct GameObject* GDIOINPJJPJ;
		struct List_1_ENNEJEPMJLJ_* NHLIIJEJNHK;
		struct List_1_PHAMLKDDCGJ_* LFCGEIMEIPH;
		struct List_1_ENNEJEPMJLJ_* LJLCMHCDIFM;
		struct List_1_UnityEngine_Collider_* EMAMJGPHNBN;
	};

	struct PHAMLKDDCGJ
	{
		struct PHAMLKDDCGJ__Class* klass;
		MonitorData* monitor;
		struct PHAMLKDDCGJ__Fields fields;
	};

	struct JLLMICINIDA__Fields
	{
		struct PHAMLKDDCGJ__Fields _;
		float DGPHADJBCDJ;
		bool DONILLPJMFC;
		int32_t KBDEBMKCNPD;
		int32_t KKEDBBAMIJL;
		float _HGHNGDFFJBD_k__BackingField;
	};

	struct JLLMICINIDA
	{
		struct JLLMICINIDA__Class* klass;
		MonitorData* monitor;
		struct JLLMICINIDA__Fields fields;
	};

	struct __declspec(align(8)) PJKMAOEINNH__Fields
	{
		bool FAGLAHOBJPM;
		struct List_1_ENNEJEPMJLJ_* IHKJAIGPJGK;
		struct List_1_ENNEJEPMJLJ_* NPLCJNDIHAH;
		struct List_1_ENNEJEPMJLJ_* LAOMMPMJKLJ;
		struct FPJOOKGDFJJ* OCEDJOHLGGE;
		struct List_1_NGame_SkillUnitIdentity_* PHDAMJALJNN;
		struct List_1_ENNEJEPMJLJ_* FGHCGANDCMM;
		struct List_1_ENNEJEPMJLJ_* OJCKOPHINIO;
		float OMNIKINCCEM;
		struct List_1_PJKMAOEINNH_BEFNFECKKBC_* OPAOMIHOKLH;
		struct List_1_PJKMAOEINNH_MHNNIAEKKBA_* BMDMFNCGPCI;
		struct MGMBKDBDDHP* BAHDMIMMEEI;
		struct MLCCAMFKGNL* JFKNJNBJFKN;
		struct List_1_ENNEJEPMJLJ_* OEBMEIOICNK;
	};

	struct PJKMAOEINNH
	{
		struct PJKMAOEINNH__Class* klass;
		MonitorData* monitor;
		struct PJKMAOEINNH__Fields fields;
	};

	struct ENNEJEPMJLJ__Array
	{
		struct ENNEJEPMJLJ__Array__Class* klass;
		MonitorData* monitor;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		struct ENNEJEPMJLJ* vector[32];
	};

	struct __declspec(align(8)) List_1_ENNEJEPMJLJ___Fields
	{
		struct ENNEJEPMJLJ__Array* _items;
		int32_t _size;
		int32_t _version;
		struct Object* _syncRoot;
	};

	struct List_1_ENNEJEPMJLJ_
	{
		struct List_1_ENNEJEPMJLJ___Class* klass;
		MonitorData* monitor;
		struct List_1_ENNEJEPMJLJ___Fields fields;
	};

	struct Object_1__Array
	{
		struct Object_1__Array__Class* klass;
		MonitorData* monitor;
		Il2CppArrayBounds* bounds;
		il2cpp_array_size_t max_length;
		struct Object_1* vector[32];
	};

	struct Assembly
	{
		struct Assembly__Class* klass;
		MonitorData* monitor;
	};

	enum class AHPHDBJOAGF__Enum : int32_t
	{
		IsObstacle = 0x00000000,
	};

	struct Char3DIdentity__Fields
	{
		struct MonoBehaviour__Fields _;
		struct ENNEJEPMJLJ* EJBODHBGPMG;
	};

	struct Char3DIdentity
	{
		struct Char3DIdentity__Class* klass;
		MonitorData* monitor;
		struct Char3DIdentity__Fields fields;
	};

	struct Scene
	{
		int32_t m_Handle;
	};

	enum class DJNPAKOJGIN__Enum : int32_t
	{
		Normal = 0x00000000,
		StackMaxAdd = 0x00000001,
		HighLevelAdd = 0x00000002,
		Dispel = 0x00000003,
	};

	struct __declspec(align(8)) JKJNJFEMOGK__Fields
	{
		struct ENNEJEPMJLJ* EJBODHBGPMG;
		struct Dictionary_2_System_UInt64_PIPHNBOBFEF_* HADDFFCOCPC;
		struct List_1_NCommon_EBuffLargeType_* DJLMLBCLKED;
		struct List_1_System_Int64_* FMJJNGBIKNF;
		struct List_1_NCommon_ESpecialState_* PAHAKNBIIOD;
		struct List_1_PIPHNBOBFEF_* NCLDGALGGGM;
		struct Dictionary_2_NCommon_ESpecialState_List_1_EKNOFMDFHGJ_* FMHMOIHKFBM;
		struct MLBDNJLOKFL* NLKNKMOBCFL;
		struct DDPFOIGOFCN* DJNIKOPKJGJ;
		struct GameObject* OAAOABGJGBC;
		int32_t ECMHCFPJBNL;
	};

	struct JKJNJFEMOGK
	{
		struct JKJNJFEMOGK__Class* klass;
		MonitorData* monitor;
		struct JKJNJFEMOGK__Fields fields;
	};

	struct __declspec(align(8)) GJGFPGJIDNG__Fields
	{
		struct ENNEJEPMJLJ* JNNMMAAAOJB;
		struct ENNEJEPMJLJ* FHFMEKNCKOO;
		float NFBBJIJBBEC;
		float NDOADBEIFKC;
		int64_t HFLFANDAJMO;
		int64_t PLBCBJGLEPB;
		int64_t DHHEGCPEDEJ;
		int64_t FNFNJJAEFGP;
		int64_t GBCGIOGHEJC;
		struct String* DIBDBFDIDII;
		float AKDGBHHLPCD;
		bool JDONIILBMLO;
		float AFDNFNKBGBB;
	};

	struct GJGFPGJIDNG
	{
		struct GJGFPGJIDNG__Class* klass;
		MonitorData* monitor;
		struct GJGFPGJIDNG__Fields fields;
	};

	struct __declspec(align(8)) PIPHNBOBFEF__Fields
	{
		uint64_t IJONAPJBFEK;
		struct HGPCCPIIIGG* DFFMKDJPPPL;
		bool DKPHBKCEAFA;
		float ICJEKNCLMJF;
		DJNPAKOJGIN__Enum CKEGENFBMAP;
		struct JKJNJFEMOGK* IGFILCLEFHH; // Has pointer to entity class
		struct GJGFPGJIDNG* AGDPKHPPCNP; // Has pointer to entity class
		struct List_1_GJGFPGJIDNG_* NOEAHDOPANM;
		struct List_1_EKNOFMDFHGJ_* OOPGJABIBCA;
		struct List_1_PIPHNBOBFEF_NLGJGGJEHEN_* LHDIFNGNDDL;
		float PKGNHLJDBNI;
		bool NGEPOFMGICN;
		bool AMMFIGCPJLN;
		bool OJJPEOKGEIF;
	};

	struct PIPHNBOBFEF
	{
		struct PIPHNBOBFEF__Class* klass;
		MonitorData* monitor;
		struct PIPHNBOBFEF__Fields fields;
	};

	struct SkillIdentity__Fields
	{
		struct MonoBehaviour__Fields _;
		struct ENNEJEPMJLJ* entity;
		struct KAAIFMKPKAG* CCKLMEPBGFN;
		struct OKDBDHFKIKF* LIMALOMLOMH;
		struct SkillCameraImpulse* CFLJBNPIKBA;
		struct List_1_UnityEngine_Collider_* NNHKPPDKHOB;
		struct IJIAGCJJCJC* AMFLIMLDLNL;
		int32_t SkipFrontBlendingFrame;
		float SkillRange;
		float SkillMinRange;
		int32_t SkillRef;
		int32_t KIIMDHGDKJP;
	};

	struct SkillIdentity
	{
		struct SkillIdentity__Class* klass;
		MonitorData* monitor;
		struct SkillIdentity__Fields fields;
	};

	enum class eTargetImpactType__Enum : int32_t
	{
		Normal = 0x00000001,
		NonExtreme = 0x00000002,
	};

	enum class eReactionType__Enum : int32_t
	{
		None = 0x00000000,
		Damaged_Random = 0x00000001,
		Damaged_A = 0x00000002,
		Damaged_B = 0x00000003,
		Damaged_C = 0x00000004,
		Float = 0x00000005,
		Grabbed = 0x00000006,
		KnockDown = 0x00000007,
		Damaged_B_Left = 0x00000008,
		Damaged_B_Right = 0x00000009,
		Float_B = 0x0000000a,
		Damaged_UpperOnly = 0x0000000b,
		Damaged_D = 0x0000000c,
		BreakFall = 0x0000000d,
		Max = 0x0000000e,
	};

	enum class TargetHitData_GMGLGFEKPNL__Enum : int32_t
	{
		Normal = 0x00000001,
		BiggerText = 0x00000002,
	};

	struct __declspec(align(8)) TargetHitData__Fields
	{
		struct HitEffectData* hitEffectData;
		struct HitEffectData__Array* extraHitEffectDatas;
		eTargetImpactType__Enum targetImpactType;
		bool targetStiff;
		bool cancelHolding;
		bool resetForce;
		bool noRotationForce;
		struct Vector3 force;
		struct Vector3 airborneForce;
		float forceDrag;
		bool upperOnly;
		eReactionType__Enum _reaction;
		struct HitDelayData* hitDelay;
		bool PreventSkillCancel;
		int64_t buffDataID;
		int32_t buffGroupIndex;
		float damageRatio;
		float damageRatioTotalValue;
		TargetHitData_GMGLGFEKPNL__Enum damageTextSettingType;
		struct AssetAddressReference_1_AddressableAssetReferenceAuidoClip_* hitSoundRef;
		struct RandomAudioClip* randomHitSound;
		struct AssetAddressReference_1_AddressableAssetReferenceAuidoClip_* secondHitSoundRef;
		struct RandomAudioClip* secondRandomHitSound;
		float pitch;
		float volume;
		int32_t hitSoundMaxPlayCount;
		int32_t hitSoundSkipCount;
		float hitSoundSkipMinTime;
		int32_t impactGroup;
		int32_t hitSoundSkipRemainCount;
		int32_t hitSoundMaxPlayRemainCount;
		float hitSoundSkipNextCheckTime;
		bool ignoreProjectileHitSound;
		bool IsFirstHitSound;
		int32_t m_HashAddValue;
		struct GKAudioClipData* specificHitSoundData;
	};

	struct TargetHitData
	{
		struct TargetHitData__Class* klass;
		MonitorData* monitor;
		struct TargetHitData__Fields fields;
	};

	enum class CEAFGMIHCCL__Enum : int32_t
	{
		None = 0x00000000,
		Projectile = 0x00000001,
		GuidedProjectile = 0x00000002,
		ParabolaProjectile = 0x00000003,
		PadImpact = 0x00000004,
		AutoUse = 0x00000005,
		ComeBackProjectile = 0x00000006,
		Max = 0x00000007,
	};

	struct SkillUnitIdentity__Fields
	{
		struct SkillIdentity__Fields _;
		CEAFGMIHCCL__Enum GKNIKFBNHDH;
		struct GameObject* FJFGAAFNLCK;
		struct IJIAGCJJCJC* IDGEGHPDOIJ;
		bool GBFLDJPAEHE;
		struct SkillIdentity* JMIFEKKOAMF;
		struct Action_1_Boolean_* HNJGPAKCCMJ;
	};

	struct SkillUnitIdentity
	{
		struct SkillUnitIdentity__Class* klass;
		MonitorData* monitor;
		struct SkillUnitIdentity__Fields fields;
	};

	enum EvadePenetration_MEPJNDGOKMK__Enum
	{
		EvadePenetration_MEPJNDGOKMK__Enum_Sphere = 0x00000000,
		EvadePenetration_MEPJNDGOKMK__Enum_Box = 0x00000001,
		EvadePenetration_MEPJNDGOKMK__Enum_Capsule = 0x00000002,
	};

	enum class EvadePenetration_APIPHPLNIJD__Enum : int32_t
	{
		Push = 0x00000000,
		Pull = 0x00000001,
	};

	struct EvadePenetration__Fields
	{
		struct ScriptableObject__Fields _;
		EvadePenetration_MEPJNDGOKMK__Enum evadeType;
		EvadePenetration_APIPHPLNIJD__Enum actionType;
		bool isAlwaysCheck;
		int32_t evadeLevel;
		bool uplevelPush;
		bool forceToOther;
		struct List_1_NGame_EvadePenetration_* m_lstNeighborhoodFromOther;
		float priority;
		float originPriority;
		bool justBackForce;
		float mass;
		float radius;
		struct RaycastHit__Array* hitResult;
		struct Transform* _BJMFKFLLGDE_k__BackingField;
		struct Collider* _LAGKKCEGHDD_k__BackingField;
		struct ENNEJEPMJLJ* m_own;
		int32_t _GEEJJDMHKJO_k__BackingField;
	};

	struct EvadePenetration
	{
		struct EvadePenetration__Class* klass;
		MonitorData* monitor;
		struct EvadePenetration__Fields fields;
	};

	struct EvadeProxyBase__Fields
	{
		struct MonoBehaviour__Fields _;
		struct EvadePenetration* evadePenetration;
		struct BLPDABOMDPF* CLJOMEFBEGL;
	};

	struct EvadeProxyBase
	{
		struct EvadeProxyBase__Class* klass;
		MonitorData* monitor;
		struct EvadeProxyBase__Fields fields;
	};

	struct EvadeProxy__Fields
	{
		struct EvadeProxyBase__Fields _;
		struct ENNEJEPMJLJ* EJBODHBGPMG;
	};

	struct EvadeProxy
	{
		struct EvadeProxy__Class* klass;
		MonitorData* monitor;
		struct EvadeProxy__Fields fields;
	};

	struct __declspec(align(8)) DungeonStageData__Fields
	{
		struct List_1_NLib_DungeonMonsterIndicatorData_* m_pDungeonMonsterIndicatorDatas;
		struct List_1_NLib_DungeonBuffData_* m_lstDungeonBuffDatas;
		struct List_1_KPBLHMGMKMK_* m_strongBuffDataList;
		struct List_1_KPBLHMGMKMK_* m_weakBuffDataList;
		struct List_1_KPBLHMGMKMK_* m_bossMetaBuffDataList;
		int32_t m_ID;
		struct String* m_IconResourceName;
		struct String* m_StageMainText;
		struct String* m_StageSubText;
		struct String* m_StageDescription;
		struct String* m_LoadingThumbnail;
		struct String* m_BgmListSet;
		int32_t m_Timelimit;
		int32_t m_BossInfo1;
		int32_t m_BossInfo2;
		int32_t m_BossInfo3;
		struct String* m_BGSceneName1;
		struct String* m_BGAddSceneName1;
		struct String* m_TriggerScene1;
		struct String* m_TriggerName1;
		struct String* m_ActiveScene1;
		struct String* m_LightScene1;
		struct String* m_LightAddScene1;
		struct String* m_ActiveAddScene1;
		struct String* m_BGSceneName2;
		struct String* m_BGAddSceneName2;
		struct String* m_TriggerScene2;
		struct String* m_TriggerName2;
		struct String* m_ActiveScene2;
		struct String* m_LightScene2;
		struct String* m_ActiveAddScene2;
		struct String* m_LightAddScene2;
		struct String* m_BGAddSceneName3;
		struct String* m_BGSceneName3;
		struct String* m_TriggerScene3;
		struct String* m_TriggerName3;
		struct String* m_ActiveScene3;
		struct String* m_LightScene3;
		struct String* m_ActiveAddScene3;
		struct String* m_LightAddScene3;
		int32_t m_RandomizeSpawnID;
		struct List_1_System_Int32_* m_nLstDungeonBuff;
		int32_t m_nMonsterIndicatorGroupID;
		struct List_1_System_Int64_* m_StrongAttribute;
		struct List_1_System_Int64_* m_WeakAttribute;
		struct List_1_System_Int64_* m_BossMetaInfo;
	};

	struct DungeonStageData
	{
		struct DungeonStageData__Class* klass;
		MonitorData* monitor;
		struct DungeonStageData__Fields fields;
	};

	enum class eUIType__Enum : int32_t
	{
		INIT = 0x00000000,
		NoticePopup = 0x00000001,
		ItemDetailPopup = 0x00000002,
		ArtifactDetailPopup = 0x00000003,
		WeaponDetailPopup = 0x00000004,
		HunterDetailPopup = 0x00000005,
		SkillDetailPopup = 0x00000006,
		EmblemDetailPopup = 0x00000007,
		ShadowDetailPopup = 0x00000008,
		CommonToastPopup = 0x00000009,
		RollingTextPopup = 0x0000000a,
		TopUI = 0x0000000b,
		TutorialButtonClickUIPopup = 0x0000000c,
		TutorialIntroUIPopup = 0x0000000d,
		TutorialDialogUIPopup = 0x0000000e,
		TutorialWalkThroughsUIPopup = 0x0000000f,
		TutorialPlayMediaUIPopup = 0x00000010,
		TutorialTimeButtonDialogUIPopup = 0x00000011,
		TutorialMobileTypeUIPopup = 0x00000012,
		GameOverPopup = 0x00000013,
		HunterLevelUpPopup = 0x00000014,
		HunterEvolvePopup = 0x00000015,
		HunterUpgradePopup = 0x00000016,
		HunterLevelUpResultPopup = 0x00000017,
		HunterEvolveResultPopup = 0x00000018,
		HunterUpgradeResultPopup = 0x00000019,
		ShadowPromotionPopup = 0x0000001a,
		ShadowUpgradePopup = 0x0000001b,
		ShadowPromotionResultPopup = 0x0000001c,
		ShadowUpgradeResultPopup = 0x0000001d,
		ShadowGetResultPopup = 0x0000001e,
		ShadowStoryPopup = 0x0000001f,
		ShadowCorpsLevelUpPopup = 0x00000020,
		ShadowCorpsLevelUpResultPopup = 0x00000021,
		SkipButtonPopup = 0x00000022,
		SystemPopup = 0x00000023,
		PasswordPopup = 0x00000024,
		ItemSellPopup = 0x00000025,
		ItemUsePopup = 0x00000026,
		ArtifactSellPopup = 0x00000027,
		ArtifactSwapPopup = 0x00000028,
		ArtifactUnEquipPopup = 0x00000029,
		ArtifactBatchSelectPopup = 0x0000002a,
		RuneRarityComparePopup = 0x0000002b,
		InventorySJW_EmblemReplacePopup = 0x0000002c,
		MissionTitlePopup = 0x0000002d,
		ElementHunterListPopup = 0x0000002e,
		GroupStatGrowthPopup = 0x0000002f,
		CommonUIItemBuyPopup = 0x00000030,
		EnergyChargeCashPopup = 0x00000031,
		EnergyChargeItemPopup = 0x00000032,
		ContentMenuPopup = 0x00000033,
		RuneItemGainResultPopup = 0x00000034,
		ProfilePlayRecordPopup = 0x00000035,
		QuickMenuPopup = 0x00000036,
		ShopBuyInfoNormalPopup = 0x00000037,
		ShopBuyInfoMonthlyPopup = 0x00000038,
		ShopBuyInfoCustomPopup = 0x00000039,
		ShopBuyInfoMissionPopup = 0x0000003a,
		RandomShopBuyInfoPopup = 0x0000003b,
		ShopBuyConfirmPopup = 0x0000003c,
		BoxItemUsePopup = 0x0000003d,
		ArtifactEnhancePopup = 0x0000003e,
		ArtifactRepeatEnhancePopup = 0x0000003f,
		ArtifactEnhanceResultPopup = 0x00000040,
		InventorySkillLevelUpPopup = 0x00000041,
		InventorySkillLevelUpResultPopup = 0x00000042,
		AccountLevelUp = 0x00000043,
		MainPCLevelUp = 0x00000044,
		BattleUIResult = 0x00000045,
		BattleUIResultNew = 0x00000046,
		TimeAttackUIResult = 0x00000047,
		Reward = 0x00000048,
		EventDiceRewardPopup = 0x00000049,
		TimeAttackInfoPopup = 0x0000004a,
		GachaHistoryPopup = 0x0000004b,
		GachaResultPopup = 0x0000004c,
		GachaPickupSelectPopup = 0x0000004d,
		GachaPickupPopularPopup = 0x0000004e,
		RewardSelectDisplayBoxPopup = 0x0000004f,
		DungeonPenaltySelectPopup = 0x00000050,
		RandomBuffListPopupNew = 0x00000051,
		SeasonPassBuyInfoPopup = 0x00000052,
		OwnedDiamondPopup = 0x00000053,
		WithdrawKRPopup = 0x00000054,
		CharacterStatDetailPopup = 0x00000055,
		CommonAbilityPointPopup = 0x00000056,
		InstanceDungeonListPopup = 0x00000057,
		PenaltySelectPopupNew = 0x00000058,
		RaidRewardPopup = 0x00000059,
		RaidBuffPopup = 0x0000005a,
		ArtifactReplacementPopup = 0x0000005b,
		Weapon_Replacement_Popup = 0x0000005c,
		WeaponBatchSelectPopup = 0x0000005d,
		CraftResultPopup = 0x0000005e,
		CraftMaterialSelectPopup = 0x0000005f,
		CraftRecipePopup = 0x00000060,
		WorldBossInfoPopup = 0x00000061,
		WorldBoss_DetailPopup = 0x00000062,
		WorldBoss_RankingDetailPopup = 0x00000063,
		WorldBossUIResult = 0x00000064,
		WorldBoss_CardPopup = 0x00000065,
		OtherWorldInfoPopup = 0x00000066,
		SkillEquipPopup = 0x00000067,
		SkillRuneEquipPopup = 0x00000068,
		InventoryWeaponSkillLevelupPopup = 0x00000069,
		SweepSJWPopup = 0x0000006a,
		SweepHunterPopup = 0x0000006b,
		SweepAdventDungeonPopup = 0x0000006c,
		SweepResultPopup = 0x0000006d,
		GateSweepRewardPopup = 0x0000006e,
		PointEventMissionInfoPopup = 0x0000006f,
		PointEventRankingInfoPopup = 0x00000070,
		PointEventAchievementNotiPopup = 0x00000071,
		IdleSystemSupportPopup = 0x00000072,
		IdleSystemInfoPopup = 0x00000073,
		IdleSystemMonthlyFeePopup = 0x00000074,
		IdleSystemRewardShowPopup = 0x00000075,
		ArtifactOptionPopup = 0x00000076,
		ArtifactEngraveResultPopup = 0x00000077,
		ArtifactEngraveMaterialPopup = 0x00000078,
		ArtifactOptionResetPopup = 0x00000079,
		ArtifactSuccessionResultPopup = 0x0000007a,
		MonsterCollectionLevelupPopup = 0x0000007b,
		BattleClassRewardInfoPopup = 0x0000007c,
		BattleClassNotiPopup = 0x0000007d,
		OptionKeyMappingPopup = 0x0000007e,
		GateMiningDetailPopup = 0x0000007f,
		GateMiningPopup = 0x00000080,
		GateMiningShuffleCheckPopup = 0x00000081,
		GateMiningShorteningPopup = 0x00000082,
		ImmediateCompletionPopup = 0x00000083,
		MiningGateDetailInfoPopup = 0x00000084,
		GateMiningRewardNew = 0x00000085,
		MiningTeamInfoPopup = 0x00000086,
		MiningGateInfoPopup = 0x00000087,
		GateMiningDeletePopup = 0x00000088,
		GateMiningLevelUpPopup = 0x00000089,
		RandomBuffPopupNew = 0x0000008a,
		BlessednessBuffPopup = 0x0000008b,
		DimensionResultPopup = 0x0000008c,
		DimensionLevelUpPopup = 0x0000008d,
		StoryQuestListPopup = 0x0000008e,
		SquadPresetListPopup = 0x0000008f,
		SquadPresetNameEditPopup = 0x00000090,
		SquadPresetCopyPopup = 0x00000091,
		MoveTargetPopup = 0x00000092,
		ProfileGreetingEditPopup = 0x00000093,
		ProfileIconSettingPopup = 0x00000094,
		FateInfoPopup = 0x00000095,
		FatePointDetailPopup = 0x00000096,
		InventoryItemMultipleSellPopup = 0x00000097,
		CharacterReplacedConfirmPopup = 0x00000098,
		InventoryDecompositionPopup = 0x00000099,
		SkillRuneBatchSelectPopup = 0x0000009a,
		ItemBatchSelectPopup = 0x0000009b,
		WeaponDecompositionPopup = 0x0000009c,
		DecompositionCheckPopup = 0x0000009d,
		ImmediateAttendancePopup = 0x0000009e,
		NicknameChangePopup = 0x0000009f,
		MonCodexLevelupResult = 0x000000a0,
		CombineSimplePopup = 0x000000a1,
		CombineGemResultPopup = 0x000000a2,
		GemEquipPopup = 0x000000a3,
		GemPointPopup = 0x000000a4,
		JobChangeRewardPopup = 0x000000a5,
		FilterSelectPopup = 0x000000a6,
		HunterSelectPopup = 0x000000a7,
		ShadowSelectPopup = 0x000000a8,
		AdventDungeonListPopup = 0x000000a9,
		AccountDeletePopup = 0x000000aa,
		StoryDungeonTitlePopup = 0x000000ab,
		BattleMissionInfoPopup = 0x000000ac,
		ContentsUnlockNotiMainPopup = 0x000000ad,
		ContentsUnlockNotiSubPopup = 0x000000ae,
		ContentsUnlockNotiSpecialPopup = 0x000000af,
		WeaponLevelupPopup = 0x000000b0,
		WeaponBreakThroughPopup = 0x000000b1,
		WeaponEvolutionPopup = 0x000000b2,
		AchieveInfoPopop = 0x000000b3,
		TutorialNickNameChangePopup = 0x000000b4,
		GuestBuyAgreementPopup = 0x000000b5,
		MonCodexStatDetailPopup = 0x000000b6,
		WeaponLevelUpResultPopup = 0x000000b7,
		WeaponBreakResultPopup = 0x000000b8,
		WeaponEvolveResultPopup = 0x000000b9,
		HotTimeInfoPopup = 0x000000ba,
		WorldDropInfoPopup = 0x000000bb,
		NMNoticeWebView = 0x000000bc,
		NMForumWebView = 0x000000bd,
		GateInfoPopup = 0x000000be,
		GateMileageInfoPopup = 0x000000bf,
		MagicEssenceExchangePopup = 0x000000c0,
		BattlePassLevelOpenPopup = 0x000000c1,
		BattlePassGoodsBuyAlarmPopup = 0x000000c2,
		PointEventInfoPopup = 0x000000c3,
		SecretFileStoryPopup = 0x000000c4,
		TimeAttackRelayRankingPopup = 0x000000c5,
		HunterExperiencePopup = 0x000000c6,
		GateReserchPopup = 0x000000c7,
		GateLevelChangePopup = 0x000000c8,
		GateListPopup = 0x000000c9,
		MultiplePlayMaxInfoPopup = 0x000000ca,
		MonsterCollectionInfoPopup = 0x000000cb,
		TimeAttackRelayStageRankingPopup = 0x000000cc,
		BattleClassDetailPopup = 0x000000cd,
		PenaltyDetailPopup = 0x000000ce,
		TimeAttackRelayUserRankDetailPopup = 0x000000cf,
		HotTimeItemApplyPopup = 0x000000d0,
		AdvancedSelectBoxPopup = 0x000000d1,
		CommonBigSlotPopup = 0x000000d2,
		WorldBossCardSelectPopup = 0x000000d3,
		TimeLimitItemInfoPopup = 0x000000d4,
		SeasonPassNewSeasonPopup = 0x000000d5,
		BattleMissionRankingRewardInfoPopup = 0x000000d6,
		ShopDailyRewardPopup = 0x000000d7,
		ShopMonthlyManageInfoPopup = 0x000000d8,
		GateMissionRewardShowPopup = 0x000000d9,
		PAGE_START = 0x000000da,
		ScreenSafe = 0x000000db,
		ScreenMask = 0x000000dc,
		ScreenLetterBox = 0x000000dd,
		Loading = 0x000000de,
		DevelopingMessagePopup = 0x000000df,
		MissionNotiPopup = 0x000000e0,
		Patch = 0x000000e1,
		Login = 0x000000e2,
		CommonPopup = 0x000000e3,
		CommonCheckPopup = 0x000000e4,
		CommonUIActivationPopup = 0x000000e5,
		SimpleOptionPopup = 0x000000e6,
		GameAccountPopup = 0x000000e7,
		ServerSelectPopup = 0x000000e8,
		AccountDeleteWithdrawalPopup = 0x000000e9,
		AccountIDProviderListPopup = 0x000000ea,
		SecurityPopup = 0x000000eb,
		LobbyStageSelect = 0x000000ec,
		Dialog2D = 0x000000ed,
		Dialog3D = 0x000000ee,
		BattleFail = 0x000000ef,
		BattleWin = 0x000000f0,
		Attendance = 0x000000f1,
		PostBox = 0x000000f2,
		Pause = 0x000000f3,
		InventoryItem = 0x000000f4,
		InventoryHunter = 0x000000f5,
		GSWeapon_Main = 0x000000f6,
		InventoryGS = 0x000000f7,
		InventoryShadow = 0x000000f8,
		InventoryShadowCorps = 0x000000f9,
		InventorySJW = 0x000000fa,
		SJWSkillSetting = 0x000000fb,
		Mission = 0x000000fc,
		Achieve = 0x000000fd,
		AchieveList = 0x000000fe,
		ArtifactGrowth = 0x000000ff,
		Artifact = 0x00000100,
		HunterStory = 0x00000101,
		HunterStoryUnlockPopup = 0x00000102,
		HunterStoryRewardPopup = 0x00000103,
		HunterStoryRewindPopup = 0x00000104,
		GachaMain = 0x00000105,
		GachaDirection = 0x00000106,
		GatePotalNew = 0x00000107,
		HunterArtifactPopup = 0x00000108,
		LobbyUI_SJWWindow = 0x00000109,
		LobbyStateMenu = 0x0000010a,
		SmartPhone = 0x0000010b,
		Option = 0x0000010c,
		GroupStat = 0x0000010d,
		Lobby = 0x0000010e,
		Shop = 0x0000010f,
		SeasonPass = 0x00000110,
		Event = 0x00000111,
		TimeAttack = 0x00000112,
		StageReady = 0x00000113,
		SquadPresetSetting = 0x00000114,
		Craft = 0x00000115,
		Raid = 0x00000116,
		MainPcJob = 0x00000117,
		InstanceDungeon = 0x00000118,
		OtherWorldMain = 0x00000119,
		OtherWorldMap = 0x0000011a,
		WorldBoss = 0x0000011b,
		WorldBossEnd = 0x0000011c,
		InventoryWeapon = 0x0000011d,
		Tower = 0x0000011e,
		InteractionDialog = 0x0000011f,
		ChallengeMission = 0x00000120,
		TutorialReplay = 0x00000121,
		MonsterCollection = 0x00000122,
		Collection = 0x00000123,
		CollectionList = 0x00000124,
		CollectionHunter = 0x00000125,
		CollectionShadow = 0x00000126,
		CollectionWeapon = 0x00000127,
		CollectionArtifact = 0x00000128,
		CollectionItem = 0x00000129,
		CollectionRune = 0x0000012a,
		BattleClass = 0x0000012b,
		HunterSkin = 0x0000012c,
		IdleSystem = 0x0000012d,
		ItemDimension = 0x0000012e,
		ItemGem = 0x0000012f,
		StoryQuestChapter = 0x00000130,
		GateMining = 0x00000131,
		GateMiningAllReward = 0x00000132,
		Profile = 0x00000133,
		Fate = 0x00000134,
		FateInfoDetail = 0x00000135,
		AttendanceMain = 0x00000136,
		AttendanceGreeting = 0x00000137,
		Combine = 0x00000138,
		CombineSelectPopup = 0x00000139,
		CommonUIOneCostPopup = 0x0000013a,
		CommonUIOneCost2Popup = 0x0000013b,
		CraftItemUsePopup = 0x0000013c,
		CommonUIOneStackPopup = 0x0000013d,
		CurrencyPurchasePopup = 0x0000013e,
		CurrencyChargePopup = 0x0000013f,
		LobbyAlarmUIPopup = 0x00000140,
		LobbyAlarmNotiPopup = 0x00000141,
		AdventDungeon = 0x00000142,
		SecretFile = 0x00000143,
		LobbyUI = 0x00000144,
		BattleUI = 0x00000145,
		CommonStatChange = 0x00000146,
		RecommendEquip = 0x00000147,
		IndicatorLoading = 0x00000148,
		IndicatorSDKWait = 0x00000149,
		SkillReward = 0x0000014a,
		ScreenEffect = 0x0000014b,
		Blocking = 0x0000014c,
		RecommendedPowerPopup = 0x0000014d,
		BoxOpenPopup = 0x0000014e,
		Production = 0x0000014f,
		StageInformationDetail = 0x00000150,
		Ranking = 0x00000151,
		RankingDetail = 0x00000152,
		TimeAttackSelect = 0x00000153,
		TimeAttackRelay = 0x00000154,
		StageDetailInfo = 0x00000155,
		TimeAttackMyRecordPopup = 0x00000156,
		TimeAttackToastPopup = 0x00000157,
		ChaosBattleField = 0x00000158,
		ChaosBattleFieldSelect = 0x00000159,
		WeaponArmory = 0x0000015a,
		WeaponArmoryDetail = 0x0000015b,
		ArmoryEnhancePopup = 0x0000015c,
		ArmoryEnhanceResultPopup = 0x0000015d,
		ArmoryPowerInfoPopup = 0x0000015e,
		ArmoryStatDetailPopup = 0x0000015f,
		CommonUIItemBuy2Popup = 0x00000160,
		TimeAttackSeasonEndPopup = 0x00000161,
		TimeAttackSeasonInfoPopup = 0x00000162,
		TimeAttackSeason = 0x00000163,
		TimeAttackRelayStage = 0x00000164,
		RewardDirection = 0x00000165,
		CapsuleDrawEventReward = 0x00000166,
		EventRPSRankingPopup = 0x00000167,
		ScreenTransitionPopup = 0x00000168,
		EventMissionPopup = 0x00000169,
		DialogLogPopup = 0x0000016a,
		MAX = 0x0000016b,
	};

	struct UIElement__Fields
	{
		struct MonoBehaviour__Fields _;
		bool _HFFLADFKODO_k__BackingField;
		bool isPushed;
		bool isShowed;
		bool JKCPLOPKAIK;
	};

	struct UIElement
	{
		struct UIElement__Class* klass;
		MonitorData* monitor;
		struct UIElement__Fields fields;
	};

	struct UIPageBase__Fields
	{
		struct UIElement__Fields _;
		struct RectTransform* cursorArea;
		eUIType__Enum KDDJIEAFDBO;
		struct UIAnimator* MPOOHFBHKPN;
	};

	struct UIPageBase
	{
		struct UIPageBase__Class* klass;
		MonitorData* monitor;
		struct UIPageBase__Fields fields;
	};

	struct UIPage__Fields
	{
		struct UIPageBase__Fields _;
		struct List_1_NGame_UISubView_* DECDGNMJOCP;
		bool IsPopupView;
		bool isFullScreenUI;
	};

	struct UIPage
	{
		struct UIPage__Class* klass;
		MonitorData* monitor;
		struct UIPage__Fields fields;
	};

	enum class eBattleSquadType__Enum : int16_t
	{
		None = 0x0000,
		Temp_MainPC = 0x0001,
		Temp_Hunter = 0x0002,
		MainStroy_MainPC = 0x0003,
		Gate_MainPC = 0x0004,
		Gate_Hunter = 0x0005,
		RedGate_MainPC = 0x0006,
		RedGate_Hunter = 0x0007,
		DungeonBreak_MainPC = 0x0008,
		DungeonBreak_Hunter = 0x0009,
		InstanceDungeon_MainPC = 0x000a,
		InstanceDungeon_Hunter = 0x000b,
		TrainingRoom_MainPC = 0x000c,
		TrainingRoom_Hunter = 0x000d,
		EventDungeon_MainPC = 0x000e,
		EventDungeon_Hunter = 0x000f,
		TimeAttack_MainPC = 0x0010,
		TimeAttack_Hunter = 0x0011,
		WorldBoss_MainPC = 0x0012,
		WorldBoss_Hunter = 0x0013,
		Raid_MainPC = 0x0014,
		Raid_Hunter = 0x0015,
		Tower_MainPC = 0x0016,
		Tower_Hunter = 0x0017,
		OtherWorld_MainPC = 0x0018,
		OtherWorld_Hunter = 0x0019,
		SubStroy_Hunter = 0x001a,
		AdventDungeon_MainPC = 0x001b,
		AdventDungeon_Hunter = 0x001c,
		MainStroy_Hunter = 0x001d,
		SubStroy_MainPC = 0x001e,
		SystemDeck_Player = 0x001f,
		SystemDeck_Hunter = 0x0020,
		JobChange_MainPC = 0x0021,
		TimeAttackRelay_MainPC = 0x0022,
		TimeAttackRelay_Hunter = 0x0023,
		HunterStory_Hunter = 0x0024,
		SpecialGate_MainPC = 0x0025,
		SpecialGate_Hunter = 0x0026,
		HunterExperience = 0x0027,
		ChaosBattleField_MainPC = 0x0028,
		ChaosBattleField_Hunter = 0x0029,
		Max = 0x002a,
	};

	enum class eBattleTeamType__Enum : uint8_t
	{
		SJWTeam = 0x00,
		HunterTeam = 0x01,
		Max = 0x02,
	};

	enum class NCMFGLJMIFJ_OFGDNPNIFOJ__Enum : int32_t
	{
		NONE = -1,
		EMPTY = 0x00000000,
		INTRO = 0x00000001,
		TITLE = 0x00000002,
		PATCH = 0x00000003,
		LOGIN = 0x00000004,
		LOBBY = 0x00000005,
		WORLD = 0x00000006,
		GAMETEST = 0x00000007,
		SUBSTART = 0x0000000a,
		SUBTEAMSTORY = 0x0000000b,
		SUBTEAMGATE = 0x0000000c,
		SUBUICOMMON = 0x0000000d,
		SUBDIALOG = 0x0000000e,
		SUBGROWTHINVEN = 0x0000000f,
		SUBMAINJOB = 0x00000010,
		SUBCOSTUME = 0x00000011,
		SUBGACHA = 0x00000012,
		SUBPROFILE = 0x00000013,
		SUBCOLLECTION = 0x00000014,
		SUBSHADOWEXTRACTION = 0x00000015,
		SUBINVENHUNTER = 0x00000016,
		SUBCOLLECTHUNTER = 0x00000017,
		SUBCOLLECTSHADOW = 0x00000018,
		SUBJOBCHANGE = 0x00000019,
		SUBSQUADPRESET = 0x0000001a,
		SUBWORLDBOSS = 0x0000001b,
		SUBGROWTHCRAFT = 0x0000001c,
		SUBINVENWEAPON = 0x0000001d,
		SUBEVENTRPS = 0x0000001e,
		SUB_MAX = 0x0000001f,
	};

	struct StageReadyPage__Fields
	{
		struct UIPage__Fields _;
		struct Image* m_pBGImg;
		struct StageInfoUI* m_stageInfoUI;
		struct SquadInfoUI* m_squadInfoUI;
		struct UIChar3DPositionSetting* char3DPositionSetting;
		eBattleSquadType__Enum EIMKAHCHPGP;
		eBattleTeamType__Enum AKIOKCBHJML;
		struct JJIJKBGACGB* LCPFKKDHDGD;
		struct DungeonStageData* FHMGDAMDBHG;
		NCMFGLJMIFJ_OFGDNPNIFOJ__Enum NJIPKOGOLMI;
		struct GIKAPOHKJIE* GNGFDFBMJAC;
		struct DEGLOKMJBBI* GPCOJCNAOPO;
		struct OCJMNBLPDKO* HPMHHDBHKGE;
	};

	struct StageReadyPage
	{
		struct StageReadyPage__Class* klass;
		MonitorData* monitor;
		struct StageReadyPage__Fields fields;
	};

	enum class EQuestStoryModeType__Enum : uint8_t
	{
		None = 0x00,
		Default = 0x01,
		Reverse = 0x02,
		Max = 0x03,
	};

	enum class EQuestStoryDifficultyType__Enum : uint8_t
	{
		None = 0x00,
		Normal = 0x01,
		Hard = 0x02,
		VeryHard = 0x03,
		Reverse = 0x04,
		ReverseHard = 0x05,
		ReverseVeryHard = 0x06,
		Max = 0x07,
	};

	struct StoryQuestChapterPage__Fields
	{
		struct UIPage__Fields _;
		struct UIContentsUnlockItem* ContentsUnlockItem;
		struct UIGraph* HLMFGMDDAKK;
		struct StoryQuestChapterListItem* FCBKMDAAGJM;
		struct StoryQuestChapterListItem* OGKFCDNBFKF;
		struct StoryQuestChapterListItem* ScrollListNoticeChapterItem;
		struct StoryQuestDifficultyTypeGroup* HPGPMDGOBDH;
		struct Button* HEIJCLLJFPG;
		struct Button* BtnProgressFocus;
		struct UIMusicPlayer__Array* MusicPlayerList;
		struct StoryQuestChpaterModeInfo* NCHNBMHIPEJ;
		EQuestStoryModeType__Enum KELBEBBNPDA;
		EQuestStoryDifficultyType__Enum PGNMMGJMGPI;
		struct ContentMenuTabGroup* m_ContentMenuTabGroup;
		struct Image__Array* backGroundImages;
		struct PGCIJEIMPKB* DKDPEDKNJHN;
		struct PHFECEJNAML* NLBDIENNAEJ;
		bool NKBDMIPCCPA;
		struct Vector3 FLCIAGINIBG;
		struct Coroutine* PMNPICKHKKK;
		struct RectTransform* CFPOEKLCAFD;
		struct AnimationCurve* focusSpeedCurve;
		struct RectTransform* MHODEEBGDDA;
	};

	struct StoryQuestChapterPage
	{
		struct StoryQuestChapterPage__Class* klass;
		MonitorData* monitor;
		struct StoryQuestChapterPage__Fields fields;
	};

	enum class GameMovie_PHMCJCHPFEF__Enum : int32_t
	{
		INIT = 0x00000000,
		PREPARE = 0x00000001,
		MOVIEPLAY = 0x00000002,
		LOGOSHOW = 0x00000003,
		FINISH = 0x00000004,
		END = 0x00000005,
	};

	struct GameMovie__Fields
	{
		struct MonoBehaviour__Fields _;
		struct Camera* pkCamera;
		struct Image* pkMovieMask;
		struct Button* pkSkipMovie;
		struct VideoPlayer* EOOLJGDCGNF;
		GameMovie_PHMCJCHPFEF__Enum EGHCFMDLNAB;
		bool NFNHAJGMBKH;
	};

	struct GameMovie
	{
		struct GameMovie__Class* klass;
		MonitorData* monitor;
		struct GameMovie__Fields fields;
	};

	enum class IntroMovie_MHCMCCIDDCE__Enum : int32_t
	{
		INIT = 0x00000000,
		PREPARE = 0x00000001,
		MOVIEPLAY = 0x00000002,
		LOGOSHOW = 0x00000003,
		FINISH = 0x00000004,
		END = 0x00000005,
	};

	struct IntroMovie__Fields
	{
		struct MonoBehaviour__Fields _;
		struct SequentialPlayer* _player;
		struct Image* pkIntroBG;
		struct Button* pkSkipButton;
		IntroMovie_MHCMCCIDDCE__Enum GFOGMEGIEJN;
		bool NFNHAJGMBKH;
	};

	struct IntroMovie
	{
		struct IntroMovie__Class* klass;
		MonitorData* monitor;
		struct IntroMovie__Fields fields;
	};

	struct CinemachineBlendDefinition
	{
		//CinemachineBlendDefinition_Style__Enum m_Style;
		//float m_Time;
		//struct AnimationCurve* m_CustomCurve;
	};

	struct BattleCamRootControl__Fields
	{
		struct MonoBehaviour__Fields _;
		struct String* findTargetBoneName;
		struct CinemachineTargetGroup* m_pTargetGroupObject;
		struct BattleCamMomentLockOn* m_pMomentLockOnCam;
		struct BattleCamManual* m_pManualCam;
		struct InteractionCamera* m_pInteractionCam;
		struct TargetGroupDefault* m_pTargetGroupDefaultCam;
		struct List_1_NGame_TargetGroupLockOn_* m_lstLockOnMember;
		struct BattleResultCam* m_BattleResultCam;
		struct SpecialLockOnCam* m_SpecialLockOnCam;
		bool GOGIGFKDGCK;
		bool LJPAGNLFGCG;
		float JJKBHIAFDEI;
		int32_t m_nNormalLockOnCamIndex;
		float m_fCameraActionCharRotTime;
		struct CinemachineBlendDefinition m_InputBackBlend;
		struct Vector2 m_vInputLimitDelta;
		struct Vector2 LDOHJMNOFOP;
		float m_DeltaMulValue;
		float m_fInputCheckTime;
		float DNFFIGKPGPH;
		struct TargetGroupLockOn* CFOLHNFGNGP;
		struct GameObject* NLIHDFDMKOG;
		struct CinemachineVirtualCameraBase* NAAMFHLDGKI;
		struct GameObject* GPMICBKMPEH;
		int32_t JBHOKGKNOOO;
		struct ENNEJEPMJLJ* player;
		struct Transform* FLHGBKCGEEJ;
		struct ENNEJEPMJLJ* target;
		float NENNLECCLBP;
		struct GameObject* PDGDNGJOMII;
		struct Coroutine* LOMGCDOILPH;
		float DBPKALIOBOG;
		bool OLJIIFFBAHM;
		bool HNKKNLBPIGE;
		bool CALIDDKBNNH;
		bool OJJOIMNEFPD;
		int32_t LOHMOFNPJKI;
		struct List_1_ENNEJEPMJLJ_* PEIBANIEKIE;
		struct SortedDictionary_2_System_Int32_List_1_ENNEJEPMJLJ_* AFPBKILHMAH;
		struct List_1_ENNEJEPMJLJ_* KNGFNGGJAGL;
		struct List_1_ENNEJEPMJLJ_* PFIPCAFNJMC;
		struct List_1_ENNEJEPMJLJ_* NIONMPMHJAM;
		struct List_1_UnityEngine_GameObject_* ONHIHPLOJMK;
		struct List_1_Cinemachine_CinemachineVirtualCamera_* MDCFJMCKNPK;
		struct Vector3 DDJOHJJLPHF;
		struct Vector3 NBBHGFDODFP;
		bool CBAAAMGOKBL;
		struct Vector3 GGGAAILLHGE;
		struct Quaternion KIEIHCGHOOE;
		struct Quaternion DHJDFMIDALJ;
		bool KCAILMDKHMF;
		float LMAAFNMNDBB;
		float MHLLMIDCFNH;
		float KIEPJGILPEO;
		float m_fCurrentCamRotationTime;
		struct FXBase* KAHMMHAOLMD;
		struct String* JCIBEIPKAKF;
		struct CameraTargetChecker* HFECCDEFDAF;
		struct MapFixCamera* CFAEHEJDNIH;
		float HJNBPAJEPBO;
		struct CinemachineFramingTransposer* OBHIKGDBAHK;
		float NNGPEJFMOBE;
		bool NOCMCOLDEFN;
		float m_AutoZoomChangeDist;
		float m_AutoZoomChangeTime;
		float FHPAOBIJEAG;
		bool CFBBHAGBGOA;
		bool HOAAENPFOKI;
	};

	struct BattleCamRootControl
	{
		struct BattleCamRootControl__Class* klass;
		MonitorData* monitor;
		struct BattleCamRootControl__Fields fields;
	};

	struct __declspec(align(8)) IFCGLMJJCGF__Fields // BattleConfig
	{
		float HNJHJDJHOGP;
		float NMBDKEDIBBE;
		int32_t IEJLCNKFHFP;
		int32_t LCCGPOIHPIJ;
		float EIJPGMGMKNF;
		float CEOCOGLPAEA;
		float JEGMDJFBOGM;
		float KAGPOAIOBCA;
		float IFALNCPAMEM;
		float BIDEFNFJJMN;
		float IHPECEFOLCE;
		float BOKOCDCOCMB;
		int32_t CINFGBIOACJ;
		int32_t EHEEAJGGIAB;
		int32_t OEEDPJCNNHN;
		int32_t MHPAIFPBPBC;
		float LFGGEKJELAI;
		float ACPLALBPHPG;
		float KJECCBCPJOL;
		float AMLMGAJBECK;
		int32_t ANFLCFMKGHD;
		int32_t HGOMFNIIPDF;
		int32_t OMOFKFDOLFP;
		float FMKMMHPMMGO;
		int32_t BFMGBDPFJCN;
		float MGIJIIBNPFG;
		int64_t JIODEFOCKPP;
		float CBGINNHFAAH;
		int64_t LFOCINOLENF;
		float ECALFEONCLK;
		float AMFOJHPPIDN;
		float LICKIOEFEJO;
		float CNNFHNBCMPD;
		float KGFAFMKPICK;
		float PLEHPCECGOH;
		float PCCFOMNBAIE;
		float BCLHPGLIBLF;
		float BNOHFCIMEBA;
		float LLJCDAFODCD;
		float IELCKNGOKGD;
		float IBLPBLJDOEP;
		int32_t GGIDCGOJNKG;
		int32_t AJLIMGHGELA;
		float LBGDPIJDHBD;
		float PHDPLOPLCMH;
		int64_t IHEGJPGDOFO;
		struct String* AKIDDPPCHCO;
		struct String* OGHKKHNPIMP;
		float GKCFPHPPKKL;
		struct String* ANPKMHAKDFH;
		struct String* CIAAGDGNKIB;
		float AJLLKEJCEIO;
		float JJCIFBCIBIH;
		float KCPGKBCIEBC;
		struct String* HFCNFCHFFBP;
		struct String* JOHIKIDOGKM;
		struct String* JMJCOAOFLFI;
		struct String* BPPHEJPBFPJ;
		struct String* PJAPILAAHHB;
		int64_t POCDCHCHKNM;
		int64_t PAHFNNPOGOP;
		float OBMBGGJAFKM;
		int32_t FNNHAHNLAPJ;
		struct List_1_System_Single_* NJLNEDGDFLL;
		float LCMJMHJCHIP;
		float HNDGFGOLNKA;
		float MKLBMMOKNFJ;
		float LDMCMKPOJBG;
		float BKPGFABLCMG;
		struct List_1_System_Int64_* BHHAAHMBBIC;
		float DGKNEKLDALE;
		float GAIPJFLDIOO;
		float KMBCFOKDDCJ;
		int32_t JOEDAHPCBLP;
		float MIAJCPMEFBN;
		float HBCLFDIFOII;
		struct List_1_System_Single_* GDGHKCNIAHB;
		struct List_1_System_Int32_* NDOJEMJBCPL;
		float ABNPNFNFDBF;
		float OBFAHAIICHD;
		float GAHMBGENNLL;
		float HKEOMEIKELG;
		float JLNAGOONLDB;
		float AGIFJAMDKHB;
		struct List_1_System_Single_* MBBDMOFMNAL;
		float EAKONLCHEPF;
		float LNIDLJCFKHJ;
		float DNIDGEEMBKI;
		float ONNNCKCCADK;
		int32_t HEBINALHJFF;
		float PGOHCCOHLGK;
		float HMLJKNHEEPH;
		int32_t DGLICJBJGLD;
		int32_t OIHDIOADOFH;
		float OBHBOAAHBJB;
		float BBDAMOMBIBD;
		int32_t HBJGMALLHAH;
		int32_t BOIOGMCKDGF;
		int32_t EPEMFIJMFBB;
		int32_t FOHONLBJCCO;
		int32_t MFMDNBDAADK;
		int32_t IFGHIPABEHD;
		int32_t EDHJDGKBFKJ;
		int32_t CPICGLLGMNC;
		float LGBDCIFJHOD;
		float ACAPEILLAAJ;
		float PKGBGIFPKEE;
		float BAMCJMKBGPP;
		float BLGAMCNBPDF;
		int32_t HOAIHIAPFAH;
		float CKBCGGGGINJ;
		int32_t AJJPMEKKMHM;
		float KCEHHDAFGPM;
		float JKINIEBJAFB;
		float NKHCNNFGBPH;
		float NGNCPNOODLJ;
		float GEDAAFNNJIJ;
		float GNJAACJLDOF;
		struct List_1_List_1_System_Single_* BDAPGIACPAG;
		struct List_1_List_1_System_Single_* NMPKCGBEGJJ;
		int32_t BOGAJNJNMPK;
		float MAEGOMCEFNN;
	};

	struct IFCGLMJJCGF
	{
		struct IFCGLMJJCGF__Class* klass;
		MonitorData* monitor;
		struct IFCGLMJJCGF__Fields fields;
	};

	struct GameFrameWork__Fields
	{
		struct MonoBehaviour__Fields _;
		bool IsQuit;
		NCMFGLJMIFJ_OFGDNPNIFOJ__Enum SceneMode;
		struct AudioListener* pkAudioListener;
		struct Camera* pkMainCamera;
		struct Camera* pkUICamera;
		struct Camera* pkSubCamera;
		struct Canvas* pkSpineCanvas;
		struct GameObject* pkSpineLetterBox;
		struct GameObject* pkRootCanvas;
		struct GameObject* pkEffectRoot;
		struct GameObject* pkSoundRoot;
		struct GameObject* pkSpawnPoolsRoot;
		struct GameObject* pkProjectileRoot;
		struct Text* pkVersion;
		struct GameObject* pkBillboardRoot;
		struct LightingPlanData* defaultLightingPlanData;
		struct VolumeProfile* volumeFXProfile;
		struct GameObject* pkScreenUITouchEffect;
		struct GameObject* pkScreenUILongTouchEffect;
		struct UITooltip* pkUITooltip;
		bool m_bIsFocusOut;
	};

	struct GameFrameWork
	{
		struct GameFrameWork__Class* klass;
		MonitorData* monitor;
		struct GameFrameWork__Fields fields;
	};

	enum class EGLGAPIAANF__Enum : int32_t
	{
		None = 0x00000000,
		EnterBattleReqProcess = 0x00000001,
		ShowBattleEnterUI = 0x00000002,
		EnterBattleReq = 0x00000003,
		EnterBattle = 0x00000004,
		RetryBattle = 0x00000005,
		NextStageBattle = 0x00000006,
		LeaveBattle = 0x00000007,
		BattleResultReq = 0x00000008,
		CompleteBattle = 0x00000009,
		StageStart = 0x0000000a,
	};

	struct __declspec(align(8)) JIBDAHKJHOG__Fields
	{
		struct JJIJKBGACGB *LCPFKKDHDGD;
		struct LJAKACHOOMI *LLOEJODNEDM;
		EGLGAPIAANF__Enum ODBFJKNANFA;
		struct List_1_JPGHFENPLMH_ *PLMEENHOBMB;
	};

	struct JIBDAHKJHOG
	{
		struct JIBDAHKJHOG__Class *klass;
		MonitorData *monitor;
		struct JIBDAHKJHOG__Fields fields;
	};

	enum class EBuffLargeType__Enum : int32_t
	{
		None = 0x00000000,
		Buff = 0x00000001,
		DeBuff = 0x00000002,
		Passive = 0x00000003,
		Special = 0x00000004,
		ShadowOnly = 0x00000005,
		Max = 0x00000006,
	};

	enum class EStatType__Enum : uint8_t
	{
		None = 0x00,
		Att = 0x01,
		AddAtt = 0x02,
		AttR = 0x03,
		AttFR = 0x04,
		Arm = 0x05,
		ArmR = 0x06,
		AddArm = 0x07,
		ArmFR = 0x08,
		MHP = 0x09,
		MHPR = 0x0a,
		AddMHP = 0x0b,
		MHPFR = 0x0c,
		Critical = 0x0d,
		CriticalP = 0x0e,
		CriticalRes = 0x0f,
		CriDam = 0x10,
		CriDamP = 0x11,
		CriDamRes = 0x12,
		Precision = 0x13,
		PrecisionP = 0x14,
		MMP = 0x15,
		MMPR = 0x16,
		AddMMP = 0x17,
		MPRegen = 0x18,
		MPRegenR = 0x19,
		MPCostRedu = 0x1a,
		MPCostReduP = 0x1b,
		MoveSpd = 0x1c,
		MoveSpdR = 0x1d,
		AttSpd = 0x1e,
		AttSpdP = 0x1f,
		CoolRedu = 0x20,
		CoolReduP = 0x21,
		ArmPen = 0x22,
		ArmPenP = 0x23,
		Dam = 0x24,
		DamP = 0x25,
		DamRedu = 0x26,
		DamReduP = 0x27,
		ReceiveHealIncre = 0x28,
		ReceiveHealIncreP = 0x29,
		HealIncre = 0x2a,
		HealIncreP = 0x2b,
		DebuffRecovery = 0x2c,
		DebuffRecoveryP = 0x2d,
		ElementDamFire = 0x2e,
		ElementDamFireP = 0x2f,
		ElementDamWater = 0x30,
		ElementDamWaterP = 0x31,
		ElementDamWind = 0x32,
		ElementDamWindP = 0x33,
		ElementDamLight = 0x34,
		ElementDamLightP = 0x35,
		ElementDamDarkness = 0x36,
		ElementDamDarknessP = 0x37,
		CriChanceWeight = 0x38,
		DebuffStateIgnoreP = 0x39,
		DebuffStateDurationReduP = 0x3a,
		HealP = 0x3b,
		CriticalResP = 0x3c,
		CriticalDamResP = 0x3d,
		Max = 0x3e,
	};

	enum class EStatStandard__Enum : uint8_t
	{
		Target = 0x00,
		Caster = 0x01,
		Max = 0x02,
	};

	enum class ETriggeredBuffCondition__Enum : uint8_t
	{
		None = 0x00,
		CastSkill = 0x01,
		CastDash = 0x02,
		HitTarget = 0x03,
		Hit = 0x04,
		CriticalHitTarget = 0x05,
		CriticalHit = 0x06,
		Die = 0x07,
		EnemyDie = 0x08,
		BuffStackCount = 0x09,
		BuffOff = 0x0a,
		HpCheck = 0x0b,
		MpCheck = 0x0c,
		Dispel = 0x0d,
		HitReaction = 0x0e,
		HitTargetAC = 0x0f,
		HitAC = 0x10,
		CriticalHitTargetAC = 0x11,
		CriticalHitAC = 0x12,
		TagIn = 0x13,
		TagOut = 0x14,
		HitTargetBuffGroup = 0x15,
		CriticalHitTargetBuffGroup = 0x16,
		HitTargetACBuffGroup = 0x17,
		CriticalHitTargetACBuffGroup = 0x18,
		HitBuffGroup = 0x19,
		CriticalHitBuffGroup = 0x1a,
		HitACBuffGroup = 0x1b,
		CriticalHitACBuffGroup = 0x1c,
		SpecialCancel = 0x1d,
		BackAttackHitTarget = 0x1e,
		CriticalHitMonsterGrade = 0x1f,
		CriticalHitACMonsterGrade = 0x20,
		ShieldOn = 0x21,
		ShieldOff = 0x22,
		HitTargetBreakBarrier = 0x23,
		HitBreakBarrier = 0x24,
		BreakHitTargetBuffGroup = 0x25,
		BreakHitTargetACBuffGroup = 0x26,
		BodyStopOn = 0x27,
		HitMainPcTarget = 0x28,
		HitMainPcTargetAC = 0x29,
		Max = 0x2a,
	};

	struct __declspec(align(8)) KPBLHMGMKMK__Fields
	{
		int64_t BPCIGFKCFCI;
		int64_t EMGCBJJLLOD;
		int32_t FIHELFIMKHO;
		struct String* EDJBLODMLBO;
		bool LOMMEDCNAHL;
		int32_t IEBJKOGEDMM;
		struct String* FAONGKOGAJI;
		EBuffLargeType__Enum CALDGMDGFLO;
		bool LLNAMEPPOCH;
		int32_t OMPONCANEDE;
		bool IGAFCNECCHC;
		int32_t PJELOKAGJDI;
		int32_t LEBPOCIOJCK;
		int32_t PNADADLNDIF;
		EStatType__Enum MJNNMKGNAAB;
		int32_t NJDPHNEBLEK;
		EStatStandard__Enum FHDGDOIADBH;
		EStatType__Enum ECNPKGPPGIH;
		int32_t OGFIOGCHJFH;
		EStatStandard__Enum CCCMIMLMPEO;
		EStatType__Enum MDKGGAAHKMO;
		int32_t KMGECGEGEPC;
		EStatStandard__Enum ELFBOMFFGJB;
		struct ESpecialState__Enum__Array* GJFKHGJCOCF;
		struct String__Array* CFENJKJPHDE;
		ESpecialState__Enum NCCOIJKJNLO;
		int64_t EPPGAOJILJL;
		int64_t BCFGDHOKJPI;
		int64_t HPKEEOFMHCH;
		struct String* HHKMKCNDFNC;
		ESpecialState__Enum CAFNJABEDFF;
		int64_t HOKBDAOGGEK;
		int64_t LLFABICDAEB;
		int64_t OMCCDCJJHLK;
		struct String* KMEMJFHNNAM;
		ESpecialState__Enum FMDPJKICDMF;
		int64_t CMJDEPGEELJ;
		int64_t BLBAFGPEGAF;
		int64_t ENLNBJGAOPN;
		struct String* EFGEONAHHLN;
		ETriggeredBuffCondition__Enum FHOOOCHPEHP;
		bool DKCFNAFGION;
		struct Int64__Array* FINHHLNECFE;
		int32_t CKNDJLADOCB;
		int32_t BAFDNKDMDHA;
		int32_t COPFMFIFPLO;
		int64_t OMKGNFFCNPF;
		int64_t KMKLEMALLOL;
		int64_t OPKLLHCMFNC;
		int64_t KGHCMCIBMHJ;
		int64_t HGJOHLFHJEL;
		struct String* LONCAAFCDFF;
		struct String* JHJNLIFGNDB;
	};

	struct KPBLHMGMKMK
	{
		struct KPBLHMGMKMK__Class* klass;
		MonitorData* monitor;
		struct KPBLHMGMKMK__Fields fields;
	};

	struct Animator__Fields
	{
		struct Behaviour__Fields _;
	};

	struct Animator
	{
		struct Animator__Class* klass;
		MonitorData* monitor;
		struct Animator__Fields fields;
	};

	struct __declspec(align(8)) OKDBDHFKIKF__Fields
	{
		int32_t GKCDKEJJPFP;
		struct List_1_ENNEJEPMJLJ_* KKKLEDCOGAH;
	};

	struct OKDBDHFKIKF
	{
		struct OKDBDHFKIKF__Class* klass;
		MonitorData* monitor;
		struct OKDBDHFKIKF__Fields fields;
	};

	struct PNECDHFEEGD__Fields
	{
		struct ENNEJEPMJLJ__Fields _;
		struct CharMonsterData* KAHOMEPMEFG;
		struct CharResourceData* DGNOCKOMMMD;
		struct List_1_ENNEJEPMJLJ_* DABFJBKNFOO;
	};

	struct PNECDHFEEGD
	{
		struct PNECDHFEEGD__Class* klass;
		MonitorData* monitor;
		struct PNECDHFEEGD__Fields fields;
	};

	struct InGameObject__Fields
	{
		struct MonoBehaviour__Fields _;
		struct ENNEJEPMJLJ* GMLNFEKCPDB;
		eCharGroup__Enum m_charGroup;
		float m_fDuration;
		struct List_1_UnityEngine_Collider_* FOOFKMKMMBK;
		float LAMGMNNOCBI;
	};

	struct InGameObject
	{
		struct InGameObject__Class* klass;
		MonitorData* monitor;
		struct InGameObject__Fields fields;
	};

	struct __declspec(align(8)) ENHPKNIEKMI__Fields
	{
		struct NMOJHKDGBKI* BJNPPIBEHDC;
		struct NMOJHKDGBKI* HEDKOOOBALG;
		struct NMOJHKDGBKI* LCPAKHGCIIO;
		struct NMOJHKDGBKI* PJHNJFECEDK;
		struct NMOJHKDGBKI* EJEPDHJAHFF;
		struct NMOJHKDGBKI* FACECGELJJK;
		float LNPIOKPPIGM;
		float FKHANCNMKNH;
	};

	struct ENHPKNIEKMI
	{
		struct ENHPKNIEKMI__Class* klass;
		MonitorData* monitor;
		struct ENHPKNIEKMI__Fields fields;
	};

	struct ModelContainer__Fields
	{
		struct MonoBehaviour__Fields _;
		struct CachedComponent_1_UnityEngine_Transform_* CGMBGKPEHDL;
		struct CachedComponent_1_UnityEngine_Transform_* CKIAKFKBKFI;
		struct CachedComponent_1_UnityEngine_Transform_* AOOKBIBLNPF;
		struct CachedComponent_1_UnityEngine_Collider_* BOIKMOCLICI;
		struct CachedComponent_1_UnityEngine_Animator_* EMKPLCDDJAF;
		struct CachedComponent_1_UnityEngine_Transform_* JFIPHCCEKFE;
		struct CachedComponent_1_UnityEngine_Transform_* IMFMNGPHIAH;
		struct CachedComponent_1_UnityEngine_SkinnedMeshRenderer_* GPFCIAOIAMO;
		struct CachedComponent_1_UnityEngine_SkinnedMeshRenderer_* CMGFGABAECP;
		struct CachedComponent_1_UnityEngine_Transform_* DDEKGOLFLIF;
		struct CachedComponent_1_UnityEngine_Transform_* KPNKKCDGHHD;
		struct CachedComponent_1_UnityEngine_Transform_* FBJGBNNGELP;
	};

	struct ModelContainer
	{
		struct ModelContainer__Class* klass;
		MonitorData* monitor;
		struct ModelContainer__Fields fields;
	};

#if !defined(_GHIDRA_) && !defined(_IDA_)
}
#endif