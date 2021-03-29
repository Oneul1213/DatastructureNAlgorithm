#include <iostream>
#include "ListBaseQueueCpp.h"
#include "ListBaseQueueCpp.cpp"

int main(void)
{
	ListQueue<int> q;

	q.Enqueue(1); q.Enqueue(2);
	q.Enqueue(3); q.Enqueue(4);
	q.Enqueue(5);

	while (!q.QIsEmpty())
		std::cout << q.Dequeue() << " ";

	return 0;
}