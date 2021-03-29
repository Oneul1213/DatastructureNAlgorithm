#include <iostream>
#include "DequeCpp.h"
#include "DequeCpp.cpp"

int main(void)
{
	Deque<int> deq;

	deq.DQAddFirst(3);
	deq.DQAddFirst(2);
	deq.DQAddFirst(1);

	deq.DQAddLast(4);
	deq.DQAddLast(5);
	deq.DQAddLast(6);

	while (!deq.DQIsEmpty())
		printf("%d ", deq.DQRemoveFirst());

	printf("\n");

	deq.DQAddFirst(3);
	deq.DQAddFirst(2);
	deq.DQAddFirst(1);

	deq.DQAddLast(4);
	deq.DQAddLast(5);
	deq.DQAddLast(6);

	while (!deq.DQIsEmpty())
		printf("%d ", deq.DQRemoveLast());

	return 0;
}