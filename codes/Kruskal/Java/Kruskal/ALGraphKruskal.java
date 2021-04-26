package Kruskal;

public class ALGraphKruskal {
    private int numV;
    private int numE;
    private SinglyLinkedList<Vertex>[] adjList;
    private int[] visitInfo;
    private PriorityQueue<Edge> pqueue;

    private boolean VisitVertex(Vertex visitV) {
        if (this.visitInfo[visitV.getValue()] == 0) {               // 방문한적 없던 정점이면
            this.visitInfo[visitV.getValue()] = 1;
            //System.out.print((char)(visitV.getValue() + 65)+" ");
            return true;                                            // 방문 성공
        }
        return false;                                               // 방문 실패
    }

    private void RecoverEdge(Vertex fromV, Vertex toV, int weight) {
        this.adjList[fromV.getValue()].LInsert(toV);
        this.adjList[toV.getValue()].LInsert(fromV);

        this.numE += 1;
    }

    private void RemoveWayEdge(Vertex fromV, Vertex toV) {
        Vertex[] edge = new Vertex[1];

        if (this.adjList[fromV.getValue()].LFirst(edge)) {
            if (edge[0] == toV) {
               this.adjList[fromV.getValue()].LRemove();
               return;
            }

            while (this.adjList[fromV.getValue()].LNext(edge)) {
                if(edge[0] == toV) {
                    this.adjList[fromV.getValue()].LRemove();
                    return;
                }
            }
        }
    }

    private boolean IsConnVertex(Vertex v1, Vertex v2) {
        ArrayStack<Vertex> stack = new ArrayStack<Vertex>();
        Vertex visitV = v1;
        Vertex[] nextV = new Vertex[1];

        this.VisitVertex(visitV);
        stack.SPush(visitV);

        while (this.adjList[visitV.getValue()].LFirst(nextV)) {
            boolean visitFlag = false;

            // 연결된 정점을 찾았다면
            if (nextV[0] == v2) {
                // 초기화 후 반환
                this.visitInfo = new int[this.numV];
                return true;
            }

            if (this.VisitVertex(nextV[0])) {
                stack.SPush(visitV);
                visitV = nextV[0];
                visitFlag = true;
            } else {
                while (this.adjList[visitV.getValue()].LNext(nextV)) {
                    // 연결된 정점을 찾았다면
                    if (nextV[0] == v2) {
                        // 초기화 후 반환
                        this.visitInfo = new int[this.numV];
                        return true;
                    }

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
        return false;                       // 연결된 정점을 못찾았음
    }

    private void RemoveEdge(Vertex fromV, Vertex toV) {
        this.RemoveWayEdge(fromV, toV);
        this.RemoveWayEdge(toV, fromV);
        (this.numE)--;
    }

    public ALGraphKruskal(int nv) {
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

        this.pqueue = new PriorityQueue<Edge>((Edge d1, Edge d2)->d1.getWeight() - d2.getWeight());
    }

    public void AddEdge(Vertex fromV, Vertex toV, int weight) {
        Edge edge = new Edge(fromV, toV, weight);

        this.adjList[fromV.getValue()].LInsert(toV);
        this.adjList[toV.getValue()].LInsert(fromV);

        this.numE += 1;

        this.pqueue.PEnqueue(edge);
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

    public void ConKruskalMST() {
        Edge[] recvEdge = new Edge[20];
        Edge edge;
        int eidx = 0;

        // MST가 될 때까지 반복
        while (this.numE + 1 > this.numV) {
            edge = this.pqueue.PDequeue();
            this.RemoveEdge(edge.getV1(), edge.getV2());

            if (!(this.IsConnVertex(edge.getV1(), edge.getV2()))) {
                this.RecoverEdge(edge.getV1(), edge.getV2(), edge.getWeight());
                recvEdge[eidx++] = edge;
            }
        }

        for (int i = 0; i < eidx; i++)
            this.pqueue.PEnqueue(recvEdge[i]);
    }

    public void ShowGraphEdgeWeightInfo() {
        PriorityQueue<Edge> copyPQ = this.pqueue;
        Edge edge;

        while (!(copyPQ.PQIsEmpty())) {
            edge = copyPQ.PDequeue();
            System.out.println("("+(char)(edge.getV1().getValue()+65)+"-"+(char)(edge.getV2().getValue()+65)+") w: "+edge.getWeight());
        }

    }
}
