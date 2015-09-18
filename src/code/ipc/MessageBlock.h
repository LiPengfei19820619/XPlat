#ifndef  XPLAT_MESSAGE_BLOCK_H
#define  XPLAT_MESSAGE_BLOCK_H


#include "XPlat_Schedual.h"
#include "DataBlock.h"


namespace XPLAT
{


class CMessageBlock
{
public:
	CMessageBlock(void);

	virtual ~CMessageBlock();

    CDataBlock  * GetDataBlock();
    WORD32        GetMsgId();
	JID_T         GetSender();
	JID_T         GetReceiver();

private:
	JID_T         m_tSrcJid;
	JID_T         m_tDstJid;

    WORD32        m_dwMsgId;

	CDataBlock  * m_ptDataBlock;
};


}   /* namespace XPLAT */


#endif  /* XPLAT_MESSAGE_BLOCK_H */

