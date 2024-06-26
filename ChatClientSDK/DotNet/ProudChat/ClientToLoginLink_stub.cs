﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace ClientToLogin
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool Login_RequestDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String ownerUuid, System.String projectUuid, System.String uniqueId);  
		public Login_RequestDelegate Login_Request = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String ownerUuid, System.String projectUuid, System.String uniqueId)
		{ 
			return false;
		};
	public override bool ProcessReceivedMessage(Nettention.Proud.ReceivedMessage pa, Object hostTag) 
	{
		Nettention.Proud.HostID remote=pa.RemoteHostID;
		if(remote==Nettention.Proud.HostID.HostID_None)
		{
			ShowUnknownHostIDWarning(remote);
		}

		Nettention.Proud.Message __msg=pa.ReadOnlyMessage;
		int orgReadOffset = __msg.ReadOffset;
        Nettention.Proud.RmiID __rmiID = Nettention.Proud.RmiID.RmiID_None;
        if (!__msg.Read( out __rmiID))
            goto __fail;
					
		switch(__rmiID)
		{
        case Common.Login_Request:
            ProcessReceivedMessage_Login_Request(__msg, pa, hostTag, remote);
            break;
		default:
			 goto __fail;
		}
		return true;
__fail:
	  {
			__msg.ReadOffset = orgReadOffset;
			return false;
	  }
	}
    void ProcessReceivedMessage_Login_Request(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        System.String ownerUuid; ProudChat.CustomMarshaler.Read(__msg,out ownerUuid);	
System.String projectUuid; ProudChat.CustomMarshaler.Read(__msg,out projectUuid);	
System.String uniqueId; ProudChat.CustomMarshaler.Read(__msg,out uniqueId);	
core.PostCheckReadMessage(__msg, RmiName_Login_Request);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
        parameterString+=ownerUuid.ToString()+",";
parameterString+=projectUuid.ToString()+",";
parameterString+=uniqueId.ToString()+",";
        NotifyCallFromStub(Common.Login_Request, RmiName_Login_Request,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.Login_Request;
        summary.rmiName = RmiName_Login_Request;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =Login_Request (remote,ctx , ownerUuid, projectUuid, uniqueId );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_Login_Request);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.Login_Request;
        summary.rmiName = RmiName_Login_Request;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
        }
    }
		#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
public const string RmiName_Login_Request="Login_Request";
       
public const string RmiName_First = RmiName_Login_Request;
		#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
public const string RmiName_Login_Request="";
       
public const string RmiName_First = "";
		#endif

		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}
namespace LoginToClient
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool Login_SuccessDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String secureKey, System.String address, UInt16 port);  
		public Login_SuccessDelegate Login_Success = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String secureKey, System.String address, UInt16 port)
		{ 
			return false;
		};
		public delegate bool Login_FailedDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String msg);  
		public Login_FailedDelegate Login_Failed = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String msg)
		{ 
			return false;
		};
	public override bool ProcessReceivedMessage(Nettention.Proud.ReceivedMessage pa, Object hostTag) 
	{
		Nettention.Proud.HostID remote=pa.RemoteHostID;
		if(remote==Nettention.Proud.HostID.HostID_None)
		{
			ShowUnknownHostIDWarning(remote);
		}

		Nettention.Proud.Message __msg=pa.ReadOnlyMessage;
		int orgReadOffset = __msg.ReadOffset;
        Nettention.Proud.RmiID __rmiID = Nettention.Proud.RmiID.RmiID_None;
        if (!__msg.Read( out __rmiID))
            goto __fail;
					
		switch(__rmiID)
		{
        case Common.Login_Success:
            ProcessReceivedMessage_Login_Success(__msg, pa, hostTag, remote);
            break;
        case Common.Login_Failed:
            ProcessReceivedMessage_Login_Failed(__msg, pa, hostTag, remote);
            break;
		default:
			 goto __fail;
		}
		return true;
__fail:
	  {
			__msg.ReadOffset = orgReadOffset;
			return false;
	  }
	}
    void ProcessReceivedMessage_Login_Success(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        System.String secureKey; ProudChat.CustomMarshaler.Read(__msg,out secureKey);	
System.String address; ProudChat.CustomMarshaler.Read(__msg,out address);	
UInt16 port; ProudChat.CustomMarshaler.Read(__msg,out port);	
core.PostCheckReadMessage(__msg, RmiName_Login_Success);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
        parameterString+=secureKey.ToString()+",";
parameterString+=address.ToString()+",";
parameterString+=port.ToString()+",";
        NotifyCallFromStub(Common.Login_Success, RmiName_Login_Success,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.Login_Success;
        summary.rmiName = RmiName_Login_Success;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =Login_Success (remote,ctx , secureKey, address, port );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_Login_Success);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.Login_Success;
        summary.rmiName = RmiName_Login_Success;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
        }
    }
    void ProcessReceivedMessage_Login_Failed(Nettention.Proud.Message __msg, Nettention.Proud.ReceivedMessage pa, Object hostTag, Nettention.Proud.HostID remote)
    {
        Nettention.Proud.RmiContext ctx = new Nettention.Proud.RmiContext();
        ctx.sentFrom=pa.RemoteHostID;
        ctx.relayed=pa.IsRelayed;
        ctx.hostTag=hostTag;
        ctx.encryptMode = pa.EncryptMode;
        ctx.compressMode = pa.CompressMode;

        System.String msg; ProudChat.CustomMarshaler.Read(__msg,out msg);	
core.PostCheckReadMessage(__msg, RmiName_Login_Failed);
        if(enableNotifyCallFromStub==true)
        {
        string parameterString = "";
        parameterString+=msg.ToString()+",";
        NotifyCallFromStub(Common.Login_Failed, RmiName_Login_Failed,parameterString);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
        summary.rmiID = Common.Login_Failed;
        summary.rmiName = RmiName_Login_Failed;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        BeforeRmiInvocation(summary);
        }

        long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();

        // Call this method.
        bool __ret =Login_Failed (remote,ctx , msg );

        if(__ret==false)
        {
        // Error: RMI function that a user did not create has been called. 
        core.ShowNotImplementedRmiWarning(RmiName_Login_Failed);
        }

        if(enableStubProfiling)
        {
        Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
        summary.rmiID = Common.Login_Failed;
        summary.rmiName = RmiName_Login_Failed;
        summary.hostID = remote;
        summary.hostTag = hostTag;
        summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
        AfterRmiInvocation(summary);
        }
    }
		#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
public const string RmiName_Login_Success="Login_Success";
public const string RmiName_Login_Failed="Login_Failed";
       
public const string RmiName_First = RmiName_Login_Success;
		#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
public const string RmiName_Login_Success="";
public const string RmiName_Login_Failed="";
       
public const string RmiName_First = "";
		#endif

		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}
