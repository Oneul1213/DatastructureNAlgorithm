#include <iostream>
#include "ArraylistCpp.h"

int main(void)
{
	ArrayList list;
	int data;

	list.LInsert(11); list.LInsert(11);
	list.LInsert(22); list.LInsert(22);
	list.LInsert(33);

	std::cout << "현재 데이터의 수: " << list.LCount() << std::endl;

	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";
	}
	std::cout << std::endl << std::endl;

	if (list.LFirst(data))
	{
		if (data == 22)
			list.LRemove();

		while (list.LNext(data))
		{
			if (data == 22)
				list.LRemove();
		}
	}

	std::cout << "현재 데이터의 수: " << list.LCount() << std::endl;

	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";
	}
	std::cout << std::endl << std::endl;
	return 0;
}