
#include "IPV4SocketAddress.h"


using namespace XPLAT;


CIPV4SocketAddress::CIPV4SocketAddress(const std::string & strIPAddr, unsigned short u16Port)
{
	m_sockaddr_in.sin_family = AF_INET;
	m_sockaddr_in.sin_addr.S_un.S_addr = inet_addr(strIPAddr.c_str());
	m_sockaddr_in.sin_port = htons(u16Port);
}


CIPV4SocketAddress::~CIPV4SocketAddress()
{
}


std::string CIPV4SocketAddress::GetIPAddr() const
{
	return inet_ntoa(this->m_sockaddr_in.sin_addr);
}


unsigned short CIPV4SocketAddress::GetPort() const
{
	return ntohs(m_sockaddr_in.sin_port);
}


void CIPV4SocketAddress::SetPortNum(unsigned int u16Port)
{
	m_sockaddr_in.sin_port = htons(u16Port);

	return;
}

