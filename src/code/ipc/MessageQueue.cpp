
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
	if(!m_queue.empty())
	{
		CMessageBlock * ptMsg = m_queue.front();
		m_queue.pop();
		return ptMsg;
	}
	return NULL;
}


bool CMessageQueue::AddMessage(CMessageBlock * ptMsg)
{
	m_queue.push(ptMsg);

	return true;
}

