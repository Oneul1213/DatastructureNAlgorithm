#ifndef __STAFF_H__
#define __STAFF_H__

#define NAME_LENGTH	10

typedef struct _staff
{
	int o_num;
	char name[NAME_LENGTH];
} Staff;

void SetStaffInfo(Staff* pstaff, int o_num, char* name);
void ShowStaffInfo(Staff* pstaff);

#endif