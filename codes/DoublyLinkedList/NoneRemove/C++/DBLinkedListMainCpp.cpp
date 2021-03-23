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

	return 0;
}