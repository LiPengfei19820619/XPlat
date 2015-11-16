#ifndef  TIMER_H
#define  TIMER_H


#include "XPlat_Timer.h"


namespace XPLAT
{


class CTimer : public ITimer
{
public:
	unsigned long GetTickCount();
	ITimerEventHandler * GetEventHandler();

	void CalcTickCount(WORD32 dwMilliSeconds);

private:
	TIMER_ID_T  m_uiTimerId;
	unsigned long  m_ulTickCount;
	ITimerEventHandler * m_ptHandler;

	static const int PRECISION = 100;  // ¾«¶È100ms
};


}   // namespace XPLAT


#endif  /* TIMER_H */

