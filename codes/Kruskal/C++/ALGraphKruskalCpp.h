#pragma once

#include "ALEdgeCpp.h"
#include "SinglyLinkedListCpp.h"
#include "PriorityQueueCpp.h"

enum { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
private:
	int numV;
	int numE;
	SinglyLinkedList<int>** adjList;
	int* visitInfo;
	PriorityQueue<Edge>* pqueue;

	int VisitVertex(int visitV);
	void RecoverEdge(int fromV, int toV, int weight);
	void RemoveWayEdge(int fromV, int toV);
	int IsConnVertex(int v1, int v2);
	void RemoveEdge(int fromV, int toV);
public:
	ALGraph(int nv);
	void GraphDestroy();
	void AddEdge(int fromV, int toV, int weight);
	void ShowGraphEdgeInfo();
	void DFShowGraphVertex(int startV);
	void ConKruskalMST();
	void ShowGraphEdgeWeightInfo();
};