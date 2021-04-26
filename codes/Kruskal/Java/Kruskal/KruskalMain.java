package Kruskal;

public class KruskalMain {
    public static void main(String[] args) {
        ALGraphKruskal graph = new ALGraphKruskal(6);

        graph.AddEdge(Vertex.A, Vertex.B, 9);
        graph.AddEdge(Vertex.B, Vertex.C, 2);
        graph.AddEdge(Vertex.A, Vertex.C, 12);
        graph.AddEdge(Vertex.A, Vertex.D, 8);
        graph.AddEdge(Vertex.D, Vertex.C, 6);
        graph.AddEdge(Vertex.A, Vertex.F, 11);
        graph.AddEdge(Vertex.F, Vertex.D, 4);
        graph.AddEdge(Vertex.D, Vertex.E, 3);
        graph.AddEdge(Vertex.E, Vertex.C, 7);
        graph.AddEdge(Vertex.F, Vertex.E, 13);

        graph.ConKruskalMST();
        graph.ShowGraphEdgeInfo();
        graph.ShowGraphEdgeWeightInfo();
    }
}
