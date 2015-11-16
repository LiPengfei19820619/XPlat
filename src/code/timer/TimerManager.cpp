
#include "XPlat_Timer.h"
#include "TimerQueue.h"


using namespace XPLAT;


IThread * CTimerManager::m_ptTimerScanTask = NULL;


bool CTimerManager::Init()
{
	CTimerQueue * ptTimerQueue = CTimerQueue::GetInstance();
	
	m_ptTimerScanTask = IThread::Create(TimerScanEntry, ptTimerQueue);

	return true;
}


unsigned __stdcall  CTimerManager::TimerScanEntry(void * pvParam)
{
	CTimerQueue * ptTimerQueue = static_cast<CTimerQueue *>(pvParam);

	while(true)
	{
		ptTimerQueue->ScanRelTimerQueue();

		//sleep(100);
	}

	return 0;
}

