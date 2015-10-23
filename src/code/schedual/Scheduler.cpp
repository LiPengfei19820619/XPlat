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

	return ptScheduler->Init(atJobRegItems, wJobNum);
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

