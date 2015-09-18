#ifndef  XPLAT_THREAD_MUTEX_WIN32_H
#define  XPLAT_THREAD_MUTEX_WIN32_H


#include "XPlat_Thread.h"

#include <Windows.h>


namespace XPLAT
{


class CWin32ThreadMutex : public IThreadMutex
{
public:
	static IThreadMutex * Create(tstring strName);

	virtual bool Lock();
	virtual bool UnLock();

private:
	HANDLE   m_hMutex;
};


}   /* namespace XPLAT */


#endif   /* XPLAT_THREAD_MUTEX_WIN32_H */

