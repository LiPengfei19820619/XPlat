
#include <process.h>
#include "Thread_Win32.h"


using namespace XPLAT;


IThread * CWin32Thread::Create(XPLAT_THREAD_FUNC func, void * args)
{
	CWin32Thread * ptThread = new CWin32Thread();
	
	ptThread->m_hThread = (HANDLE)_beginthreadex(NULL,
		                                         0,
												 func,
												 args,
												 0,
												 (unsigned int *)&(ptThread->m_dwThreadID));
	return ptThread;
}


int CWin32Thread::Join()
{
	::WaitForSingleObject(this->m_hThread, INFINITE);
	return 0;
}


void CWin32Thread::Release()
{
	delete this;
}


CWin32Thread::CWin32Thread()
{
}


CWin32Thread::~CWin32Thread()
{
}

