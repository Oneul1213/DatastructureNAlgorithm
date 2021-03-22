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

	// 4명의 사원 정보 저장
	list.LInsert(new Staff(2201036, "정바름"));
	list.LInsert(new Staff(2003014, "나유연"));
	list.LInsert(new Staff(1903048, "구아름"));
	list.LInsert(new Staff(2003075, "신재현"));

	// 누구 당직인지 확인
	staff = WhoIsOnDutyNext(list, "정바름", 6);
	staff->ShowStaffInfo();

	return 0;
}