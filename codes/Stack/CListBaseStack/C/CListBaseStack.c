#include <stdio.h>
#include <stdlib.h>
#include "CListBaseStack.h"

void StackInit(Stack* pstack)
{
	ListInit(&(pstack->list));
}

int SIsEmpty(Stack* pstack)
{
	if (pstack->list.tail == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack* pstack, Data data)
{
	LInsertFront(&(pstack->list), data);
}

Data SPop(Stack* pstack)
{
	Data data;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	LFirst(&(pstack->list), &data);
	return LRemove(&(pstack->list));
}

Data SPeek(Stack* pstack)
{
	Data data;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	LFirst(&(pstack->list), &data);
	return data;
}