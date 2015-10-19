
#include "MessageBlock.h"


using namespace XPLAT;


CMessageBlock::CMessageBlock(const char * data, size_t length)
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


void CMessageBlock::SetMsgId(WORD32 dwMsgId)
{
	m_dwMsgId = dwMsgId;
}


JID_T CMessageBlock::GetSender()
{
	return this->m_tSrcJid;
}


void CMessageBlock::SetSender(JID_T tSrcJid)
{
	m_tSrcJid = tSrcJid;
}


JID_T CMessageBlock::GetReceiver()
{
	return this->m_tDstJid;
}


void CMessageBlock::SetReceiver(JID_T tDstJid)
{
	m_tDstJid = tDstJid;
}


bool CMessageBlock::Init(const char * data, size_t length)
{
	this->m_ptDataBlock = new CDataBlock();
	m_ptDataBlock->SetData(data, length);

	return true;
}


void CMessageBlock::Free()
{
	if(m_ptDataBlock != NULL)
	{
		delete m_ptDataBlock;
		m_ptDataBlock = NULL;
	}

	return;
}

