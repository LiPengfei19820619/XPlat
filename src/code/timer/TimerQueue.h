#ifndef  TIMER_QUEUE_H
#define  TIMER_QUEUE_H


#include <vector>
#include <list>
#include "XPlat_Timer.h"

namespace XPLAT
{


class CTimerQueue
{
public:
	static CTimerQueue * GetInstance();

	bool  AddRelativeTimer(ITimer * ptTimer);

	void  ScanRelTimerQueue();

private:
	CTimerQueue();
	~CTimerQueue();

	static CTimerQueue * m_pInstance;

	static const int QUEUE_SCAN_LENGTH = 1024;

	typedef std::list<ITimer *> TIMER_TRIG_LIST;
	typedef std::vector<TIMER_TRIG_LIST *> TIMER_SCAN_QUEUE;

	void InitScanQueue(TIMER_SCAN_QUEUE & timerScanQueue);
	void FreeScanQueue(TIMER_SCAN_QUEUE & timerScanQueue);

	void ScanQueue(TIMER_SCAN_QUEUE & timerScanQueue);

	void TrigTimerList(TIMER_TRIG_LIST & timerList);

	TIMER_SCAN_QUEUE m_vecShortRelativeQueue;
	TIMER_SCAN_QUEUE m_vecLongRelativeQueue;

	bool AddRelTimerToShortScanQueue(ITimer * ptTimer);

	unsigned int m_uiCurShortScanPos;
};


}   /* namespace XPLAT */


#endif  /* TIMER_QUEUE_H */

