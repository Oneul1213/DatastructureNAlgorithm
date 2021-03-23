#include <iostream>
#include "DBLinkedListCpp.h"
#include "DBLinkedListCpp.cpp"

int main(void)
{
	DoublyLinkedList<int> list;
	int data;

	for (int i = 1; i < 9; i++)
		list.LInsert(i);

	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";

		while (list.LPrevious(data))
			std::cout << data << " ";
		std::cout << std::endl << std::endl;
	}

	if (list.LFirst(data))
	{
		if (data % 2 == 0)
			list.LRemove();

		while (list.LNext(data))
			if (data % 2 == 0)
				list.LRemove();
	}

	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";

		std::cout << std::endl << std::endl;
	}

	return 0;
}