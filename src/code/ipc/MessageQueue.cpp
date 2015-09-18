
#include "MessageQueue.h"


using namespace XPLAT;


CMessageQueue::CMessageQueue()
{
}


CMessageQueue::~CMessageQueue()
{
}


unsigned int CMessageQueue::GetLength() const
{
	return m_uiLength;
}


CMessageBlock * CMessageQueue::GetMessage()
{
	return NULL;
}

