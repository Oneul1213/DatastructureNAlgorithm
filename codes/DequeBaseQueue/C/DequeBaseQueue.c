#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"

void QueueInit(Queue* pq)
{
	DequeInit(&pq->deq);
}

int QIsEmpty(Queue* pq)
{
	return DQIsEmpty(&pq->deq);
}

void Enqueue(Queue* pq, Data data)
{
	DQAddLast(&pq->deq, data);
}

Data Dequeue(Queue* pq)
{
	return DQRemoveFirst(&pq->deq);
}

Data QPeek(Queue* pq)
{
	return DQGetFirst(&pq->deq);
}