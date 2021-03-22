#include <iostream>
#include <string>
#include "StaffCpp.h"
#include "CircularLinkedListCpp.h"
#include "CircularLinkedListCpp.cpp"

Staff* WhoIsOnDutyNext(CircularLinkedList<Staff*>& list, std::string name, int days_later)
{
	Staff* staff;

	if (list.LFirst(staff))
	{
		if (staff->name.compare(name) == 0)
			for (int i = 0; i < days_later; i++)
				list.LNext(staff);
			return staff;
	}

	while (1)
	{
		list.LNext(staff);
		if (staff->name.compare(name) == 0)
			for (int i = 0; i < days_later; i++)
				list.LNext(staff);
			return staff;
	}
}

int main(void)
{
	CircularLinkedList<Staff*> list;
	Staff* staff;

	// 4���� ��� ���� ����
	list.LInsert(new Staff(2201036, "���ٸ�"));
	list.LInsert(new Staff(2003014, "������"));
	list.LInsert(new Staff(1903048, "���Ƹ�"));
	list.LInsert(new Staff(2003075, "������"));

	// ���� �������� Ȯ��
	staff = WhoIsOnDutyNext(list, "���ٸ�", 6);
	staff->ShowStaffInfo();

	return 0;
}