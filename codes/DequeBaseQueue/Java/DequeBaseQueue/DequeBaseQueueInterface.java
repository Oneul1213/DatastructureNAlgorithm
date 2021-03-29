package DequeBaseQueue;

public interface DequeBaseQueueInterface<T> {
    boolean QIsEmpty();

    void Enqueue(T data);
    T Dequeue();
    T QPeek();
}
