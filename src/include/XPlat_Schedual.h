#ifndef  XPLAT_SCHEDUAL_H
#define  XPLAT_SCHEDUAL_H


#include "os_types.h"


namespace XPLAT
{


typedef struct tagJid
{
	WORD16     wJno;
	WORD16     wInstance;

public:
	bool operator==(tagJid tJid) { return (wJno == tJid.wJno) && (wInstance == tJid.wInstance); }
}JID_T;


}   /* namespace XPLAT */


#endif   /* XPLAT_SCHEDUAL_H */

