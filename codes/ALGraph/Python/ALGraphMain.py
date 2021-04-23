import ALGraph as ag

graph = ag.ALGraph(5)

graph.AddEdge(ag.Vertex.A, ag.Vertex.B)
graph.AddEdge(ag.Vertex.A, ag.Vertex.D)
graph.AddEdge(ag.Vertex.B, ag.Vertex.C)
graph.AddEdge(ag.Vertex.D, ag.Vertex.E)
graph.AddEdge(ag.Vertex.E, ag.Vertex.A)

graph.ShowGraphEdgeInfo()
