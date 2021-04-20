#ifndef __CHAINING_TABLE_H__
#define __CHAINING_TABLE_H__

#include "ChainingSlot.h"
#include "SinglyLinkedList.h"

#define MAX_TBL 100

typedef int HashFunc(Key k);

typedef struct _table
{
	List tbl[MAX_TBL];
	HashFunc* hf;
} Table;

void TBLInit(Table* pt, HashFunc* f);

void TBLInsert(Table* pt, Key k, Value v);

Value TBLDelete(Table* pt, Key k);

Value TBLSearch(Table* pt, Key k);

#endif