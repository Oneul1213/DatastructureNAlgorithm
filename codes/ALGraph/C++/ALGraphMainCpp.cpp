#include <iostream>
#include "ALGraphCpp.h"

int main(void)
{
	ALGraph graph(5);

	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(C, D);
	graph.AddEdge(D, E);
	graph.AddEdge(E, A);

	graph.ShowGraphEdgeInfo();
	return 0;
}