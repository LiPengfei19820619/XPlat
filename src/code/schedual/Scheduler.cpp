#include "XPlat_Schedual.h"

using namespace XPLAT;


CScheduler * CScheduler::m_pInstance = NULL;


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
	return true;
}


CScheduler::CScheduler()
{
}

