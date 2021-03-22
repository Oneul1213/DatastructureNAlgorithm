#include <stdio.h>
#include <string.h>
#include "Staff.h"

void SetStaffInfo(Staff* pstaff, int o_num, char* name)
{
	pstaff->o_num = o_num;
	strcpy(pstaff->name, name);
}

void ShowStaffInfo(Staff* pstaff)
{
	printf("사번 : %d\n", pstaff->o_num);
	printf("이름 : %s\n", pstaff->name);
}