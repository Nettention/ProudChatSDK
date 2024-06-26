using Nettention.Proud;
using ProudChat;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using static ChatToClient.Stub;

namespace Proud
{
    public class ChatClient
    {
        public ChatClient() {
            InitStub();

            LoginNetClient.AttachProxy(LoginProxy);
            LoginNetClient.AttachStub(LoginStub);

            ChatNetClient.AttachStub(ChatStub);
            ChatNetClient.AttachProxy(ChatProxy);
        }

        private static System.Guid m_Version = new System.Guid("{0x587372c5,0x0d61,0x45f7,{0xbb,0xa2,0x36,0x4a,0x37,0x12,0x10,0x01}}");
        private static System.String m_ServerIP = "chat-lb-2d547d8ff8aaf11f.elb.ap-northeast-2.amazonaws.com";
        private static ushort m_serverPort = 80;
        private static string localFilePath = "filtering.txt"; // 로컬에 저장될 파일 경로를 입력하세요.
        private static ushort msgLimit = 200;

        /// <summary>
        /// NetClient 객체
        /// </summary>
        private Nettention.Proud.NetClient LoginNetClient = new Nettention.Proud.NetClient();
        private Nettention.Proud.NetClient ChatNetClient = new Nettention.Proud.NetClient();

        private String authUUID;
        private String projectUUID;
        private String uniqueId;
        private ServerConnectionState state = new ServerConnectionState();
        private bool isLogin = false;
        //private ConnectionState connectionState;
        private Filtering m_Filtering = new Filtering();


        private HashSet<String> channelList = new HashSet<String>();

        //private bool isReconnect = false;

        //Login Service
        private ClientToLogin.Proxy LoginProxy = new ClientToLogin.Proxy();
        private LoginToClient.Stub LoginStub = new LoginToClient.Stub();

        //Chat Service
        private ClientToChat.Proxy ChatProxy = new ClientToChat.Proxy();
        private ChatToClient.Stub ChatStub = new ChatToClient.Stub();

        /// <summary>
        /// Server Connection 완료 후 Login까지 성공하면 호출되는 함수
        /// 사용자는 Event를 등록하여 사용할 수 있습니다.
        /// </summary>
        public delegate void ChatClientJoinComplete();
        private ChatClientJoinComplete chatClientJoinCompleteDelegate = null;

        /// <summary>
        /// Server Login 실패 시 호출되는 함수
        /// 이 함수를 타게 되는 시점은 서버와의 연결은 성공하였으나 계정 로그인을 못할때 발생하는 이벤트입니다.
        /// 이 부분은 실패시 재시도를 하지 않으므로 설정 확인이 필요합니다.
        /// 사용자는 Event를 등록하여 사용할 수 있습니다.
        /// </summary>
        /// <param name="errorMsg">Server Login 실패 시 에러를 반환해준다.</param>
        public delegate void ChatClientJoinFailed(System.String errorMsg);
        private ChatClientJoinFailed chatClientJoinFailedDelegate = null;

        /// <summary>
        /// Chat 서버와 연결이 끊어지면 발생하는 이벤트 입니다.
        /// </summary>
        /// <param name="errorMsg">Server 와의 연결이 끊어진 에러를 반환해줍니다</param>
        public delegate void ChatDisconnect(System.String errorMsg);
        private ChatDisconnect chatDisconnectDelegate = null;
        public ChatDisconnect Chat_DisconnectDelegate
        {
            set { chatDisconnectDelegate = value; }
        }

        /// <summary>
        /// Channel Message가 도착했을 때 발생하는 이벤트 
        /// 사용자는 Event를 등록하여 사용할 수 있습니다.
        /// </summary>
        /// <param name="channelKey">메시지가 온 Channel의 고유한 key</param>
        /// <param name="srcUniqueID">메시지를 발생시킨 유저의 UniqueID</param>
        /// <param name="msg">상대방이 보낸 메시지</param>
        public delegate void ChannelMsg_Response(System.String channelKey, System.String srcUniqueID, System.String msg);
        private ChannelMsg_Response channelMsg_ResponseDelegate = null;
        public ChannelMsg_Response ChannelMsg_ResponseDelegate
        {
            set {channelMsg_ResponseDelegate = value; }
        }

        /// <summary>
        /// Send Message가 도착했을 때 발생하는 이벤트
        /// 사용자는 Event를 등록하여 사용할 수 있습니다.
        /// </summary>
        /// <param name="srcUniqueID">메시지를 보낸 유저의 UniqueID</param>
        /// <param name="msg">상대방이 보낸 메시지</param>
        public delegate void DirectMsg_Response(System.String srcUniqueID, System.String msg);
        private DirectMsg_Response directMsg_ResponseDelegate = null;

        public DirectMsg_Response DirectMsg_ResponseDelegate
        {
            set { directMsg_ResponseDelegate = value;}
        }

        /// <summary>
        /// 공지사항이 도착했을 때 발생하는 이벤트 
        /// 사용자는 Event를 등록하여 사용할 수 있습니다.
        /// </summary>
        /// <param name="msg">Proud Console에서 발송 된 공지사항 내용 </param>
        public delegate void Notice_Response(System.String msg);
        private Notice_Response notice_ResponseDelegate = null;

        public Notice_Response Notice_ResponseDelegate
        {
            set { notice_ResponseDelegate = value; }
        }

        /// <summary>
        /// 채널 접속이 완료되면 발생하는 이벤트
        /// </summary>
        /// <param name="channelKey">접속 성공한 ChannelKey </param>
        public delegate void Channel_Join_Success(System.String channelKey);
        private Channel_Join_Success channelJoinSuccessDelegate = null;

        public Channel_Join_Success ChannelJoinSuccessDelegate
        {
            set { channelJoinSuccessDelegate = value; }
        }


        /// <summary>
        /// 채널 접속이 실패하면 발생하는 이벤트
        /// </summary>
        /// <param name="channelKey">접속 실패한 ChannelKey</param>
        /// <param name="msg">접속 실패한 사유</param>
        public delegate void Channel_Join_Failed(System.String channelKey , System.String msg);
        private Channel_Join_Failed channelJoinFailedDelegate = null;

        public Channel_Join_Failed ChannelJoinFailedDelegate
        {
            set { channelJoinFailedDelegate = value; }
        }

        /// <summary>
        /// 채널 접속 해제가 완료되면 발생하는 이벤트
        /// </summary>
        /// <param name="channelKey">접속 해제 성공한 ChannelKey </param>
        public delegate void Channel_Leave_Success(System.String channelKey);
        private Channel_Leave_Success channelLeaveSuccessDelegate = null;

        public Channel_Leave_Success ChannelLeaveSuccessDelegate
        {
            set { channelLeaveSuccessDelegate = value; }
            
        }

        /// <summary>
        /// 채널 접속 해제가 실패하면 발생하는 이벤트
        /// </summary>
        /// <param name="channelKey">해제 실패한 ChannelKey</param>
        /// <param name="msg">해제 실패한 사유</param>
        public delegate void Channel_Leave_Failed(System.String channelKey, System.String msg);
        private Channel_Leave_Failed channelLeaveFailedDelegate = null;
        public Channel_Leave_Failed ChannelLeaveFailedDelegate
        {
            set { channelLeaveFailedDelegate = value; }
        }

        /// <summary>
        /// 번역 성공 시 발생하는 이벤트 (Beta)
        /// </summary>
        /// <param name="msgKey">메세지 인식 Key</param>
        /// <param name="msg">번역이 완료된 메세지</param>
        public delegate void Msg_Translate_Success(System.String msgKey , System.String msg);
        private Msg_Translate_Success msgTranslateSuccessDelegate = null;
        public Msg_Translate_Success MsgTranslateSuccessDelegate
        {
            set { msgTranslateSuccessDelegate = value; }
        }

        /// <summary>
        /// 번역 실패시 발생하는 이벤트 (Beta)
        /// </summary>
        /// <param name="msgKey">메세지 인식 Key</param>
        /// <param name="msg">번역 실패 사유</param>
        public delegate void Msg_Translate_Failed(System.String msgKey , System.String msg);
        private Msg_Translate_Failed msgTranslateFailedDelegate = null;
        public Msg_Translate_Failed MsgTranslateFailedDelegate
        {
            set { MsgTranslateFailedDelegate = value; }
        }

        /// <summary>
        /// 과거 메세지 기록 불러오기 최대 90일 100건 (Beta)
        /// </summary>
        /// <param name="records">과거의 메세지 기록 데이터</param>
        public delegate void Msg_Record_Success(tagMsgRecords records);
        private Msg_Record_Success msgRecordSuccessDelegate = null;
        public Msg_Record_Success MsgRecordSuccessDelegate
        {
            set { msgRecordSuccessDelegate = value; }
        }

        /// <summary>
        /// 과거 메세지 기록 불러오기 최대 90일 100건 (Beta)
        /// </summary>
        /// <param name="records">과거의 메세지 기록 데이터</param>
        public delegate void Msg_Record_Failed(System.String msg);
        private Msg_Record_Failed msgRecordFailedDelegate = null;
        public Msg_Record_Failed MsgRecordFailedDelegate
        {
            set { msgRecordFailedDelegate = value; }
        }


        private void InitStub()
        {
            ChatStub.Connect_Success = Connect_Success;
            ChatStub.Connect_Failed = Connect_Failed;
            ChatStub.ChannelMsg = ChannelMsg_Stub;
            ChatStub.DirectMsg = DirectMsg_Stub;
            ChatStub.Event_Filtering = Event_Filtering;
            ChatStub.Event_Notice = Event_Notice;
            ChatStub.ChannelJoin_Success = ChannelJoin_Success;
            ChatStub.ChannelJoin_Failed = ChannelJoin_Failed;
            ChatStub.ChannelLeave_Success = ChannelLeave_Success;
            ChatStub.ChannelLeave_Failed = ChannelLeave_Failed;
            ChatStub.MsgTranslate_Success = MsgTranslate_Success;
            ChatStub.MsgTranslate_Failed = MsgTranslate_Failed;
            ChatStub.MsgRecord_Success = MsgRecord_Success;
            ChatStub.MsgRecord_Failed = MsgRecord_Failed;


            LoginStub.Login_Success = Login_Success;
            LoginStub.Login_Failed = Login_Failed;
        }

        /// <summary>
        /// 서버와의 연결이 되어있는지 확인하는 함수
        /// </summary>
        /// <returns>서버 연결이 상태 여부</returns>
        public bool isConnected()
        {
            return ChatNetClient.HasServerConnection() && isLogin;
        }

        /// <summary>
        /// ProudChat을 Init하는 부분입니다.
        /// 유저는 사용전에 꼭 Init을 호출하여 서버와의 연결을 해주셔야합니다.
        /// </summary>
        /// <param name="authUUID">>https://console.nettention.com 에서 제공되는 유저의 UUID를 입력해주세요</param>
        /// <param name="projectUUID">https://console.nettention.com 에서 제공되는 Project의 UUID를 입력해주세요</param>
        /// <param name="uniqueId">
        /// 고유의 키값을 입력해주세요. 
        /// 각각의 유저는 다른 고유의 UniqueID를 갖으셔야합니다.
        /// UniqueID가 중복 시 상대 먼저 접속한 UniqueID를 가진 유저는 로그아웃 처리가 진행됩니다.</param>
        /// <returns></returns>
        public bool Init(String authUUID, String projectUUID, String uniqueId
            , ChatClientJoinComplete joinDelegateCompleteDelegate
            , ChatClientJoinFailed joinDelegateFailedDelegate)
        {
            LoginNetClient.Disconnect();
            ChatNetClient.Disconnect();

            isLogin = false;

            this.authUUID = authUUID;
            this.projectUUID = projectUUID;
            this.uniqueId = uniqueId;

            this.chatClientJoinCompleteDelegate = joinDelegateCompleteDelegate;
            this.chatClientJoinFailedDelegate = joinDelegateFailedDelegate;

            LoginNetClient.JoinServerCompleteHandler = (info, replyFromServer) =>
            {
                if (info.errorType == ErrorType.Ok)
                {
                    LoginProxy.Login_Request(HostID.HostID_Server, RmiContext.ReliableSend, this.authUUID, this.projectUUID, this.uniqueId);
                }
                else
                {
                    Console.Write("Failed to connect server.\n");
                    Console.WriteLine("errorType = {0}, detailType = {1}, comment = {2}", info.errorType, info.detailType, info.comment);
                    if (null != chatClientJoinFailedDelegate)
                        chatClientJoinFailedDelegate(info.comment);
                }
            };

            // set a routine for network disconnection.
            LoginNetClient.LeaveServerHandler = (errorInfo) =>
            {
                Console.Write("OnLeaveServer: {0}\n", errorInfo.comment);
            };

            Nettention.Proud.NetConnectionParam loginParam = new Nettention.Proud.NetConnectionParam();

            loginParam.protocolVersion = new Nettention.Proud.Guid();
            loginParam.protocolVersion.Set(m_Version);
            loginParam.serverPort = m_serverPort;
            loginParam.serverIP = m_ServerIP;

            if (false == LoginNetClient.Connect(loginParam))
                return false;

            return true;
        }

        /// <summary>
        /// Disconnect시 호출하는 함수
        /// </summary>
        public void Disconnect()
        {
            LoginNetClient.Disconnect();
            ChatNetClient.Disconnect();

            isLogin = false;
        }

        /// <summary>
        /// 기본적으로 FrameMove를 진행해주셔야 이벤트가 발생합니다.
        /// </summary>
        public void FrameMove()
        {
            LoginNetClient.FrameMove();
            ChatNetClient.FrameMove();

            //if(true == isReconnect)
            //{
            //    connectionState = netClient.GetServerConnectionState(state);
            //    if (connectionState == ConnectionState.ConnectionState_Disconnecting)
            //    {
            //        isReconnect = false;
            //        netClient.Connect(param);
            //    }
            //}
        }

        //로그인 완료 되었다 로그인 서버와의 연결은 끊고 ChatServer의 요청을 보내자
        private bool Login_Success(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String secureKey, System.String address, UInt16 port)
        {
            LoginNetClient.Disconnect();

            ChatNetClient.JoinServerCompleteHandler = (info, replyFromServer) =>
            {
                if (info.errorType == ErrorType.Ok)
                {
                    //Connect 요청을 보낸다
                    ChatProxy.Connect_Request(HostID.HostID_Server, RmiContext.ReliableSend, secureKey);
                }
                else
                {
                    Console.Write("Failed to connect server.\n");
                    Console.WriteLine("errorType = {0}, detailType = {1}, comment = {2}", info.errorType, info.detailType, info.comment);

                    if (null != chatClientJoinFailedDelegate)
                        chatClientJoinFailedDelegate(info.comment);
                }
            };

            // set a routine for network disconnection.
            ChatNetClient.LeaveServerHandler = (errorInfo) =>
            {
                Console.Write("OnLeaveChatServer: {0}\n", errorInfo.comment);
                isLogin = false;
                if (null != chatDisconnectDelegate)
                    chatDisconnectDelegate(errorInfo.comment);
            };


            Nettention.Proud.NetConnectionParam chatParam = new Nettention.Proud.NetConnectionParam();

            chatParam.protocolVersion = new Nettention.Proud.Guid();
            chatParam.protocolVersion.Set(m_Version);
            chatParam.serverPort = port;
            chatParam.serverIP = address;

            if (false == ChatNetClient.Connect(chatParam))
                return false;


            return true;
        }

        //로그인 실패를 하였다 로그인 실패 원인을 분석하라
        private bool Login_Failed(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String msg)
        {
            if (chatClientJoinFailedDelegate != null)
                chatClientJoinFailedDelegate(msg);
            return true;
        }

        /// <summary>
        /// 로그인 시 Delegate되는 함수
        /// </summary>
        private bool Connect_Success(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String filtering, System.String msg)
        {
            isLogin = true;
            Console.WriteLine(msg);
            
            SetUpFiltering(filtering, localFilePath);

            SetUpChannel();

            if (chatClientJoinCompleteDelegate != null)
                chatClientJoinCompleteDelegate();

            return true;
        }

        //Chat Server와의 연결에 실패하였다.
        private bool Connect_Failed(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String msg)
        {
            if(chatClientJoinFailedDelegate != null)
                chatClientJoinFailedDelegate(msg);
            return true;
        }

        /// <summary>
        /// 다른 유저가 채널에게 메세지를 보내면은 Delegate되는 함수
        /// </summary>
        /// <param name="channelKey">어떤 채널인지의 대한 채널의 고유한 식별 값</param>
        /// <param name="srcUniqueID">채널에 메세지를 올린 상대방의 고유한 식별 값</param>
        /// <param name="msg">상대방이 채널에 보낸 메세지</param>
        private bool ChannelMsg_Stub(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String channelKey, System.String srcUniqueID, System.String msg)
        {
            if (null != channelMsg_ResponseDelegate)
            {
                m_Filtering.FilteringText(ref msg);
                channelMsg_ResponseDelegate(channelKey, srcUniqueID, msg);
            }
            return true;
        }

        /// <summary>
        /// 다른유저가 나에게 메세지를 보내면은 Delegate되는 함수
        /// </summary>
        /// <param name="srcUniqueID">메세지를 보낸 상대방의 고유한 식별 값</param>
        /// <param name="msg">상대방이 나에게 보낸 메세지</param>
        private bool DirectMsg_Stub(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String srcUniqueID, System.String msg)
        {
            if (null != directMsg_ResponseDelegate)
            {
                m_Filtering.FilteringText(ref msg);
                directMsg_ResponseDelegate(srcUniqueID, msg);
            }
            return true;
        }

        /// <summary>
        /// 특정 채널에게 메세지를 보낼 때 사용합니다.
        /// </summary>
        /// <param name="channelKey">특정 채널의 고유한 식별 값</param>
        /// <param name="msg">특정 채널에게 보낼 메세지</param>
        public bool Send_Channel_Msg(System.String channelKey, System.String msg)
        {
            if (msg.Length > msgLimit)
                return false;

            if (ChatNetClient.HasServerConnection() && channelList.Contains(channelKey))
                return ChatProxy.ChannelMsg(HostID.HostID_Server, RmiContext.ReliableSend, channelKey, msg);

            return false;
        }

        /// <summary>
        /// 특정 상대에게 메세지를 보낼 때 사용합니다.
        /// </summary>
        /// <param name="destUniqueId">특정 상대방 고유한 식별 값</param>
        /// <param name="msg">특정 상대방에게 보낼 메세지</param>
        public bool Send_Direct_Msg(System.String destUniqueId, System.String msg)
        {
            if (msg.Length > msgLimit)
                return false;

            if (ChatNetClient.HasServerConnection())
                return ChatProxy.DirectMsg(HostID.HostID_Server, RmiContext.ReliableSend, destUniqueId, msg);

            return false;
        }

        /// <summary>
        /// 접속하고 싶은 채널의 키를 입력합니다.
        /// </summary>
        /// <param name="channelKey">접속하고 싶은 채널의 고유 Key</param>
        public bool Join_Channel(System.String channelKey)
        {
            if (ChatNetClient.HasServerConnection())
                return ChatProxy.ChannelJoin(HostID.HostID_Server , RmiContext.ReliableSend, channelKey);
            return false;
        }

        /// <summary>
        /// 접속한 채널에서 나가고 싶을때
        /// </summary>
        /// <param name="channelKey">나가고 싶은 채널의 고유 Key</param>
        public bool Leave_Channel(System.String channelKey)
        {
            if (ChatNetClient.HasServerConnection() && channelList.Contains(channelKey))
                return ChatProxy.ChannelLeave(HostID.HostID_Server, RmiContext.ReliableSend, channelKey);
            return false;

        }


        /// <summary>
        /// 번역 요청 하기 (Beta)
        /// </summary>
        /// <param name="src">시작 언어 국가 코드</param>
        /// <param name="target">번역 언어 국가 코드</param>
        /// <param name="msgKey">메세지 인식 Key</param>
        /// <param name="msg">번역할 메세지</param>
        public bool MsgTranslate(System.String src, System.String target, System.String msgKey , System.String msg)
        {
            if(msgKey.Length > msgLimit) return false;

            if (ChatNetClient.HasServerConnection())
                return ChatProxy.MsgTranslate(HostID.HostID_Server, RmiContext.ReliableSend , src, target, msgKey , msg);
            
            return false;
        }

        /// <summary>
        /// 자동 번역 요청 하기 (Beta)
        /// </summary>
        /// <param name="target">번역 언어 국가 코드</param>
        /// <param name="msgKey">메세지 인식 키</param>
        /// <param name="msg">번역할 메세지</param>
        public bool MsgTranslate_Auto(System.String target, System.String msgKey , System.String msg)
        {
            if (msgKey.Length > msgLimit)
                return false;

            if (ChatNetClient.HasServerConnection())
                return ChatProxy.MsgTranslate_auto(HostID.HostID_Server , RmiContext.ReliableSend , target , msgKey , msg);

            return false;
        }

        /// <summary>
        /// 채널의 과거 기록 가져오기 최대 90일 100건 (Beta)
        /// </summary>
        /// <param name="channelKey">해당 채널 키</param>
        /// <param name="day">기록을 가져올 날짜</param>
        /// <param name="cnt">기록을 가져올 갯수</param>
        public bool MsgRecord_Channel(System.String channelKey , UInt16 day , UInt16 cnt)
        {
            if (ChatNetClient.HasServerConnection())
                return ChatProxy.MsgRecord_Channel(HostID.HostID_Server, RmiContext.ReliableSend, channelKey , day , cnt);
            return false;
        }

        /// <summary>
        /// Direct 메세지 과거 기록 가져오기 최대 90일 100건 (Beta)
        /// </summary>
        /// <param name="src">메세지 보낸 유저 Key</param>
        public bool MsgRecord_Direct(System.String src, UInt16 day, UInt16 cnt)
        {
            if (ChatNetClient.HasServerConnection())
                return ChatProxy.MsgRecord_Direct(HostID.HostID_Server, RmiContext.ReliableSend, src, day, cnt);
            return false;
        }

        /// <summary>
        /// Notice 메세지 과거 기록 가져오기 최대 90일 100건 (Beta)
        /// </summary>
        public bool MsgRecord_Notice(UInt16 day, UInt16 cnt)
        {
            if (ChatNetClient.HasServerConnection())
                return ChatProxy.MsgRecord_Notice(HostID.HostID_Server, RmiContext.ReliableSend , day , cnt);
            return false;
        }
        private void SetUpChannel()
        {
            if (false == ChatNetClient.HasServerConnection())
                return;

            foreach(var channelKey in channelList)
                ChatProxy.ChannelJoin(HostID.HostID_Server, RmiContext.ReliableSend, channelKey);
        }

        private bool Event_Filtering(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String filtering)
        {
            SetUpFiltering(filtering, localFilePath);
            return true;
        }

        /// <summary>
        /// ProudConsole 에서 공지사항 발송 시 Delegate되는 함수
        /// </summary>
        /// <param name="context">공지사항 내용을 출력합니다</param>
        private bool Event_Notice(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String context)
        {
            if (null != notice_ResponseDelegate)
                notice_ResponseDelegate(context);

            return true;
        }

        /// <summary>
        /// ProudChat에서 Channel Join 성공 시 Delegate되는 함수
        /// </summary>
        /// <param name="channelKey">Channel Join 성공한 ChannelKey</param>
        /// <returns></returns>
        private bool ChannelJoin_Success(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String channelKey)
        {
            if (false == channelList.Contains(channelKey))
                channelList.Add(channelKey);

            if(null != channelJoinSuccessDelegate)
                channelJoinSuccessDelegate(channelKey);

            return true;
        }

        /// <summary>
        /// ProudChat에서 Channel Join 실패 시 Delegate 되는 함수
        /// </summary>
        /// <param name="channelKey">Channel Join 실패한 ChannelKey</param>
        /// <param name="msg">Channel Join 실패한 이유</param>
        /// <returns></returns>
        private bool ChannelJoin_Failed(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String channelKey, System.String msg)
        {
            if (null != channelJoinFailedDelegate)
                channelJoinFailedDelegate(channelKey, msg);

            return true;
        }

        /// <summary>
        /// ProudChat에서 Channel Leave 성공 시 Delegate 되는 함수
        /// </summary>
        /// <param name="channelKey">Channel Leave 성공한 ChannelKey</param>
        /// <returns></returns>
        private bool ChannelLeave_Success(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String channelKey)
        {
            if (true == channelList.Contains(channelKey))
                channelList.Remove(channelKey);

            if(null != channelLeaveSuccessDelegate) 
                channelLeaveSuccessDelegate(channelKey);

            return true;
        }

        /// <summary>
        /// ProudChat에서 Channel Leave 실패 시 Delegate 되는 함수
        /// </summary>
        /// <param name="channelKey">Channel Leave 실패한 ChannelKey</param>
        /// <param name="msg">Channel Leave 실패한 이유</param>
        /// <returns></returns>
        private bool ChannelLeave_Failed(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String channelKey, System.String msg)
        {
            if(null != channelLeaveFailedDelegate)
                channelLeaveFailedDelegate(channelKey, msg);
            return true;
        }

        /// <summary>
        /// ProudChat Translate Success 시 Delegate 되는 함수
        /// </summary>
        /// <param name="msg">번역 완료 된 메세지</param>
        /// <returns></returns>
        private bool MsgTranslate_Success(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String msgKey , System.String msg)
        {
            if (null != msgTranslateSuccessDelegate)
                msgTranslateSuccessDelegate(msgKey , msg);
            return true;
        }

        /// <summary>
        /// ProudChat Translate Failed 시 Delegate 되는 함수
        /// </summary>
        /// <param name="msg">번역 실패 사유</param>
        /// <returns></returns>
        private bool MsgTranslate_Failed(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String msgKey , System.String msg)
        {
            if(null != msgTranslateFailedDelegate)
                msgTranslateFailedDelegate(msgKey , msg);
            return true;
        }

        /// <summary>
        /// ProudChat 과거 기록 가져오기 성공 시 Delegate 되는 함수
        /// </summary>
        /// <param name="records">과거 기록 데이터</param>
        /// <returns></returns>
        private bool MsgRecord_Success(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, tagMsgRecords records)
        {
            if (null != msgRecordSuccessDelegate) { 
                foreach(var  record in records.records)
                    m_Filtering.FilteringText(ref record.message);
                msgRecordSuccessDelegate(records);
            }
            return true;
        }

        /// <summary>
        /// ProudChat 과거 기록 가져오기 실패 시 Delegate 되는 함수
        /// 과거 데이터가 0이여도 Failed 이벤트 발생
        /// </summary>
        /// <param name="msg">실패 사유</param>
        /// <returns></returns>
        private bool MsgRecord_Failed(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String msg)
        {
            if (null != msgRecordFailedDelegate)
                msgRecordFailedDelegate(msg);
            return true;
        }

        private void SetUpFiltering(System.String filtering , System.String filePath)
        {
            m_Filtering.RemoveFiltering();
            System.String filterText = Proud.FileSync.GetCDNFile(filtering, filePath);
            if (null != filterText)
                m_Filtering.AddFiltering(filterText);
        }
        public List<string> GetChannel()
        {
            return channelList.ToList();
        }
    }
}
