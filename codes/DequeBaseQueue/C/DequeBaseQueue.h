#ifndef __DB_Q_H__
#define __DB_Q_H__

#include "Deque.h"

typedef int Data;

typedef struct _dbQueue
{
	Deque deq;
} DBQueue;

typedef DBQueue Queue;

void QueueInit(Queue* pq);
int QIsEmpty(Queue* pq);

void Enqueue(Queue* pq, Data data);
Data Dequeue(Queue* pq);
Data QPeek(Queue* pq);

#endif