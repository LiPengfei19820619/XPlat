#ifndef  PROCESS_WIN32_H
#define  PROCESS_WIN32_H


#include "XPlat_Process.h"

#include <Windows.h>

namespace XPLAT
{


class CWin32Process   : public IProcess
{
public:
	static IProcess * Create();

	int Spawn(CProcessOptions &options);

	XPLAT_PID_T   GetPid();

	XPLAT_PID_T Wait(XPLAT_EXIT_CODE * ptExitCode = NULL);

	bool IsRunning();

	void Release();

private:
	CWin32Process();
	~CWin32Process();

	PROCESS_INFORMATION m_process_info;
	XPLAT_EXIT_CODE     m_exit_code;
};


}   /* namespace XPLAT */



#endif   /* PROCESS_WIN32_H */

