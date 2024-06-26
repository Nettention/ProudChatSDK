// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FMsgRecords;
#ifdef PROUDCHAT_ProudChatActor_generated_h
#error "ProudChatActor.generated.h already included, missing '#pragma once' in ProudChatActor.h"
#endif
#define PROUDCHAT_ProudChatActor_generated_h

#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_37_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMsgRecords_Statics; \
	PROUDCHAT_API static class UScriptStruct* StaticStruct();


template<> PROUDCHAT_API UScriptStruct* StaticStruct<struct FMsgRecords>();

#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_23_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FMsgRecord_Statics; \
	PROUDCHAT_API static class UScriptStruct* StaticStruct();


template<> PROUDCHAT_API UScriptStruct* StaticStruct<struct FMsgRecord>();

#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_SPARSE_DATA
#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execK2_IsConnected); \
	DECLARE_FUNCTION(execK2_MsgRecord_Notice); \
	DECLARE_FUNCTION(execK2_MsgRecord_Channel); \
	DECLARE_FUNCTION(execK2_MsgRecord_Direct); \
	DECLARE_FUNCTION(execK2_MsgTranslate_Auto); \
	DECLARE_FUNCTION(execK2_MsgTranslate); \
	DECLARE_FUNCTION(execK2_SendChannelMsg); \
	DECLARE_FUNCTION(execK2_SendDirectMsg); \
	DECLARE_FUNCTION(execK2_LeaveChannel); \
	DECLARE_FUNCTION(execK2_JoinChannel); \
	DECLARE_FUNCTION(execK2_Disconnect); \
	DECLARE_FUNCTION(execK2_Init);


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execK2_IsConnected); \
	DECLARE_FUNCTION(execK2_MsgRecord_Notice); \
	DECLARE_FUNCTION(execK2_MsgRecord_Channel); \
	DECLARE_FUNCTION(execK2_MsgRecord_Direct); \
	DECLARE_FUNCTION(execK2_MsgTranslate_Auto); \
	DECLARE_FUNCTION(execK2_MsgTranslate); \
	DECLARE_FUNCTION(execK2_SendChannelMsg); \
	DECLARE_FUNCTION(execK2_SendDirectMsg); \
	DECLARE_FUNCTION(execK2_LeaveChannel); \
	DECLARE_FUNCTION(execK2_JoinChannel); \
	DECLARE_FUNCTION(execK2_Disconnect); \
	DECLARE_FUNCTION(execK2_Init);


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_EVENT_PARMS \
	struct ProudChatActor_eventK2_Channel_Join_Failed_Parms \
	{ \
		FString channelKey; \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_Channel_Join_Success_Parms \
	{ \
		FString channelKey; \
	}; \
	struct ProudChatActor_eventK2_Channel_Leave_Failed_Parms \
	{ \
		FString channelKey; \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_Channel_Leave_Success_Parms \
	{ \
		FString channelKey; \
	}; \
	struct ProudChatActor_eventK2_ChannelMsg_Response_Parms \
	{ \
		FString channelKey; \
		FString srcUniqueID; \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_ChatClientInitFailed_Parms \
	{ \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_ChatDisconnect_Parms \
	{ \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_DirectMsg_Response_Parms \
	{ \
		FString srcUniqueID; \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_MsgRecord_Failed_Parms \
	{ \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_MsgRecord_Success_Parms \
	{ \
		FMsgRecords records; \
	}; \
	struct ProudChatActor_eventK2_MsgTranslate_Failed_Parms \
	{ \
		FString msgKey; \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_MsgTranslate_Success_Parms \
	{ \
		FString msgKey; \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_Notice_Response_Parms \
	{ \
		FString msg; \
	};


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_CALLBACK_WRAPPERS
#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProudChatActor(); \
	friend struct Z_Construct_UClass_AProudChatActor_Statics; \
public: \
	DECLARE_CLASS(AProudChatActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProudChat"), NO_API) \
	DECLARE_SERIALIZER(AProudChatActor)


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_INCLASS \
private: \
	static void StaticRegisterNativesAProudChatActor(); \
	friend struct Z_Construct_UClass_AProudChatActor_Statics; \
public: \
	DECLARE_CLASS(AProudChatActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProudChat"), NO_API) \
	DECLARE_SERIALIZER(AProudChatActor)


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AProudChatActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AProudChatActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProudChatActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProudChatActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProudChatActor(AProudChatActor&&); \
	NO_API AProudChatActor(const AProudChatActor&); \
public:


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProudChatActor(AProudChatActor&&); \
	NO_API AProudChatActor(const AProudChatActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProudChatActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProudChatActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProudChatActor)


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_58_PROLOG \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_EVENT_PARMS


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_SPARSE_DATA \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_RPC_WRAPPERS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_CALLBACK_WRAPPERS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_INCLASS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_SPARSE_DATA \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_CALLBACK_WRAPPERS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_61_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROUDCHAT_API UClass* StaticClass<class AProudChatActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h


#define FOREACH_ENUM_EMSGTYPE(op) \
	op(EMsgType::None) \
	op(EMsgType::Direct) \
	op(EMsgType::Channel) \
	op(EMsgType::Notice) 

enum class EMsgType;
template<> PROUDCHAT_API UEnum* StaticEnum<EMsgType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
