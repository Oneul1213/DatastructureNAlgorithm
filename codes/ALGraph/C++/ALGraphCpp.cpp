#include <iostream>
#include <cstdlib>
#include "ALGraphCpp.h"
#include "SinglyLinkedListCpp.h"
#include "SinglyLinkedListCpp.cpp"

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

ALGraph::ALGraph(int nv) : numV(nv), numE(0)
{
	this->adjList = (SinglyLinkedList<int>**)malloc(sizeof(SinglyLinkedList<int>*) * nv);

	for (int i = 0; i < nv; i++)
	{
		this->adjList[i] = new SinglyLinkedList<int>();
		this->adjList[i]->SetSortRule(WhoIsPrecede);
	}
}

void ALGraph::GraphDestroy()
{
	if (*(this->adjList) != NULL)
		free(this->adjList);
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