#ifndef  XPLAT_SCHEDUAL_H
#define  XPLAT_SCHEDUAL_H


#include <string>
#include <vector>
#include "os_types.h"
#include "XPlat_Socket.h"
#include "XPlat_Timer.h"


namespace XPLAT
{


typedef void (* JOB_ENTRY_FUNC)(WORD32 dwEvent, void * pvMsg, WORD16 wMsgLen);


typedef struct tagJid
{
	WORD16     wJno;
	WORD16     wInstance;

public:
	bool operator==(tagJid tJid) { return (wJno == tJid.wJno) && (wInstance == tJid.wInstance); }
}JID_T;


class CJob : public ISocketEventHandler, public ITimerEventHandler
{
public:
	CJob(std::string strName = "XPlat_Job");
	virtual ~CJob();

	virtual bool  PowerOn();
	virtual bool  PowerDown();

	virtual void  OnMsg(WORD32 dwEvent, void * pvMsg, WORD16 wMsgLen) = 0;

	JID_T    GetSelfJid();

public:
	void OnReadable();
	void OnWritable();
	void OnConnected();
	void OnAccepted(ISocket * ptSocket, ISocketAddress * ptAddress);
	void OnError();

public:
	void OnTimerOut();

protected:
	void  SendAsyncMsg(BYTE * pbMsg, WORD16 wMsgLen, JID_T tDestJid);

	std::string  m_strName;

private:
	JID_T    m_tJid;
};


typedef struct tabJobRegItem
{
	WORD16          wJobType;
	WORD16          wInstance;
	WORD16          wScheIndex;
	
	CJob          * ptJob;
}JOB_REG_ITEM_T;


class CScheduleManager
{
public:
	static bool Init(JOB_REG_ITEM_T atJobRegItems[], WORD16 wJobNum);
};


}   /* namespace XPLAT */


#endif   /* XPLAT_SCHEDUAL_H */

