#pragma once

namespace ChatC2S {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Login_Request = (::Proud::RmiID)(1000+1);
               
    static const ::Proud::RmiID Rmi_SendMsg = (::Proud::RmiID)(1000+2);
               
    static const ::Proud::RmiID Rmi_ChannelMsg = (::Proud::RmiID)(1000+3);
               
    static const ::Proud::RmiID Rmi_ChannelJoin = (::Proud::RmiID)(1000+4);
               
    static const ::Proud::RmiID Rmi_ChannelLeave = (::Proud::RmiID)(1000+5);
               
    static const ::Proud::RmiID Rmi_GetChannelList_Request = (::Proud::RmiID)(1000+6);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


namespace ChatS2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Login_Response = (::Proud::RmiID)(2000+1);
               
    static const ::Proud::RmiID Rmi_SendMsg = (::Proud::RmiID)(2000+2);
               
    static const ::Proud::RmiID Rmi_ChannelMsg = (::Proud::RmiID)(2000+3);
               
    static const ::Proud::RmiID Rmi_GetChannelList_Response = (::Proud::RmiID)(2000+4);
               
    static const ::Proud::RmiID Rmi_Event_Filtering = (::Proud::RmiID)(2000+5);
               
    static const ::Proud::RmiID Rmi_Event_Notice = (::Proud::RmiID)(2000+6);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 

// Forward declarations


// Declarations



