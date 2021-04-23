import ALGraph as ag

graph = ag.ALGraph(7)

graph.AddEdge(ag.Vertex.A, ag.Vertex.B)
graph.AddEdge(ag.Vertex.A, ag.Vertex.D)
graph.AddEdge(ag.Vertex.B, ag.Vertex.C)
graph.AddEdge(ag.Vertex.D, ag.Vertex.C)
graph.AddEdge(ag.Vertex.D, ag.Vertex.E)
graph.AddEdge(ag.Vertex.E, ag.Vertex.F)
graph.AddEdge(ag.Vertex.E, ag.Vertex.G)

graph.ShowGraphEdgeInfo()

graph.DFShowGraphVertex(ag.Vertex.A)
print()
graph.DFShowGraphVertex(ag.Vertex.C)
print()
graph.DFShowGraphVertex(ag.Vertex.E)
print()
graph.DFShowGraphVertex(ag.Vertex.G)
print()
