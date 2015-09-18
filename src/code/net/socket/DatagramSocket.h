
#include "Socket.h"


class CDatagramSocket : public CSocket
{
public:
	static ISocket * Create();

private:
	CDatagramSocket();
};

