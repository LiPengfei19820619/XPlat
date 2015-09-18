#ifndef  THREAD_WIN32_H
#define  THREAD_WIN32_H


#include "XPlat_Thread.h"

#include <Windows.h>

namespace XPLAT
{


class CWin32Thread  : public IThread
{
public:
	static IThread * Create(XPLAT_THREAD_FUNC func, void * args);

	virtual int Join();

	virtual void Release();

private:
	CWin32Thread();
	~CWin32Thread();

	DWORD   m_dwThreadID;
	HANDLE  m_hThread;
};


}   /* namespace XPLAT */


#endif  /* THREAD_WIN32_H */

