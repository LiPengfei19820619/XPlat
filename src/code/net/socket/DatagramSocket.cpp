
#include "DatagramSocket.h"


ISocket * CDatagramSocket::Create()
{
	return new CDatagramSocket();
}


CDatagramSocket::CDatagramSocket()
{
	this->m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
}

