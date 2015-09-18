
#include "InetSocketAddress.h"
#include "IPV4SocketAddress.h"


using namespace XPLAT;


CInetSocketAddress::CInetSocketAddress()
{
}


CInetSocketAddress::~CInetSocketAddress()
{
}


ISocketAddress * CInetSocketAddress::CreateIPV4SocketAddress(const std::string & strIPAddr, unsigned short u16Port)
{
	return new CIPV4SocketAddress(strIPAddr, u16Port);
}


void CInetSocketAddress::Release()
{
	delete this;
}

