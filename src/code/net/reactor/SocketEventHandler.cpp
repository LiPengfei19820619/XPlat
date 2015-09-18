
#include "SocketEventHandler.h"


using namespace XPLAT;


void CSocketEventHandler::OnReadable()
{
	return;
}


void CSocketEventHandler::OnWritable()
{
	return;
}


void CSocketEventHandler::OnConnected()
{
	return;
}


void CSocketEventHandler::OnAccepted(ISocket * ptSocket, ISocketAddress * ptAddress)
{
	return;
}


void CSocketEventHandler::OnError()
{
	return;
}


ISocketReactor * CSocketEventHandler::GetReactor()
{
	return &m_reactor;
}

