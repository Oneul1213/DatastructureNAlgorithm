import Kruskal as k

graph = k.ALGraph(6)

graph.AddEdge(k.Vertex.A, k.Vertex.B, 9)
graph.AddEdge(k.Vertex.B, k.Vertex.C, 2)
graph.AddEdge(k.Vertex.A, k.Vertex.C, 12)
graph.AddEdge(k.Vertex.A, k.Vertex.D, 8)
graph.AddEdge(k.Vertex.D, k.Vertex.C, 6)
graph.AddEdge(k.Vertex.A, k.Vertex.F, 11)
graph.AddEdge(k.Vertex.F, k.Vertex.D, 4)
graph.AddEdge(k.Vertex.D, k.Vertex.E, 3)
graph.AddEdge(k.Vertex.E, k.Vertex.C, 7)
graph.AddEdge(k.Vertex.F, k.Vertex.E, 13)

graph.ConKruskalMST()
graph.ShowGraphEdgeInfo()
graph.ShowGraphEdgeWeightInfo()
