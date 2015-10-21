#ifndef  XPLAT_SCHEDULER_H
#define  XPLAT_SCHEDULER_H


#include "SchedualTask.h"


namespace XPLAT
{


class CScheduler
{
public:
	static CScheduler * GetInstance();

	bool Init(JOB_REG_ITEM_T atJobItems[], WORD16 wItemNum);

	CSchedualTask * GetSchedualTaskByJobType(WORD16 wJobType);

private:
	CScheduler();

	static CScheduler  * m_pInstance;
};


}   /* namespace XPLAT */


#endif  /* XPLAT_SCHEDULER_H */

