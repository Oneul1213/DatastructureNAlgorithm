package PriorityQueue;

public class PriorityQueue<T> {
    private Heap<T> heap;

    public PriorityQueue(PriorityComp<T> pc) {
        this.heap = new Heap<T>(pc);
    }

    public boolean PQIsEmpty() {
        return this.heap.HIsEmpty();
    }

    public void PEnqueue(T data) {
        this.heap.HInsert(data);
    }

    public T PDequeue() {
        return this.heap.HDelete();
    }
}
