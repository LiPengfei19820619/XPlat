
#include "Process_Win32.h"

using namespace XPLAT;


IProcess * CWin32Process::Create()
{
	return new CWin32Process();
}


int CWin32Process::Spawn(CProcessOptions &options)
{
	BOOL   blResult = FALSE;

	STARTUPINFO si = { sizeof(si) };
	SECURITY_ATTRIBUTES   saProcess, saThread;
	
	saProcess.nLength = sizeof(saProcess);
	saProcess.lpSecurityDescriptor = NULL;
	saProcess.bInheritHandle = TRUE;

	saThread.nLength = sizeof(saThread);
	saThread.lpSecurityDescriptor = NULL;
	saThread.bInheritHandle = FALSE;
		
	blResult = CreateProcess(NULL,
		                     options.GetCommandLineBuf(),
							 &saProcess,
							 &saThread,
							 TRUE,
							 0,
							 NULL,
							 NULL,
							 &si,
							 &this->m_process_info);
	if(!blResult)
	{
		return -1;
	}

	return 0;
}


XPLAT_PID_T CWin32Process::GetPid()
{
	return m_process_info.dwProcessId;
}


XPLAT_PID_T CWin32Process::Wait(XPLAT_EXIT_CODE * ptExitCode)
{
	DWORD dwWaitResult = WaitForSingleObject(this->m_process_info.hProcess, INFINITE);
	if(dwWaitResult == WAIT_OBJECT_0)
	{
		GetExitCodeProcess(this->m_process_info.hProcess, &this->m_exit_code);
		if(ptExitCode != NULL)
		{
			* ptExitCode = m_exit_code;
		}

		return this->GetPid();
	}

	return XPLAT_INVALID_PID;
}


bool CWin32Process::IsRunning()
{
	DWORD code;

	BOOL result = ::GetExitCodeProcess (this->m_process_info.hProcess, &code);
    return result && code == STILL_ACTIVE;
}


void CWin32Process::Release()
{
	delete this;
}


CWin32Process::CWin32Process()
{
	memset(&this->m_process_info, 0, sizeof(this->m_process_info));
}


CWin32Process::~CWin32Process()
{
	CloseHandle(this->m_process_info.hProcess);
	CloseHandle(this->m_process_info.hThread);
}


