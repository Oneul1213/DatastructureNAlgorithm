#include <iostream>
#include "ALGraphCpp.h"

int main(void)
{
	ALGraph graph(7);

	graph.AddEdge(A, B);
	graph.AddEdge(A, D);
	graph.AddEdge(B, C);
	graph.AddEdge(D, C);
	graph.AddEdge(D, E);
	graph.AddEdge(E, F);
	graph.AddEdge(E, G);

	graph.ShowGraphEdgeInfo();

	graph.DFShowGraphVertex(A); std::cout << std::endl;
	graph.DFShowGraphVertex(C); std::cout << std::endl;
	graph.DFShowGraphVertex(E); std::cout << std::endl;
	graph.DFShowGraphVertex(G); std::cout << std::endl;

	graph.GraphDestroy();
	return 0;
}