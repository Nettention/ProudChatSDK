#pragma once

namespace ClientToLogin {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Login_Request = (::Proud::RmiID)(12000+1);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


namespace LoginToClient {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Login_Success = (::Proud::RmiID)(13000+1);
               
    static const ::Proud::RmiID Rmi_Login_Failed = (::Proud::RmiID)(13000+2);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 

// Forward declarations


// Declarations



