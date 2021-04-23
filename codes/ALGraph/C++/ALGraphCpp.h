#pragma once

#include "SinglyLinkedListCpp.h"

enum { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
private:
	int numV;
	int numE;
	SinglyLinkedList<int>** adjList;
	int* visitInfo;

	int VisitVertex(int visitV);
public:
	ALGraph(int nv);
	void GraphDestroy();
	void AddEdge(int fromV, int toV);
	void ShowGraphEdgeInfo();
	void DFShowGraphVertex(int startV);
};