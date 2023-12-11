// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef PROUDCHAT_ProudChatActor_generated_h
#error "ProudChatActor.generated.h already included, missing '#pragma once' in ProudChatActor.h"
#endif
#define PROUDCHAT_ProudChatActor_generated_h

#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_15_DELEGATE \
struct _Script_ProudChat_eventDelegateChannelMsg_Response_Parms \
{ \
	FString channelKey; \
	FString srcUniqueId; \
	FString msg; \
}; \
static inline void FDelegateChannelMsg_Response_DelegateWrapper(const FMulticastScriptDelegate& DelegateChannelMsg_Response, const FString& channelKey, const FString& srcUniqueId, const FString& msg) \
{ \
	_Script_ProudChat_eventDelegateChannelMsg_Response_Parms Parms; \
	Parms.channelKey=channelKey; \
	Parms.srcUniqueId=srcUniqueId; \
	Parms.msg=msg; \
	DelegateChannelMsg_Response.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_14_DELEGATE \
struct _Script_ProudChat_eventDelegateSendMsg_Response_Parms \
{ \
	FString desteUniqueId; \
	FString msg; \
}; \
static inline void FDelegateSendMsg_Response_DelegateWrapper(const FMulticastScriptDelegate& DelegateSendMsg_Response, const FString& desteUniqueId, const FString& msg) \
{ \
	_Script_ProudChat_eventDelegateSendMsg_Response_Parms Parms; \
	Parms.desteUniqueId=desteUniqueId; \
	Parms.msg=msg; \
	DelegateSendMsg_Response.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_13_DELEGATE \
struct _Script_ProudChat_eventDelegateNotice_Response_Parms \
{ \
	FString msg; \
}; \
static inline void FDelegateNotice_Response_DelegateWrapper(const FMulticastScriptDelegate& DelegateNotice_Response, const FString& msg) \
{ \
	_Script_ProudChat_eventDelegateNotice_Response_Parms Parms; \
	Parms.msg=msg; \
	DelegateNotice_Response.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_12_DELEGATE \
struct _Script_ProudChat_eventDelegateInitFailed_Parms \
{ \
	FString msg; \
}; \
static inline void FDelegateInitFailed_DelegateWrapper(const FMulticastScriptDelegate& DelegateInitFailed, const FString& msg) \
{ \
	_Script_ProudChat_eventDelegateInitFailed_Parms Parms; \
	Parms.msg=msg; \
	DelegateInitFailed.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_11_DELEGATE \
static inline void FDelegateInitComplete_DelegateWrapper(const FMulticastScriptDelegate& DelegateInitComplete) \
{ \
	DelegateInitComplete.ProcessMulticastDelegate<UObject>(NULL); \
}


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_SPARSE_DATA
#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execK2_Init); \
	DECLARE_FUNCTION(execK2_SendChannelMsg); \
	DECLARE_FUNCTION(execK2_SendMsg); \
	DECLARE_FUNCTION(execK2_LeaveChannel); \
	DECLARE_FUNCTION(execK2_AddChannel);


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execK2_Init); \
	DECLARE_FUNCTION(execK2_SendChannelMsg); \
	DECLARE_FUNCTION(execK2_SendMsg); \
	DECLARE_FUNCTION(execK2_LeaveChannel); \
	DECLARE_FUNCTION(execK2_AddChannel);


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_EVENT_PARMS \
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
	struct ProudChatActor_eventK2_Notice_Response_Parms \
	{ \
		FString msg; \
	}; \
	struct ProudChatActor_eventK2_SendMsg_Response_Parms \
	{ \
		FString srcUniqueID; \
		FString msg; \
	};


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_CALLBACK_WRAPPERS
#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAProudChatActor(); \
	friend struct Z_Construct_UClass_AProudChatActor_Statics; \
public: \
	DECLARE_CLASS(AProudChatActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProudChat"), NO_API) \
	DECLARE_SERIALIZER(AProudChatActor)


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAProudChatActor(); \
	friend struct Z_Construct_UClass_AProudChatActor_Statics; \
public: \
	DECLARE_CLASS(AProudChatActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/ProudChat"), NO_API) \
	DECLARE_SERIALIZER(AProudChatActor)


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_STANDARD_CONSTRUCTORS \
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


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AProudChatActor(AProudChatActor&&); \
	NO_API AProudChatActor(const AProudChatActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AProudChatActor); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AProudChatActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AProudChatActor)


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_PRIVATE_PROPERTY_OFFSET
#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_17_PROLOG \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_EVENT_PARMS


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_SPARSE_DATA \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_RPC_WRAPPERS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_CALLBACK_WRAPPERS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_INCLASS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_PRIVATE_PROPERTY_OFFSET \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_SPARSE_DATA \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_CALLBACK_WRAPPERS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_INCLASS_NO_PURE_DECLS \
	HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> PROUDCHAT_API UClass* StaticClass<class AProudChatActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HostProject_Plugins_ProudChat_Source_ProudChat_Public_ProudChatActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
