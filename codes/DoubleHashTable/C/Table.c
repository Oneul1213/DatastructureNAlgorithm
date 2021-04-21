#include <stdio.h>
#include <stdlib.h>
#include "Table.h"

void TBLInit(Table* pt, HashFunc* f1, HashFunc* f2)
{
	int i;

	for (i = 0; i < MAX_TBL; i++)
		(pt->tbl[i]).status = EMPTY;

	pt->hf1 = f1;
	pt->hf2 = f2;
}

void TBLInsert(Table* pt, Key k, Value v)
{
	int hv = pt->hf1(k);

	// 키가 중복되었다면
	if (TBLSearch(pt, k) != NULL)
	{
		printf("키 중복 오류 발생 \n");
		return;
	}

	// 충돌 발생 시 빈 자리를 찾을 때까지 반복
	while (pt->tbl[hv].status == INUSE || pt->tbl[hv].status == DELETED)
		hv = hv + pt->hf2(k);

	pt->tbl[hv].val = v;
	pt->tbl[hv].key = k;
	pt->tbl[hv].status = INUSE;
}

Value TBLDelete(Table* pt, Key k)
{
	int hv = pt->hf1(k);

	// 충돌 발생 시 빈 자리를 찾을 때까지 반복
	while (pt->tbl[hv].status == DELETED)
		hv = hv + pt->hf2(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
	{
		(pt->tbl[hv]).status = DELETED;
		return (pt->tbl[hv]).val;
	}
}

Value TBLSearch(Table* pt, Key k)
{
	int hv = pt->hf1(k);

	// 충돌 발생 시 빈 자리를 찾을 때까지 반복
	while (pt->tbl[hv].status == DELETED)
		hv = hv + pt->hf2(k);

	if ((pt->tbl[hv]).status != INUSE)
		return NULL;
	else
		return (pt->tbl[hv]).val;
}