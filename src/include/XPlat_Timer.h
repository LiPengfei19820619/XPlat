#ifndef  XPLAT_TIMER_H
#define  XPLAT_TIMER_H


#include "os_types.h"


namespace XPLAT
{


class ITimer
{
public:
	typedef enum TimerType
	{
		TIMER_TYPE_RELATIVE = 0,
		TIMER_TYPE_ABSOLUTE = 1,
		TIMER_TYPE_LOOP     = 2
	}TIMER_TYPE_EN;

public:
	static ITimer * Create(TIMER_TYPE_EN type);

	virtual bool Set(WORD32 dwMilliSeconds) = 0;
	virtual bool Kill() = 0;

};


class CTimerManager
{
public:
	static bool Init();
};


}  // namespace XPLAT


#endif  /* XPLAT_TIMER_H */

