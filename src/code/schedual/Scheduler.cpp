#include "XPlat_Schedual.h"
#include "Scheduler.h"


using namespace XPLAT;


CScheduler * CScheduler::m_pInstance = NULL;


bool CScheduleManager::Init(JOB_REG_ITEM_T atJobRegItems[], WORD16 wJobNum)
{
	CScheduler * ptScheduler = CScheduler::GetInstance();
	if(ptScheduler == NULL)
	{
		return false;
	}

	if(!ptScheduler->Init(atJobRegItems, wJobNum))
	{
		return false;
	}

	return ptScheduler->Start();
}


CScheduler * CScheduler::GetInstance()
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new CScheduler();
	}

	return m_pInstance;
}


bool CScheduler::Init(JOB_REG_ITEM_T atJobItems[], WORD16 wItemNum)
{
	for(unsigned int uiIndex = 0; uiIndex < wItemNum; uiIndex ++)
	{
		JOB_REG_ITEM_T * ptJobRegItem = &atJobItems[uiIndex];
		m_mapJobTypeScheIndex.insert(std::pair<WORD16, unsigned int>(ptJobRegItem->wJobType, ptJobRegItem->wScheIndex));

		CSchedualTask * ptTask = NULL;
		SCHE_INDEX_TASK_MAP::iterator it = m_mapScheIndexTask.find(ptJobRegItem->wScheIndex);
		if(it != m_mapScheIndexTask.end())
		{
			ptTask = (* it).second;
		}
		else
		{
			ptTask = new CSchedualTask();
			m_mapScheIndexTask.insert(std::pair<unsigned int, CSchedualTask *>(ptJobRegItem->wScheIndex, ptTask));
		}
		ptTask->AddJob(ptJobRegItem->ptJob);
	}

	return true;
}


bool CScheduler::Start()
{
	CSchedualTask * ptTask = NULL;
	SCHE_INDEX_TASK_MAP::iterator it = m_mapScheIndexTask.begin();

	while(it != m_mapScheIndexTask.end())
	{
		ptTask = (* it).second;
		ptTask->Start();

		it ++;
	}

	return true;
}


CSchedualTask * CScheduler::GetSchedualTaskByJobType(WORD16 wJobType)
{
	return NULL;
}


CScheduler::CScheduler()
{
}

