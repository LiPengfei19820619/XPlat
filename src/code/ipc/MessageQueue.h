#ifndef   XPLAT_MESSAGE_QUEUE_H
#define   XPLAT_MESSAGE_QUEUE_H


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

private:
	unsigned int   m_uiLength;
};


}   /* namespace XPLAT */


#endif  /* XPLAT_MESSAGE_QUEUE_H */

