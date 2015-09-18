
#include "XPlat_Socket.h"
#include <map>
#include <vector>


using namespace XPLAT;


class CSocketReactor : public ISocketReactor
{
public:
	CSocketReactor();
	~CSocketReactor();

	void Release();

	void Run();
	void Stop();
	void AddEventHandler(ISocket *, ISocketEventHandler * ptHandler);
	void RemoveEventHandler(ISocket *, ISocketEventHandler * ptHandler);
	bool HasEventHandler(ISocket *, ISocketEventHandler * ptHandler);

private:

	typedef std::vector<ISocket *>  SocketList;
	typedef std::map<ISocket *, ISocketEventHandler *>  EventHandlerMap;

	void Select(SocketList & readList, SocketList & writeList, SocketList &errorList);
	bool InSocketList(ISocket *, SocketList &);

	EventHandlerMap     m_mapHandlers;

	bool  m_blStop;
};

