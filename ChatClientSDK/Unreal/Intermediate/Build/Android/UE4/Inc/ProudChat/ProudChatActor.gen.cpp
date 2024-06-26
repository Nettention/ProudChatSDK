// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ProudChat/Public/ProudChatActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProudChatActor() {}
// Cross Module References
	PROUDCHAT_API UEnum* Z_Construct_UEnum_ProudChat_EMsgType();
	UPackage* Z_Construct_UPackage__Script_ProudChat();
	PROUDCHAT_API UScriptStruct* Z_Construct_UScriptStruct_FMsgRecords();
	PROUDCHAT_API UScriptStruct* Z_Construct_UScriptStruct_FMsgRecord();
	PROUDCHAT_API UClass* Z_Construct_UClass_AProudChatActor_NoRegister();
	PROUDCHAT_API UClass* Z_Construct_UClass_AProudChatActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static UEnum* EMsgType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_ProudChat_EMsgType, Z_Construct_UPackage__Script_ProudChat(), TEXT("EMsgType"));
		}
		return Singleton;
	}
	template<> PROUDCHAT_API UEnum* StaticEnum<EMsgType>()
	{
		return EMsgType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EMsgType(EMsgType_StaticEnum, TEXT("/Script/ProudChat"), TEXT("EMsgType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_ProudChat_EMsgType_Hash() { return 1616942781U; }
	UEnum* Z_Construct_UEnum_ProudChat_EMsgType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_ProudChat();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EMsgType"), 0, Get_Z_Construct_UEnum_ProudChat_EMsgType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EMsgType::None", (int64)EMsgType::None },
				{ "EMsgType::Direct", (int64)EMsgType::Direct },
				{ "EMsgType::Channel", (int64)EMsgType::Channel },
				{ "EMsgType::Notice", (int64)EMsgType::Notice },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "Bitflags", "" },
				{ "Channel.Name", "EMsgType::Channel" },
				{ "Direct.Name", "EMsgType::Direct" },
				{ "ModuleRelativePath", "Public/ProudChatActor.h" },
				{ "None.Name", "EMsgType::None" },
				{ "Notice.Name", "EMsgType::Notice" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_ProudChat,
				nullptr,
				"EMsgType",
				"EMsgType",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FMsgRecords::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PROUDCHAT_API uint32 Get_Z_Construct_UScriptStruct_FMsgRecords_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMsgRecords, Z_Construct_UPackage__Script_ProudChat(), TEXT("MsgRecords"), sizeof(FMsgRecords), Get_Z_Construct_UScriptStruct_FMsgRecords_Hash());
	}
	return Singleton;
}
template<> PROUDCHAT_API UScriptStruct* StaticStruct<FMsgRecords>()
{
	return FMsgRecords::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMsgRecords(FMsgRecords::StaticStruct, TEXT("/Script/ProudChat"), TEXT("MsgRecords"), false, nullptr, nullptr);
static struct FScriptStruct_ProudChat_StaticRegisterNativesFMsgRecords
{
	FScriptStruct_ProudChat_StaticRegisterNativesFMsgRecords()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MsgRecords")),new UScriptStruct::TCppStructOps<FMsgRecords>);
	}
} ScriptStruct_ProudChat_StaticRegisterNativesFMsgRecords;
	struct Z_Construct_UScriptStruct_FMsgRecords_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMsgRecords_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMsgRecords_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMsgRecords>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMsgRecords_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProudChat,
		nullptr,
		&NewStructOps,
		"MsgRecords",
		sizeof(FMsgRecords),
		alignof(FMsgRecords),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMsgRecords_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMsgRecords_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMsgRecords()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMsgRecords_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ProudChat();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MsgRecords"), sizeof(FMsgRecords), Get_Z_Construct_UScriptStruct_FMsgRecords_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMsgRecords_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMsgRecords_Hash() { return 1050206843U; }
class UScriptStruct* FMsgRecord::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern PROUDCHAT_API uint32 Get_Z_Construct_UScriptStruct_FMsgRecord_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FMsgRecord, Z_Construct_UPackage__Script_ProudChat(), TEXT("MsgRecord"), sizeof(FMsgRecord), Get_Z_Construct_UScriptStruct_FMsgRecord_Hash());
	}
	return Singleton;
}
template<> PROUDCHAT_API UScriptStruct* StaticStruct<FMsgRecord>()
{
	return FMsgRecord::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FMsgRecord(FMsgRecord::StaticStruct, TEXT("/Script/ProudChat"), TEXT("MsgRecord"), false, nullptr, nullptr);
static struct FScriptStruct_ProudChat_StaticRegisterNativesFMsgRecord
{
	FScriptStruct_ProudChat_StaticRegisterNativesFMsgRecord()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("MsgRecord")),new UScriptStruct::TCppStructOps<FMsgRecord>);
	}
} ScriptStruct_ProudChat_StaticRegisterNativesFMsgRecord;
	struct Z_Construct_UScriptStruct_FMsgRecord_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FMsgRecord_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FMsgRecord_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FMsgRecord>();
	}
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FMsgRecord_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_ProudChat,
		nullptr,
		&NewStructOps,
		"MsgRecord",
		sizeof(FMsgRecord),
		alignof(FMsgRecord),
		nullptr,
		0,
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FMsgRecord_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FMsgRecord_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FMsgRecord()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FMsgRecord_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_ProudChat();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("MsgRecord"), sizeof(FMsgRecord), Get_Z_Construct_UScriptStruct_FMsgRecord_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FMsgRecord_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FMsgRecord_Hash() { return 2344922441U; }
	DEFINE_FUNCTION(AProudChatActor::execK2_IsConnected)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_IsConnected();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_MsgRecord_Notice)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_day);
		P_GET_PROPERTY(FIntProperty,Z_Param_cnt);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_MsgRecord_Notice(Z_Param_day,Z_Param_cnt);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_MsgRecord_Channel)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_channelKey);
		P_GET_PROPERTY(FIntProperty,Z_Param_day);
		P_GET_PROPERTY(FIntProperty,Z_Param_cnt);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_MsgRecord_Channel(Z_Param_channelKey,Z_Param_day,Z_Param_cnt);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_MsgRecord_Direct)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_target);
		P_GET_PROPERTY(FIntProperty,Z_Param_day);
		P_GET_PROPERTY(FIntProperty,Z_Param_cnt);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_MsgRecord_Direct(Z_Param_target,Z_Param_day,Z_Param_cnt);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_MsgTranslate_Auto)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_target);
		P_GET_PROPERTY(FStrProperty,Z_Param_msgKey);
		P_GET_PROPERTY(FStrProperty,Z_Param_msg);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_MsgTranslate_Auto(Z_Param_target,Z_Param_msgKey,Z_Param_msg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_MsgTranslate)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_src);
		P_GET_PROPERTY(FStrProperty,Z_Param_target);
		P_GET_PROPERTY(FStrProperty,Z_Param_msgKey);
		P_GET_PROPERTY(FStrProperty,Z_Param_msg);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_MsgTranslate(Z_Param_src,Z_Param_target,Z_Param_msgKey,Z_Param_msg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_SendChannelMsg)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_channelKey);
		P_GET_PROPERTY(FStrProperty,Z_Param_msg);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_SendChannelMsg(Z_Param_channelKey,Z_Param_msg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_SendDirectMsg)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_destUniqueId);
		P_GET_PROPERTY(FStrProperty,Z_Param_msg);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_SendDirectMsg(Z_Param_destUniqueId,Z_Param_msg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_LeaveChannel)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_channelKey);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_LeaveChannel(Z_Param_channelKey);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_JoinChannel)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_channelKey);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_JoinChannel(Z_Param_channelKey);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_Disconnect)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->K2_Disconnect();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AProudChatActor::execK2_Init)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_authUUID);
		P_GET_PROPERTY(FStrProperty,Z_Param_projectUUID);
		P_GET_PROPERTY(FStrProperty,Z_Param_uniqueID);
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->K2_Init(Z_Param_authUUID,Z_Param_projectUUID,Z_Param_uniqueID);
		P_NATIVE_END;
	}
	static FName NAME_AProudChatActor_K2_Channel_Join_Failed = FName(TEXT("K2_Channel_Join_Failed"));
	void AProudChatActor::K2_Channel_Join_Failed(const FString& channelKey, const FString& msg)
	{
		ProudChatActor_eventK2_Channel_Join_Failed_Parms Parms;
		Parms.channelKey=channelKey;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_Channel_Join_Failed),&Parms);
	}
	static FName NAME_AProudChatActor_K2_Channel_Join_Success = FName(TEXT("K2_Channel_Join_Success"));
	void AProudChatActor::K2_Channel_Join_Success(const FString& channelKey)
	{
		ProudChatActor_eventK2_Channel_Join_Success_Parms Parms;
		Parms.channelKey=channelKey;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_Channel_Join_Success),&Parms);
	}
	static FName NAME_AProudChatActor_K2_Channel_Leave_Failed = FName(TEXT("K2_Channel_Leave_Failed"));
	void AProudChatActor::K2_Channel_Leave_Failed(const FString& channelKey, const FString& msg)
	{
		ProudChatActor_eventK2_Channel_Leave_Failed_Parms Parms;
		Parms.channelKey=channelKey;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_Channel_Leave_Failed),&Parms);
	}
	static FName NAME_AProudChatActor_K2_Channel_Leave_Success = FName(TEXT("K2_Channel_Leave_Success"));
	void AProudChatActor::K2_Channel_Leave_Success(const FString& channelKey)
	{
		ProudChatActor_eventK2_Channel_Leave_Success_Parms Parms;
		Parms.channelKey=channelKey;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_Channel_Leave_Success),&Parms);
	}
	static FName NAME_AProudChatActor_K2_ChannelMsg_Response = FName(TEXT("K2_ChannelMsg_Response"));
	void AProudChatActor::K2_ChannelMsg_Response(const FString& channelKey, const FString& srcUniqueID, const FString& msg)
	{
		ProudChatActor_eventK2_ChannelMsg_Response_Parms Parms;
		Parms.channelKey=channelKey;
		Parms.srcUniqueID=srcUniqueID;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_ChannelMsg_Response),&Parms);
	}
	static FName NAME_AProudChatActor_K2_ChatClientInitComplete = FName(TEXT("K2_ChatClientInitComplete"));
	void AProudChatActor::K2_ChatClientInitComplete()
	{
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_ChatClientInitComplete),NULL);
	}
	static FName NAME_AProudChatActor_K2_ChatClientInitFailed = FName(TEXT("K2_ChatClientInitFailed"));
	void AProudChatActor::K2_ChatClientInitFailed(const FString& msg)
	{
		ProudChatActor_eventK2_ChatClientInitFailed_Parms Parms;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_ChatClientInitFailed),&Parms);
	}
	static FName NAME_AProudChatActor_K2_ChatDisconnect = FName(TEXT("K2_ChatDisconnect"));
	void AProudChatActor::K2_ChatDisconnect(const FString& msg)
	{
		ProudChatActor_eventK2_ChatDisconnect_Parms Parms;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_ChatDisconnect),&Parms);
	}
	static FName NAME_AProudChatActor_K2_DirectMsg_Response = FName(TEXT("K2_DirectMsg_Response"));
	void AProudChatActor::K2_DirectMsg_Response(const FString& srcUniqueID, const FString& msg)
	{
		ProudChatActor_eventK2_DirectMsg_Response_Parms Parms;
		Parms.srcUniqueID=srcUniqueID;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_DirectMsg_Response),&Parms);
	}
	static FName NAME_AProudChatActor_K2_MsgRecord_Failed = FName(TEXT("K2_MsgRecord_Failed"));
	void AProudChatActor::K2_MsgRecord_Failed(const FString& msg)
	{
		ProudChatActor_eventK2_MsgRecord_Failed_Parms Parms;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_MsgRecord_Failed),&Parms);
	}
	static FName NAME_AProudChatActor_K2_MsgRecord_Success = FName(TEXT("K2_MsgRecord_Success"));
	void AProudChatActor::K2_MsgRecord_Success(FMsgRecords const& records)
	{
		ProudChatActor_eventK2_MsgRecord_Success_Parms Parms;
		Parms.records=records;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_MsgRecord_Success),&Parms);
	}
	static FName NAME_AProudChatActor_K2_MsgTranslate_Failed = FName(TEXT("K2_MsgTranslate_Failed"));
	void AProudChatActor::K2_MsgTranslate_Failed(const FString& msgKey, const FString& msg)
	{
		ProudChatActor_eventK2_MsgTranslate_Failed_Parms Parms;
		Parms.msgKey=msgKey;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_MsgTranslate_Failed),&Parms);
	}
	static FName NAME_AProudChatActor_K2_MsgTranslate_Success = FName(TEXT("K2_MsgTranslate_Success"));
	void AProudChatActor::K2_MsgTranslate_Success(const FString& msgKey, const FString& msg)
	{
		ProudChatActor_eventK2_MsgTranslate_Success_Parms Parms;
		Parms.msgKey=msgKey;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_MsgTranslate_Success),&Parms);
	}
	static FName NAME_AProudChatActor_K2_Notice_Response = FName(TEXT("K2_Notice_Response"));
	void AProudChatActor::K2_Notice_Response(const FString& msg)
	{
		ProudChatActor_eventK2_Notice_Response_Parms Parms;
		Parms.msg=msg;
		ProcessEvent(FindFunctionChecked(NAME_AProudChatActor_K2_Notice_Response),&Parms);
	}
	void AProudChatActor::StaticRegisterNativesAProudChatActor()
	{
		UClass* Class = AProudChatActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "K2_Disconnect", &AProudChatActor::execK2_Disconnect },
			{ "K2_Init", &AProudChatActor::execK2_Init },
			{ "K2_IsConnected", &AProudChatActor::execK2_IsConnected },
			{ "K2_JoinChannel", &AProudChatActor::execK2_JoinChannel },
			{ "K2_LeaveChannel", &AProudChatActor::execK2_LeaveChannel },
			{ "K2_MsgRecord_Channel", &AProudChatActor::execK2_MsgRecord_Channel },
			{ "K2_MsgRecord_Direct", &AProudChatActor::execK2_MsgRecord_Direct },
			{ "K2_MsgRecord_Notice", &AProudChatActor::execK2_MsgRecord_Notice },
			{ "K2_MsgTranslate", &AProudChatActor::execK2_MsgTranslate },
			{ "K2_MsgTranslate_Auto", &AProudChatActor::execK2_MsgTranslate_Auto },
			{ "K2_SendChannelMsg", &AProudChatActor::execK2_SendChannelMsg },
			{ "K2_SendDirectMsg", &AProudChatActor::execK2_SendDirectMsg },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Channel_Join_Failed_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_channelKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Channel_Join_Failed_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_channelKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "Channel_Join_Failed" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat Channel Join \xec\x8b\xa4\xed\x8c\xa8 \xec\x8b\x9c Deegate\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_Channel_Join_Failed", nullptr, nullptr, sizeof(ProudChatActor_eventK2_Channel_Join_Failed_Parms), Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Channel_Join_Success_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::NewProp_channelKey_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::NewProp_channelKey,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "Channel_Join_Success" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat Channel Join \xec\x84\xb1\xea\xb3\xb5 \xec\x8b\x9c Deegate\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_Channel_Join_Success", nullptr, nullptr, sizeof(ProudChatActor_eventK2_Channel_Join_Success_Parms), Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Channel_Leave_Failed_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_channelKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Channel_Leave_Failed_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_channelKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "Channel_Leave_Success" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat Channel Leave \xec\x8b\xa4\xed\x8c\xa8 \xec\x8b\x9c Deegate\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_Channel_Leave_Failed", nullptr, nullptr, sizeof(ProudChatActor_eventK2_Channel_Leave_Failed_Parms), Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Channel_Leave_Success_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::NewProp_channelKey_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::NewProp_channelKey,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "Channel_Leave_Success" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat Channel Leave \xec\x84\xb1\xea\xb3\xb5 \xec\x8b\x9c Deegate\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_Channel_Leave_Success", nullptr, nullptr, sizeof(ProudChatActor_eventK2_Channel_Leave_Success_Parms), Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_srcUniqueID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_srcUniqueID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_ChannelMsg_Response_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_channelKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_srcUniqueID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_srcUniqueID = { "srcUniqueID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_ChannelMsg_Response_Parms, srcUniqueID), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_srcUniqueID_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_srcUniqueID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_ChannelMsg_Response_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_channelKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_srcUniqueID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "ChannelMsg_Response" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xeb\x8b\xa4\xeb\xa5\xb8 \xec\x9c\xa0\xec\xa0\x80\xea\xb0\x80 \xec\xb1\x84\xeb\x84\x90\xec\x97\x90 \xeb\xa9\x94\xec\x84\xb8\xec\xa7\x80\xeb\xa5\xbc \xeb\xb3\xb4\xeb\x82\xb4\xeb\xa9\xb4 \xed\x98\xb8\xec\xb6\x9c\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_ChannelMsg_Response", nullptr, nullptr, sizeof(ProudChatActor_eventK2_ChannelMsg_Response_Parms), Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "ChatClientInitComplete" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "ProudChat Init \xec\x84\xb1\xea\xb3\xb5 \xec\x8b\x9c Deegate\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_ChatClientInitComplete", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_ChatClientInitFailed_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "ChatClientInitFailed" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "ProudChat Init \xec\x8b\xa4\xed\x8c\xa8 \xec\x8b\x9c Deegate\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_ChatClientInitFailed", nullptr, nullptr, sizeof(ProudChatActor_eventK2_ChatClientInitFailed_Parms), Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_ChatDisconnect_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "ChatDisconnect" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "ProudChat Disconnect \xeb\xb0\x9c\xec\x83\x9d \xec\x8b\x9c Delegate \xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_ChatDisconnect", nullptr, nullptr, sizeof(ProudChatActor_eventK2_ChatDisconnect_Parms), Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_srcUniqueID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_srcUniqueID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_srcUniqueID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_srcUniqueID = { "srcUniqueID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_DirectMsg_Response_Parms, srcUniqueID), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_srcUniqueID_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_srcUniqueID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_DirectMsg_Response_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_srcUniqueID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "DirectMsg_Response" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xeb\x8b\xa4\xeb\xa5\xb8\xec\x9c\xa0\xec\xa0\x80\xea\xb0\x80 \xeb\x82\x98\xec\x97\x90\xea\xb2\x8c \xeb\xa9\x94\xec\x84\xb8\xec\xa7\x80\xeb\xa5\xbc \xeb\xb3\xb4\xeb\x82\xb4\xeb\xa9\xb4\xec\x9d\x80 \xed\x98\xb8\xec\xb6\x9c\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_DirectMsg_Response", nullptr, nullptr, sizeof(ProudChatActor_eventK2_DirectMsg_Response_Parms), Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_Disconnect_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Disconnect_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "Disconnect" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "ProudChat \xec\x97\xb0\xea\xb2\xb0\xec\x9d\x84 \xec\xa2\x85\xeb\xa3\x8c\xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xed\x95\xa8\xec\x88\x98" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_Disconnect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_Disconnect", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Disconnect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Disconnect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_Disconnect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_Disconnect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_Init_Statics
	{
		struct ProudChatActor_eventK2_Init_Parms
		{
			FString authUUID;
			FString projectUUID;
			FString uniqueID;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_authUUID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_authUUID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_projectUUID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_projectUUID;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_uniqueID_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_uniqueID;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_authUUID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_authUUID = { "authUUID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Init_Parms, authUUID), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_authUUID_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_authUUID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_projectUUID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_projectUUID = { "projectUUID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Init_Parms, projectUUID), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_projectUUID_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_projectUUID_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_uniqueID_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_uniqueID = { "uniqueID", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Init_Parms, uniqueID), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_uniqueID_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_uniqueID_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_Init_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_Init_Parms), &Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_authUUID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_projectUUID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_uniqueID,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "Init" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "ProudChat\xec\x9d\x84 \xec\x97\xb0\xea\xb2\xb0\xed\x95\x98\xea\xb8\xb0 \xec\x9c\x84\xed\x95\x9c \xed\x95\xa8\xec\x88\x98" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_Init", nullptr, nullptr, sizeof(ProudChatActor_eventK2_Init_Parms), Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_Init()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_Init_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics
	{
		struct ProudChatActor_eventK2_IsConnected_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_IsConnected_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_IsConnected_Parms), &Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "IsConnected" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xed\x98\x84\xec\x9e\xac \xec\x97\xb0\xea\xb2\xb0\xec\x9d\xb4 Chat Server\xec\x99\x80\xec\x9d\x98 \xec\x97\xb0\xea\xb2\xb0\xec\x9d\xb4 \xeb\x90\x98\xec\x96\xb4\xec\x9e\x88\xeb\x8a\x94\xec\xa7\x80 \xed\x99\x95\xec\x9d\xb8\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4." },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_IsConnected", nullptr, nullptr, sizeof(ProudChatActor_eventK2_IsConnected_Parms), Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_IsConnected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_IsConnected_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics
	{
		struct ProudChatActor_eventK2_JoinChannel_Parms
		{
			FString channelKey;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_JoinChannel_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_channelKey_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_JoinChannel_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_JoinChannel_Parms), &Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_channelKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "JoinChannel" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xec\xa0\x91\xec\x86\x8d\xed\x95\x98\xea\xb3\xa0 \xec\x8b\xb6\xec\x9d\x80 \xec\xb1\x84\xeb\x84\x90\xec\x9d\x98 \xed\x82\xa4\xeb\xa5\xbc \xec\x9e\x85\xeb\xa0\xa5\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_JoinChannel", nullptr, nullptr, sizeof(ProudChatActor_eventK2_JoinChannel_Parms), Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_JoinChannel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_JoinChannel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics
	{
		struct ProudChatActor_eventK2_LeaveChannel_Parms
		{
			FString channelKey;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_LeaveChannel_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_channelKey_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_LeaveChannel_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_LeaveChannel_Parms), &Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_channelKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "LeaveChannel" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xec\xa0\x91\xec\x86\x8d\xec\x9d\x84 \xed\x95\xb4\xec\xa0\x9c\xed\x95\x98\xea\xb3\xa0 \xec\x8b\xb6\xec\x9d\x80 \xec\xb1\x84\xeb\x84\x90\xec\x9d\x98 \xed\x82\xa4\xeb\xa5\xbc \xec\x9e\x85\xeb\xa0\xa5\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_LeaveChannel", nullptr, nullptr, sizeof(ProudChatActor_eventK2_LeaveChannel_Parms), Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics
	{
		struct ProudChatActor_eventK2_MsgRecord_Channel_Parms
		{
			FString channelKey;
			int32 day;
			int32 cnt;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_day_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_day;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cnt_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_cnt;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Channel_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_channelKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_day_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_day = { "day", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Channel_Parms, day), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_day_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_day_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_cnt_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_cnt = { "cnt", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Channel_Parms, cnt), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_cnt_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_cnt_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_MsgRecord_Channel_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_MsgRecord_Channel_Parms), &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_channelKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_day,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_cnt,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgRecord_Channel" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Channel \xea\xb8\xb0\xeb\xa1\x9d\xec\x9d\x84 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xac \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgRecord_Channel", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgRecord_Channel_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics
	{
		struct ProudChatActor_eventK2_MsgRecord_Direct_Parms
		{
			FString target;
			int32 day;
			int32 cnt;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_target_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_day_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_day;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cnt_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_cnt;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_target_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_target = { "target", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Direct_Parms, target), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_target_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_target_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_day_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_day = { "day", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Direct_Parms, day), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_day_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_day_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_cnt_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_cnt = { "cnt", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Direct_Parms, cnt), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_cnt_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_cnt_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_MsgRecord_Direct_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_MsgRecord_Direct_Parms), &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_day,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_cnt,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgRecord_Direct" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Direct \xeb\xa9\x94\xec\x84\xb8\xec\xa7\x80 \xea\xb8\xb0\xeb\xa1\x9d\xec\x9d\x84 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xac \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgRecord_Direct", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgRecord_Direct_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Failed_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgRecord" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat \xea\xb3\xbc\xea\xb1\xb0 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xa4\xea\xb8\xb0 \xec\x8b\xa4\xed\x8c\xa8 \xec\x8b\x9c Delegate \xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgRecord_Failed", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgRecord_Failed_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics
	{
		struct ProudChatActor_eventK2_MsgRecord_Notice_Parms
		{
			int32 day;
			int32 cnt;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_day_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_day;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cnt_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_cnt;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_day_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_day = { "day", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Notice_Parms, day), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_day_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_day_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_cnt_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_cnt = { "cnt", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Notice_Parms, cnt), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_cnt_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_cnt_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_MsgRecord_Notice_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_MsgRecord_Notice_Parms), &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_day,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_cnt,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgRecord_Notice" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Notice \xea\xb8\xb0\xeb\xa1\x9d\xec\x9d\x84 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xac \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgRecord_Notice", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgRecord_Notice_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_records_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_records;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::NewProp_records_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::NewProp_records = { "records", nullptr, (EPropertyFlags)0x0010000008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgRecord_Success_Parms, records), Z_Construct_UScriptStruct_FMsgRecords, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::NewProp_records_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::NewProp_records_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::NewProp_records,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgRecord" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat \xea\xb3\xbc\xea\xb1\xb0 \xeb\x8d\xb0\xec\x9d\xb4\xed\x84\xb0 \xea\xb0\x80\xec\xa0\xb8\xec\x98\xa4\xea\xb8\xb0 \xec\x84\xb1\xea\xb3\xb5 \xec\x8b\x9c Delegate \xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgRecord_Success", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgRecord_Success_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08420800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics
	{
		struct ProudChatActor_eventK2_MsgTranslate_Parms
		{
			FString src;
			FString target;
			FString msgKey;
			FString msg;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_src_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_src;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_target_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msgKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msgKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_src_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_src = { "src", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Parms, src), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_src_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_src_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_target_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_target = { "target", nullptr, (EPropertyFlags)0x0010000000000082, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Parms, target), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_target_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_target_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msgKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msgKey = { "msgKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Parms, msgKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msgKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msgKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msg_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_MsgTranslate_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_MsgTranslate_Parms), &Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_src,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msgKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_msg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgTranslate" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xeb\xa9\x94\xec\x84\xb8\xec\xa7\x80 \xeb\xb2\x88\xec\x97\xad\xec\x9d\x84 \xec\x9a\x94\xec\xb2\xad\xed\x95\xa0 \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgTranslate", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgTranslate_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics
	{
		struct ProudChatActor_eventK2_MsgTranslate_Auto_Parms
		{
			FString target;
			FString msgKey;
			FString msg;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_target_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_target;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msgKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msgKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_target_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_target = { "target", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Auto_Parms, target), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_target_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_target_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msgKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msgKey = { "msgKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Auto_Parms, msgKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msgKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msgKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Auto_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msg_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_MsgTranslate_Auto_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_MsgTranslate_Auto_Parms), &Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_target,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msgKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_msg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgTranslate_Auto" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xeb\xa9\x94\xec\x84\xb8\xec\xa7\x80 \xec\x9e\x90\xeb\x8f\x99 \xeb\xb2\x88\xec\x97\xad\xec\x9d\x84 \xec\x9a\x94\xec\xb2\xad\xed\x95\xa0 \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgTranslate_Auto", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgTranslate_Auto_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msgKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msgKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msgKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msgKey = { "msgKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Failed_Parms, msgKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msgKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msgKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Failed_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msgKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgTranslate_Failed" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat \xeb\xb2\x88\xec\x97\xad \xec\x9a\x94\xec\xb2\xad \xec\x8b\xa4\xed\x8c\xa8 \xec\x8b\x9c Delegate \xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgTranslate_Failed", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgTranslate_Failed_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msgKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msgKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msgKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msgKey = { "msgKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Success_Parms, msgKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msgKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msgKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_MsgTranslate_Success_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msgKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "MsgTranslate_Success" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "Proud Chat \xeb\xb2\x88\xec\x97\xad \xec\x9a\x94\xec\xb2\xad \xec\x84\xb1\xea\xb3\xb5 \xec\x8b\x9c Delegate \xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_MsgTranslate_Success", nullptr, nullptr, sizeof(ProudChatActor_eventK2_MsgTranslate_Success_Parms), Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_Notice_Response_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::NewProp_msg_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "Notice_Response" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "ProudConsole\xec\x97\x90\xec\x84\x9c \xea\xb3\xb5\xec\xa7\x80\xec\x82\xac\xed\x95\xad \xeb\xb0\x9c\xec\x86\xa1 \xec\x8b\x9c Deegate\xeb\x90\x98\xeb\x8a\x94 \xec\x9d\xb4\xeb\xb2\xa4\xed\x8a\xb8" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_Notice_Response", nullptr, nullptr, sizeof(ProudChatActor_eventK2_Notice_Response_Parms), Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x08020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_Notice_Response()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_Notice_Response_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics
	{
		struct ProudChatActor_eventK2_SendChannelMsg_Parms
		{
			FString channelKey;
			FString msg;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_channelKey_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_channelKey;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_channelKey_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_channelKey = { "channelKey", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_SendChannelMsg_Parms, channelKey), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_channelKey_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_channelKey_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_SendChannelMsg_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_msg_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_SendChannelMsg_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_SendChannelMsg_Parms), &Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_channelKey,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_msg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "SendChannelMsg" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xec\xb1\x84\xeb\x84\x90\xec\x97\x90\xea\xb2\x8c \xeb\xa9\x94\xec\x84\xb8\xec\xa7\x80\xeb\xa5\xbc \xeb\xb3\xb4\xeb\x82\xbc \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_SendChannelMsg", nullptr, nullptr, sizeof(ProudChatActor_eventK2_SendChannelMsg_Parms), Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics
	{
		struct ProudChatActor_eventK2_SendDirectMsg_Parms
		{
			FString destUniqueId;
			FString msg;
			bool ReturnValue;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_destUniqueId_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_destUniqueId;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_msg_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_destUniqueId_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_destUniqueId = { "destUniqueId", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_SendDirectMsg_Parms, destUniqueId), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_destUniqueId_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_destUniqueId_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_msg_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ProudChatActor_eventK2_SendDirectMsg_Parms, msg), METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_msg_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_msg_MetaData)) };
	void Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ProudChatActor_eventK2_SendDirectMsg_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ProudChatActor_eventK2_SendDirectMsg_Parms), &Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_destUniqueId,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_msg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::Function_MetaDataParams[] = {
		{ "Category", "ProudChat" },
		{ "DisplayName", "SendDirectMsg" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
		{ "ToolTip", "\xed\x8a\xb9\xec\xa0\x95 \xec\x83\x81\xeb\x8c\x80\xec\x97\x90\xea\xb2\x8c \xeb\xa9\x94\xec\x84\xb8\xec\xa7\x80\xeb\xa5\xbc \xeb\xb3\xb4\xeb\x82\xbc \xeb\x95\x8c \xec\x82\xac\xec\x9a\xa9\xed\x95\xa9\xeb\x8b\x88\xeb\x8b\xa4" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AProudChatActor, nullptr, "K2_SendDirectMsg", nullptr, nullptr, sizeof(ProudChatActor_eventK2_SendDirectMsg_Parms), Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AProudChatActor_NoRegister()
	{
		return AProudChatActor::StaticClass();
	}
	struct Z_Construct_UClass_AProudChatActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AProudChatActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_ProudChat,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AProudChatActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Failed, "K2_Channel_Join_Failed" }, // 1562838944
		{ &Z_Construct_UFunction_AProudChatActor_K2_Channel_Join_Success, "K2_Channel_Join_Success" }, // 3495719471
		{ &Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Failed, "K2_Channel_Leave_Failed" }, // 1977298420
		{ &Z_Construct_UFunction_AProudChatActor_K2_Channel_Leave_Success, "K2_Channel_Leave_Success" }, // 2027942653
		{ &Z_Construct_UFunction_AProudChatActor_K2_ChannelMsg_Response, "K2_ChannelMsg_Response" }, // 3300210051
		{ &Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitComplete, "K2_ChatClientInitComplete" }, // 2061743381
		{ &Z_Construct_UFunction_AProudChatActor_K2_ChatClientInitFailed, "K2_ChatClientInitFailed" }, // 2620593378
		{ &Z_Construct_UFunction_AProudChatActor_K2_ChatDisconnect, "K2_ChatDisconnect" }, // 3034893070
		{ &Z_Construct_UFunction_AProudChatActor_K2_DirectMsg_Response, "K2_DirectMsg_Response" }, // 3420073818
		{ &Z_Construct_UFunction_AProudChatActor_K2_Disconnect, "K2_Disconnect" }, // 1837149372
		{ &Z_Construct_UFunction_AProudChatActor_K2_Init, "K2_Init" }, // 1710891580
		{ &Z_Construct_UFunction_AProudChatActor_K2_IsConnected, "K2_IsConnected" }, // 1095689948
		{ &Z_Construct_UFunction_AProudChatActor_K2_JoinChannel, "K2_JoinChannel" }, // 4078717915
		{ &Z_Construct_UFunction_AProudChatActor_K2_LeaveChannel, "K2_LeaveChannel" }, // 2601943281
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Channel, "K2_MsgRecord_Channel" }, // 3522100872
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Direct, "K2_MsgRecord_Direct" }, // 699897846
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Failed, "K2_MsgRecord_Failed" }, // 1664518467
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Notice, "K2_MsgRecord_Notice" }, // 2307862703
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgRecord_Success, "K2_MsgRecord_Success" }, // 2170561236
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate, "K2_MsgTranslate" }, // 3251987375
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Auto, "K2_MsgTranslate_Auto" }, // 2524750502
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Failed, "K2_MsgTranslate_Failed" }, // 3077782457
		{ &Z_Construct_UFunction_AProudChatActor_K2_MsgTranslate_Success, "K2_MsgTranslate_Success" }, // 3312355699
		{ &Z_Construct_UFunction_AProudChatActor_K2_Notice_Response, "K2_Notice_Response" }, // 3372096467
		{ &Z_Construct_UFunction_AProudChatActor_K2_SendChannelMsg, "K2_SendChannelMsg" }, // 757536358
		{ &Z_Construct_UFunction_AProudChatActor_K2_SendDirectMsg, "K2_SendDirectMsg" }, // 2602757413
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AProudChatActor_Statics::Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ProudChatActor.h" },
		{ "IsBlueprintBase", "true" },
		{ "ModuleRelativePath", "Public/ProudChatActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AProudChatActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AProudChatActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AProudChatActor_Statics::ClassParams = {
		&AProudChatActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AProudChatActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AProudChatActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AProudChatActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AProudChatActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AProudChatActor, 2800527567);
	template<> PROUDCHAT_API UClass* StaticClass<AProudChatActor>()
	{
		return AProudChatActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AProudChatActor(Z_Construct_UClass_AProudChatActor, &AProudChatActor::StaticClass, TEXT("/Script/ProudChat"), TEXT("AProudChatActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AProudChatActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
