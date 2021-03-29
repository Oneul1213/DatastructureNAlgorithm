package ListBaseQueue;

public interface ListQueueInterface<T> {
    boolean QIsEmpty();

    void Enqueue(T data);
    T Dequeue();
    T QPeek();
}
