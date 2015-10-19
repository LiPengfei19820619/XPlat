#ifndef  XPLAT_MESSAGE_BLOCK_H
#define  XPLAT_MESSAGE_BLOCK_H


#include "XPlat_Schedual.h"
#include "DataBlock.h"


namespace XPLAT
{


class CMessageBlock
{
public:
	CMessageBlock(const char * data, size_t length);

	virtual ~CMessageBlock();

    CDataBlock  * GetDataBlock();

    WORD32        GetMsgId();
	void          SetMsgId(WORD32 dwMsgId);

	JID_T         GetSender();
	void          SetSender(JID_T tSrcJid);
	
	JID_T         GetReceiver();
	void          SetReceiver(JID_T tDstJid);

protected:
	bool          Init(const char * data, size_t length);
	void          Free();

private:
	JID_T         m_tSrcJid;
	JID_T         m_tDstJid;

    WORD32        m_dwMsgId;

	CDataBlock  * m_ptDataBlock;
};


}   /* namespace XPLAT */


#endif  /* XPLAT_MESSAGE_BLOCK_H */

