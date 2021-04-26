#include <stdio.h>
#include "ALGraph.h"

int main(void)
{
	ALGraph graph;
	GraphInit(&graph, 7);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, D);
	AddEdge(&graph, B, C);
	AddEdge(&graph, D, C);
	AddEdge(&graph, D, E);
	AddEdge(&graph, E, F);
	AddEdge(&graph, E, G);

	ShowGraphEdgeInfo(&graph); printf("\n");

	printf("DFS 결과\n");
	DFShowGraphVertex(&graph, A); printf("\n");
	DFShowGraphVertex(&graph, C); printf("\n");
	DFShowGraphVertex(&graph, E); printf("\n");
	DFShowGraphVertex(&graph, G); printf("\n");
	printf("\n");

	printf("BFS 결과\n");
	BFShowGraphVertex(&graph, A); printf("\n");
	BFShowGraphVertex(&graph, C); printf("\n");
	BFShowGraphVertex(&graph, E); printf("\n");
	BFShowGraphVertex(&graph, G); printf("\n");
	printf("\n");

	GraphDestroy(&graph);
	return 0;
}