
#include "MessageBlock.h"
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


JID_T CJob::GetSelfJid()
{
	return m_tJid;
}


void CJob::SendAsyncMsg(BYTE * pbMsg, WORD16 wMsgLen, JID_T tDestJid)
{
	CMessageBlock * ptMsg = new CMessageBlock((const char *)pbMsg, wMsgLen);
}

