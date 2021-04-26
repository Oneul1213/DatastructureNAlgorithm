#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ALGraph.h"
#include "SinglyLinkedList.h"
#include "ArrayBaseStack.h"
#include "CircularQueue.h"

int WhoIsPrecede(int data1, int data2);

void GraphInit(ALGraph* pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List) * nv);
	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}

	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void GraphDestroy(ALGraph* pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);

	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}

void AddEdge(ALGraph* pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph* pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

int VisitVertex(ALGraph* pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)		// 방문한적 없던 정점이면
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;					// 방문 성공
	}
	return FALSE;						// 방문 실패
}

void DFShowGraphVertex(ALGraph* pg, int startV)
{
	Stack stack;
	int visitV = startV;
	int nextV;

	StackInit(&stack);
	VisitVertex(pg, visitV);
	SPush(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)
		{
			SPush(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					SPush(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (SIsEmpty(&stack) == TRUE)		// 처음 정점으로 돌아왔다면
				break;
			else
				visitV = SPop(&stack);			// 돌아갈 정점
		}
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}

void BFShowGraphVertex(ALGraph* pg, int startV)
{
	Queue queue;
	int visitV = startV;
	int nextV;

	QueueInit(&queue);

	VisitVertex(pg, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		if (VisitVertex(pg, nextV) == TRUE)
			Enqueue(&queue, nextV);

		while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
		{
			if (VisitVertex(pg, nextV) == TRUE)
				Enqueue(&queue, nextV);
		}

		if (QIsEmpty(&queue) == TRUE)	// 모든 정점을 다 방문했다면
			break;
		else
			visitV = Dequeue(&queue);	// 연결된 다른 정점에서 다시 시작
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}