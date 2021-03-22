package Question5_1;

public interface CircularLinkedListInterface<T> {
    void LInsert(T data);
    void LInsertFront(T data);

    boolean LFirst(T[] data);
    boolean LNext(T[] data);

    T LRemove();
    int LCount();
}
