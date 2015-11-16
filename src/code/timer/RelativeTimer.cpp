
#include "RelativeTimer.h"


using namespace XPLAT;


bool CRelativeTimer::Set(WORD32 dwMilliSeconds)
{
	CalcTickCount(dwMilliSeconds);

	return true;
}


bool CRelativeTimer::Kill()
{
	return true;
}

