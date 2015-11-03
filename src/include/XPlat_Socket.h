#ifndef XPLAT_SOCKET_H
#define XPLAT_SOCKET_H


#include "XPlat_SocketAddress.h"


namespace XPLAT
{


class ISocket
{
public:
	typedef enum SocketType
	{
		SOCKET_TYPE_INVALID  = 0,
		SOCKET_TYPE_STREAM   = 1,
		SOCKET_TYPE_DATAGRAM = 2
	}SOCKET_TYPE_EN;

public:
	static ISocket * Create(SOCKET_TYPE_EN type);

	virtual bool Bind(const ISocketAddress * address, bool reuseAddress = false) = 0;

	virtual int  SendTo(const void * buffer, int length, const ISocketAddress * address, int flags = 0) = 0;
    virtual int  ReceiveFrom(void * buffer, int length, ISocketAddress ** pptAddress) = 0;

	virtual bool Connect(const ISocketAddress * ptAddress) = 0;
	virtual bool Listen() = 0;
	virtual ISocket * Accept(ISocketAddress ** pptAddress = NULL) = 0;

    virtual bool Shutdown(bool blShutdown_Read = true, bool blShutdown_Write = true) = 0;
	virtual bool Close() = 0;

    virtual bool IsEqualTo(ISocket *) = 0;
    virtual bool IsConnectPending() = 0;
    virtual bool CheckConnectResult() = 0;
	virtual bool IsListening() = 0;
};


class ISocketReactor;

class ISocketEventHandler
{
public:
	virtual void OnReadable() = 0;
	virtual void OnWritable() = 0;
	virtual void OnConnected() = 0;
	virtual void OnAccepted(ISocket *, ISocketAddress *) = 0;
	virtual void OnError() = 0;

protected:
	virtual ISocketReactor  * GetReactor(){return NULL;}
};


class ISocketReactor
{
public:
	static ISocketReactor * Create();

	virtual void Release() = 0;

	virtual void Run() = 0;
	virtual void Stop() = 0;

	virtual void AddEventHandler(ISocket *, ISocketEventHandler *) = 0;
};


class CNetManager
{
public:
	static bool Init();
	static ISocketReactor * GetReactor();

private:
	static ISocketReactor * m_ptReactor;
};


}


#endif /* XPLAT_SOCKET_H */


