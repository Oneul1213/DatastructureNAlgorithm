#include <iostream>
#include "SinglyLinkedListCpp.h"
#include "SinglyLinkedListCpp.cpp"

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}

int main(void)
{
	SinglyLinkedList<int> list;
	int data;

	list.SetSortRule(WhoIsPrecede);

	list.LInsert(11); list.LInsert(11);
	list.LInsert(22); list.LInsert(22);
	list.LInsert(33);

	std::cout << "현재 데이터의 수 : " << list.LCount() << std::endl;

	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";
	}
	std::cout << std::endl;

	if (list.LFirst(data))
	{
		if (data == 22)
			list.LRemove();

		while (list.LNext(data))
			if (data == 22)
				list.LRemove();
	}

	std::cout << "현재 데이터의 수 : " << list.LCount() << std::endl;

	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";
	}
	std::cout << std::endl;
}