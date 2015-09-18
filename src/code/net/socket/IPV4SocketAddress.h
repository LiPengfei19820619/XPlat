#ifndef  IP_V4_SOCKET_ADDRESS_H
#define  IP_V4_SOCKET_ADDRESS_H


#include "InetSocketAddress.h"


namespace XPLAT
{


class CIPV4SocketAddress : public CInetSocketAddress
{
public:
	CIPV4SocketAddress(const std::string & strIPAddr, unsigned short u16Port);
	~CIPV4SocketAddress();

	std::string GetIPAddr() const ;
    unsigned short  GetPort() const ;

	void SetPortNum(unsigned int u16Port);
};


}


#endif  /* IP_V4_SOCKET_ADDRESS_H */

