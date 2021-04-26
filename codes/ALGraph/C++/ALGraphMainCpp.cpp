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

	graph.ShowGraphEdgeInfo(); std::cout << std::endl;

	std::cout << "DFS 결과" << std::endl;
	graph.DFShowGraphVertex(A); std::cout << std::endl;
	graph.DFShowGraphVertex(C); std::cout << std::endl;
	graph.DFShowGraphVertex(E); std::cout << std::endl;
	graph.DFShowGraphVertex(G); std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "BFS 결과" << std::endl;
	graph.BFShowGraphVertex(A); std::cout << std::endl;
	graph.BFShowGraphVertex(C); std::cout << std::endl;
	graph.BFShowGraphVertex(E); std::cout << std::endl;
	graph.BFShowGraphVertex(G); std::cout << std::endl;
	std::cout << std::endl;

	graph.GraphDestroy();
	return 0;
}