
#include "MessageBlock.h"


using namespace XPLAT;


CMessageBlock::CMessageBlock()
{
}


CMessageBlock::~CMessageBlock()
{
}


CDataBlock * CMessageBlock::GetDataBlock()
{
	return this->m_ptDataBlock;
}


WORD32 CMessageBlock::GetMsgId()
{
	return this->m_dwMsgId;
}


JID_T CMessageBlock::GetSender()
{
	return this->m_tSrcJid;
}


JID_T CMessageBlock::GetReceiver()
{
	return this->m_tDstJid;
}



