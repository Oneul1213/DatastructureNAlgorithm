#include <stdio.h>
#include <stdlib.h>
#include "Staff.h"
#include "CLinkedList.h"

Staff* WhoIsOnDutyNext(List* plist, char* name, int days_later)
{
	Staff* pstaff = (Staff*)malloc(sizeof(Staff));
	int i;

	if (LFirst(plist, &pstaff))
	{
		if (!strcmp(pstaff->name, name))
		{
			for (i = 0; i < days_later; i++)
			{
				LNext(plist, &pstaff);
			}
			return pstaff;
		}

		while (1)
		{
			LNext(plist, &pstaff);
			if (!strcmp(pstaff->name, name))
			{
				for (i = 0; i < days_later; i++)
				{
					LNext(plist, &pstaff);
				}
				return pstaff;
			}

		}
	}
}

int main(void)
{
	List list;
	Staff* pstaff;

	ListInit(&list);

	// 4���� ��� ���� ����
	pstaff = (Staff*)malloc(sizeof(Staff));
	SetStaffInfo(pstaff, 2201036, "���ٸ�");
	LInsert(&list, pstaff);

	pstaff = (Staff*)malloc(sizeof(Staff));
	SetStaffInfo(pstaff, 2003014, "������");
	LInsert(&list, pstaff);

	pstaff = (Staff*)malloc(sizeof(Staff));
	SetStaffInfo(pstaff, 1903048, "���Ƹ�");
	LInsert(&list, pstaff);

	pstaff = (Staff*)malloc(sizeof(Staff));
	SetStaffInfo(pstaff, 2003075, "������");
	LInsert(&list, pstaff);

	// ������ �������� Ȯ��
	pstaff = WhoIsOnDutyNext(&list, "���ٸ�", 6);
	ShowStaffInfo(pstaff);

	return 0;
}