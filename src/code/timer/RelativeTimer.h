#ifndef  RELATIVE_TIMER_H
#define  RELATIVE_TIMER_H


#include "XPlat_Timer.h"
#include "Timer.h"


namespace  XPLAT
{


class CRelativeTimer : public CTimer
{
public:
	bool Set(WORD32 dwMilliSeconds);
	bool Kill();

private:
	unsigned int m_uiTickCount;
};


}  // namespace  XPLAT


#endif  /* RELATIVE_TIMER_H */

