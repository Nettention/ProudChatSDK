// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ChatClient.h"
#include "ProudChatActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(FDelegateInitComplete, AProudChatActor, InitComplete_Delegate);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FDelegateInitFailed, AProudChatActor, InitFailed_Delegate, const FString&, msg);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FDelegateNotice_Response, AProudChatActor, Notice_Response_Delegate, const FString&, msg);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_TwoParams(FDelegateSendMsg_Response, AProudChatActor, SendMsg_Response_Delegate, const FString&, desteUniqueId, const FString&, msg);
DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_ThreeParams(FDelegateChannelMsg_Response, AProudChatActor, ChannelMsg_Response_Delegate, const FString&, channelKey, const FString&, srcUniqueId, const FString&, msg);

UCLASS(Blueprintable)
class PROUDCHAT_API AProudChatActor : public AActor
{
	GENERATED_BODY()

public:
	AProudChatActor();

	/// <summary>
	/// Server Connection 완료 후 Login까지 성공하면 호출되는 함수
	/// </summary>
	void ChatClientInitComplete();
		UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "ChatClientInitComplete" , ToolTip = "ProudChat Init 성공 시 Deegate되는 이벤트"))
		void K2_ChatClientInitComplete();

	/// <summary>
	/// Server Login 실패 시 호출되는 함수
	/// 이 함수를 타게 되는 시점은 서버와의 연결은 성공하였으나 계정 로그인을 못할때 발생하는 이벤트입니다.
	/// 이 부분은 실패시 재시도를 하지 않으므로 설정 확인이 필요합니다.
	/// </summary>
	/// <param name="msg">Server Login 실패 시 에러를 반환해준다.</param>
	void ChatClientInitFailed(const String& msg);
		UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "ChatClientInitFailed" , ToolTip = "ProudChat Init 실패 시 Deegate되는 이벤트"))
		void K2_ChatClientInitFailed(const FString& msg);

	/// <summary>
	/// 접속하고 싶은 채널의 키를 입력합니다.
	/// </summary>
	/// <param name="channelKey">접속하고 싶은 채널의 고유 Key</param>
	void AddChannel(const String& channelKey);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "AddChannel", ToolTip = "접속하고 싶은 채널의 키를 입력합니다"))
		void K2_AddChannel(const FString& channelKey) {
#if PLATFORM_WINDOWS
		AddChannel(TCHAR_TO_WCHAR(*channelKey));
#elif PLATFORM_ANDROID
		AddChannel(TCHAR_TO_UTF8(*channelKey));
#endif
	}

	/// <summary>
	/// 접속을 해제하고 싶은 채널의 키를 입력합니다.
	/// </summary>
	/// <param name="channelKey">접속 해제하고 싶은 채널의 고유 Key</param>
	void LeaveChannel(const String& channelKey);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "LeaveChannel" , ToolTip = "접속을 해제하고 싶은 채널의 키를 입력합니다"))
		void K2_LeaveChannel(const FString& channelKey) {
#if PLATFORM_WINDOWS
		LeaveChannel(TCHAR_TO_WCHAR(*channelKey));
#elif PLATFORM_ANDROID
		LeaveChannel(TCHAR_TO_UTF8(*channelKey));
		//LeaveChannel(TCHAR_TO_ANSI(channelKey));
#endif
	}

	/// <summary>
	/// 다른유저가 나에게 메세지를 보내면은 Delegate되는 함수
	/// </summary>
	/// <param name="srcUniqueID">메세지를 보낸 상대방의 고유한 식별 값</param>
	/// <param name="msg">상대방이 나에게 보낸 메세지</param>
	void SendMsg_Response(const String& srcUniqueID, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "SendMsg_Response" , ToolTip = "다른유저가 나에게 메세지를 보내면은 호출되는 이벤트"))
		void K2_SendMsg_Response(const FString& srcUniqueID, const FString& msg);

	/// <summary>
	/// 다른 유저가 채널에 메세지를 보내면은 Delegate되는 함수
	/// </summary>
	/// <param name="channelKey">어떤 채널인지의 대한 채널의 고유한 식별 값</param>
	/// <param name="srcUniqueID">채널에 메세지를 올린 상대방의 고유한 식별 값</param>
	/// <param name="msg">상대방이 채널에 보낸 메세지</param>
	void ChannelMsg_Response(const String& channelKey, const String& srcUniqueID, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "ChannelMsg_Response" , ToolTip = "다른 유저가 채널에 메세지를 보내면 호출되는 이벤트"))
		void K2_ChannelMsg_Response(const FString& channelKey, const FString& srcUniqueID, const FString& msg);

	/// <summary>
	/// 특정 상대에게 메세지를 보낼 때 사용합니다.
	/// </summary>
	/// <param name="destUniqueId">특정 상대방 고유한 식별 값</param>
	/// <param name="msg">특정 상대방에게 보낼 메세지</param>
	void SendMsg(const String& destUniqueId, const String& msg);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "SendMsg" , ToolTip = "특정 상대에게 메세지를 보낼 때 사용합니다"))
		void K2_SendMsg(const FString& destUniqueId, const FString& msg) {
#if PLATFORM_WINDOWS
		SendMsg(TCHAR_TO_WCHAR(*destUniqueId), TCHAR_TO_WCHAR(*msg));
#elif PLATFORM_ANDROID
		SendMsg(TCHAR_TO_UTF8(*destUniqueId), TCHAR_TO_UTF8(*msg));
		//SendMsg(StringT2A(destUniqueId).c_str(), StringT2A(msg).c_str());
#endif
	}

	/// <summary>
	/// 특정 채널에게 메세지를 보낼 때 사용합니다.
	/// </summary>
	/// <param name="channelKey">특정 채널의 고유한 식별 값</param>
	/// <param name="msg">특정 채널에게 보낼 메세지</param>
	void SendChannelMsg(const String& channelKey, const String& msg);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "SendChannelMsg" , ToolTip = "특정 채널에게 메세지를 보낼 때 사용합니다"))
		void K2_SendChannelMsg(const FString& channelKey, const FString& msg) {
#if PLATFORM_WINDOWS
		SendChannelMsg(TCHAR_TO_WCHAR(*channelKey), TCHAR_TO_WCHAR(*msg));
#elif PLATFORM_ANDROID
		SendChannelMsg(TCHAR_TO_UTF8(*channelKey), TCHAR_TO_UTF8(*msg));
		//SendChannelMsg(StringT2A(channelKey).c_str(), StringT2A(msg).c_str());
#endif
	}


	/// <summary>
	/// ProudConsole에서 공지사항 발송 시 Deegate되는 함수
	/// </summary>
	/// <param name="msg">공지사항 내용을 출력합니다</param>
	void Notice_Response(const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "Notice_Response" , ToolTip = "ProudConsole에서 공지사항 발송 시 Deegate되는 이벤트"))
		void K2_Notice_Response(const FString& msg);


		/// <summary>
	/// ProudChat을 연결하기 위한 함수
	/// </summary>
	/// <param name="authUUID">https://console.nettention.com 에서 AuthUUID를 확인 후 넣어주세요</param>
	/// <param name="projectUUID">https://console.nettention.com 에서 ProjectUUID를 확인 후 넣어주세요</param>
	/// <param name="uniqueID">유저의 고유한 닉네임을 입력해주세요</param>
	void Init(const String& authUUID, const String& projectUUID, const String& uniqueID);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "Init", ToolTip = "ProudChat을 연결하기 위한 함수"))
		void K2_Init(const FString& authUUID, const FString& projectUUID , const FString& uniqueID) {
#if PLATFORM_WINDOWS
		Init(TCHAR_TO_WCHAR(*authUUID), TCHAR_TO_WCHAR(*projectUUID), TCHAR_TO_WCHAR(*uniqueID));
#elif PLATFORM_ANDROID
		Init(TCHAR_TO_UTF8(*authUUID), TCHAR_TO_UTF8(*projectUUID), TCHAR_TO_UTF8(*uniqueID));
		//Init(*authUUID, *projectUUID, *uniqueID);
		//Init(StringT2A(authUUID).c_str(), StringT2A(projectUUID).c_str(), StringT2A(uniqueID).c_str());
#endif
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	/// <summary>
	/// Chat Client 객체
	/// </summary>
	std::shared_ptr<ProudChat::CChatClient> m_pChatClient;

public:
	/// <summary>
	/// Send Msg가 도착했을때 호출되는 이벤트
	/// </summary>
	UPROPERTY(BlueprintAssignable, Category = "ProudChat")
		FDelegateSendMsg_Response SendMsg_Response_Delegate;


	/// <summary>
	/// Channel Msg가 도착했을때 호출되는 이벤트
	/// </summary>
	UPROPERTY(BlueprintAssignable, Category = "ProudChat")
		FDelegateChannelMsg_Response ChannelMsg_Response_Delegate;

	/// <summary>
	/// Notice가 도착했을때 호출도는 이벤트
	/// </summary>
	UPROPERTY(BlueprintAssignable, Category = "ProudChat")
		FDelegateNotice_Response Notice_Response_Delegate;

	/// <summary>
	/// Init Complete가 완료되었을때 호출되는 이벤트
	/// </summary>
	UPROPERTY(BlueprintAssignable , Category = "ProudChat")
		FDelegateInitComplete InitComplete_Delegate;

	/// <summary>
	/// Init Failed가 되었을때 호출되는 이벤트
	/// </summary>
	UPROPERTY(BlueprintAssignable , Category = "ProudChat")
		FDelegateInitFailed InitFailed_Delegate;
};
