// Fill out your copyright notice in the Description page of Project Settings.


#include "ProudChatActor.h"

// Sets default values
AProudChatActor::AProudChatActor()
	: m_pChatClient(new ProudChat::CChatClient())
{
	PrimaryActorTick.bCanEverTick = true;

}

void AProudChatActor::ChatClientInitComplete()
{
	K2_ChatClientInitComplete();
	InitComplete_Delegate.Broadcast();

	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Green, TEXT("ProudChat Connection Success"));
	std::cout << "ProudChat Connection Success" << std::endl;

	//기본적으로 ALL 채널에 접속합니다.
	//삭제 및 변경하셔도 무방합니다.
	//AddChannel(_PNT("ALL"));
}

void AProudChatActor::ChatClientInitFailed(const String& msg)
{
#if PLATFORM_WINDOWS
	K2_ChatClientInitFailed(WCHAR_TO_TCHAR(msg.c_str()));
	InitFailed_Delegate.Broadcast(WCHAR_TO_TCHAR(msg.c_str()));
	GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("ProudChat Connection Failed") + *WCHAR_TO_TCHAR(msg.c_str()));

#elif PLATFORM_ANDROID
	K2_ChatClientInitFailed(UTF8_TO_TCHAR(msg.c_str()));
	InitFailed_Delegate.Broadcast(UTF8_TO_TCHAR(msg.c_str()));
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("ProudChat Connection Failed") + *UTF8_TO_TCHAR(msg.c_str()));
#endif
	std::cout << "ProudChat Connection Failed" << msg.c_str() << std::endl;
}

void AProudChatActor::AddChannel(const String& channelKey) {
	m_pChatClient->Add_Channel(channelKey);
}


void AProudChatActor::LeaveChannel(const String& channelKey)
{
	m_pChatClient->Leave_Channel(channelKey);
}

void AProudChatActor::SendMsg_Response(const String& srcUniqueID, const String& msg) {
#if PLATFORM_WINDOWS
	K2_SendMsg_Response(WCHAR_TO_TCHAR(srcUniqueID.c_str()), WCHAR_TO_TCHAR(msg.c_str()));
	SendMsg_Response_Delegate.Broadcast(WCHAR_TO_TCHAR(srcUniqueID.c_str()), WCHAR_TO_TCHAR(msg.c_str()));
#elif PLATFORM_ANDROID
	K2_SendMsg_Response(UTF8_TO_TCHAR(srcUniqueID.c_str()), UTF8_TO_TCHAR(msg.c_str()));
	SendMsg_Response_Delegate.Broadcast(UTF8_TO_TCHAR(srcUniqueID.c_str()), UTF8_TO_TCHAR(msg.c_str()));
#endif
}


void AProudChatActor::ChannelMsg_Response(const String& channelKey, const String& srcUniqueID, const String& msg)
{
#if PLATFORM_WINDOWS
	K2_ChannelMsg_Response(WCHAR_TO_TCHAR(channelKey.c_str()), WCHAR_TO_TCHAR(srcUniqueID.c_str()), WCHAR_TO_TCHAR(msg.c_str()));
	ChannelMsg_Response_Delegate.Broadcast(WCHAR_TO_TCHAR(channelKey.c_str()), WCHAR_TO_TCHAR(srcUniqueID.c_str()), WCHAR_TO_TCHAR(msg.c_str()));

#elif PLATFORM_ANDROID
	K2_ChannelMsg_Response(UTF8_TO_TCHAR(channelKey.c_str()), UTF8_TO_TCHAR(srcUniqueID.c_str()), UTF8_TO_TCHAR(msg.c_str()));
	ChannelMsg_Response_Delegate.Broadcast(UTF8_TO_TCHAR(channelKey.c_str()), UTF8_TO_TCHAR(srcUniqueID.c_str()), UTF8_TO_TCHAR(msg.c_str()));
#endif

}

void AProudChatActor::SendMsg(const String& destUniqueId, const String& msg) {
	m_pChatClient->Send_Msg(destUniqueId, msg);
}

void AProudChatActor::SendChannelMsg(const String& channelKey, const String& msg) {
	m_pChatClient->Send_ChannelMsg(channelKey, msg);
}

void AProudChatActor::Notice_Response(const String& msg)
{
#if PLATFORM_WINDOWS
	K2_Notice_Response(WCHAR_TO_TCHAR(msg.c_str()));
	Notice_Response_Delegate.Broadcast(WCHAR_TO_TCHAR(msg.c_str()));
#elif PLATFORM_ANDROID
	K2_Notice_Response(UTF8_TO_TCHAR(msg.c_str()));
	Notice_Response_Delegate.Broadcast(UTF8_TO_TCHAR(msg.c_str()));
#endif
}

void AProudChatActor::Init(const String& authUUID, const String& projectUUID, const String& uniqueID) {
	m_pChatClient->Init(authUUID, projectUUID, uniqueID, std::bind(&AProudChatActor::ChatClientInitComplete, this) , std::bind(&AProudChatActor::ChatClientInitFailed , this , std::placeholders::_1));

}

void AProudChatActor::BeginPlay()
{
	Super::BeginPlay();

	//나에게 메세지가 오는 부분을 bind시켜준다.
	m_pChatClient->sendMsg_ResponseDelegate = std::bind(&AProudChatActor::SendMsg_Response, this, std::placeholders::_1, std::placeholders::_2);
	//채널에 메세지 오는 부분을 bind시켜준다.
	m_pChatClient->channelMsg_ResponseDelegate = std::bind(&AProudChatActor::ChannelMsg_Response, this, std::placeholders::_1, std::placeholders::_2 , std::placeholders::_3);

	m_pChatClient->notice_ResponseDelegate = std::bind(&AProudChatActor::Notice_Response, this, std::placeholders::_1);
}

// Called every frame
void AProudChatActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//FrameMove를 호출해줘야 서버에서 받은 이벤트를 호출해줄수있다.
	m_pChatClient->FrameMove();

}
