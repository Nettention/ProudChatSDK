// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ChatClient.h"
#include "ProudChatActor.generated.h"

UENUM(Meta = (Bitflags))
enum class EMsgType {
	None = 0,
	Direct = 1,
	Channel = 2,
	Notice = 3,
};


USTRUCT(BlueprintType)
struct FMsgRecord
{
	GENERATED_USTRUCT_BODY()
	//시간
	uint64_t timestamp;
	//메세지 전송자
	FString src;
	//메세지 받은자 or 채널Key
	FString dest;
	//메세지
	FString message;

};

USTRUCT(BlueprintType)
struct FMsgRecords {
	GENERATED_USTRUCT_BODY()
		EMsgType msgType;
	TArray<FMsgRecord> records;
};

DECLARE_DELEGATE(FDelegateInitComplete);
DECLARE_DELEGATE_OneParam(FDelegateChatDisconnect, const FString&);
DECLARE_DELEGATE_OneParam(FDelegateInitFailed, const FString&);
DECLARE_DELEGATE_OneParam(FDelegateNotice_Response, const FString&);
DECLARE_DELEGATE_OneParam(FDelegateChannel_Join_Success, const FString&);
DECLARE_DELEGATE_OneParam(FDelegateChannel_Leave_Success, const FString&);
DECLARE_DELEGATE_OneParam(FDelegateMsgRecordSuccess, const FMsgRecords&);
DECLARE_DELEGATE_OneParam(FDelegateMsgRecordFailed, const FString& msg);
DECLARE_DELEGATE_TwoParams(FDelegateChannel_Join_Failed, const FString&, const FString&);
DECLARE_DELEGATE_TwoParams(FDelegateChannel_Leave_Failed, const FString&, const FString&);
DECLARE_DELEGATE_TwoParams(FDelegateDirectMsg_Response, const FString&, const FString&);
DECLARE_DELEGATE_TwoParams(FDelegateMsgTranslate_Success, const FString&, const FString&);
DECLARE_DELEGATE_TwoParams(FDelegateMsgTranslate_Failed, const FString&, const FString&);
DECLARE_DELEGATE_ThreeParams(FDelegateChannelMsg_Response, const FString&, const FString&, const FString&);


UCLASS(Blueprintable)
class PROUDCHAT_API AProudChatActor : public AActor
{
	GENERATED_BODY()

public:
	AProudChatActor();

private:
	FString ConvertFString(const Proud::String& str);
	Proud::String ConvertPNString(const FString& str);

public:
	/// <summary>
	/// Server Connection 완료 후 Login까지 성공하면 호출되는 함수
	/// </summary>
	void ChatClientInitComplete();
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "ChatClientInitComplete", ToolTip = "ProudChat Init 성공 시 Deegate되는 이벤트"))
		void K2_ChatClientInitComplete();

	/// <summary>
	/// Server Login 실패 시 호출되는 함수
	/// 이 함수를 타게 되는 시점은 서버와의 연결은 성공하였으나 계정 로그인을 못할때 발생하는 이벤트입니다.
	/// 이 부분은 실패시 재시도를 하지 않으므로 설정 확인이 필요합니다.
	/// </summary>
	/// <param name="msg">Server Login 실패 시 에러를 반환해준다.</param>
	void ChatClientInitFailed(const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "ChatClientInitFailed", ToolTip = "ProudChat Init 실패 시 Deegate되는 이벤트"))
		void K2_ChatClientInitFailed(const FString& msg);

	/// <summary>
	/// ProudChat Server Disconnect 발생 시 Delegate되는 함수
	/// </summary>
	/// /// <param name="msg">Disconnect 발생 원인</param>
	void ChatDisconnect(const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "ChatDisconnect", ToolTip = "ProudChat Disconnect 발생 시 Delegate 되는 이벤트"))
		void K2_ChatDisconnect(const FString& msg);

	/// <summary>
	/// 다른유저가 나에게 메세지를 보내면은 Delegate되는 함수
	/// </summary>
	/// <param name="srcUniqueID">메세지를 보낸 상대방의 고유한 식별 값</param>
	/// <param name="msg">상대방이 나에게 보낸 메세지</param>
	void DirectMsg_Response(const String& srcUniqueID, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "DirectMsg_Response", ToolTip = "다른유저가 나에게 메세지를 보내면은 호출되는 이벤트"))
		void K2_DirectMsg_Response(const FString& srcUniqueID, const FString& msg);

	/// <summary>
	/// 다른 유저가 채널에 메세지를 보내면은 Delegate되는 함수
	/// </summary>
	/// <param name="channelKey">어떤 채널인지의 대한 채널의 고유한 식별 값</param>
	/// <param name="srcUniqueID">채널에 메세지를 올린 상대방의 고유한 식별 값</param>
	/// <param name="msg">상대방이 채널에 보낸 메세지</param>
	void ChannelMsg_Response(const String& channelKey, const String& srcUniqueID, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "ChannelMsg_Response", ToolTip = "다른 유저가 채널에 메세지를 보내면 호출되는 이벤트"))
		void K2_ChannelMsg_Response(const FString& channelKey, const FString& srcUniqueID, const FString& msg);


	/// <summary>
	/// ProudConsole에서 공지사항 발송 시 Deegate되는 함수
	/// </summary>
	/// <param name="msg">공지사항 내용을 출력합니다</param>
	void Notice_Response(const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "Notice_Response", ToolTip = "ProudConsole에서 공지사항 발송 시 Deegate되는 이벤트"))
		void K2_Notice_Response(const FString& msg);

	/// <summary>
	/// Proud Chat Channel Join 성공 시 Delegate 되는 함수
	/// </summary>
	/// <param name="channelKey">Join 성공한 ChannelKey</param>
	void Channel_Join_Success(const String& channelKey);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "Channel_Join_Success", ToolTip = "Proud Chat Channel Join 성공 시 Deegate되는 이벤트"))
		void K2_Channel_Join_Success(const FString& channelKey);

	/// <summary>
	/// Proud Chat Channel Join 실패 시 Delegate 되는 함수
	/// </summary>
	/// <param name="channelKey">Join 성공한 ChannelKey</param>
	void Channel_Join_Failed(const String& channelKey, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "Channel_Join_Failed", ToolTip = "Proud Chat Channel Join 실패 시 Deegate되는 이벤트"))
		void K2_Channel_Join_Failed(const FString& channelKey, const FString& msg);

	/// <summary>
	/// Proud Chat Channel Leave 성공 시 Delegate 되는 함수
	/// </summary>
	/// <param name="channelKey">Leave 성공한 ChannelKey</param>
	void Channel_Leave_Success(const String& channelKey);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "Channel_Leave_Success", ToolTip = "Proud Chat Channel Leave 성공 시 Deegate되는 이벤트"))
		void K2_Channel_Leave_Success(const FString& channelKey);

	/// <summary>
	/// Proud Chat Channel Leave 실패 시 Delegate 되는 함수
	/// </summary>
	/// <param name="channelKey">Leave 성공한 ChannelKey</param>
	void Channel_Leave_Failed(const String& channelKey, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "Channel_Leave_Success", ToolTip = "Proud Chat Channel Leave 실패 시 Deegate되는 이벤트"))
		void K2_Channel_Leave_Failed(const FString& channelKey, const FString& msg);

	/// <summary>
	/// Proud Chat 번역 요청 성공 시 Delegate 되는 함수 (Beta)
	/// </summary>
	/// <param name="msgKey">메세지 고유 키</param>
	/// <param name="msg">메세지 내용</param>
	void MsgTranslate_Success(const String& msgKey, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "MsgTranslate_Success", ToolTip = "Proud Chat 번역 요청 성공 시 Delegate 되는 이벤트"))
		void K2_MsgTranslate_Success(const FString& msgKey, const FString& msg);

	/// <summary>
	/// Proud Chat 번역 요청 실패 시 Delegate 되는 함수 (Beta)
	/// </summary>
	/// <param name="msgKey">메세지 고유 키</param>
	/// <param name="msg">메세지 내용</param>
	void MsgTranslate_Failed(const String& msgKey, const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "MsgTranslate_Failed", ToolTip = "Proud Chat 번역 요청 실패 시 Delegate 되는 이벤트"))
		void K2_MsgTranslate_Failed(const FString& msgKey, const FString& msg);


	/// <summary>
	/// ProudChat 과거 기록 요청 성공 시 Delegate 되는 함수 (Beta)
	/// </summary>
	/// <param name="records">과거 데이터</param>
	void MsgRecord_Success(const tagMsgRecords records);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "MsgRecord", ToolTip = "Proud Chat 과거 데이터 가져오기 성공 시 Delegate 되는 이벤트"))
		void K2_MsgRecord_Success(const FMsgRecords& records);

	/// <summary>
	/// ProudChat 과거 기록 요청 실패 시 Delegate 되는 함수 (Beta)
	/// </summary>
	/// <param name="msg">실패 사유</param>
	void MsgRecord_Failed(const String& msg);
	UFUNCTION(BlueprintImplementableEvent, Category = "ProudChat", meta = (DisplayName = "MsgRecord", ToolTip = "Proud Chat 과거 데이터 가져오기 실패 시 Delegate 되는 이벤트"))
		void K2_MsgRecord_Failed(const FString& msg);



public:
	/// <summary>
	/// ProudChat을 연결하기 위한 함수
	/// </summary>
	/// <param name="authUUID">https://console.nettention.com 에서 AuthUUID를 확인 후 넣어주세요</param>
	/// <param name="projectUUID">https://console.nettention.com 에서 ProjectUUID를 확인 후 넣어주세요</param>
	/// <param name="uniqueID">유저의 고유한 닉네임을 입력해주세요</param>
	bool Init(const FString& authUUID, const FString& projectUUID, const FString& uniqueID);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "Init", ToolTip = "ProudChat을 연결하기 위한 함수"))
		bool K2_Init(const FString& authUUID, const FString& projectUUID, const FString& uniqueID) {
		return Init(authUUID, projectUUID, uniqueID);
	}

	/// <summary>
	/// ProudChat과의 연결을 해재하기 위한 함수
	/// </summary>
	void Disconnect();
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "Disconnect", ToolTip = "ProudChat 연결을 종료하기 위한 함수"))
		void K2_Disconnect() {
		Disconnect();
	}

	/// <summary>
	/// 접속하고 싶은 채널의 키를 입력합니다.
	/// </summary>
	/// <param name="channelKey">접속하고 싶은 채널의 고유 Key</param>
	bool JoinChannel(const FString& channelKey);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "JoinChannel", ToolTip = "접속하고 싶은 채널의 키를 입력합니다"))
		bool K2_JoinChannel(const FString& channelKey) {
		return JoinChannel(channelKey);
	}

	/// <summary>
	/// 접속을 해제하고 싶은 채널의 키를 입력합니다.
	/// </summary>
	/// <param name="channelKey">접속 해제하고 싶은 채널의 고유 Key</param>
	bool LeaveChannel(const FString& channelKey);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "LeaveChannel", ToolTip = "접속을 해제하고 싶은 채널의 키를 입력합니다"))
		bool K2_LeaveChannel(const FString& channelKey) {
		return LeaveChannel(channelKey);
	}

	/// <summary>
	/// 특정 상대에게 메세지를 보낼 때 사용합니다.
	/// </summary>
	/// <param name="destUniqueId">특정 상대방 고유한 식별 값</param>
	/// <param name="msg">특정 상대방에게 보낼 메세지</param>
	bool SendDirectMsg(const FString& destUniqueId, const FString& msg);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "SendDirectMsg", ToolTip = "특정 상대에게 메세지를 보낼 때 사용합니다"))
		bool K2_SendDirectMsg(const FString& destUniqueId, const FString& msg) {
		return SendDirectMsg(destUniqueId, msg);
	}

	/// <summary>
	/// 특정 채널에게 메세지를 보낼 때 사용합니다.
	/// </summary>
	/// <param name="channelKey">특정 채널의 고유한 식별 값</param>
	/// <param name="msg">특정 채널에게 보낼 메세지</param>
	bool SendChannelMsg(const FString& channelKey, const FString& msg);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "SendChannelMsg", ToolTip = "특정 채널에게 메세지를 보낼 때 사용합니다"))
		bool K2_SendChannelMsg(const FString& channelKey, const FString& msg) {
		return SendChannelMsg(channelKey, msg);
	}

	/// <summary>
	/// 메세지 번역을 요청할 때 사용합니다 (Beta)
	/// </summary>
	/// <param name="src">시작 국가 코드</param>
	/// <param name="target">번역 국가 코드</param>
	/// <param name="msgKey">메세지 고유 키</param>
	/// <param name="msg">메세지</param>
	bool MsgTranslate(const FString& src, const FString target, const FString& msgKey, const FString& msg);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "MsgTranslate", ToolTip = "메세지 번역을 요청할 때 사용합니다"))
		bool K2_MsgTranslate(const FString& src, const FString target, const FString& msgKey, const FString& msg) {
		return MsgTranslate(src, target, msgKey, msg);
	}

	/// <summary>
	/// 메세지 자동 번역을 요청할 때 사용합니다 (Beta)
	/// </summary>
	/// <param name="target">번역 국가 코드</param>
	/// <param name="msgKey">메세지 고유 키</param>
	/// <param name="msg">메세지</param>
	bool MsgTranslate_Auto(const FString& target, const FString& msgKey, const FString& msg);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "MsgTranslate_Auto", ToolTip = "메세지 자동 번역을 요청할 때 사용합니다"))
		bool K2_MsgTranslate_Auto(const FString& target, const FString& msgKey, const FString& msg) {
		return MsgTranslate_Auto(target, msgKey, msg);
	}

	/// <summary>
	/// Direct 메세지 기록을 가져옵니다. 최대 90일 100건 (Beta)
	/// </summary>
	/// <param name="target">기록을 가져올 대상</param>
	/// <param name="day">가져올 일수 최대 90</param>
	/// <param name="cnt">가져올 개수 최대 100</param>
	bool MsgRecord_Direct(const FString& target , const uint16_t day , const uint16_t cnt);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "MsgRecord_Direct", ToolTip = "Direct 메세지 기록을 가져올 때 사용합니다"))
		bool K2_MsgRecord_Direct(const FString& target, const int32 day, const int32 cnt) {
		if (day < 0 || day > UINT16_MAX || cnt < 0 || cnt > UINT16_MAX)
			return false;
		return MsgRecord_Direct(target , day , cnt);
	}

	/// <summary>
	/// Channel 메세지 기록을 가져옵니다. 최대 90일 100건 (Beta)
	/// </summary>
	/// <param name="channelKey">기록을 가져올 ChannelKey</param>
	/// <param name="day">가져올 일수 최대 90</param>
	/// <param name="cnt">가져올 개수 최대 100</param>
	bool MsgRecord_Channel(const FString& channelKey, const uint16_t day, const uint16_t cnt);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "MsgRecord_Channel", ToolTip = "Channel 기록을 가져올 때 사용합니다"))
		bool K2_MsgRecord_Channel(const FString& channelKey, const int32 day, const int32 cnt) {
		if (day < 0 || day > UINT16_MAX || cnt < 0 || cnt > UINT16_MAX)
			return false;
		return MsgRecord_Channel(channelKey , day , cnt);
	}

	/// <summary>
	/// Notice 메세지 기록을 가져옵니다. 최대 90일 100건 (Beta)
	/// </summary>
	/// <param name="day">가져올 일수 최대 90</param>
	/// <param name="cnt">가져올 개수 최대 100</param>
	bool MsgRecord_Notice(const uint16_t day, const uint16_t cnt);
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "MsgRecord_Notice", ToolTip = "Notice 기록을 가져올 때 사용합니다"))
		bool K2_MsgRecord_Notice(const int32 day, const int32 cnt) {
		if (day < 0 || day > UINT16_MAX || cnt < 0 || cnt > UINT16_MAX)
			return false;
		return MsgRecord_Notice(day , cnt);
	}

	/// <summary>
	/// 현재 Chat Server와의 연결이 되어있는지 확인합니다.
	/// </summary>
	/// <return>연결 상태</return>
	bool IsConnected();
	UFUNCTION(BlueprintCallable, Category = "ProudChat", meta = (DisplayName = "IsConnected", ToolTip = "현재 연결이 Chat Server와의 연결이 되어있는지 확인합니다."))
		bool K2_IsConnected() {
		return IsConnected();
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
	/// Init Complete가 완료되었을때 호출되는 이벤트
	/// </summary>
	FDelegateInitComplete InitComplete_Delegate;

	/// <summary>
	/// Init Failed가 되었을때 호출되는 이벤트
	/// </summary>
	FDelegateInitFailed InitFailed_Delegate;

	/// <summary>
	/// Chat Server와 연결이 끊어졋을때 호출되는 이벤트
	/// </summary>
	FDelegateChatDisconnect ChatDisconnect_Delegate;

	/// <summary>
	/// Direct Msg가 도착했을때 호출되는 이벤트
	/// </summary>
	FDelegateDirectMsg_Response DirectMsg_Response_Delegate;

	/// <summary>
	/// Channel Msg가 도착했을때 호출되는 이벤트
	/// </summary>
	FDelegateChannelMsg_Response ChannelMsg_Response_Delegate;

	/// <summary>
	/// Notice가 도착했을때 호출되는 이벤트
	/// </summary>
	FDelegateNotice_Response Notice_Response_Delegate;

	/// <summary>
	/// Channel Join 성공 시 호출되는 이벤트
	/// </summary>
	FDelegateChannel_Join_Success Channel_Join_Success_Delegate;

	/// <summary>
	/// Channel Join 실패 시 호출되는 이벤트
	/// </summary>
	FDelegateChannel_Join_Failed Channel_Join_Failed_Delegate;

	/// <summary>
	/// Channel Leave 성공 시 호출되는 이벤트
	/// </summary>
	FDelegateChannel_Leave_Success Channel_Leave_Success_Delegate;

	/// <summary>
	/// Channel Leave 실패 시 호출되는 이벤트
	/// </summary>
	FDelegateChannel_Leave_Failed Channel_Leave_Failed_Delegate;

	/// <summary>
	/// Msg 번역 성공했을때 호출되는 이벤트 (Beta)
	/// </summary>
	FDelegateMsgTranslate_Success MsgTranslate_Success_Delegate;

	/// <summary>
	/// Msg 번역 실패했을때 호출되는 이벤트 (Beta)
	/// </summary>
	FDelegateMsgTranslate_Failed MsgTranslate_Failed_Delegate;

	/// <summary>
	/// Msg 기록 불러오기 성공 시 호출되는 이벤트 (Beta)
	/// </summary>
	FDelegateMsgRecordSuccess MsgRecord_Success_Delegate;

	/// <summary>
	/// Msg 기록 불러오기 실패 시 호출되는 이벤트 (Beta)
	/// </summary>
	FDelegateMsgRecordFailed MsgRecord_Failed_Delegate;
};
