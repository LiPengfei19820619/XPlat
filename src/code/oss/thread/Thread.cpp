
#include "XPlat_Thread.h"
#include "Thread_Win32.h"
#include "ThreadMutex_Win32.h"


using namespace XPLAT;


IThread * IThread::Create(XPLAT_THREAD_FUNC func, void * args)
{
#ifdef WIN32
	return CWin32Thread::Create(func, args);
#else
	return NULL;
#endif
}


IThreadMutex * IThreadMutex::Create(tstring strName)
{
#ifdef WIN32
	return CWin32ThreadMutex::Create(strName);
#else
	return NULL;
#endif
}

