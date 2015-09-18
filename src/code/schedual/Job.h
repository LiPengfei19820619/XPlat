#ifndef  XPLAT_JOB_H
#define  XPLAT_JOB_H


#include "os_types.h"
#include "XPlat_Schedual.h"


namespace XPLAT
{


class CJob
{
public:
	bool  PowerOn();
	bool  PowerDown();

	virtual void  OnMsg(WORD32 dwEvent, void * pvMsg, WORD16 wMsgLen) = 0;

	JID_T    GetJid();

private:
	JID_T    m_tJid;
};


}   /* namespace XPLAT */


#endif   /* XPLAT_JOB_H */

