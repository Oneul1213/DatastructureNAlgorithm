package Kruskal;

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

public class Edge {
    private Vertex v1;
    private Vertex v2;
    private int weight;

    public Edge(Vertex _v1, Vertex _v2, int _weight) {
        this.v1 = _v1;
        this.v2 = _v2;
        this.weight = _weight;
    }

    public Vertex getV1() {
        return v1;
    }

    public void setV1(Vertex v1) {
        this.v1 = v1;
    }

    public Vertex getV2() {
        return v2;
    }

    public void setV2(Vertex v2) {
        this.v2 = v2;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }
}
