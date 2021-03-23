#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List* plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}

void LInsert(List* plist, Data data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;

	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List* plist, Data* pdata)
{
	if (plist->head == NULL)
		return FALSE;

	plist->cur = plist->head;
	plist->before = plist->cur->prev;
	plist->after = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List* plist, Data* pdata)
{
	if (plist->after == NULL)
		return FALSE;

	if (plist->cur == NULL)
		plist->cur = plist->before;

	plist->cur = plist->cur->next;
	plist->before = plist->cur->prev;
	plist->after = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LPrevious(List* plist, Data* pdata)
{
	if (plist->before == NULL)
		return FALSE;

	if (plist->cur == NULL)
		plist->cur = plist->after;

	plist->cur = plist->cur->prev;
	plist->before = plist->cur->prev;
	plist->after = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List* plist)
{
	Node* rpos = plist->cur;
	Data rdata = rpos->data;

	if (plist->cur == plist->head && plist->after == NULL)	// 마지막 노드인 head를 삭제
	{
		plist->head = NULL;
	}
	else if (plist->cur == plist->head)							// 마지막 노드가 아닌 head를 삭제
	{
		plist->after->prev = NULL;
		plist->head = plist->after;
		plist->before = plist->head;
	}
	else if (plist->after == NULL)							// 마지막 노드를 삭제
	{
		plist->before->next = NULL;
		plist->after = plist->before;
	}
	else
	{
		plist->before->next = plist->after;
		plist->after->prev = plist->before;
	}

	plist->cur = NULL;
	(plist->numOfData)--;
	return rdata;
}

int LCount(List* plist)
{
	return plist->numOfData;
}