#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

void DequeInit(Deque* pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque* pdeq)
{
	if (pdeq->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void DQAddFirst(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (DQIsEmpty(pdeq))
	{
		pdeq->tail = newNode;
	}
	else
	{
		newNode->next = pdeq->head;
		pdeq->head->prev = newNode;
	}
	pdeq->head = newNode;
}

void DQAddLast(Deque* pdeq, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (pdeq->tail == NULL)
	{
		pdeq->head = newNode;
	}
	else
	{
		newNode->prev = pdeq->tail;
		pdeq->tail->next = newNode;
	}
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque* pdeq)
{
	Node* delNode = pdeq->head;
	Data retData = delNode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	if (pdeq->head == pdeq->tail)
	{
		pdeq->head = NULL;
		pdeq->tail = NULL;
	}
	else
	{
		pdeq->head = delNode->next;
		pdeq->head->prev = NULL;
	}

	free(delNode);
	return retData;
}

Data DQRemoveLast(Deque* pdeq)
{
	Node* delNode = pdeq->tail;
	Data retData = delNode->data;

	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	if (pdeq->head == pdeq->tail)
	{
		pdeq->head = NULL;
		pdeq->tail = NULL;
	}
	else
	{
		pdeq->tail = delNode->prev;
		pdeq->tail->next = NULL;
	}

	free(delNode);
	return retData;
}

Data DQGetFirst(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->head->data;
}

Data DQGetLast(Deque* pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return pdeq->tail->data;
}