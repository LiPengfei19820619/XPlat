
#include "TimerQueue.h"


using namespace XPLAT;


CTimerQueue * CTimerQueue::m_pInstance = NULL;


CTimerQueue::CTimerQueue()
{
}


CTimerQueue::~CTimerQueue()
{
}


CTimerQueue * CTimerQueue::GetInstance()
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new CTimerQueue();
	}

	return m_pInstance;
}


bool CTimerQueue::AddRelativeTimer(ITimer * ptTimer)
{
	return true;
}

