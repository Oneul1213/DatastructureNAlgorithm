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
		printf("%c�� ����� ����: ", i + 65);

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
	if (pg->visitInfo[visitV] == 0)		// �湮���� ���� �����̸�
	{
		pg->visitInfo[visitV] = 1;
		printf("%c ", visitV + 65);
		return TRUE;					// �湮 ����
	}
	return FALSE;						// �湮 ����
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
			if (SIsEmpty(&stack) == TRUE)		// ó�� �������� ���ƿԴٸ�
				break;
			else
				visitV = SPop(&stack);			// ���ư� ����
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

		if (QIsEmpty(&queue) == TRUE)	// ��� ������ �� �湮�ߴٸ�
			break;
		else
			visitV = Dequeue(&queue);	// ����� �ٸ� �������� �ٽ� ����
	}

	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}