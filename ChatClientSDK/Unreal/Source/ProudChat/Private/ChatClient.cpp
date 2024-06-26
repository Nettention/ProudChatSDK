#include "ChatClient.h"

#include "ClientChatLink_common.cpp"
#include "ClientChatLink_proxy.cpp"
#include "ClientChatLink_stub.cpp"

#include "ClientToLoginLink_common.cpp"
#include "ClientToLoginLink_proxy.cpp"
#include "ClientToLoginLink_stub.cpp"


#include "Filtering.h"
#include "FileSync.h"
#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"

ProudChat::CChatClient::CChatClient()
	: m_LoginNetClient(Proud::CNetClient::Create())
	, m_ChatNetClient(Proud::CNetClient::Create())
	, m_Filtering(new CFiltering())
{
	m_LoginNetClient->AttachProxy(&m_LoginProxy);
	m_LoginNetClient->AttachStub((LoginToClient::Stub*)this);

	m_ChatNetClient->AttachProxy(&m_ChatProxy);
	m_ChatNetClient->AttachStub((ChatToClient::Stub*)this);
}

ProudChat::CChatClient::~CChatClient()
{
	if (NULL != m_ChatNetClient) {
		delete m_ChatNetClient;
		m_ChatNetClient = NULL;
	}

	if (NULL != m_LoginNetClient) {
		delete m_LoginNetClient;
		m_LoginNetClient = NULL;
	}

	if (nullptr != m_Filtering) {
		delete m_Filtering;
		m_Filtering = nullptr;
	}
}

bool ProudChat::CChatClient::Init(const String& authUUID, const String& projectUUID, const String& uniqueId , std::function<void()> joinDelegateCompleteDelegate , std::function<void(const String& msg)> joinDelegateFailedDelegate)
{
	m_LoginNetClient->Disconnect();
	m_ChatNetClient->Disconnect();

	isLogin = false;

	m_authUUID = authUUID;
	m_projectUUID = projectUUID;
	m_uniqueId = uniqueId;

	chatClientJoinCompleteDelegate = joinDelegateCompleteDelegate;
	chatClientJoinFailedDelegate = joinDelegateFailedDelegate;

	m_LoginNetClient->OnJoinServerComplete = [this , joinDelegateCompleteDelegate](ErrorInfo* info, const ByteArray& replyFromServer)
	{
		if (info->m_errorType == ErrorType::Ok)
		{
			std::cout << "Succeed to connect server. Allocated hostID=" << m_LoginNetClient->GetLocalHostID() << std::endl;
			//isReconnect = false;
			m_LoginProxy.Login_Request(HostID::HostID_Server, RmiContext::ReliableSend, m_authUUID, m_projectUUID, m_uniqueId);
		}
		else
		{
			// connection failure.
			//isReconnect = true;
			std::cout << "Failed to connect server." << std::endl;
			std::cout << "errorType = " << (int)info->m_errorType << "detailType = " << (int)info->m_detailType << "comment = " << info->m_comment.c_str() << std::endl;
			if (chatClientJoinFailedDelegate)
				chatClientJoinFailedDelegate(info->m_comment);
		}
	};

	// set a routine for network disconnection.
	m_LoginNetClient->OnLeaveServer = [this](ErrorInfo * errorInfo)
	{
		std::cout << "OnLeaveServer :" << errorInfo->m_comment.c_str() << std::endl;
		//isReconnect = true;
	};

	Proud::CNetConnectionParam param;

	param.m_protocolVersion = g_ChatProtocolVersion;
	param.m_serverPort = m_serverPort;
	param.m_serverIP = m_ServerIP;

	if (false == m_LoginNetClient->Connect(param))
		return false;

	return true;

}

void ProudChat::CChatClient::Disconnect()
{
	m_LoginNetClient->Disconnect();
	m_ChatNetClient->Disconnect();

	isLogin = false;
}

void ProudChat::CChatClient::FrameMove()
{
	m_LoginNetClient->FrameMove();
	m_ChatNetClient->FrameMove();

	/*if (true == isReconnect)
	{
		connectionState = m_netClient->GetServerConnectionState(state);
		if (connectionState == Proud::ConnectionState_Disconnecting)
		{
			isReconnect = false;
			m_netClient->Connect(param);
		}
	}*/
}

bool ProudChat::CChatClient::isConnected()
{
	return m_ChatNetClient->HasServerConnection() && isLogin;
}

bool ProudChat::CChatClient::Send_Direct_Msg(const String& destUniqueId, const String& msg)
{
	if(msg.GetLength() > MsgLimit)
		return false;
	if (m_ChatNetClient->HasServerConnection())
		return m_ChatProxy.DirectMsg(HostID::HostID_Server, RmiContext::ReliableSend, destUniqueId, msg);
	return false;
}

bool ProudChat::CChatClient::Join_Channel(const String& channelKey)
{
	if (m_ChatNetClient->HasServerConnection())
		return m_ChatProxy.ChannelJoin(HostID::HostID_Server, RmiContext::ReliableSend, channelKey);
	return false;
}

bool ProudChat::CChatClient::Leave_Channel(const String& channelKey) {
	if (m_ChatNetClient->HasServerConnection() && channelList.ContainsKey(channelKey))
		return m_ChatProxy.ChannelLeave(HostID::HostID_Server, RmiContext::ReliableSend, channelKey);
	return false;
}

DEFRMI_LoginToClient_Login_Success(ProudChat::CChatClient) {
	m_LoginNetClient->Disconnect();
	
	m_ChatNetClient->OnJoinServerComplete = [this , secureKey](ErrorInfo* info, const ByteArray& replyFromServer)
	{
		if (info->m_errorType == ErrorType::Ok)
		{
			std::cout << "Succeed to connect server. Allocated hostID=" << m_LoginNetClient->GetLocalHostID() << std::endl;
			//isReconnect = false;
			m_ChatProxy.Connect_Request(HostID::HostID_Server, RmiContext::ReliableSend, secureKey);
		}
		else
		{
			// connection failure.
			//isReconnect = true;
			std::cout << "Failed to connect server." << std::endl;
			std::cout << "errorType = " << (int)info->m_errorType << "detailType = " << (int)info->m_detailType << "comment = " << info->m_comment.c_str() << std::endl;
			if (chatClientJoinFailedDelegate)
				chatClientJoinFailedDelegate(info->m_comment);
		}
	};

	// set a routine for network disconnection.
	m_ChatNetClient->OnLeaveServer = [this](ErrorInfo* errorInfo)
	{
		isLogin = false;
		std::cout << "OnLeaveServer :" << errorInfo->m_comment.c_str() << std::endl;
		if (nullptr != chatDisconnectDelegate)
			chatDisconnectDelegate(errorInfo->m_comment);
		//isReconnect = true;
	};

	Proud::CNetConnectionParam param;

	param.m_protocolVersion = g_ChatProtocolVersion;
	param.m_serverPort = port;
	param.m_serverIP = address;

	if (false == m_ChatNetClient->Connect(param))
		return false;


	return true;
}

DEFRMI_LoginToClient_Login_Failed(ProudChat::CChatClient) {

	if (chatClientJoinFailedDelegate)
		chatClientJoinFailedDelegate(msg);
	return true;
}

DEFRMI_ChatToClient_Connect_Success(ProudChat::CChatClient)
{
	isLogin = true;
	SetUpFiltering(filtering, localFilePath);
	SetUpChannel();

	if(chatClientJoinCompleteDelegate)
		chatClientJoinCompleteDelegate();

	return true;
}

DEFRMI_ChatToClient_Connect_Failed(ProudChat::CChatClient) {
	if (chatClientJoinFailedDelegate)
		chatClientJoinFailedDelegate(msg);

	return true;
}

DEFRMI_ChatToClient_ChannelMsg(ProudChat::CChatClient)
{
	if (nullptr != channelMsg_ResponseDelegate)
	{
		Proud::String filteringMsg = msg;
		m_Filtering->FilteringText(filteringMsg);
		channelMsg_ResponseDelegate(channelKey, srcUniqueID, filteringMsg);
	}
	return true;
}

DEFRMI_ChatToClient_DirectMsg(ProudChat::CChatClient)
{
	if (nullptr != directMsg_ResponseDelegate)
	{
		Proud::String filteringMsg = msg;
		m_Filtering->FilteringText(filteringMsg);
		directMsg_ResponseDelegate(srcUniqueID, filteringMsg);
	}
	return true;
}

bool ProudChat::CChatClient::Send_Channel_Msg(const String& channelKey, const String& msg)
{
	if(msg.GetLength() > MsgLimit)
		return false;

	if (m_ChatNetClient->HasServerConnection() && true == channelList.ContainsKey(channelKey))
		return m_ChatProxy.ChannelMsg(HostID::HostID_Server, RmiContext::ReliableSend, channelKey, msg);
	return false;
}

void ProudChat::CChatClient::SetUpChannel()
{
	if (false == m_ChatNetClient->HasServerConnection())
		return;

	Proud::CFastSet<String>::iterator iter = channelList.begin();
	Proud::CFastSet<String>::iterator iterEnd = channelList.end();

	for (; iter != iterEnd; ++iter)
		m_ChatProxy.ChannelJoin(HostID::HostID_Server, RmiContext::ReliableSend, (*iter));
}

DEFRMI_ChatToClient_Event_Filtering(ProudChat::CChatClient)
{
	SetUpFiltering(filtering, localFilePath);
	return true;
}

DEFRMI_ChatToClient_Event_Notice(ProudChat::CChatClient) {
	if (nullptr != notice_ResponseDelegate)
		notice_ResponseDelegate(context);

	return true;
}

DEFRMI_ChatToClient_ChannelJoin_Success(ProudChat::CChatClient) {
	if (false == channelList.ContainsKey(channelKey))
		channelList.Add(channelKey);

	if (nullptr != channelJoinSuccessDelegate)
		channelJoinSuccessDelegate(channelKey);

	return true;
};
DEFRMI_ChatToClient_ChannelJoin_Failed(ProudChat::CChatClient) {

	if (nullptr != channelJoinFailedDelegate)
		channelJoinFailedDelegate(channelKey, msg);

	return true;
};
DEFRMI_ChatToClient_ChannelLeave_Success(ProudChat::CChatClient) {
	if (true == channelList.ContainsKey(channelKey))
		channelList.Remove(channelKey);

	if (nullptr != channelLeaveSuccessDelegate)
		channelLeaveSuccessDelegate(channelKey);

	return true;
};
DEFRMI_ChatToClient_ChannelLeave_Failed(ProudChat::CChatClient) {

	if (nullptr != channelLeaveFailedDelegate)
		channelLeaveFailedDelegate(channelKey, msg);

	return true;
};

DEFRMI_ChatToClient_MsgTranslate_Success(ProudChat::CChatClient) {
	if (nullptr != msgTranslateSuccessDelegate) {
		Proud::String filteringMsg = msg;
		m_Filtering->FilteringText(filteringMsg);
		msgTranslateSuccessDelegate(msgKey, filteringMsg);
	}
	return true;
};
DEFRMI_ChatToClient_MsgTranslate_Failed(ProudChat::CChatClient) {
	if (nullptr != msgTranslateFailedDelegate)
		msgTranslateFailedDelegate(msgKey, msg);
	return true;
};
DEFRMI_ChatToClient_MsgRecord_Success(ProudChat::CChatClient) {
	if (nullptr != msgRecordSuccessDelegate) {
		tagMsgRecords filteringRecords;
		filteringRecords.msgType = records.msgType;
		for (int i = 0; i < filteringRecords.records.GetCount(); ++i)
		{
			tagMsgRecord record = records.records[i];
			m_Filtering->FilteringText(record.message);
			filteringRecords.records.Add(record);
		}

		msgRecordSuccessDelegate(filteringRecords);
	}
	return true;
};

DEFRMI_ChatToClient_MsgRecord_Failed(ProudChat::CChatClient) {
	if (nullptr != msgRecordFailedDelegate) {
		msgRecordFailedDelegate(msg);
	}
	return true;
};

void ProudChat::CChatClient::SetUpFiltering(const String& filtering, const String& filePath)
{
	m_Filtering->RemoveFiltering();

	
#if PLATFORM_WINDOWS
	std::wstring filterText = TCHAR_TO_WCHAR(*Proud::CFileSync::GetCDNFile(WCHAR_TO_TCHAR(filtering.c_str()), WCHAR_TO_TCHAR(filePath.c_str())));
#elif PLATFORM_ANDROID
	std::wstring filterText = TCHAR_TO_WCHAR(*Proud::CFileSync::GetCDNFile(UTF8_TO_TCHAR(filtering.c_str()), UTF8_TO_TCHAR(filePath.c_str())));
#endif

	//std::wstring filterText;
	m_Filtering->AddFiltering(filterText);
}

bool ProudChat::CChatClient::MsgTranslate(const String& src, const String& target, const String& msgKey, const String& msg)
{
	if(msg.GetLength() > MsgLimit)
		return false;

	if (m_ChatNetClient->HasServerConnection())
		return m_ChatProxy.MsgTranslate(Proud::HostID_Server, Proud::RmiContext::ReliableSend, src, target, msgKey, msg);
	return false;
}

bool ProudChat::CChatClient::MsgTranslate_auto(const String& target, const String& msgKey, const String& msg)
{
	if(msg.GetLength() > MsgLimit)
		return false;

	if (m_ChatNetClient->HasServerConnection())
		return m_ChatProxy.MsgTranslate_auto(Proud::HostID_Server, Proud::RmiContext::ReliableSend, target, msgKey, msg);
	return false;
}

bool ProudChat::CChatClient::MsgRecord_Direct(const String& src , const uint16_t day , const uint16_t cnt)
{
	if (m_ChatNetClient->HasServerConnection())
		return m_ChatProxy.MsgRecord_Direct(HostID_Server, RmiContext::ReliableSend, src , day , cnt);
	return false;
}

bool ProudChat::CChatClient::MsgRecord_Channel(const String& channelKey, const uint16_t day, const uint16_t cnt)
{
	if (m_ChatNetClient->HasServerConnection())
		return m_ChatProxy.MsgRecord_Channel(HostID_Server, RmiContext::ReliableSend, channelKey , day , cnt);
	return false;
}

bool ProudChat::CChatClient::MsgRecord_Notice(const uint16_t day, const uint16_t cnt)
{
	if (m_ChatNetClient->HasServerConnection())
		return m_ChatProxy.MsgRecord_Notice(HostID_Server, RmiContext::ReliableSend , day , cnt);
	return false;
}
