package Deque;

public interface DequeInterface<T> {
    boolean DQIsEmpty();

    void DQAddFirst(T data);
    void DQAddLast(T data);

    T DQRemoveFirst();
    T DQRemoveLast();

    T DQGetFirst();
    T DQGetLast();
}
