﻿



  
// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

#pragma once


#include "ClientToLoginLink_common.h"

namespace ClientToLogin {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool Login_Request ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & ownerUuid, const Proud::String & projectUuid, const Proud::String & uniqueId) PN_SEALED; 
	virtual bool Login_Request ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & ownerUuid, const Proud::String & projectUuid, const Proud::String & uniqueId)   PN_SEALED;  
static const PNTCHAR* RmiName_Login_Request;
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


namespace LoginToClient {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool Login_Success ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & secureKey, const Proud::String & address, const uint16_t & port) PN_SEALED; 
	virtual bool Login_Success ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & secureKey, const Proud::String & address, const uint16_t & port)   PN_SEALED;  
	virtual bool Login_Failed ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & msg) PN_SEALED; 
	virtual bool Login_Failed ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & msg)   PN_SEALED;  
static const PNTCHAR* RmiName_Login_Success;
static const PNTCHAR* RmiName_Login_Failed;
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


