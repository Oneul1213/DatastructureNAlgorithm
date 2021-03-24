#ifndef __C_LIST_BASE_STACK_H__
#define __C_LIST_BASE_STACK_H__

#include "CLinkedList.h"

typedef struct _cListStack
{
	List list;
} CListStack;

typedef CListStack Stack;

void StackInit(Stack* pstack);
int SIsEmpty(Stack* pstack);

void SPush(Stack* pstack, Data data);
Data SPop(Stack* pstack);
Data SPeek(Stack* pstack);

#endif