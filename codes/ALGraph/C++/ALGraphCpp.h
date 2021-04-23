#pragma once

#include "SinglyLinkedListCpp.h"

enum { A, B, C, D, E, F, G, H, I, J };

class ALGraph
{
private:
	int numV;
	int numE;
	SinglyLinkedList<int>** adjList;
public:
	ALGraph(int nv);
	void GraphDestroy();
	void AddEdge(int fromV, int toV);
	void ShowGraphEdgeInfo();
};