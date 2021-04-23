package ALGraph;

enum Vertex {
    A(0), B(1), C(2), D(3), E(4), F(5), G(6), H(7), I(8), J(9);

    private int value;

    Vertex(int value) {
        this.value = value;
    }

    public int getValue() {
        return this.value;
    }
}

public class ALGraph {
    private int numV;
    private int numE;
    private SinglyLinkedList<Vertex>[] adjList;

    public ALGraph(int nv) {
        this.numV = nv;
        this.numE = 0;
        this.adjList = new SinglyLinkedList[nv];

        for (int i = 0; i < nv; i++) {
            this.adjList[i] = new SinglyLinkedList<Vertex>();
            this.adjList[i].SetSortRule((d1, d2) -> {
                if (d1.compareTo(d2) < 0)
                    return 0;
                else
                    return 1;
            });
        }

    }

    public void AddEdge(Vertex fromV, Vertex toV) {
        this.adjList[fromV.getValue()].LInsert(toV);
        this.adjList[toV.getValue()].LInsert(fromV);

        this.numE += 1;
    }

    public void ShowGraphEdgeInfo() {
        Vertex vx[] = new Vertex[1];

        for (int i = 0; i < this.numV; i++) {
            System.out.print((char)(i+65)+"와 연결된 정점: ");
            
            if (this.adjList[i].LFirst(vx)) {
                System.out.print((char)(vx[0].getValue() + 65)+" ");

                while (this.adjList[i].LNext(vx))
                    System.out.print((char)(vx[0].getValue() + 65)+" ");
            }
            System.out.println();
        }
    }
}
