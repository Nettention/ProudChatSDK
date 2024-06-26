// Fill out your copyright notice in the Description page of Project Settings.


#include "ProudChatActor.h"

// Sets default values
AProudChatActor::AProudChatActor()
	: m_pChatClient(new ProudChat::CChatClient())
{
	PrimaryActorTick.bCanEverTick = true;

}

FString AProudChatActor::ConvertFString(const Proud::String& str)
{
#if PLATFORM_WINDOWS
	return WCHAR_TO_TCHAR(str.c_str());
#elif PLATFORM_ANDROID
	return UTF8_TO_TCHAR(str.c_str());
#endif
}

Proud::String AProudChatActor::ConvertPNString(const FString& str)
{
#if PLATFORM_WINDOWS
	return TCHAR_TO_WCHAR(*str);
#elif PLATFORM_ANDROID
	return TCHAR_TO_UTF8(*str);
#endif
}

void AProudChatActor::ChatClientInitComplete()
{
	K2_ChatClientInitComplete();
	InitComplete_Delegate.ExecuteIfBound();

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("ProudChat Connection Success"));
	std::cout << "ProudChat Connection Success" << std::endl;

	//기본적으로 ALL 채널에 접속합니다.
	//삭제 및 변경하셔도 무방합니다.
	//AddChannel(_PNT("ALL"));
}

void AProudChatActor::ChatClientInitFailed(const String& msg)
{
	FString p1 = ConvertFString(msg);
	K2_ChatClientInitFailed(p1);
	InitFailed_Delegate.ExecuteIfBound(p1);
}

void AProudChatActor::ChatDisconnect(const String& msg)
{
	FString p1 = ConvertFString(msg);
	K2_ChatDisconnect(p1);
	ChatDisconnect_Delegate.ExecuteIfBound(p1);
}

bool AProudChatActor::JoinChannel(const FString& channelKey) {
	return m_pChatClient->Join_Channel(ConvertPNString(channelKey));
}


bool AProudChatActor::LeaveChannel(const FString& channelKey)
{
	return m_pChatClient->Leave_Channel(ConvertPNString(channelKey));
}

void AProudChatActor::DirectMsg_Response(const String& srcUniqueID, const String& msg) {
	FString p1 , p2;
	p1 = ConvertFString(srcUniqueID);
	p2 = ConvertFString(msg);
	K2_DirectMsg_Response(p1, p2);
	DirectMsg_Response_Delegate.ExecuteIfBound(p1, p2);
}


void AProudChatActor::ChannelMsg_Response(const String& channelKey, const String& srcUniqueID, const String& msg)
{
	FString p1 , p2 , p3;
	p1 = ConvertFString(channelKey);
	p2 = ConvertFString(srcUniqueID);
	p3 = ConvertFString(msg);
	K2_ChannelMsg_Response(p1 , p2 , p3);
	ChannelMsg_Response_Delegate.ExecuteIfBound(p1 , p2 , p3);
}

bool AProudChatActor::SendDirectMsg(const FString& destUniqueId, const FString& msg) {
	Proud::String p1 , p2;
	p1 = ConvertPNString(destUniqueId);
	p2 = ConvertPNString(msg);
	return m_pChatClient->Send_Direct_Msg(p1, p2);
}

bool AProudChatActor::SendChannelMsg(const FString& channelKey, const FString& msg) {
	Proud::String p1 , p2;
	p1 = ConvertPNString(channelKey);
	p2 = ConvertPNString(msg);
	return m_pChatClient->Send_Channel_Msg(p1, p2);
}

bool AProudChatActor::MsgTranslate(const FString& src, const FString target, const FString& msgKey, const FString& msg)
{
	Proud::String p1 , p2 , p3 , p4;
	p1 = ConvertPNString(src);
	p2 = ConvertPNString(target);
	p3 = ConvertPNString(msgKey);
	p4 = ConvertPNString(msg);

	return m_pChatClient->MsgTranslate(p1, p2, p3, p4);
}

bool AProudChatActor::MsgTranslate_Auto(const FString& target, const FString& msgKey, const FString& msg)
{
	Proud::String p1 , p2 , p3;
	p1 = ConvertPNString(target);
	p2 = ConvertPNString(msgKey);
	p3 = ConvertPNString(msg);
	return m_pChatClient->MsgTranslate_auto(p1 , p2 , p3);
}

bool AProudChatActor::MsgRecord_Direct(const FString& target, const uint16_t day, const uint16_t cnt)
{
	return m_pChatClient->MsgRecord_Direct(ConvertPNString(target) , day , cnt);
}

bool AProudChatActor::MsgRecord_Channel(const FString& channelKey, const uint16_t day, const uint16_t cnt)
{
	return m_pChatClient->MsgRecord_Channel(ConvertPNString(channelKey) , day , cnt);
}

bool AProudChatActor::MsgRecord_Notice(const uint16_t day, const uint16_t cnt)
{
	return m_pChatClient->MsgRecord_Notice(day , cnt);
}

bool AProudChatActor::IsConnected()
{
	return m_pChatClient->isConnected();
}

void AProudChatActor::Notice_Response(const String& msg)
{
	FString p1 = ConvertFString(msg);
	K2_Notice_Response(p1);
	Notice_Response_Delegate.ExecuteIfBound(p1);
}

void AProudChatActor::Channel_Join_Success(const String& channelKey)
{
	FString p1 = ConvertFString(channelKey);
	K2_Channel_Join_Success(p1);
	Channel_Join_Success_Delegate.ExecuteIfBound(p1);
}

void AProudChatActor::Channel_Join_Failed(const String& channelKey, const String& msg)
{
	FString p1 , p2;
	p1 = ConvertFString(channelKey);
	p2 = ConvertFString(msg);
	K2_Channel_Join_Failed(p1 , p2);
	Channel_Join_Failed_Delegate.ExecuteIfBound(p1 , p2);
}

void AProudChatActor::Channel_Leave_Success(const String& channelKey)
{
	FString p1 = ConvertFString(channelKey);
	K2_Channel_Leave_Success(p1);
	Channel_Leave_Success_Delegate.ExecuteIfBound(p1);
}

void AProudChatActor::Channel_Leave_Failed(const String& channelKey, const String& msg)
{
	FString p1 , p2;
	p1 = ConvertFString(channelKey);
	p2 = ConvertFString(msg);
	K2_Channel_Leave_Failed(p1 , p2);
	Channel_Leave_Failed_Delegate.ExecuteIfBound(p1 , p2);

}

void AProudChatActor::MsgTranslate_Success(const String& msgKey, const String& msg)
{
	FString p1 , p2;
	p1 = ConvertFString(msgKey);
	p2 = ConvertFString(msg);
	K2_MsgTranslate_Success(p1 , p2);
	MsgTranslate_Success_Delegate.ExecuteIfBound(p1 , p2);

}

void AProudChatActor::MsgTranslate_Failed(const String& msgKey, const String& msg)
{
	FString p1, p2;
	p1 = ConvertFString(msgKey);
	p2 = ConvertFString(msg);

	K2_MsgTranslate_Failed(p1 , p2);
	MsgTranslate_Failed_Delegate.ExecuteIfBound(p1 , p2);
}

void AProudChatActor::MsgRecord_Success(const tagMsgRecords records)
{
	FMsgRecords msgRecords;
	msgRecords.msgType = (EMsgType)records.msgType;

	for (int i = 0; i < records.records.GetCount(); ++i) {
		FMsgRecord record;
		record.timestamp = records.records[i].timestamp;
		record.src = ConvertFString(records.records[i].src);
		record.dest = ConvertFString(records.records[i].dest);
		record.message = ConvertFString(records.records[i].message);
		msgRecords.records.Add(record);
	}

	K2_MsgRecord_Success(msgRecords);
	MsgRecord_Success_Delegate.ExecuteIfBound(msgRecords);
}

void AProudChatActor::MsgRecord_Failed(const String& msg)
{
	FString p1 = ConvertFString(msg);
	K2_MsgRecord_Failed(p1);
	MsgRecord_Failed_Delegate.ExecuteIfBound(p1);
}

bool AProudChatActor::Init(const FString& authUUID, const FString& projectUUID, const FString& uniqueID) {
	Proud::String p1 , p2 , p3;
	p1 = ConvertPNString(authUUID);
	p2 = ConvertPNString(projectUUID);
	p3 = ConvertPNString(uniqueID);

	return m_pChatClient->Init(p1, p2, p3, std::bind(&AProudChatActor::ChatClientInitComplete, this) , std::bind(&AProudChatActor::ChatClientInitFailed , this , std::placeholders::_1));
}

void AProudChatActor::Disconnect()
{
	m_pChatClient->Disconnect();
}

void AProudChatActor::BeginPlay()
{
	Super::BeginPlay();

	//나에게 메세지가 오는 부분을 bind시켜준다.
	m_pChatClient->directMsg_ResponseDelegate = std::bind(&AProudChatActor::DirectMsg_Response, this, std::placeholders::_1, std::placeholders::_2);
	//채널에 메세지 오는 부분을 bind시켜준다.
	m_pChatClient->channelMsg_ResponseDelegate = std::bind(&AProudChatActor::ChannelMsg_Response, this, std::placeholders::_1, std::placeholders::_2 , std::placeholders::_3);

	m_pChatClient->notice_ResponseDelegate = std::bind(&AProudChatActor::Notice_Response, this, std::placeholders::_1);

	m_pChatClient->channelJoinSuccessDelegate = std::bind(&AProudChatActor::Channel_Join_Success, this, std::placeholders::_1);
	m_pChatClient->channelJoinFailedDelegate = std::bind(&AProudChatActor::Channel_Join_Failed, this, std::placeholders::_1 , std::placeholders::_2);

	m_pChatClient->channelLeaveSuccessDelegate = std::bind(&AProudChatActor::Channel_Leave_Success, this, std::placeholders::_1);
	m_pChatClient->channelLeaveFailedDelegate = std::bind(&AProudChatActor::Channel_Leave_Failed, this, std::placeholders::_1, std::placeholders::_2);

	m_pChatClient->chatDisconnectDelegate = std::bind(&AProudChatActor::ChatDisconnect, this, std::placeholders::_1);
	m_pChatClient->msgTranslateSuccessDelegate = std::bind(&AProudChatActor::MsgTranslate_Success , this , std::placeholders::_1 , std::placeholders::_2);
	m_pChatClient->msgTranslateFailedDelegate = std::bind(&AProudChatActor::MsgTranslate_Failed, this, std::placeholders::_1, std::placeholders::_2);

	m_pChatClient->msgRecordSuccessDelegate = std::bind(&AProudChatActor::MsgRecord_Success, this, std::placeholders::_1);
	m_pChatClient->msgRecordFailedDelegate = std::bind(&AProudChatActor::MsgRecord_Failed, this, std::placeholders::_1);
}

// Called every frame
void AProudChatActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FrameMove를 호출해줘야 서버에서 받은 이벤트를 호출해줄수있다.
	m_pChatClient->FrameMove();

}
