#include "ChatClient.h"

#include "Chat_proxy.cpp"
#include "Chat_stub.cpp"
#include "Chat_common.cpp"
#include "Filtering.h"
#include "FileSync.h"

ProudChat::CChatClient::CChatClient()
	:m_netClient(Proud::CNetClient::Create())
	, m_Filtering(new CFiltering())
{
}

ProudChat::CChatClient::~CChatClient()
{
	if (NULL != m_netClient) {
		delete m_netClient;
		m_netClient = NULL;
	}

	if (nullptr != m_Filtering) {
		delete m_Filtering;
		m_Filtering = nullptr;
	}
}

bool ProudChat::CChatClient::Init(String authUUID, String projectUUID, String uniqueId , std::function<void()> joinDelegateCompleteDelegate , std::function<void(const String& msg)> joinDelegateFailedDelegate)
{
	m_netClient->AttachProxy(&m_ChatProxy);
	m_netClient->AttachStub((ChatS2C::Stub*)this);

	m_authUUID = authUUID;
	m_projectUUID = projectUUID;
	m_uniqueId = uniqueId;

	chatClientJoinCompleteDelegate = joinDelegateCompleteDelegate;
	chatClientJoinFailedDelegate = joinDelegateFailedDelegate;

	m_netClient->OnJoinServerComplete = [this , joinDelegateCompleteDelegate](ErrorInfo* info, const ByteArray& replyFromServer)
	{
		if (info->m_errorType == ErrorType::Ok)
		{
			std::cout << "Succeed to connect server. Allocated hostID=" << m_netClient->GetLocalHostID() << std::endl;
			isReconnect = false;
			m_ChatProxy.Login_Request(HostID::HostID_Server, RmiContext::ReliableSend, m_authUUID, m_projectUUID, m_uniqueId);
		}
		else
		{
			// connection failure.
			isReconnect = true;
			std::cout << "Failed to connect server." << std::endl;
			std::cout << "errorType = " << (int)info->m_errorType << "detailType = " << (int)info->m_detailType << "comment = " << info->m_comment.c_str() << std::endl;
		}
	};

	// set a routine for network disconnection.
	m_netClient->OnLeaveServer = [this](ErrorInfo * errorInfo)
	{
		std::cout << "OnLeaveServer :" << errorInfo->m_comment.c_str() << std::endl;
		isReconnect = true;
	};

	param.m_serverPort = m_serverPort;
	param.m_protocolVersion = g_ChatProtocolVersion;
	param.m_serverIP = m_ServerIP;

	if (false == m_netClient->Connect(param))
		return false;

	return true;

}

void ProudChat::CChatClient::FrameMove()
{
	if (NULL == m_netClient)
		return;

	m_netClient->FrameMove();

	if (true == isReconnect)
	{
		connectionState = m_netClient->GetServerConnectionState(state);
		if (connectionState == Proud::ConnectionState_Disconnecting)
		{
			isReconnect = false;
			m_netClient->Connect(param);
		}
	}

}

void ProudChat::CChatClient::Send_Msg(String destUniqueId, String msg)
{
	if (m_netClient->HasServerConnection())
	{
		m_ChatProxy.SendMsg(HostID::HostID_Server, RmiContext::ReliableSend, destUniqueId, msg);
	}
}

void ProudChat::CChatClient::Add_Channel(String channelKey)
{
	if (m_netClient->HasServerConnection())
		m_ChatProxy.ChannelJoin(HostID::HostID_Server, RmiContext::ReliableSend, channelKey);

	if (false == channelList.ContainsKey(channelKey))
		channelList.Add(channelKey);
}

void ProudChat::CChatClient::Leave_Channel(String channelKey) {
	if (m_netClient->HasServerConnection() && channelList.ContainsKey(channelKey))
		m_ChatProxy.ChannelLeave(HostID::HostID_Server, RmiContext::ReliableSend, channelKey);

	if (true == channelList.ContainsKey(channelKey))
		channelList.Remove(channelKey);
}

DEFRMI_ChatS2C_Login_Response(ProudChat::CChatClient)
{
	if (errorType != Proud::ErrorType::Ok)
	{
		if(chatClientJoinFailedDelegate)
			chatClientJoinFailedDelegate(msg);
		return true;
	}
	SetUpFiltering(filtering, localFilePath);
	SetUpChannel();

	if(chatClientJoinCompleteDelegate)
		chatClientJoinCompleteDelegate();

	return true;
}

DEFRMI_ChatS2C_ChannelMsg(ProudChat::CChatClient)
{
	if (nullptr != channelMsg_ResponseDelegate)
	{
		Proud::String filteringMsg = msg;
		m_Filtering->FilteringText(filteringMsg);
		channelMsg_ResponseDelegate(channelKey, srcUniqueID, filteringMsg);
	}
	return true;
}

DEFRMI_ChatS2C_SendMsg(ProudChat::CChatClient)
{
	if (nullptr != sendMsg_ResponseDelegate)
	{
		Proud::String filteringMsg = msg;
		m_Filtering->FilteringText(filteringMsg);
		sendMsg_ResponseDelegate(srcUniqueID, filteringMsg);
	}
	return true;
}

void ProudChat::CChatClient::Send_ChannelMsg(String channelKey, String msg)
{
	if (m_netClient->HasServerConnection() && true == channelList.ContainsKey(channelKey))
		m_ChatProxy.ChannelMsg(HostID::HostID_Server, RmiContext::ReliableSend, channelKey, msg);
}

void ProudChat::CChatClient::SetUpChannel()
{
	if (false == m_netClient->HasServerConnection())
		return;

	Proud::CFastSet<String>::iterator iter = channelList.begin();
	Proud::CFastSet<String>::iterator iterEnd = channelList.end();

	for (; iter != iterEnd; ++iter)
		m_ChatProxy.ChannelJoin(HostID::HostID_Server, RmiContext::ReliableSend, (*iter));
}

DEFRMI_ChatS2C_Event_Filtering(ProudChat::CChatClient)
{
	SetUpFiltering(filtering, localFilePath);
	return true;
}

DEFRMI_ChatS2C_Event_Notice(ProudChat::CChatClient) {
	if (nullptr != notice_ResponseDelegate)
		notice_ResponseDelegate(context);

	return true;
}

void ProudChat::CChatClient::SetUpFiltering(String filtering, String filePath)
{
	m_Filtering->RemoveFiltering();
	//std::wstring filterText = ProudChat::CFileSync::GetCDNFile(filtering, filePath);
	std::wstring filterText;
	m_Filtering->AddFiltering(filterText);
}
