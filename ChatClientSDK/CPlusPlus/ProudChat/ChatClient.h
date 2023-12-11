#pragma once

#include "pch.h"
#include "ProudNetClient.h"

#include "Chat_proxy.h"
#include "Chat_stub.h"

#include <unordered_set>

using namespace Proud;
namespace ProudChat {
	class CFiltering;
	class CChatClient : public ChatS2C::Stub
	{
	public :
		CChatClient();
		virtual ~CChatClient();

	public :
		DECRMI_ChatS2C_Login_Response;
		DECRMI_ChatS2C_ChannelMsg;
		DECRMI_ChatS2C_SendMsg;
		DECRMI_ChatS2C_Event_Filtering;
		DECRMI_ChatS2C_Event_Notice;

	public :
		bool Init(String authUUID, String projectUUID, String uniqueId, std::function<void()> joinDelegateCompleteDelegate , std::function<void(const String& msg)> joinDelegateFailedDelegate);
		void FrameMove();

	public :
		void Send_Msg(String destUniqueId, String msg);
		void Add_Channel(String channelKey);
		void Leave_Channel(String channelKey);
		void Send_ChannelMsg(String channelKey, String msg);
		void SetUpChannel();
		void SetUpFiltering(String filtering, String filePath);

	private :


	private:
		CNetClient* m_netClient = NULL;
		ChatC2S::Proxy m_ChatProxy;

	private :
		CFiltering* m_Filtering = nullptr;

	private:
		Guid g_ChatProtocolVersion = Guid({ 0x587372c5,0x0d61,0x45f7,{0xbb,0xa2,0x36,0x4a,0x37,0x12,0x10,0x01} });
		Proud::String m_ServerIP = _PNT("chat-lb-2d547d8ff8aaf11f.elb.ap-northeast-2.amazonaws.com");
		unsigned short m_serverPort = 80;
		Proud::String localFilePath = _PNT("filtering.txt"); // 로컬에 저장될 파일 경로를 입력하세요.

		Proud::CNetConnectionParam param;

		String m_authUUID;
		String m_projectUUID;
		String m_uniqueId;
		Proud::CServerConnectionState state;
		ConnectionState connectionState;

		Proud::CFastSet<String> channelList;

		bool isReconnect = false;


	private :
		std::function<void()> chatClientJoinCompleteDelegate = nullptr;

	public :
		std::function<void(const String& msg)> chatClientJoinFailedDelegate = nullptr;
		std::function<void(const String& channelKey, const String& srcUniqueID, const String& msg)> channelMsg_ResponseDelegate = nullptr;
		std::function<void(const String& srcUniqueID, const String& msg)> sendMsg_ResponseDelegate = nullptr;
		std::function<void(const String& msg)> noticeDelegate = nullptr;



	};
}


