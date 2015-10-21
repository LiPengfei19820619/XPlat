
#include "Job.h"
#include "SchedualTask.h"


using namespace XPLAT;


CSchedualTask::CSchedualTask() :
    m_ptThread(NULL)
{
}


CSchedualTask::~CSchedualTask()
{
	if(m_ptThread != NULL)
	{
		m_ptThread->Join();
		m_ptThread->Release();
		m_ptThread = NULL;
	}
}


bool CSchedualTask::Start()
{
	m_ptThread = IThread::Create(SchedualEntry, this);
	if(m_ptThread == NULL)
	{
		return false;
	}

	return true;
}


bool CSchedualTask::AddJob(CJob * ptJob)
{
	if(ptJob == NULL)
	{
		return false;
	}

	m_vecJobList.push_back(ptJob);

	return true;
}


CJob * CSchedualTask::GetJob(JID_T tJid)
{
	JOB_LIST_T::iterator it = m_vecJobList.begin();

	for(; it != m_vecJobList.end(); it ++)
	{
		if( (* it)->GetSelfJid() == tJid)
		{
			return (* it);
		}
	}
	return NULL;
}


bool CSchedualTask::AddMessage(CMessageBlock * ptMsg)
{
	return true;
}


unsigned int CSchedualTask::SchedualEntry(void * pvParam)
{
	CSchedualTask * ptSchedualTask = (CSchedualTask *)pvParam;

	if(ptSchedualTask == NULL)
	{
		return -1;
	}

	CMessageBlock * ptMsg = NULL;

	while( (ptMsg = ptSchedualTask->m_msgQueue.GetMessage()) != NULL )
	{
		JID_T  tJid = ptMsg->GetReceiver();
		CJob * ptJob = ptSchedualTask->GetJob(tJid);
		if(ptJob != NULL)
		{
			CDataBlock * ptDataBlock = ptMsg->GetDataBlock();

			ptJob->OnMsg(ptMsg->GetMsgId(), ptDataBlock->GetData(), ptDataBlock->GetSize());
		}
	}

	return 0;
}

