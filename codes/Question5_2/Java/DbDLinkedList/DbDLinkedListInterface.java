package DbDLinkedList;

public interface DbDLinkedListInterface<T> {
    void LInsert(T data);

    boolean LFirst(T[] data);
    boolean LNext(T[] data);

    T LRemove();
    int LCount();
}
