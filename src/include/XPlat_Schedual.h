#ifndef  XPLAT_SCHEDUAL_H
#define  XPLAT_SCHEDUAL_H


#include <string>
#include "os_types.h"


namespace XPLAT
{


typedef void (* JOB_ENTRY_FUNC)(WORD32 dwEvent, void * pvMsg, WORD16 wMsgLen);


typedef struct tagJid
{
	WORD16     wJno;
	WORD16     wInstance;

public:
	bool operator==(tagJid tJid) { return (wJno == tJid.wJno) && (wInstance == tJid.wInstance); }
}JID_T;


typedef struct tabJobRegItem
{
	WORD16          wJobType;
	WORD16          wInstance;
	WORD16          wScheIndex;
	std::string     strName;
	JOB_ENTRY_FUNC  pfEntry; 
}JOB_REG_ITEM_T;


}   /* namespace XPLAT */


#endif   /* XPLAT_SCHEDUAL_H */

