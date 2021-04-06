#include <iostream>
#include "HeapCpp.h"
#include "HeapCpp.cpp"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main(void)
{
	Heap<char> heap(DataPriorityComp);

	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');
	std::cout << heap.HDelete() << std::endl;

	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');
	std::cout << heap.HDelete() << std::endl;

	while (!heap.HIsEmpty())
		std::cout << heap.HDelete() << std::endl;

	return 0;
}