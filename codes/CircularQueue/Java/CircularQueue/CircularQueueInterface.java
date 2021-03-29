package CircularQueue;

public interface CircularQueueInterface<T> {
    int QUE_LEN = 100;

    boolean QIsEmpty();

    void Enqueue(T data);
    T Dequeue();
    T QPeek();
}
