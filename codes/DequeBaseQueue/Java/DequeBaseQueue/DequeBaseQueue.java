package DequeBaseQueue;

public class DequeBaseQueue<T> implements DequeBaseQueueInterface<T> {
    private Deque<T> deq;

    public DequeBaseQueue() {
        this.deq = new Deque<T>();
    }
    @Override
    public boolean QIsEmpty() {
        return this.deq.DQIsEmpty();
    }

    @Override
    public void Enqueue(T data) {
        this.deq.DQAddLast(data);
    }

    @Override
    public T Dequeue() {
        return this.deq.DQRemoveFirst();
    }

    @Override
    public T QPeek() {
        return this.deq.DQGetFirst();
    }
}
