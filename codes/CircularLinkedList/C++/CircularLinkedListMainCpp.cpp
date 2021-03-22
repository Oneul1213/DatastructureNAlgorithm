#include <iostream>
#include "CircularLinkedListCpp.h"
#include "CircularLinkedListCpp.cpp"

int main(void)
{
	CircularLinkedList<int>* list = new CircularLinkedList<int>();
	int data, i, nodeNum;

	list->LInsert(3);
	list->LInsert(4);
	list->LInsert(5);
	list->LInsertFront(2);
	list->LInsertFront(1);

	if (list->LFirst(data))
	{
		std::cout << data << " ";

		for (i = 0; i < list->LCount() * 3 - 1; i++)
		{
			if (list->LNext(data))
				std::cout << data << " ";
		}
	}
	std::cout << std::endl;

	nodeNum = list->LCount();

	if (nodeNum != 0)
	{
		list->LFirst(data);
		if (data % 2 == 0)
			list->LRemove();

		for (i = 0; i < nodeNum - 1; i++)
		{
			list->LNext(data);
			if (data % 2 == 0)
				list->LRemove();
		}
	}

	if (list->LFirst(data))
	{
		std::cout << data << " ";

		for (i = 0; i < list->LCount() - 1; i++)
		{
			if (list->LNext(data))
				std::cout << data << " ";
		}
	}
	std::cout << std::endl;
	return 0;
}