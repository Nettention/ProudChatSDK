﻿



  
// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

#pragma once


#include "ClientChatLink_common.h"

namespace ClientToChat {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool Connect_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & secureKey) PN_SEALED; 
	virtual bool Connect_Request ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & secureKey)   PN_SEALED;  
	virtual bool DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & destUniqueID, const Proud::String & msg) PN_SEALED; 
	virtual bool DirectMsg ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & destUniqueID, const Proud::String & msg)   PN_SEALED;  
	virtual bool ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) PN_SEALED; 
	virtual bool ChannelMsg ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey, const Proud::String & msg)   PN_SEALED;  
	virtual bool ChannelJoin ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_SEALED; 
	virtual bool ChannelJoin ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey)   PN_SEALED;  
	virtual bool ChannelLeave ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_SEALED; 
	virtual bool ChannelLeave ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey)   PN_SEALED;  
	virtual bool GetChannelList_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ) PN_SEALED; 
	virtual bool GetChannelList_Request ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext)   PN_SEALED;  
	virtual bool MsgTranslate ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & src, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg) PN_SEALED; 
	virtual bool MsgTranslate ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & src, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)   PN_SEALED;  
	virtual bool MsgTranslate_auto ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg) PN_SEALED; 
	virtual bool MsgTranslate_auto ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & target, const Proud::String & msgKey, const Proud::String & msg)   PN_SEALED;  
	virtual bool MsgRecord_Channel ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const uint16_t & day, const uint16_t & cnt) PN_SEALED; 
	virtual bool MsgRecord_Channel ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey, const uint16_t & day, const uint16_t & cnt)   PN_SEALED;  
	virtual bool MsgRecord_Direct ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & target, const uint16_t & day, const uint16_t & cnt) PN_SEALED; 
	virtual bool MsgRecord_Direct ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & target, const uint16_t & day, const uint16_t & cnt)   PN_SEALED;  
	virtual bool MsgRecord_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const uint16_t & day, const uint16_t & cnt) PN_SEALED; 
	virtual bool MsgRecord_Notice ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const uint16_t & day, const uint16_t & cnt)   PN_SEALED;  
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
		Proxy()
		{
			if(m_signature != 1)
				::Proud::ShowUserMisuseError(::Proud::ProxyBadSignatureErrorText);
		}

		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; } 
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

}


namespace ChatToClient {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool Connect_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering, const Proud::String & msg) PN_SEALED; 
	virtual bool Connect_Success ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & filtering, const Proud::String & msg)   PN_SEALED;  
	virtual bool Connect_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg) PN_SEALED; 
	virtual bool Connect_Failed ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & msg)   PN_SEALED;  
	virtual bool ChannelJoin_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_SEALED; 
	virtual bool ChannelJoin_Success ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey)   PN_SEALED;  
	virtual bool ChannelJoin_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) PN_SEALED; 
	virtual bool ChannelJoin_Failed ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey, const Proud::String & msg)   PN_SEALED;  
	virtual bool ChannelLeave_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey) PN_SEALED; 
	virtual bool ChannelLeave_Success ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey)   PN_SEALED;  
	virtual bool ChannelLeave_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & msg) PN_SEALED; 
	virtual bool ChannelLeave_Failed ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey, const Proud::String & msg)   PN_SEALED;  
	virtual bool DirectMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & srcUniqueID, const Proud::String & msg) PN_SEALED; 
	virtual bool DirectMsg ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & srcUniqueID, const Proud::String & msg)   PN_SEALED;  
	virtual bool ChannelMsg ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & channelKey, const Proud::String & srcUniqueID, const Proud::String & msg) PN_SEALED; 
	virtual bool ChannelMsg ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & channelKey, const Proud::String & srcUniqueID, const Proud::String & msg)   PN_SEALED;  
	virtual bool GetChannelList_Response ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::ErrorType & errorType, const Proud::CFastArray<Proud::String> & channelList) PN_SEALED; 
	virtual bool GetChannelList_Response ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::ErrorType & errorType, const Proud::CFastArray<Proud::String> & channelList)   PN_SEALED;  
	virtual bool Event_Filtering ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & filtering) PN_SEALED; 
	virtual bool Event_Filtering ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & filtering)   PN_SEALED;  
	virtual bool Event_Notice ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & context) PN_SEALED; 
	virtual bool Event_Notice ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & context)   PN_SEALED;  
	virtual bool MsgTranslate_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg) PN_SEALED; 
	virtual bool MsgTranslate_Success ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & msgKey, const Proud::String & msg)   PN_SEALED;  
	virtual bool MsgTranslate_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msgKey, const Proud::String & msg) PN_SEALED; 
	virtual bool MsgTranslate_Failed ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & msgKey, const Proud::String & msg)   PN_SEALED;  
	virtual bool MsgRecord_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const tagMsgRecords & records) PN_SEALED; 
	virtual bool MsgRecord_Success ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const tagMsgRecords & records)   PN_SEALED;  
	virtual bool MsgRecord_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg) PN_SEALED; 
	virtual bool MsgRecord_Failed ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & msg)   PN_SEALED;  
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
		Proxy()
		{
			if(m_signature != 1)
				::Proud::ShowUserMisuseError(::Proud::ProxyBadSignatureErrorText);
		}

		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; } 
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

}



