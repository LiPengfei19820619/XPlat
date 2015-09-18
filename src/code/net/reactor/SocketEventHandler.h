
#include "XPlat_Socket.h"
#include "SocketReactor.h"


using namespace XPLAT;


class CSocketEventHandler : public ISocketEventHandler
{
public:
	void OnReadable();
	void OnWritable();
	void OnConnected();
	void OnAccepted(ISocket * ptSocket, ISocketAddress * ptAddress);
	void OnError();

public:
	ISocketReactor  * GetReactor();

private:
	CSocketReactor    m_reactor;
};

