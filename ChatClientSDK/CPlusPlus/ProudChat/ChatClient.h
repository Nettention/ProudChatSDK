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
		/// <summary>
		/// ProudChat을 Init하는 부분입니다.
		/// 유저는 사용전에 꼭 Init을 호출하여 서버와의 연결을 해주셔야합니다.
		/// </summary>
		/// <param name="authUUID">https://console.nettention.com 에서 제공되는 유저의 UUID를 입력해주세요</param>
		/// <param name="projectUUID">https://console.nettention.com 에서 제공되는 Project의 UUID를 입력해주세요</param>
		/// <param name="uniqueID">
		/// 고유의 키값을 입력해주세요. 
		/// 각각의 유저는 다른 고유의 UniqueID를 갖으셔야합니다.
		/// UniqueID가 중복 시 상대 먼저 접속한 UniqueID를 가진 유저는 로그아웃 처리가 진행됩니다.</param>
		/// <returns></returns>
		bool Init(String authUUID, String projectUUID, String uniqueId, std::function<void()> joinDelegateCompleteDelegate , std::function<void(const String& msg)> joinDelegateFailedDelegate);

		/// <summary>
		/// 기본적으로 FrameMove를 호출해 주셔야 이벤트가 발생합니다.
		/// </summary>
		void FrameMove();

	public :
		/// <summary>
		/// 특정 상대에게 메시지를 보낼 때 사용합니다.
		/// </summary>
		/// <param name="destUniqueId">특정 상대방 고유한 식별 값</param>
		/// <param name="msg">특정 상대방에게 보낼 메시지</param>
		void Send_Msg(String destUniqueId, String msg);

		/// <summary>
		/// 접속하고 싶은 채널의 키를 입력합니다.
		/// </summary>
		/// <param name="channelKey">접속하고 싶은 채널의 고유 key</param>
		void Add_Channel(String channelKey);

		/// <summary>
		/// 접속을 해제하고 싶은 채널의 키를 입력합니다.
		/// </summary>
		/// <param name="channelKey">접속 해제하고 싶은 채널의 고유 key</param>
		void Leave_Channel(String channelKey);

		/// <summary>
		/// 특정 채널에게 메시지를 보낼 때 사용합니다.
		/// </summary>
		/// <param name="channelKey">특정 채널의 고유한 식별 key</param>
		/// <param name="msg">특정 채널에게 보낼 메시지</param>
		void Send_ChannelMsg(String channelKey, String msg);

		void SetUpChannel();
		void SetUpFiltering(String filtering, String filePath);

	private :


	private:
		/// <summary>
		/// NetClient 객체
		/// </summary>
		CNetClient* m_netClient = NULL;
		ChatC2S::Proxy m_ChatProxy;

	private :
		CFiltering* m_Filtering = nullptr;

	private:
		Guid g_ChatProtocolVersion = Guid({ 0x587372c5,0x0d61,0x45f7,{0xbb,0xa2,0x36,0x4a,0x37,0x12,0x10,0x01} });
		Proud::String m_ServerIP = _PNT("chat-lb-2d547d8ff8aaf11f.elb.ap-northeast-2.amazonaws.com");
		unsigned short m_serverPort = 80;
		Proud::String localFilePath = _PNT("filtering.txt"); // 로컬에 저장될 파일 경로를 입력하세요.

		/// <summary>
		/// 서버 시작에 필요한 Parameter
		/// </summary>
		Proud::CNetConnectionParam param;

		String m_authUUID;
		String m_projectUUID;
		String m_uniqueId;
		Proud::CServerConnectionState state;
		ConnectionState connectionState;

		Proud::CFastSet<String> channelList;

		bool isReconnect = false;


	private :
		/// <summary>
		/// Server Connection 완료 후 Login까지 성공하면 호출되는 이벤트 
		/// </summary>
		std::function<void()> chatClientJoinCompleteDelegate = nullptr;

	public :
		/// <summary>
		/// Server Login 실패 시 호출되는 이벤트
		/// 이 함수를 타게 되는 시점은 서버와의 연결은 성공하였으나 계정 로그인을 못할 때 발생하는 이벤트 입니다.
		/// 이 부분은 실패 시 재시도를 하지 않으므로 설정 확인이 필요합니다.
		/// <param name="msg">Server Login 실패 시 에러를 반환해준다.</param>
		/// </summary>
		std::function<void(const String& msg)> chatClientJoinFailedDelegate = nullptr;

		/// <summary>
		/// 다른 유저가 채널에게 메세지를 보내면은 Delegate되는 이벤트
		/// </summary>
		/// <param name="channelKey">어떤 채널인지의 대한 채널의 고유한 식별 값</param>
		/// <param name="srcUniqueID">채널에 메세지를 올린 상대방의 고유한 식별 값</param>
		/// <param name="msg">상대방이 채널에 보낸 메세지</param>
		std::function<void(const String& channelKey, const String& srcUniqueID, const String& msg)> channelMsg_ResponseDelegate = nullptr;

		/// <summary>
		/// 다른유저가 나에게 메세지를 보내면은 Delegate되는 이벤트
		/// </summary>
		/// <param name="srcUniqueID">메세지를 보낸 상대방의 고유한 식별 값</param>
		/// <param name="msg">상대방이 나에게 보낸 메세지</param>
		std::function<void(const String& srcUniqueID, const String& msg)> sendMsg_ResponseDelegate = nullptr;

		/// <summary>
		/// ProudConsole 에서 공지사항 발송 시 Delegate되는 이벤트
		/// </summary>
		/// <param name="msg">공지사항 내용을 출력합니다</param>
		std::function<void(const String& msg)> noticeDelegate = nullptr;
	};
}


