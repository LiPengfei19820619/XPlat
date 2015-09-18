#ifndef  SOCKET_H
#define  SOCKET_H


//#include <WinSock2.h>
#include "XPlat_Socket.h"
#include "SocketDefs.h"


using namespace XPLAT;


class CSocket : public ISocket
{
public:
	bool Bind(const ISocketAddress * address, bool reuseAddress = false);

	int  SendTo(const void * buffer, int length, const ISocketAddress * address, int flags = 0);
	int  ReceiveFrom(void * buffer, int length, ISocketAddress ** pptAddress);

	bool Connect(const ISocketAddress * ptAddress);
	bool Listen();
	ISocket * Accept(ISocketAddress ** pptAddress = NULL);

	bool Shutdown(bool blShutdown_Read = true, bool blShutdown_Write = true);
	bool Close();

	bool IsEqualTo(ISocket * ptSocket);
	bool IsConnectPending();
	bool CheckConnectResult();
	bool IsListening();

	int  GetLastError();

    XPLAT_SOCKET_T  GetSockFd();

	bool GetSocketError(int & sockError);
		/// Returns the value of the SO_ERROR socket option.

protected:
	CSocket();
	CSocket(XPLAT_SOCKET_T sock);
	virtual ~CSocket();

	XPLAT_SOCKET_T   m_sockfd;

private:
	bool GetOption(int level, int option, int& value);
		/// Returns the value of the socket option 
		/// specified by level and option.

	bool m_blConnectPending;
	bool m_blListening;
};


#endif /* SOCKET_H */

