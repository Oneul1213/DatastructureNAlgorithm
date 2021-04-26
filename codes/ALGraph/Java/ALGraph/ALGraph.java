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
    private int[] visitInfo;

    private boolean VisitVertex(Vertex visitV) {
        if (this.visitInfo[visitV.getValue()] == 0) {               // 방문한적 없던 정점이면
            this.visitInfo[visitV.getValue()] = 1;
            System.out.print((char)(visitV.getValue() + 65)+" ");
            return true;                                            // 방문 성공
        }
        return false;                                               // 방문 실패
    }

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

        this.visitInfo = new int[this.numV];
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

    public void DFShowGraphVertex(Vertex startV) {
        ArrayStack<Vertex> stack = new ArrayStack<Vertex>();
        Vertex visitV = startV;
        Vertex[] nextV = new Vertex[1];

        this.VisitVertex(visitV);
        stack.SPush(visitV);

        while (this.adjList[visitV.getValue()].LFirst(nextV)) {
            boolean visitFlag = false;

            if (this.VisitVertex(nextV[0])) {
                stack.SPush(visitV);
                visitV = nextV[0];
                visitFlag = true;
            } else {
                while (this.adjList[visitV.getValue()].LNext(nextV)) {
                    if (this.VisitVertex(nextV[0])) {
                        stack.SPush(visitV);
                        visitV = nextV[0];
                        visitFlag = true;
                        break;
                    }
                }
            }

            if (!visitFlag) {
                if (stack.SIsEmpty())       // 처음 정점으로 돌아왔다면
                    break;
                else
                    visitV = stack.SPop();  // 돌아갈 정점
            }
        }

        this.visitInfo = new int[this.numV];
    }

    public void BFShowGraphVertex(Vertex startV) {
        CircularQueue<Vertex> queue = new CircularQueue<Vertex>();
        Vertex visitV = startV;
        Vertex[] nextV = new Vertex[1];

        this.VisitVertex(visitV);

        while (this.adjList[visitV.getValue()].LFirst(nextV)) {
            if (this.VisitVertex(nextV[0]))
                queue.Enqueue(nextV[0]);

            while (this.adjList[visitV.getValue()].LNext(nextV)) {
                if (this.VisitVertex(nextV[0]))
                    queue.Enqueue(nextV[0]);
            }

            if (queue.QIsEmpty())
                break;
            else
                visitV = queue.Dequeue();
        }

        this.visitInfo = new int[this.numV];
    }
}
