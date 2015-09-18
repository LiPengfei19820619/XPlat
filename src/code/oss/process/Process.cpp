#include <stdio.h>
#include "..\include\Process.h"
#include "Process_Win32.h"


using namespace XPLAT;


IProcess * IProcess::Create()
{
#ifdef WIN32
	return CWin32Process::Create();
#else
	return NULL;
#endif
}


bool CProcessOptions::SetCommandLine(const XPLAT_TCHAR * format, ...)
{
	va_list argp;
	
    va_start (argp, format);

	XPLAT_TEXT("aaa");

	_vsnwprintf_s(this->m_achCommandLine, DEFAULT_COMMAND_LINE_BUF_LEN, format, argp);

	va_end (argp);

	return true;
}


XPLAT_TCHAR * CProcessOptions::GetCommandLineBuf()
{
	return this->m_achCommandLine;
}

