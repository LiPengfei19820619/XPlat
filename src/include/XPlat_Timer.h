#ifndef  XPLAT_TIMER_H
#define  XPLAT_TIMER_H


#include "os_types.h"
#include "XPlat_Thread.h"


namespace XPLAT
{


class ITimerEventHandler;

class ITimer
{
public:
	typedef enum TimerType
	{
		TIMER_TYPE_RELATIVE = 0,
		TIMER_TYPE_ABSOLUTE = 1,
		TIMER_TYPE_LOOP     = 2
	}TIMER_TYPE_EN;

	typedef unsigned int TIMER_ID_T;

public:
	static ITimer * Create(TIMER_TYPE_EN type);

	virtual bool Set(WORD32 dwMilliSeconds) = 0;
	virtual bool Kill() = 0;

	virtual TIMER_ID_T GetTimerId() = 0;

	virtual unsigned long GetTickCount() = 0;
	virtual ITimerEventHandler * GetEventHandler() = 0;
};


class ITimerEventHandler
{
public:
	virtual void OnTimerOut() = 0;
};


class CTimerManager
{
public:
	static bool Init();

private:
	static IThread * m_ptTimerScanTask;

	static unsigned __stdcall TimerScanEntry(void * pvParam);
};


}  // namespace XPLAT


#endif  /* XPLAT_TIMER_H */

