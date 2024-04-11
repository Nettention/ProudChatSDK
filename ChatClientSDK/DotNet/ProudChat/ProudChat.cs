using Nettention.Proud;
using ProudChat;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using static Proud.ChatClient;

namespace Proud
{
    public class ChatClient
    {
        public ChatClient() { }

        private static System.Guid m_Version = new System.Guid("{0x587372c5,0x0d61,0x45f7,{0xbb,0xa2,0x36,0x4a,0x37,0x12,0x10,0x01}}");
        private static System.String m_ServerIP = "chat-lb-2d547d8ff8aaf11f.elb.ap-northeast-2.amazonaws.com";
        private static ushort m_serverPort = 80;
        private static string localFilePath = "filtering.txt"; // 로컬에 저장될 파일 경로를 입력하세요.

        /// <summary>
        /// 서버 시작에 필요한 Parameter
        /// </summary>
        private Nettention.Proud.NetConnectionParam param = new Nettention.Proud.NetConnectionParam();

        /// <summary>
        /// NetClient 객체
        /// </summary>
        private Nettention.Proud.NetClient netClient = new Nettention.Proud.NetClient();
        
        private String authUUID;
        private String projectUUID;
        private String uniqueId;
        private ServerConnectionState state = new ServerConnectionState();
        private ConnectionState connectionState;
        private Filtering m_Filtering = new Filtering();


        private HashSet<String> channelList = new HashSet<String>();

        private bool isReconnect = false;

        private ChatC2S.Proxy ChatProxy = new ChatC2S.Proxy();
        private ChatS2C.Stub ChatStub = new ChatS2C.Stub();

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
            set { if (value != null) channelMsg_ResponseDelegate = value; }
        }

        /// <summary>
        /// Send Message가 도착했을 때 발생하는 이벤트
        /// 사용자는 Event를 등록하여 사용할 수 있습니다.
        /// </summary>
        /// <param name="srcUniqueID">메시지를 보낸 유저의 UniqueID</param>
        /// <param name="msg">상대방이 보낸 메시지</param>
        public delegate void SendMsg_Response(System.String srcUniqueID, System.String msg);
        private SendMsg_Response sendMsg_ResponseDelegate = null;

        public SendMsg_Response SendMsg_ResponseDelegate
        {
            set { if(value != null) sendMsg_ResponseDelegate = value;}
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
            set { if (value != null) notice_ResponseDelegate = value; }
        }


        private void InitStub()
        {
            ChatStub.Login_Response = Login_Response;
            ChatStub.ChannelMsg = ChannelMsg_Stub;
            ChatStub.SendMsg = SendMsg_Stub;
            ChatStub.Event_Filtering = Event_Filtering;
            ChatStub.Event_Notice = Event_Notice;
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
            InitStub();

            netClient.AttachProxy(ChatProxy);
            netClient.AttachStub(ChatStub);

            this.authUUID = authUUID;
            this.projectUUID = projectUUID;
            this.uniqueId = uniqueId;

            this.chatClientJoinCompleteDelegate = joinDelegateCompleteDelegate;
            this.chatClientJoinFailedDelegate = joinDelegateFailedDelegate;

            netClient.JoinServerCompleteHandler = (info, replyFromServer) =>
            {
                if (info.errorType == ErrorType.Ok)
                {
                    isReconnect = false;
                    Console.Write("Succeed to connect server. Allocated hostID={0}", netClient.GetLocalHostID());
                    ChatProxy.Login_Request(HostID.HostID_Server, RmiContext.ReliableSend, this.authUUID, this.projectUUID, this.uniqueId);
                }
                else
                {
                    // connection failure.
                    isReconnect = true;
                    Console.Write("Failed to connect server.\n");
                    Console.WriteLine("errorType = {0}, detailType = {1}, comment = {2}", info.errorType, info.detailType, info.comment);
                }
            };

            // set a routine for network disconnection.
            netClient.LeaveServerHandler = (errorInfo) =>
            {
                //ReConnection  로직 추가해야함
                Console.Write("OnLeaveServer: {0}\n", errorInfo.comment);
                isReconnect = true;
            };

            param.serverPort = m_serverPort;
            param.protocolVersion.Set(m_Version);
            param.serverIP = m_ServerIP;

            if (false == netClient.Connect(param))
                return false;

            return true;
        }

        /// <summary>
        /// 기본적으로 FrameMove를 진행해주셔야 이벤트가 발생합니다.
        /// </summary>
        public void FrameMove()
        {
            netClient.FrameMove();

            if(true == isReconnect)
            {
                connectionState = netClient.GetServerConnectionState(state);
                if (connectionState == ConnectionState.ConnectionState_Disconnecting)
                {
                    isReconnect = false;
                    netClient.Connect(param);
                }
            }
        }

        /// <summary>
        /// 로그인 시 Delegate되는 함수
        /// </summary>
        private bool Login_Response(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, Nettention.Proud.ErrorType errorType , System.String filtering , System.String msg)
        {
            Console.WriteLine(msg);
            if (errorType != ErrorType.Ok)
            {
                if(chatClientJoinFailedDelegate != null)
                chatClientJoinFailedDelegate(msg);
                return true;
            }
            SetUpFiltering(filtering, localFilePath);
           
            SetUpChannel();

            if(chatClientJoinCompleteDelegate != null)
                chatClientJoinCompleteDelegate();

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
        private bool SendMsg_Stub(Nettention.Proud.HostID remote, Nettention.Proud.RmiContext rmiContext, System.String srcUniqueID, System.String msg)
        {
            if (null != sendMsg_ResponseDelegate)
            {
                m_Filtering.FilteringText(ref msg);
                sendMsg_ResponseDelegate(srcUniqueID, msg);
            }
            return true;
        }

        /// <summary>
        /// 특정 채널에게 메세지를 보낼 때 사용합니다.
        /// </summary>
        /// <param name="channelKey">특정 채널의 고유한 식별 값</param>
        /// <param name="msg">특정 채널에게 보낼 메세지</param>
        public void Send_ChannelMsg(System.String channelKey, System.String msg)
        {
            if (netClient.HasServerConnection() && channelList.Contains(UpperString(channelKey)))
                ChatProxy.ChannelMsg(HostID.HostID_Server, RmiContext.ReliableSend, UpperString(channelKey), msg);
        }

        /// <summary>
        /// 특정 상대에게 메세지를 보낼 때 사용합니다.
        /// </summary>
        /// <param name="destUniqueId">특정 상대방 고유한 식별 값</param>
        /// <param name="msg">특정 상대방에게 보낼 메세지</param>
        public void Send_Msg(System.String destUniqueId, System.String msg)
        {
            if (netClient.HasServerConnection())
            {
                ChatProxy.SendMsg(HostID.HostID_Server, RmiContext.ReliableSend, destUniqueId, msg);
            }
        }

        /// <summary>
        /// 접속하고 싶은 채널의 키를 입력합니다.
        /// </summary>
        /// <param name="channelKey">접속하고 싶은 채널의 고유 Key</param>
        public void Add_Channel(System.String channelKey)
        {
            if (netClient.HasServerConnection())
                ChatProxy.ChannelJoin(HostID.HostID_Server , RmiContext.ReliableSend, UpperString(channelKey));
            
            if(false == channelList.Contains(UpperString(channelKey)))
                channelList.Add(UpperString(channelKey));
        }

        /// <summary>
        /// 접속한 채널에서 나가고 싶을때
        /// </summary>
        /// <param name="channelKey">나가고 싶은 채널의 고유 Key</param>
        public void Leave_Channel(System.String channelKey)
        {
            if (netClient.HasServerConnection() && channelList.Contains(UpperString(channelKey)))
                ChatProxy.ChannelLeave(HostID.HostID_Server, RmiContext.ReliableSend, UpperString(channelKey));

            if(true == channelList.Contains(UpperString(channelKey))) 
                channelList.Remove(UpperString(channelKey));
        }

        private void SetUpChannel()
        {
            if (false == netClient.HasServerConnection())
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
            {
                notice_ResponseDelegate(context);
            }

            return true;
        }

        private void SetUpFiltering(System.String filtering , System.String filePath)
        {
            m_Filtering.RemoveFiltering();
            System.String filterText = Proud.FileSync.GetCDNFile(filtering, filePath);
            if(null != filterText)
                m_Filtering.AddFiltering(filterText);
        }
        public List<string> GetChannel()
        {
            return channelList.ToList();
        }

        /// <summary>
        /// 해당 코드 삭제 시 채팅 기능에 문제가 발생할 수 있습니다.
        /// </summary>
        /// <returns></returns>
        private String UpperString(System.String stringKey)
        {
            return stringKey.ToUpper();
        }
    }
}
