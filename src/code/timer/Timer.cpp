
#include "Timer.h"


using namespace XPLAT;


unsigned long CTimer::GetTickCount()
{
	return m_ulTickCount;
}


ITimerEventHandler * CTimer::GetEventHandler()
{
	return m_ptHandler;
}


void CTimer::CalcTickCount(WORD32 dwMilliSeconds)
{
	m_ulTickCount = dwMilliSeconds / PRECISION;

	return;
}

