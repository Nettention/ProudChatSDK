#pragma once

namespace ClientToChat {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Connect_Request = (::Proud::RmiID)(10000+1);
               
    static const ::Proud::RmiID Rmi_DirectMsg = (::Proud::RmiID)(10000+2);
               
    static const ::Proud::RmiID Rmi_ChannelMsg = (::Proud::RmiID)(10000+3);
               
    static const ::Proud::RmiID Rmi_ChannelJoin = (::Proud::RmiID)(10000+4);
               
    static const ::Proud::RmiID Rmi_ChannelLeave = (::Proud::RmiID)(10000+5);
               
    static const ::Proud::RmiID Rmi_GetChannelList_Request = (::Proud::RmiID)(10000+6);
               
    static const ::Proud::RmiID Rmi_MsgTranslate = (::Proud::RmiID)(10000+7);
               
    static const ::Proud::RmiID Rmi_MsgTranslate_auto = (::Proud::RmiID)(10000+8);
               
    static const ::Proud::RmiID Rmi_MsgRecord_Channel = (::Proud::RmiID)(10000+9);
               
    static const ::Proud::RmiID Rmi_MsgRecord_Direct = (::Proud::RmiID)(10000+10);
               
    static const ::Proud::RmiID Rmi_MsgRecord_Notice = (::Proud::RmiID)(10000+11);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


namespace ChatToClient {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Connect_Success = (::Proud::RmiID)(11000+1);
               
    static const ::Proud::RmiID Rmi_Connect_Failed = (::Proud::RmiID)(11000+2);
               
    static const ::Proud::RmiID Rmi_ChannelJoin_Success = (::Proud::RmiID)(11000+3);
               
    static const ::Proud::RmiID Rmi_ChannelJoin_Failed = (::Proud::RmiID)(11000+4);
               
    static const ::Proud::RmiID Rmi_ChannelLeave_Success = (::Proud::RmiID)(11000+5);
               
    static const ::Proud::RmiID Rmi_ChannelLeave_Failed = (::Proud::RmiID)(11000+6);
               
    static const ::Proud::RmiID Rmi_DirectMsg = (::Proud::RmiID)(11000+7);
               
    static const ::Proud::RmiID Rmi_ChannelMsg = (::Proud::RmiID)(11000+8);
               
    static const ::Proud::RmiID Rmi_GetChannelList_Response = (::Proud::RmiID)(11000+9);
               
    static const ::Proud::RmiID Rmi_Event_Filtering = (::Proud::RmiID)(11000+10);
               
    static const ::Proud::RmiID Rmi_Event_Notice = (::Proud::RmiID)(11000+11);
               
    static const ::Proud::RmiID Rmi_MsgTranslate_Success = (::Proud::RmiID)(11000+12);
               
    static const ::Proud::RmiID Rmi_MsgTranslate_Failed = (::Proud::RmiID)(11000+13);
               
    static const ::Proud::RmiID Rmi_MsgRecord_Success = (::Proud::RmiID)(11000+14);
               
    static const ::Proud::RmiID Rmi_MsgRecord_Failed = (::Proud::RmiID)(11000+15);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 

// Forward declarations


// Declarations



