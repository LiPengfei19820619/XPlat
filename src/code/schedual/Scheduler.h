#ifndef  XPLAT_SCHEDULER_H
#define  XPLAT_SCHEDULER_H

#include <map>

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

	typedef std::map<WORD16, unsigned int> JOBTYPE_SCHE_INDEX_MAP;
	typedef std::map<unsigned int, CSchedualTask *> SCHE_INDEX_TASK_MAP;

	JOBTYPE_SCHE_INDEX_MAP m_mapJobTypeScheIndex;
	SCHE_INDEX_TASK_MAP    m_mapScheIndexTask;
};


}   /* namespace XPLAT */


#endif  /* XPLAT_SCHEDULER_H */

