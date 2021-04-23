package ALGraph;

public class ALGraphMain {
    public static void main(String[] args) {
        ALGraph graph = new ALGraph(5);

        graph.AddEdge(Vertex.A, Vertex.B);
        graph.AddEdge(Vertex.A, Vertex.D);
        graph.AddEdge(Vertex.B, Vertex.C);
        graph.AddEdge(Vertex.D, Vertex.E);
        graph.AddEdge(Vertex.E, Vertex.A);

        graph.ShowGraphEdgeInfo();
    }
}
