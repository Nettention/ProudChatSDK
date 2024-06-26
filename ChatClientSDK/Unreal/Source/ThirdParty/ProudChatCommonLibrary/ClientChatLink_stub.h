﻿  






// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.
   
#pragma once


#include "ClientChatLink_common.h"

     
namespace ClientToChat {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool Connect_Request ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_Connect_Request bool Connect_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & secureKey) PN_OVERRIDE

#define DEFRMI_ClientToChat_Connect_Request(DerivedClass) bool DerivedClass::Connect_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & secureKey)
#define CALL_ClientToChat_Connect_Request Connect_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & secureKey)
#define PARAM_ClientToChat_Connect_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & secureKey)
               
		virtual bool DirectMsg ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_DirectMsg bool DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & destUniqueID, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ClientToChat_DirectMsg(DerivedClass) bool DerivedClass::DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & destUniqueID, const Proud::String & msg)
#define CALL_ClientToChat_DirectMsg DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & destUniqueID, const Proud::String & msg)
#define PARAM_ClientToChat_DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & destUniqueID, const Proud::String & msg)
               
		virtual bool ChannelMsg ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_ChannelMsg bool ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ClientToChat_ChannelMsg(DerivedClass) bool DerivedClass::ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
#define CALL_ClientToChat_ChannelMsg ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
#define PARAM_ClientToChat_ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
               
		virtual bool ChannelJoin ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_ChannelJoin bool ChannelJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_OVERRIDE

#define DEFRMI_ClientToChat_ChannelJoin(DerivedClass) bool DerivedClass::ChannelJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define CALL_ClientToChat_ChannelJoin ChannelJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define PARAM_ClientToChat_ChannelJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
               
		virtual bool ChannelLeave ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_ChannelLeave bool ChannelLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_OVERRIDE

#define DEFRMI_ClientToChat_ChannelLeave(DerivedClass) bool DerivedClass::ChannelLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define CALL_ClientToChat_ChannelLeave ChannelLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define PARAM_ClientToChat_ChannelLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
               
		virtual bool GetChannelList_Request ( ::Proud::HostID, ::Proud::RmiContext& )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_GetChannelList_Request bool GetChannelList_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ) PN_OVERRIDE

#define DEFRMI_ClientToChat_GetChannelList_Request(DerivedClass) bool DerivedClass::GetChannelList_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext )
#define CALL_ClientToChat_GetChannelList_Request GetChannelList_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext )
#define PARAM_ClientToChat_GetChannelList_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext )
               
		virtual bool MsgTranslate ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_MsgTranslate bool MsgTranslate ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & src, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ClientToChat_MsgTranslate(DerivedClass) bool DerivedClass::MsgTranslate ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & src, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)
#define CALL_ClientToChat_MsgTranslate MsgTranslate ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & src, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)
#define PARAM_ClientToChat_MsgTranslate ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & src, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)
               
		virtual bool MsgTranslate_auto ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_MsgTranslate_auto bool MsgTranslate_auto ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ClientToChat_MsgTranslate_auto(DerivedClass) bool DerivedClass::MsgTranslate_auto ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)
#define CALL_ClientToChat_MsgTranslate_auto MsgTranslate_auto ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)
#define PARAM_ClientToChat_MsgTranslate_auto ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)
               
		virtual bool MsgRecord_Channel ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const uint16_t & , const uint16_t & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_MsgRecord_Channel bool MsgRecord_Channel ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const uint16_t & day, const uint16_t & cnt) PN_OVERRIDE

#define DEFRMI_ClientToChat_MsgRecord_Channel(DerivedClass) bool DerivedClass::MsgRecord_Channel ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const uint16_t & day, const uint16_t & cnt)
#define CALL_ClientToChat_MsgRecord_Channel MsgRecord_Channel ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const uint16_t & day, const uint16_t & cnt)
#define PARAM_ClientToChat_MsgRecord_Channel ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const uint16_t & day, const uint16_t & cnt)
               
		virtual bool MsgRecord_Direct ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const uint16_t & , const uint16_t & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_MsgRecord_Direct bool MsgRecord_Direct ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const uint16_t & day, const uint16_t & cnt) PN_OVERRIDE

#define DEFRMI_ClientToChat_MsgRecord_Direct(DerivedClass) bool DerivedClass::MsgRecord_Direct ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const uint16_t & day, const uint16_t & cnt)
#define CALL_ClientToChat_MsgRecord_Direct MsgRecord_Direct ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const uint16_t & day, const uint16_t & cnt)
#define PARAM_ClientToChat_MsgRecord_Direct ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const uint16_t & day, const uint16_t & cnt)
               
		virtual bool MsgRecord_Notice ( ::Proud::HostID, ::Proud::RmiContext& , const uint16_t & , const uint16_t & )		{ 
			return false;
		} 

#define DECRMI_ClientToChat_MsgRecord_Notice bool MsgRecord_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const uint16_t & day, const uint16_t & cnt) PN_OVERRIDE

#define DEFRMI_ClientToChat_MsgRecord_Notice(DerivedClass) bool DerivedClass::MsgRecord_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const uint16_t & day, const uint16_t & cnt)
#define CALL_ClientToChat_MsgRecord_Notice MsgRecord_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const uint16_t & day, const uint16_t & cnt)
#define PARAM_ClientToChat_MsgRecord_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const uint16_t & day, const uint16_t & cnt)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_Connect_Request;
		static const PNTCHAR* RmiName_DirectMsg;
		static const PNTCHAR* RmiName_ChannelMsg;
		static const PNTCHAR* RmiName_ChannelJoin;
		static const PNTCHAR* RmiName_ChannelLeave;
		static const PNTCHAR* RmiName_GetChannelList_Request;
		static const PNTCHAR* RmiName_MsgTranslate;
		static const PNTCHAR* RmiName_MsgTranslate_auto;
		static const PNTCHAR* RmiName_MsgRecord_Channel;
		static const PNTCHAR* RmiName_MsgRecord_Direct;
		static const PNTCHAR* RmiName_MsgRecord_Notice;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > Connect_Request_Function;
		virtual bool Connect_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & secureKey) 
		{ 
			if (Connect_Request_Function==nullptr) 
				return true; 
			return Connect_Request_Function(remote,rmiContext, secureKey); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > DirectMsg_Function;
		virtual bool DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & destUniqueID, const Proud::String & msg) 
		{ 
			if (DirectMsg_Function==nullptr) 
				return true; 
			return DirectMsg_Function(remote,rmiContext, destUniqueID, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > ChannelMsg_Function;
		virtual bool ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) 
		{ 
			if (ChannelMsg_Function==nullptr) 
				return true; 
			return ChannelMsg_Function(remote,rmiContext, channelKey, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > ChannelJoin_Function;
		virtual bool ChannelJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) 
		{ 
			if (ChannelJoin_Function==nullptr) 
				return true; 
			return ChannelJoin_Function(remote,rmiContext, channelKey); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > ChannelLeave_Function;
		virtual bool ChannelLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) 
		{ 
			if (ChannelLeave_Function==nullptr) 
				return true; 
			return ChannelLeave_Function(remote,rmiContext, channelKey); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& ) > GetChannelList_Request_Function;
		virtual bool GetChannelList_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ) 
		{ 
			if (GetChannelList_Request_Function==nullptr) 
				return true; 
			return GetChannelList_Request_Function(remote,rmiContext); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & , const Proud::String & , const Proud::String & ) > MsgTranslate_Function;
		virtual bool MsgTranslate ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & src, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg) 
		{ 
			if (MsgTranslate_Function==nullptr) 
				return true; 
			return MsgTranslate_Function(remote,rmiContext, src, target, msgKey, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & , const Proud::String & ) > MsgTranslate_auto_Function;
		virtual bool MsgTranslate_auto ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg) 
		{ 
			if (MsgTranslate_auto_Function==nullptr) 
				return true; 
			return MsgTranslate_auto_Function(remote,rmiContext, target, msgKey, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const uint16_t & , const uint16_t & ) > MsgRecord_Channel_Function;
		virtual bool MsgRecord_Channel ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const uint16_t & day, const uint16_t & cnt) 
		{ 
			if (MsgRecord_Channel_Function==nullptr) 
				return true; 
			return MsgRecord_Channel_Function(remote,rmiContext, channelKey, day, cnt); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const uint16_t & , const uint16_t & ) > MsgRecord_Direct_Function;
		virtual bool MsgRecord_Direct ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const uint16_t & day, const uint16_t & cnt) 
		{ 
			if (MsgRecord_Direct_Function==nullptr) 
				return true; 
			return MsgRecord_Direct_Function(remote,rmiContext, target, day, cnt); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const uint16_t & , const uint16_t & ) > MsgRecord_Notice_Function;
		virtual bool MsgRecord_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const uint16_t & day, const uint16_t & cnt) 
		{ 
			if (MsgRecord_Notice_Function==nullptr) 
				return true; 
			return MsgRecord_Notice_Function(remote,rmiContext, day, cnt); 
		}

	};
#endif

}


     
namespace ChatToClient {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool Connect_Success ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_Connect_Success bool Connect_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_Connect_Success(DerivedClass) bool DerivedClass::Connect_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering, const Proud::String & msg)
#define CALL_ChatToClient_Connect_Success Connect_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering, const Proud::String & msg)
#define PARAM_ChatToClient_Connect_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering, const Proud::String & msg)
               
		virtual bool Connect_Failed ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_Connect_Failed bool Connect_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_Connect_Failed(DerivedClass) bool DerivedClass::Connect_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg)
#define CALL_ChatToClient_Connect_Failed Connect_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg)
#define PARAM_ChatToClient_Connect_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg)
               
		virtual bool ChannelJoin_Success ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_ChannelJoin_Success bool ChannelJoin_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_OVERRIDE

#define DEFRMI_ChatToClient_ChannelJoin_Success(DerivedClass) bool DerivedClass::ChannelJoin_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define CALL_ChatToClient_ChannelJoin_Success ChannelJoin_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define PARAM_ChatToClient_ChannelJoin_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
               
		virtual bool ChannelJoin_Failed ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_ChannelJoin_Failed bool ChannelJoin_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_ChannelJoin_Failed(DerivedClass) bool DerivedClass::ChannelJoin_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
#define CALL_ChatToClient_ChannelJoin_Failed ChannelJoin_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
#define PARAM_ChatToClient_ChannelJoin_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
               
		virtual bool ChannelLeave_Success ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_ChannelLeave_Success bool ChannelLeave_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_OVERRIDE

#define DEFRMI_ChatToClient_ChannelLeave_Success(DerivedClass) bool DerivedClass::ChannelLeave_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define CALL_ChatToClient_ChannelLeave_Success ChannelLeave_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
#define PARAM_ChatToClient_ChannelLeave_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey)
               
		virtual bool ChannelLeave_Failed ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_ChannelLeave_Failed bool ChannelLeave_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_ChannelLeave_Failed(DerivedClass) bool DerivedClass::ChannelLeave_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
#define CALL_ChatToClient_ChannelLeave_Failed ChannelLeave_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
#define PARAM_ChatToClient_ChannelLeave_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg)
               
		virtual bool DirectMsg ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_DirectMsg bool DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & srcUniqueID, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_DirectMsg(DerivedClass) bool DerivedClass::DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & srcUniqueID, const Proud::String & msg)
#define CALL_ChatToClient_DirectMsg DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & srcUniqueID, const Proud::String & msg)
#define PARAM_ChatToClient_DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & srcUniqueID, const Proud::String & msg)
               
		virtual bool ChannelMsg ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_ChannelMsg bool ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & srcUniqueID, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_ChannelMsg(DerivedClass) bool DerivedClass::ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & srcUniqueID, const Proud::String & msg)
#define CALL_ChatToClient_ChannelMsg ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & srcUniqueID, const Proud::String & msg)
#define PARAM_ChatToClient_ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & srcUniqueID, const Proud::String & msg)
               
		virtual bool GetChannelList_Response ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::ErrorType & , const Proud::CFastArray<Proud::String> & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_GetChannelList_Response bool GetChannelList_Response ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::ErrorType & errorType, const Proud::CFastArray<Proud::String> & channelList) PN_OVERRIDE

#define DEFRMI_ChatToClient_GetChannelList_Response(DerivedClass) bool DerivedClass::GetChannelList_Response ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::ErrorType & errorType, const Proud::CFastArray<Proud::String> & channelList)
#define CALL_ChatToClient_GetChannelList_Response GetChannelList_Response ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::ErrorType & errorType, const Proud::CFastArray<Proud::String> & channelList)
#define PARAM_ChatToClient_GetChannelList_Response ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::ErrorType & errorType, const Proud::CFastArray<Proud::String> & channelList)
               
		virtual bool Event_Filtering ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_Event_Filtering bool Event_Filtering ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering) PN_OVERRIDE

#define DEFRMI_ChatToClient_Event_Filtering(DerivedClass) bool DerivedClass::Event_Filtering ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering)
#define CALL_ChatToClient_Event_Filtering Event_Filtering ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering)
#define PARAM_ChatToClient_Event_Filtering ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering)
               
		virtual bool Event_Notice ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_Event_Notice bool Event_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & context) PN_OVERRIDE

#define DEFRMI_ChatToClient_Event_Notice(DerivedClass) bool DerivedClass::Event_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & context)
#define CALL_ChatToClient_Event_Notice Event_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & context)
#define PARAM_ChatToClient_Event_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & context)
               
		virtual bool MsgTranslate_Success ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_MsgTranslate_Success bool MsgTranslate_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_MsgTranslate_Success(DerivedClass) bool DerivedClass::MsgTranslate_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg)
#define CALL_ChatToClient_MsgTranslate_Success MsgTranslate_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg)
#define PARAM_ChatToClient_MsgTranslate_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg)
               
		virtual bool MsgTranslate_Failed ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_MsgTranslate_Failed bool MsgTranslate_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_MsgTranslate_Failed(DerivedClass) bool DerivedClass::MsgTranslate_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg)
#define CALL_ChatToClient_MsgTranslate_Failed MsgTranslate_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg)
#define PARAM_ChatToClient_MsgTranslate_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg)
               
		virtual bool MsgRecord_Success ( ::Proud::HostID, ::Proud::RmiContext& , const tagMsgRecords & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_MsgRecord_Success bool MsgRecord_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const tagMsgRecords & records) PN_OVERRIDE

#define DEFRMI_ChatToClient_MsgRecord_Success(DerivedClass) bool DerivedClass::MsgRecord_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const tagMsgRecords & records)
#define CALL_ChatToClient_MsgRecord_Success MsgRecord_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const tagMsgRecords & records)
#define PARAM_ChatToClient_MsgRecord_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const tagMsgRecords & records)
               
		virtual bool MsgRecord_Failed ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_ChatToClient_MsgRecord_Failed bool MsgRecord_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg) PN_OVERRIDE

#define DEFRMI_ChatToClient_MsgRecord_Failed(DerivedClass) bool DerivedClass::MsgRecord_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg)
#define CALL_ChatToClient_MsgRecord_Failed MsgRecord_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg)
#define PARAM_ChatToClient_MsgRecord_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_Connect_Success;
		static const PNTCHAR* RmiName_Connect_Failed;
		static const PNTCHAR* RmiName_ChannelJoin_Success;
		static const PNTCHAR* RmiName_ChannelJoin_Failed;
		static const PNTCHAR* RmiName_ChannelLeave_Success;
		static const PNTCHAR* RmiName_ChannelLeave_Failed;
		static const PNTCHAR* RmiName_DirectMsg;
		static const PNTCHAR* RmiName_ChannelMsg;
		static const PNTCHAR* RmiName_GetChannelList_Response;
		static const PNTCHAR* RmiName_Event_Filtering;
		static const PNTCHAR* RmiName_Event_Notice;
		static const PNTCHAR* RmiName_MsgTranslate_Success;
		static const PNTCHAR* RmiName_MsgTranslate_Failed;
		static const PNTCHAR* RmiName_MsgRecord_Success;
		static const PNTCHAR* RmiName_MsgRecord_Failed;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > Connect_Success_Function;
		virtual bool Connect_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering, const Proud::String & msg) 
		{ 
			if (Connect_Success_Function==nullptr) 
				return true; 
			return Connect_Success_Function(remote,rmiContext, filtering, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > Connect_Failed_Function;
		virtual bool Connect_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg) 
		{ 
			if (Connect_Failed_Function==nullptr) 
				return true; 
			return Connect_Failed_Function(remote,rmiContext, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > ChannelJoin_Success_Function;
		virtual bool ChannelJoin_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) 
		{ 
			if (ChannelJoin_Success_Function==nullptr) 
				return true; 
			return ChannelJoin_Success_Function(remote,rmiContext, channelKey); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > ChannelJoin_Failed_Function;
		virtual bool ChannelJoin_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) 
		{ 
			if (ChannelJoin_Failed_Function==nullptr) 
				return true; 
			return ChannelJoin_Failed_Function(remote,rmiContext, channelKey, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > ChannelLeave_Success_Function;
		virtual bool ChannelLeave_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) 
		{ 
			if (ChannelLeave_Success_Function==nullptr) 
				return true; 
			return ChannelLeave_Success_Function(remote,rmiContext, channelKey); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > ChannelLeave_Failed_Function;
		virtual bool ChannelLeave_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) 
		{ 
			if (ChannelLeave_Failed_Function==nullptr) 
				return true; 
			return ChannelLeave_Failed_Function(remote,rmiContext, channelKey, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > DirectMsg_Function;
		virtual bool DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & srcUniqueID, const Proud::String & msg) 
		{ 
			if (DirectMsg_Function==nullptr) 
				return true; 
			return DirectMsg_Function(remote,rmiContext, srcUniqueID, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & , const Proud::String & ) > ChannelMsg_Function;
		virtual bool ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & srcUniqueID, const Proud::String & msg) 
		{ 
			if (ChannelMsg_Function==nullptr) 
				return true; 
			return ChannelMsg_Function(remote,rmiContext, channelKey, srcUniqueID, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::ErrorType & , const Proud::CFastArray<Proud::String> & ) > GetChannelList_Response_Function;
		virtual bool GetChannelList_Response ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::ErrorType & errorType, const Proud::CFastArray<Proud::String> & channelList) 
		{ 
			if (GetChannelList_Response_Function==nullptr) 
				return true; 
			return GetChannelList_Response_Function(remote,rmiContext, errorType, channelList); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > Event_Filtering_Function;
		virtual bool Event_Filtering ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering) 
		{ 
			if (Event_Filtering_Function==nullptr) 
				return true; 
			return Event_Filtering_Function(remote,rmiContext, filtering); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > Event_Notice_Function;
		virtual bool Event_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & context) 
		{ 
			if (Event_Notice_Function==nullptr) 
				return true; 
			return Event_Notice_Function(remote,rmiContext, context); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > MsgTranslate_Success_Function;
		virtual bool MsgTranslate_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg) 
		{ 
			if (MsgTranslate_Success_Function==nullptr) 
				return true; 
			return MsgTranslate_Success_Function(remote,rmiContext, msgKey, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & , const Proud::String & ) > MsgTranslate_Failed_Function;
		virtual bool MsgTranslate_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg) 
		{ 
			if (MsgTranslate_Failed_Function==nullptr) 
				return true; 
			return MsgTranslate_Failed_Function(remote,rmiContext, msgKey, msg); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const tagMsgRecords & ) > MsgRecord_Success_Function;
		virtual bool MsgRecord_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const tagMsgRecords & records) 
		{ 
			if (MsgRecord_Success_Function==nullptr) 
				return true; 
			return MsgRecord_Success_Function(remote,rmiContext, records); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& , const Proud::String & ) > MsgRecord_Failed_Function;
		virtual bool MsgRecord_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg) 
		{ 
			if (MsgRecord_Failed_Function==nullptr) 
				return true; 
			return MsgRecord_Failed_Function(remote,rmiContext, msg); 
		}

	};
#endif

}


