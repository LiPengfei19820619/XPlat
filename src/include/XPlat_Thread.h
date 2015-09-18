// -*- C++ -*-

//=============================================================================
/**
 *  @file    Thread.h
 *
 *  $Id: Process.h 97553 2014-10-20 Nanjing $
 *
 *  @author LI Pengfei <pflinuaa@gmail.com>
 */
//=============================================================================

#ifndef XPLAT_THREAD_H
#define XPLAT_THREAD_H


#include <string>
#include "os_types.h"


namespace XPLAT
{


typedef unsigned (__stdcall * XPLAT_THREAD_FUNC)(void *);


class IThread
{
public:
	static IThread * Create(XPLAT_THREAD_FUNC func, void * args);

	virtual int Join() = 0;

    virtual void Release() = 0;
};


class IThreadMutex
{
public:
	static IThreadMutex * Create(tstring strName);

	virtual bool Lock() = 0;
	virtual bool UnLock() = 0;
};



}   /* namespace XPLAT */

#endif  /* XPLAT_THREAD_H */

