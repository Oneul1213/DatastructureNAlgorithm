#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ALGraphCpp.h"
#include "SinglyLinkedListCpp.h"
#include "SinglyLinkedListCpp.cpp"
#include "ArrayBaseStackCpp.h"
#include "ArrayBaseStackCpp.cpp"

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

int ALGraph::VisitVertex(int visitV)
{
	if (this->visitInfo[visitV] == 0)		// 방문한적 없던 정점이면
	{
		this->visitInfo[visitV] = 1;
		std::cout << char(visitV + 65) << " ";
		return true;						// 방문 성공
	}
	return false;							// 방문 실패
}

ALGraph::ALGraph(int nv) : numV(nv), numE(0)
{
	this->adjList = (SinglyLinkedList<int>**)malloc(sizeof(SinglyLinkedList<int>*) * nv);

	for (int i = 0; i < nv; i++)
	{
		this->adjList[i] = new SinglyLinkedList<int>();
		this->adjList[i]->SetSortRule(WhoIsPrecede);
	}

	this->visitInfo = (int*)malloc(sizeof(int) * this->numV);
	memset(this->visitInfo, 0, sizeof(int) * this->numV);
}

void ALGraph::GraphDestroy()
{
	if (*(this->adjList) != NULL)
		free(this->adjList);

	if (this->visitInfo != NULL)
		free(this->visitInfo);
}

void ALGraph::AddEdge(int fromV, int toV)
{
	this->adjList[fromV]->LInsert(toV);
	this->adjList[toV]->LInsert(fromV);

	this->numE += 1;
}

void ALGraph::ShowGraphEdgeInfo()
{
	int vx;

	for (int i = 0; i < this->numV; i++)
	{
		std::cout << char(i + 65) << "와 연결된 정점: ";

		if (this->adjList[i]->LFirst(vx))
		{
			std::cout << char(vx + 65) << " ";

			while (this->adjList[i]->LNext(vx))
				std::cout << char(vx + 65) << " ";
		}
		std::cout << std::endl;
	}
}

void ALGraph::DFShowGraphVertex(int startV)
{
	ArrayStack<int> stack;
	int visitV = startV;
	int nextV;

	this->VisitVertex(visitV);
	stack.SPush(visitV);

	while (this->adjList[visitV]->LFirst(nextV) == true)
	{
		int visitFlag = false;

		if (this->VisitVertex(nextV) == true)
		{
			stack.SPush(visitV);
			visitV = nextV;
			visitFlag = true;
		}
		else
		{
			while (this->adjList[visitV]->LNext(nextV) == true)
			{
				if (this->VisitVertex(nextV) == true)
				{
					stack.SPush(visitV);
					visitV = nextV;
					visitFlag = true;
					break;
				}
			}
		}

		if (visitFlag == false)
		{
			if (stack.SIsEmpty() == true)		// 처음 정점으로 돌아왔다면
				break;
			else
				visitV = stack.SPop();			// 돌아갈 정점
		}
	}

	memset(this->visitInfo, 0, sizeof(int) * this->numV);
}