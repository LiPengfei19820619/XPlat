
#include "Socket.h"
#include "DatagramSocket.h"


using namespace XPLAT;


ISocket * ISocket::Create(SOCKET_TYPE_EN type)
{
	if(type == ISocket::SOCKET_TYPE_DATAGRAM)
	{
		return CDatagramSocket::Create();
	}

	return NULL;
}


CSocket::CSocket()
	: m_blConnectPending(false),
	  m_blListening(false)
{
}


CSocket::CSocket(XPLAT_SOCKET_T sock)
	: m_sockfd(sock),
	  m_blConnectPending(false),
	  m_blListening(false)
{
}


CSocket::~CSocket()
{
	Close();
}


bool CSocket::Bind(const ISocketAddress * address, bool reuseAddress )
{
	sockaddr_in addr;

	memset(&addr, 0, sizeof(addr));
	
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr(address->GetIPAddr().c_str());
	addr.sin_port = htons(address->GetPort());

	if(bind(m_sockfd, (const sockaddr *)&addr, sizeof(addr)) < 0)
	{
		return false;
	}
	return true;
}


int CSocket::SendTo(const void * buffer, int length, const ISocketAddress * address, int flags)
{
	int  rc;
	sockaddr_in addr;
	
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr(address->GetIPAddr().c_str());
	addr.sin_port = htons(address->GetPort());

	rc = sendto(m_sockfd,
		        reinterpret_cast<const char *>(buffer),
				length,
				flags,
				(const sockaddr *)&addr,
				sizeof(addr));
	return rc;
}


int CSocket::ReceiveFrom(void * buffer, int length, ISocketAddress ** pptAddress)
{
	int  rc;
	sockaddr_in addr;
	int addrlen = sizeof(addr);

	rc = recvfrom(m_sockfd,
		          reinterpret_cast<char *>(buffer),
				  length,
				  0,
				  (sockaddr *)&addr,
				  &addrlen);

	if(rc >= 0)
	{
		if(pptAddress != NULL)
		{
			* pptAddress = ISocketAddress::Create(inet_ntoa(addr.sin_addr),
				                                  ntohs(addr.sin_port));
		}
	}

	return rc;
}


bool CSocket::Connect(const ISocketAddress * ptAddress)
{
	int rc;
	sockaddr_in addr;
	
	addr.sin_family = AF_INET;
	addr.sin_addr.S_un.S_addr = inet_addr(ptAddress->GetIPAddr().c_str());
	addr.sin_port = htons(ptAddress->GetPort());

	rc = connect(m_sockfd, (const sockaddr *)&addr, sizeof(addr));
	if(rc < 0)
	{
		int err = GetLastError();
		if(err != XPLAT_ERROR_INPROGRESS && err != XPLAT_ERROR_WOULDBLOCK)
		{
			return false;
		}
		m_blConnectPending = true;
	}
	else
	{
	}

	return true;
}


bool CSocket::Listen()
{
	int rc;

	rc = listen(m_sockfd, 5);
	if(rc < 0)
	{
		return false;
	}

	m_blListening = true;
	return true;
}


ISocket * CSocket::Accept(ISocketAddress ** pptAddress)
{
	sockaddr_in addr;
	int addrlen = sizeof(addr);

	XPLAT_SOCKET_T sock;
	do
	{
		sock = accept(m_sockfd, (sockaddr *)&addr, &addrlen);
	}while( (sock == XPLAT_INVALID_SOCKET) && (GetLastError() != XPLAT_ERROR_INTR));

	if(sock != XPLAT_INVALID_SOCKET)
	{
		ISocket * ptSocket = new CSocket(sock);
		if(pptAddress != NULL)
		{
			* pptAddress = ISocketAddress::Create(inet_ntoa(addr.sin_addr),
				                                  ntohs(addr.sin_port));
		}

		return ptSocket;
	}

	return NULL;
}


bool CSocket::Shutdown(bool blShutdown_Read, bool blShutdown_Write)
{
	int how = 0;

	if(blShutdown_Read && blShutdown_Write)
	{
		how = SD_BOTH;
	}
	else if(blShutdown_Read)
	{
		how = SD_RECEIVE;
	}
	else if(blShutdown_Write)
	{
		how = SD_SEND;
	}
	else
	{
		return true;
	}

	if(shutdown(m_sockfd, how) != 0)
	{
		return false;
	}

	return true;
}


bool CSocket::Close()
{
	if(XPLAT_CLOSESOCKET(m_sockfd) < 0)
	{
		return false;
	}

	return true;
}


bool CSocket::IsEqualTo(ISocket * ptISocket)
{
	if(ptISocket == NULL)
	{
		return false;
	}

	CSocket * ptSocket = dynamic_cast<CSocket *>(ptISocket);
	if(ptSocket == NULL)
	{
		return false;
	}

	return this->m_sockfd == ptSocket->m_sockfd;
}


bool CSocket::IsConnectPending()
{
	return this->m_blConnectPending;
}


bool CSocket::CheckConnectResult()
{
	int  value;

	m_blConnectPending = false;

	if(!GetSocketError(value))
	{
		return false;
	}

	if(value != 0)
	{
		return false;
	}

	return true;
}


bool CSocket::IsListening()
{
	return m_blListening;
}


int CSocket::GetLastError()
{
#if defined(WIN32)
	return WSAGetLastError();
#else
	return errno;
#endif
}


XPLAT_SOCKET_T CSocket::GetSockFd()
{
	return m_sockfd;
}


bool CSocket::GetSocketError(int & sockError)
{
	if(GetOption(SOL_SOCKET, SO_ERROR, sockError))
	{
		return true;
	}

	return false;
}


bool CSocket::GetOption(int level, int option, int& value)
{
	XPLAT_SOCKLEN_T  len = sizeof(value);

	if(getsockopt(m_sockfd, level, option, reinterpret_cast<char*>(&value), &len))
	{
		return false;
	}

	return true;
}

