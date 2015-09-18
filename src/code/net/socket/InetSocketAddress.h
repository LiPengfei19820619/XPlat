#ifndef  INET_SOCKET_ADDRESS_H
#define  INET_SOCKET_ADDRESS_H


#include <WinSock2.h>

#include "XPlat_SocketAddress.h"


namespace XPLAT
{


class CInetSocketAddress : public ISocketAddress
{
public:
	static ISocketAddress * CreateIPV4SocketAddress(const std::string & strIPAddr, unsigned short u16Port);

	void Release();

protected:
	SOCKADDR_IN    m_sockaddr_in;

protected:
	CInetSocketAddress();
	virtual ~CInetSocketAddress();
};


}


#endif  /* INET_SOCKET_ADDRESS_H */

