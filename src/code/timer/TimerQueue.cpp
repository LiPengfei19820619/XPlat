
#include "TimerQueue.h"


using namespace XPLAT;


CTimerQueue * CTimerQueue::m_pInstance = NULL;


CTimerQueue::CTimerQueue()
	: m_vecShortRelativeQueue(QUEUE_SCAN_LENGTH, NULL),
	  m_uiCurShortScanPos(0)
{
	InitScanQueue(m_vecShortRelativeQueue);
	InitScanQueue(m_vecLongRelativeQueue);
}


CTimerQueue::~CTimerQueue()
{
	FreeScanQueue(m_vecShortRelativeQueue);
	FreeScanQueue(m_vecLongRelativeQueue);
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
	if(ptTimer == NULL)
	{
		return false;
	}

	unsigned long ulTickCount = ptTimer->GetTickCount();
	if(ulTickCount <= QUEUE_SCAN_LENGTH)
	{
	}
	

	return true;
}


void CTimerQueue::ScanRelTimerQueue()
{
}


void CTimerQueue::InitScanQueue(TIMER_SCAN_QUEUE & timerScanQueue)
{
	for(TIMER_SCAN_QUEUE::iterator it = timerScanQueue.begin();
		it != timerScanQueue.end();
		it ++)
	{
		(* it) = new TIMER_TRIG_LIST(0);
	}

	return;
}


void CTimerQueue::FreeScanQueue(TIMER_SCAN_QUEUE & timerScanQueue)
{
	for(TIMER_SCAN_QUEUE::iterator it = timerScanQueue.begin();
		it != timerScanQueue.end();
		it ++)
	{
		delete (* it);
	}

	return;
}


void CTimerQueue::ScanQueue(TIMER_SCAN_QUEUE & timerScanQueue)
{
	TIMER_TRIG_LIST * ptTimerList = timerScanQueue[this->m_uiCurShortScanPos];

	TrigTimerList(* ptTimerList);
}


void CTimerQueue::TrigTimerList(TIMER_TRIG_LIST & timerList)
{
	for(TIMER_TRIG_LIST::iterator it = timerList.begin();
		it != timerList.end();
		it ++)
	{

	}
}


bool CTimerQueue::AddRelTimerToShortScanQueue(ITimer * ptTimer)
{
	if(ptTimer == NULL)
	{
		return false;
	}

	if(ptTimer->GetTickCount() > QUEUE_SCAN_LENGTH)
	{
		return false;
	}

	unsigned int uiPos = (m_uiCurShortScanPos + ptTimer->GetTickCount()) % QUEUE_SCAN_LENGTH;
	m_vecShortRelativeQueue[uiPos]->push_front(ptTimer);

	return true;
}

