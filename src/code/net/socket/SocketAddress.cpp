
#include "XPlat_SocketAddress.h"

#include "InetSocketAddress.h"


using namespace XPLAT;


ISocketAddress * ISocketAddress::Create(const std::string & strIPAddr, unsigned short u16Port)
{
	return CInetSocketAddress::CreateIPV4SocketAddress(strIPAddr, u16Port);
}

