#pragma once

#include "pch.h"
#include "ProudNetClient.h"

#include "CustomTypeMarshal.h"

#include "ClientToLoginLink_common.h"
#include "ClientToLoginLink_proxy.h"
#include "ClientToLoginLink_stub.h"

#include "ClientChatLink_common.h"
#include "ClientChatLink_proxy.h"
#include "ClientChatLink_stub.h"

#include <unordered_set>

using namespace Proud;
namespace ProudChat {
	class CFiltering;
	class CChatClient 
		: public LoginToClient::Stub
		, public ChatToClient::Stub
	{
	public :
		int16_t MsgLimit = 200;
	public :
		CChatClient();
		virtual ~CChatClient();

	public :
		DECRMI_LoginToClient_Login_Success;
		DECRMI_LoginToClient_Login_Failed;

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
		bool Init(const String& authUUID, const String& projectUUID, const String& uniqueId, std::function<void()> joinDelegateCompleteDelegate , std::function<void(const String& msg)> joinDelegateFailedDelegate);
		
		/// <summary>
		/// Disconnect 하는 부분입니다.
		/// </summary>
		void Disconnect();
		
		/// <summary>
		/// 기본적으로 FrameMove를 호출해 주셔야 이벤트가 발생합니다.
		/// </summary>
		void FrameMove();

	public :

		/// <summary>
		/// Chat서버와의 연결 상태 확인
		/// </summary>
		/// <returns>Chat Server 연결 여부</returns>
		bool isConnected();

		/// <summary>
		/// 특정 상대에게 메시지를 보낼 때 사용합니다. (200자 제한)
		/// </summary>
		/// <param name="destUniqueId">특정 상대방 고유한 식별 값</param>
		/// <param name="msg">특정 상대방에게 보낼 메시지</param>
		/// <returns>전송 성공 여부</returns>
		bool Send_Direct_Msg(const String& destUniqueId, const String& msg);

		/// <summary>
		/// 접속하고 싶은 채널의 키를 입력합니다.
		/// </summary>
		/// <param name="channelKey">접속하고 싶은 채널의 고유 key</param>
		/// <param name="msg">특정 채널에게 보낼 메시지</param>
		bool Join_Channel(const String& channelKey);

		/// <summary>
		/// 접속을 해제하고 싶은 채널의 키를 입력합니다.
		/// </summary>
		/// <param name="channelKey">접속 해제하고 싶은 채널의 고유 key</param>
		/// <param name="msg">특정 채널에게 보낼 메시지</param>
		bool Leave_Channel(const String& channelKey);

		/// <summary>
		/// 특정 채널에게 메시지를 보낼 때 사용합니다. (200자 제한)
		/// </summary>
		/// <param name="channelKey">특정 채널의 고유한 식별 key</param>
		/// <param name="msg">특정 채널에게 보낼 메시지</param>
		bool Send_Channel_Msg(const String& channelKey, const String& msg);

		/// <summary>
		/// 해당 msg 번역을 요청합니다. (Beta 버전)
		/// </summary>
		/// <param name="src">현재 언어 국가 코드</param>
		/// <param name="target">변환할 언어 국가 코드</param>
		/// <param name="msgKey">변환할 메세지의 인식 값</param>
		/// <param name="msg">변환할 메세지</param>
		/// <return>전송 성공 여부</para>
		bool MsgTranslate(const Proud::String& src, const Proud::String& target , const Proud::String& msgKey, const Proud::String& msg);

		/// <summary>
		/// 해당 msg 자동으로 언어를 감지 해 번역을 요청합니다. (Beta 버전)
		/// </summary>
		/// <param name="target">변환할 언어 국가 코드</param>
		/// <param name="msgKey">변환할 메세지의 인식 값</param>
		/// <param name="msg">변환할 메세지</param>
		/// <return>전송 성공 여부</para>
		bool MsgTranslate_Auto(const Proud::String& target , const Proud::String& msgKey, const Proud::String& msg);

		/// <summary>
		/// 해당 채널의 과거 기록을 가져옵니다. 90일 100건까지 (Beta 버전)
		/// </summary>
		/// <param name="channelKey">해당 채널의 키</param>
		/// <param name="day">일수 최대 90</param>
		/// <param name="cnt">해당 채널의 키</param>
		/// <return>전송 성공 여부</para>
		bool MsgRecord_Channel(const Proud::String& channelKey, const uint16_t day, const uint16_t cnt);

		/// <summary>
		/// Direct 메세지의 과거 기록을 가져옵니다. 90일 100건 (Beta 버전)
		/// </summary>
		/// <param name="target">해당 메세지를 보낸 UniqueKey</param>
		/// <param name="day">일수 최대 90</param>
		/// <param name="cnt">해당 채널의 키</param>
		/// <return>전송 성공 여부</para>
		bool MsgRecord_Direct(const Proud::String& target, const uint16_t day, const uint16_t cnt);

		/// <summary>
		/// Notice 의 과거 기록을 가져옵니다. 90일 100건 (Beta 버전)
		/// </summary>
		/// <param name="day">일수 최대 90</param>
		/// <param name="cnt">해당 채널의 키</param>
		/// <return>전송 성공 여부</para>
		bool MsgRecord_Notice(const uint16_t day, const uint16_t cnt);


	private :
		void SetUpChannel();
		void SetUpFiltering(const String& filtering, const String& filePath);

	private:
		/// <summary>
		/// NetClient 객체
		/// </summary>
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
		//ConnectionState connectionState;

		Proud::CFastSet<String> channelList;

		//bool isReconnect = false;


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
		/// Chat Server와 연결이 끊어지면 발생하는 이벤트
		/// <param name="msg">Server 연결이 끊어진 이유 반환</param>
		/// </summary>
		std::function<void(const String& msg)> chatClientDisconnectDelegate = nullptr;

		/// <summary>
		/// 다른 유저가 채널에게 메세지를 보내면은 Delegate되는 이벤트
		/// </summary>
		/// <param name="channelKey">어떤 채널인지의 대한 채널의 고유한 식별 값</param>
		/// <param name="srcUniqueID">채널에 메세지를 올린 상대방의 고유한 식별 값</param>
		/// <param name="msg">상대방이 채널에 보낸 메세지</param>
		std::function<void(const String& channelKey, const String& srcUniqueID, const String& msg)> channelMsg_ResponseDelegate = nullptr;

		/// <summary>
		/// 다른유저가 나에게 Direct 메세지를 보내면은 Delegate되는 이벤트
		/// </summary>
		/// <param name="srcUniqueID">메세지를 보낸 상대방의 고유한 식별 값</param>
		/// <param name="msg">상대방이 나에게 보낸 메세지</param>
		std::function<void(const String& srcUniqueID, const String& msg)> directMsg_ResponseDelegate = nullptr;

		/// <summary>
		/// ProudConsole 에서 공지사항 발송 시 Delegate되는 이벤트
		/// </summary>
		/// <param name="msg">공지사항 내용을 출력합니다</param>
		std::function<void(const String& msg)> noticeDelegate = nullptr;

		/// <summary>
		/// Channel Join 성공 시 Delegate되는 이벤트
		/// </summary>
		/// <param name="channelKey">Join성공한 ChannelKey</param>
		std::function<void(const Proud::String& channelKey)> channelJoinSuccessDelegate = nullptr;

		/// <summary>
		/// Channel Join 실패 시 Delegate되는 이벤트
		/// </summary>
		/// <param name="channelKey">Join실패한 ChannelKey</param>
		/// <param name="msg">Join실패한 이유</param>
		std::function<void(const Proud::String& channelKey , const Proud::String& msg)> channelJoinFailedDelegate = nullptr;

		/// <summary>
		/// Channel Leave 성공 시 Delegate되는 이벤트
		/// </summary>
		/// <param name="channelKey">Leave성공한 ChannelKey</param>
		std::function<void(const Proud::String& channelKey)> channelLeaveSuccessDelegate = nullptr;

		/// <summary>
		/// Channel Leave 실패 시 Delegate되는 이벤트
		/// </summary>
		/// <param name="channelKey">Leave 실패한 ChannelKey</param>
		/// <param name="msg">Leave 실패한 이유</param>
		std::function<void(const Proud::String& channelKey, const Proud::String& msg)> channelLeaveFailedDelegate = nullptr;

		/// <summary>
		/// Translate 성공 시 Delegate 되는 이벤트
		/// <param name="msgKey">변환할 메세지의 인식 값</param>
		/// <param name="msg">Translate 성공한 Msg</param>
		/// </summary>
		std::function<void(const Proud::String& msgKey , const Proud::String& msg)> msgTranslateSuccessDelegate = nullptr;

		/// <summary>
		/// Translate 실패 시 Delegate 되는 이벤트
		/// <param name="msgKey">변환할 메세지의 인식 값</param>
		/// <param name="msg">Translate 실패한 이유</param>
		/// </summary>
		std::function<void(const Proud::String& msgKey , const Proud::String& msg)> msgTranslateFailedDelegate = nullptr;

		/// <summary>
		/// 과거 기록 가져오기 성공 시 Delegate 되는 이벤트
		/// <param name="records">과거의 기록들의 정보</param>
		/// </summary>
		std::function<void(const tagMsgRecords& records)> msgRecordSuccessDelegate = nullptr;

		/// <summary>
		/// 과거 기록 가져오기 실패 시 Delegate 되는 이벤트
		/// 과거 기록이 없어도 Failed 이벤트가 발생합니다.
		/// <param name="records">과거의 기록들의 정보</param>
		/// </summary>
		std::function<void(const Proud::String& msg)> msgRecordFailedDelegate = nullptr;
	};
}


