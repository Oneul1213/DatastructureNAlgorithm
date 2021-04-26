#include <iostream>
#include <cstdlib>
#include <cstring>
#include "ALGraphKruskalCpp.h"
#include "SinglyLinkedListCpp.h"
#include "SinglyLinkedListCpp.cpp"
#include "ArrayBaseStackCpp.h"
#include "ArrayBaseStackCpp.cpp"
#include "PriorityQueueCpp.h"
#include "PriorityQueueCpp.cpp"

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}

int PQWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}

int ALGraph::VisitVertex(int visitV)
{
	if (this->visitInfo[visitV] == 0)		// 방문한적 없던 정점이면
	{
		this->visitInfo[visitV] = 1;
		//std::cout << char(visitV + 65) << " ";
		return true;						// 방문 성공
	}
	return false;							// 방문 실패
}

void ALGraph::RecoverEdge(int fromV, int toV, int weight)
{
	this->adjList[fromV]->LInsert(toV);
	this->adjList[toV]->LInsert(fromV);

	this->numE += 1;
}

void ALGraph::RemoveWayEdge(int fromV, int toV)
{
	int edge;

	if (this->adjList[fromV]->LFirst(edge))
	{
		if (edge == toV)
		{
			this->adjList[fromV]->LRemove();
			return;
		}

		while (this->adjList[fromV]->LNext(edge))
		{
			if (edge == toV)
			{
				this->adjList[fromV]->LRemove();
				return;
			}
		}
	}
}

int ALGraph::IsConnVertex(int v1, int v2)
{
	ArrayStack<int> stack;
	int visitV = v1;
	int nextV;

	this->VisitVertex(visitV);
	stack.SPush(visitV);

	while (this->adjList[visitV]->LFirst(nextV) == true)
	{
		int visitFlag = false;

		// 연결된 정점을 찾았다면
		if (nextV == v2)
		{
			// 초기화 후 반환
			memset(this->visitInfo, 0, sizeof(int) * this->numV);
			return true;
		}

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
				// 연결된 정점을 찾았다면
				if (nextV == v2)
				{
					// 초기화 후 반환
					memset(this->visitInfo, 0, sizeof(int) * this->numV);
					return true;
				}

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
	return false;								// 연결된 정점을 못찾았음
}

void ALGraph::RemoveEdge(int fromV, int toV)
{
	this->RemoveWayEdge(fromV, toV);
	this->RemoveWayEdge(toV, fromV);
	(this->numE)--;
}

ALGraph::ALGraph(int nv) : numV(nv), numE(0)
{
	this->adjList = (SinglyLinkedList<int> * *)malloc(sizeof(SinglyLinkedList<int>*) * nv);

	for (int i = 0; i < nv; i++)
	{
		this->adjList[i] = new SinglyLinkedList<int>();
		this->adjList[i]->SetSortRule(WhoIsPrecede);
	}

	this->visitInfo = (int*)malloc(sizeof(int) * this->numV);
	memset(this->visitInfo, 0, sizeof(int) * this->numV);

	this->pqueue = new PriorityQueue<Edge>(PQWeightComp);
}

void ALGraph::GraphDestroy()
{
	if (*(this->adjList) != NULL)
		free(this->adjList);

	if (this->visitInfo != NULL)
		free(this->visitInfo);
}

void ALGraph::AddEdge(int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };

	this->adjList[fromV]->LInsert(toV);
	this->adjList[toV]->LInsert(fromV);

	this->numE += 1;

	this->pqueue->PEnqueue(edge);
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

void ALGraph::ConKruskalMST()
{
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;

	// MST가 될 때까지 반복
	while (this->numE + 1 > this->numV)
	{
		edge = this->pqueue->PDequeue();
		this->RemoveEdge(edge.v1, edge.v2);

		if (!(this->IsConnVertex(edge.v1, edge.v2)))				// 다른 경로가 없는 정점이면
		{
			this->RecoverEdge(edge.v1, edge.v2, edge.weight);		// 복원
			recvEdge[eidx++] = edge;
		}
	}

	for (int i = 0; i < eidx; i++)
		this->pqueue->PEnqueue(recvEdge[i]);					// 완성된 MST의 간선 정보 복구
}

void ALGraph::ShowGraphEdgeWeightInfo()
{
	PriorityQueue<Edge>* copyPQ = this->pqueue;
	Edge edge;

	while (!(copyPQ->PQIsEmpty()))
	{
		edge = copyPQ->PDequeue();
		std::cout << "(" << char(edge.v1 + 65) << "-" << char(edge.v2 + 65) << ")" << " w: " << edge.weight << std::endl;
	}
}