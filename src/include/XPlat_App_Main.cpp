#include <iostream>

#include "XPlat_Schedual.h"

using namespace XPLAT;


extern JOB_REG_ITEM_T g_atJobRegItems[];
extern WORD16 g_wJobNum;


int main(int argc, char *argv[])
{
	std::cout<<"XPlat App starting..."<<std::endl;

	CScheduleManager::Init(g_atJobRegItems, g_wJobNum);

	return 0;
}
