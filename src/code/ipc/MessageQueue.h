#ifndef   XPLAT_MESSAGE_QUEUE_H
#define   XPLAT_MESSAGE_QUEUE_H


#include <queue>
#include "MessageBlock.h"


namespace XPLAT
{


class CMessageQueue
{
public:
	CMessageQueue(void);

	virtual ~CMessageQueue();

	unsigned int  GetLength() const;

	CMessageBlock * GetMessage();
	bool AddMessage(CMessageBlock * ptMsg);

private:
	typedef std::queue<CMessageBlock *> QUEUE_T;
	QUEUE_T        m_queue;
	unsigned int   m_uiLength;
};


}   /* namespace XPLAT */


#endif  /* XPLAT_MESSAGE_QUEUE_H */

