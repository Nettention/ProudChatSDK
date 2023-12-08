// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeProudChat_init() {}
	PROUDCHAT_API UFunction* Z_Construct_USparseDelegateFunction_ProudChat_DelegateInitComplete__DelegateSignature();
	PROUDCHAT_API UFunction* Z_Construct_USparseDelegateFunction_ProudChat_DelegateInitFailed__DelegateSignature();
	PROUDCHAT_API UFunction* Z_Construct_USparseDelegateFunction_ProudChat_DelegateNotice_Response__DelegateSignature();
	PROUDCHAT_API UFunction* Z_Construct_USparseDelegateFunction_ProudChat_DelegateSendMsg_Response__DelegateSignature();
	PROUDCHAT_API UFunction* Z_Construct_USparseDelegateFunction_ProudChat_DelegateChannelMsg_Response__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_ProudChat()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_USparseDelegateFunction_ProudChat_DelegateInitComplete__DelegateSignature,
				(UObject* (*)())Z_Construct_USparseDelegateFunction_ProudChat_DelegateInitFailed__DelegateSignature,
				(UObject* (*)())Z_Construct_USparseDelegateFunction_ProudChat_DelegateNotice_Response__DelegateSignature,
				(UObject* (*)())Z_Construct_USparseDelegateFunction_ProudChat_DelegateSendMsg_Response__DelegateSignature,
				(UObject* (*)())Z_Construct_USparseDelegateFunction_ProudChat_DelegateChannelMsg_Response__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/ProudChat",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x5177A40D,
				0x3DC0EAC2,
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
