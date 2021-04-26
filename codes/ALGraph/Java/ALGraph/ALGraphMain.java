package ALGraph;

public class ALGraphMain {
    public static void main(String[] args) {
        ALGraph graph = new ALGraph(7);

        graph.AddEdge(Vertex.A, Vertex.B);
        graph.AddEdge(Vertex.A, Vertex.D);
        graph.AddEdge(Vertex.B, Vertex.C);
        graph.AddEdge(Vertex.D, Vertex.C);
        graph.AddEdge(Vertex.D, Vertex.E);
        graph.AddEdge(Vertex.E, Vertex.F);
        graph.AddEdge(Vertex.E, Vertex.G);

        graph.ShowGraphEdgeInfo(); System.out.println();

        System.out.println("DFS 결과");
        graph.DFShowGraphVertex(Vertex.A); System.out.println();
        graph.DFShowGraphVertex(Vertex.C); System.out.println();
        graph.DFShowGraphVertex(Vertex.E); System.out.println();
        graph.DFShowGraphVertex(Vertex.G); System.out.println();
        System.out.println();

        System.out.println("BFS 결과");
        graph.BFShowGraphVertex(Vertex.A); System.out.println();
        graph.BFShowGraphVertex(Vertex.C); System.out.println();
        graph.BFShowGraphVertex(Vertex.E); System.out.println();
        graph.BFShowGraphVertex(Vertex.G); System.out.println();
        System.out.println();
    }
}
