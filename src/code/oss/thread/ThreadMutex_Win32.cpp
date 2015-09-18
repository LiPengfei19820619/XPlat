
#include "ThreadMutex_Win32.h"


using namespace XPLAT;


IThreadMutex * CWin32ThreadMutex::Create(tstring strName)
{
	CWin32ThreadMutex  * ptMutex = new CWin32ThreadMutex();

	ptMutex->m_hMutex = CreateMutex(NULL, FALSE, strName.c_str());

	return ptMutex;
}


bool CWin32ThreadMutex::Lock()
{
	DWORD dwWaitResult = WaitForSingleObject(this->m_hMutex, INFINITE);
	if(dwWaitResult = WAIT_OBJECT_0)
	{
		return true;
	}

	return false;
}


bool CWin32ThreadMutex::UnLock()
{
	if(ReleaseMutex(this->m_hMutex))
	{
		return true;
	}

	return false;
}
