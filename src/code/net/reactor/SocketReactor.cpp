
#include "Socket.h"
#include "SocketReactor.h"


using namespace XPLAT;


ISocketReactor * ISocketReactor::Create()
{
	return new CSocketReactor();
}


void CSocketReactor::Release()
{
	delete this;
}


CSocketReactor::CSocketReactor() :
                    m_blStop(false)
{
}


CSocketReactor::~CSocketReactor()
{
}


void CSocketReactor::Run()
{
	SocketList      readable;
	SocketList      writable;
	SocketList      except;

	while(!m_blStop)
	{
		readable.clear();
		writable.clear();
		except.clear();

		for(EventHandlerMap::iterator it = m_mapHandlers.begin(); it != m_mapHandlers.end(); it ++)
		{
			readable.push_back(it->first);
			writable.push_back(it->first);
		}

		Select(readable, writable, except);

		for(EventHandlerMap::iterator it = m_mapHandlers.begin(); it != m_mapHandlers.end(); it ++)
		{
			if(InSocketList(it->first, readable))
			{
				if(it->first->IsListening())
				{
					ISocket * ptSocket = NULL;
					ISocketAddress * ptAddress = NULL;

					ptSocket = it->first->Accept(&ptAddress);

					it->second->OnAccepted(ptSocket, ptAddress);
				}
				else
				{
					it->second->OnReadable();
				}
			}
			if(InSocketList(it->first, writable))
			{
				if(it->first->IsConnectPending())
				{
					if(it->first->CheckConnectResult())
					{
						it->second->OnConnected();
					}
					else
					{
						it->second->OnError();
					}
				}
				else
				{
					it->second->OnWritable();
				}
			}
		}
	}
}


void CSocketReactor::Stop()
{
	m_blStop = true;
}


void CSocketReactor::AddEventHandler(ISocket * ptSocket, ISocketEventHandler * ptHandler)
{
	EventHandlerMap::iterator it;
	for(it = m_mapHandlers.begin(); it != m_mapHandlers.end(); it ++)
	{
		if(it->first->IsEqualTo(ptSocket))
		{
			return;
		}
	}

	m_mapHandlers.insert(std::pair<ISocket *, ISocketEventHandler *>(ptSocket, ptHandler));

	return;
}


void CSocketReactor::RemoveEventHandler(ISocket * ptSocket, ISocketEventHandler * ptHandler)
{
	EventHandlerMap::iterator it;
	for(it = m_mapHandlers.begin(); it != m_mapHandlers.end(); it ++)
	{
		if(it->first->IsEqualTo(ptSocket))
		{
			m_mapHandlers.erase(it);
			return;
		}
	}

	return;
}


bool CSocketReactor::HasEventHandler(ISocket * ptSocket, ISocketEventHandler * ptHandler)
{
	EventHandlerMap::iterator it;
	for(it = m_mapHandlers.begin(); it != m_mapHandlers.end(); it ++)
	{
		if(it->first->IsEqualTo(ptSocket))
		{
			return true;
		}
	}

	return false;
}


void CSocketReactor::Select(SocketList & readList, SocketList & writeList, SocketList &errorList)
{
	fd_set fdRead;
	fd_set fdWrite;
	//fd_set fdExcept;
	int nfd = 0;
	FD_ZERO(&fdRead);
	FD_ZERO(&fdWrite);

	for(SocketList::iterator it = readList.begin(); it != readList.end(); it ++)
	{
		ISocket * ptISocket = (* it);
		CSocket * ptSocket = dynamic_cast<CSocket *>(ptISocket);
		if(ptSocket != NULL)
		{
			FD_SET(ptSocket->GetSockFd(), &fdRead);
		}
	}

	for(SocketList::iterator it = writeList.begin(); it != writeList.end(); it ++)
	{
		ISocket * ptISocket = (* it);
		CSocket * ptSocket = dynamic_cast<CSocket *>(ptISocket);
		if(ptSocket != NULL)
		{
			FD_SET(ptSocket->GetSockFd(), &fdWrite);
		}
	}

	struct timeval tv;
	tv.tv_sec = 0;
	tv.tv_usec = 250000;

	int rc = 0;
	rc = select(0, &fdRead, &fdWrite, NULL, &tv);
	if(rc < 0)
	{
		return;
	}

	SocketList readyReadList;
	for(SocketList::const_iterator it = readList.begin(); it != readList.end(); it ++)
	{
		CSocket * ptSocket = dynamic_cast<CSocket *>(* it);
		if(ptSocket != NULL)
		{
			if(FD_ISSET(ptSocket->GetSockFd(), &fdRead))
			{
				readyReadList.push_back(* it);
			}
		}
	}
	std::swap(readList, readyReadList);

	SocketList readyWriteList;
	for(SocketList::const_iterator it = writeList.begin(); it != writeList.end(); it ++)
	{
		CSocket * ptSocket = dynamic_cast<CSocket *>(* it);
		if(ptSocket != NULL)
		{
			if(FD_ISSET(ptSocket->GetSockFd(), &fdRead))
			{
				readyWriteList.push_back(* it);
			}
		}
	}
	std::swap(writeList, readyWriteList);

	return;
}


bool CSocketReactor::InSocketList(ISocket * ptSocket, SocketList & sockList)
{
	if(ptSocket == NULL)
	{
		return false;
	}

	for(SocketList::const_iterator it = sockList.begin(); it != sockList.end(); it ++)
	{
		if((* it)->IsEqualTo(ptSocket))
		{
			return true;
		}
	}

	return false;
}

