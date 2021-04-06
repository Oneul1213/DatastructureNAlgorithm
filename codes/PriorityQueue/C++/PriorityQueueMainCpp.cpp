#include <iostream>
#include "PriorityQueueCpp.h"
#include "PriorityQueueCpp.cpp"

int DataPriorityComp(char ch1, char ch2)
{
	return ch2 - ch1;
}

int main(void)
{
	PriorityQueue<char> pq(DataPriorityComp);

	pq.PEnqueue('A');
	pq.PEnqueue('B');
	pq.PEnqueue('C');
	std::cout << pq.PDequeue() << std::endl;

	pq.PEnqueue('A');
	pq.PEnqueue('B');
	pq.PEnqueue('C');
	std::cout << pq.PDequeue() << std::endl;

	while (!pq.PQIsEmpty())
		std::cout << pq.PDequeue() << std::endl;

	return 0;
}