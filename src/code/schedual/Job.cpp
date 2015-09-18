
#include "Job.h"


using namespace XPLAT;


bool CJob::PowerOn()
{
	return true;
}


bool CJob::PowerDown()
{
	return true;
}


JID_T CJob::GetJid()
{
	return m_tJid;
}

