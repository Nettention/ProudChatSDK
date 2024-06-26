#pragma once
//#pragma warning(disable:4005)
#include "Engine.h"
#include "ProudNetClient.h"

#include "CustomTypeMarshal.h"
#include "ClientChatLink_common.h"
#include "ClientChatLink_proxy.h"
#include "ClientChatLink_stub.h"

#include "ClientToLoginLink_common.h"
#include "ClientToLoginLink_proxy.h"
#include "ClientToLoginLink_stub.h"

#include <unordered_set>

using namespace Proud;
namespace ProudChat {
	class CFiltering;
	class CChatClient 
		: public LoginToClient::Stub
		, public ChatToClient::Stub
	{
	public :
		CChatClient();
		virtual ~CChatClient();

	public :
		DECRMI_ChatToClient_Connect_Success;
		DECRMI_ChatToClient_Connect_Failed;
		DECRMI_ChatToClient_ChannelMsg;
		DECRMI_ChatToClient_DirectMsg;
		DECRMI_ChatToClient_Event_Filtering;
		DECRMI_ChatToClient_Event_Notice;
		DECRMI_ChatToClient_ChannelJoin_Success;
		DECRMI_ChatToClient_ChannelJoin_Failed;
		DECRMI_ChatToClient_ChannelLeave_Success;
		DECRMI_ChatToClient_ChannelLeave_Failed;
		DECRMI_ChatToClient_MsgTranslate_Success;
		DECRMI_ChatToClient_MsgTranslate_Failed;
		DECRMI_ChatToClient_MsgRecord_Success;
		DECRMI_ChatToClient_MsgRecord_Failed;


		DECRMI_LoginToClient_Login_Success;
		DECRMI_LoginToClient_Login_Failed;

	public :
		bool Init(const String& authUUID, const String& projectUUID, const String& uniqueId, std::function<void()> joinDelegateCompleteDelegate, std::function<void(const String& msg)> joinDelegateFailedDelegate);
		void Disconnect();
		void FrameMove();

	public :
		bool isConnected();

	public :
		bool Send_Direct_Msg(const String& destUniqueId, const String& msg);
		bool Join_Channel(const String& channelKey);
		bool Leave_Channel(const String& channelKey);
		bool Send_Channel_Msg(const String& channelKey, const String& msg);
		bool MsgTranslate(const String& src, const String& target, const String& msgKey, const String& msg);
		bool MsgTranslate_auto(const String& target, const String& msgKey, const String& msg);
		bool MsgRecord_Direct(const String& target, const uint16_t day, const uint16_t cnt);
		bool MsgRecord_Channel(const String& channelKey, const uint16_t day, const uint16_t cnt);
		bool MsgRecord_Notice(const uint16_t day, const uint16_t cnt);

	private :
		void SetUpFiltering(const String& filtering, const String& filePath);
		void SetUpChannel();

	private:
		CNetClient* m_LoginNetClient = NULL;
		CNetClient* m_ChatNetClient = NULL;

		ClientToLogin::Proxy m_LoginProxy;
		ClientToChat::Proxy m_ChatProxy;

	private :
		CFiltering* m_Filtering = nullptr;

	private:
		Guid g_ChatProtocolVersion = Guid({ 0x587372c5,0x0d61,0x45f7,{0xbb,0xa2,0x36,0x4a,0x37,0x12,0x10,0x01} });
		Proud::String m_ServerIP = _PNT("chat-lb-2d547d8ff8aaf11f.elb.ap-northeast-2.amazonaws.com");
		unsigned short m_serverPort = 80;
		Proud::String localFilePath = _PNT("filtering.txt"); // 로컬에 저장될 파일 경로를 입력하세요.


		String m_authUUID;
		String m_projectUUID;
		String m_uniqueId;
		Proud::CServerConnectionState state;
		bool isLogin = false;
		ConnectionState connectionState;
		int16_t MsgLimit = 200;


		Proud::CFastSet<String> channelList;

		//bool isReconnect = false;

	private :
		std::function<void()> chatClientJoinCompleteDelegate = nullptr;
		std::function<void(const Proud::String& msg)> chatClientJoinFailedDelegate = nullptr;

	public :
		std::function<void(const Proud::String& msg)> chatDisconnectDelegate = nullptr;
		std::function<void(const Proud::String& channelKey, const Proud::String& srcUniqueID, const Proud::String& msg)> channelMsg_ResponseDelegate = nullptr;
		std::function<void(const Proud::String& srcUniqueID, const Proud::String& msg)> directMsg_ResponseDelegate = nullptr;
		std::function<void(const Proud::String& msg)> notice_ResponseDelegate = nullptr;
		std::function<void(const Proud::String& channelKey)> channelJoinSuccessDelegate = nullptr;
		std::function<void(const Proud::String& channelKey, const Proud::String& msg)> channelJoinFailedDelegate = nullptr;
		std::function<void(const Proud::String& channelKey)> channelLeaveSuccessDelegate = nullptr;
		std::function<void(const Proud::String& channelKey, const Proud::String& msg)> channelLeaveFailedDelegate = nullptr;
		std::function<void(const Proud::String& msgKey, const Proud::String& msg)> msgTranslateSuccessDelegate = nullptr;
		std::function<void(const Proud::String& msgKey, const Proud::String& msg)> msgTranslateFailedDelegate = nullptr;
		std::function<void(const tagMsgRecords& records)> msgRecordSuccessDelegate = nullptr;
		std::function<void(const Proud::String& records)> msgRecordFailedDelegate = nullptr;
	};
}


