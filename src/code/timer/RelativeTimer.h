#ifndef  RELATIVE_TIMER_H
#define  RELATIVE_TIMER_H


#include "XPlat_Timer.h"


namespace  XPLAT
{


class CRelativeTimer : public ITimer
{
public:
	bool Set(WORD32 dwMilliSeconds);
	bool Kill();
};


}  // namespace  XPLAT


#endif  /* RELATIVE_TIMER_H */

