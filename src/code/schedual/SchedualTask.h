#ifndef  XPLAT_SCHEDUAL_TASK_H
#define  XPLAT_SCHEDUAL_TASK_H


#include <vector>
#include "XPlat_Thread.h"
#include "..\ipc\MessageQueue.h"


namespace  XPLAT
{


class CJob;

class CSchedualTask
{
public:
	CSchedualTask();
	~CSchedualTask();

	bool  Start();
	bool  AddJob(CJob * ptJob);
	CJob * GetJob(JID_T tJid);

	bool AddMessage(CMessageBlock * ptMsg);
	CMessageBlock * GetMessage();

private:
	unsigned int m_uiIndex;

	typedef std::vector<CJob *>  JOB_LIST_T;

	JOB_LIST_T  m_vecJobList;

	static unsigned int __stdcall SchedualEntry(void *);

	IThread  * m_ptThread;

	CMessageQueue  m_msgQueue;
};


};   /* namespace XPLAT */


#endif

