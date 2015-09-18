// -*- C++ -*-

//=============================================================================
/**
 *  @file    Process.h
 *
 *  $Id: Process.h 97553 2014-10-20 Nanjing $
 *
 *  @author LI Pengfei <pflinuaa@gmail.com>
 */
//=============================================================================

#ifndef XPLAT_PROCESS_H
#define XPLAT_PROCESS_H


#include "os_types.h"


namespace XPLAT
{


class CProcessOptions;

class IProcess
{
public:
	static IProcess * Create();

	virtual int Spawn(CProcessOptions &options) = 0;
	virtual XPLAT_PID_T GetPid() = 0;

    virtual XPLAT_PID_T Wait(XPLAT_EXIT_CODE * ptExitCode = 0) = 0;

	virtual bool IsRunning() = 0;

    virtual void Release() = 0;

};


class CProcessOptions
{
public:
	bool SetCommandLine(const XPLAT_TCHAR * format, ...);
	XPLAT_TCHAR * GetCommandLineBuf();

private:
#define  DEFAULT_COMMAND_LINE_BUF_LEN  1024
	XPLAT_TCHAR  m_achCommandLine[DEFAULT_COMMAND_LINE_BUF_LEN];
};


}   /* namespace XPLAT */

#endif  /* XPLAT_PROCESS_H */

