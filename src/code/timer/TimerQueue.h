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

private:
	CTimerQueue();
	~CTimerQueue();

	static CTimerQueue * m_pInstance;

	static const int QUEUE_SCAN_LENGTH = 1024;

	typedef std::list<ITimer *> TIMER_TRIG_LIST;
	typedef std::vector<TIMER_TRIG_LIST *> TIMER_SCAN_QUEUE;

	TIMER_SCAN_QUEUE m_vecRelativeQueue[QUEUE_SCAN_LENGTH];
};


}   /* namespace XPLAT */


#endif  /* TIMER_QUEUE_H */

