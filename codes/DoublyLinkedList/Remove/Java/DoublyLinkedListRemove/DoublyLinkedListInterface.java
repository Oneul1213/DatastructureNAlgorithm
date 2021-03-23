package DoublyLinkedListRemove;

public interface DoublyLinkedListInterface<T> {
    void LInsert(T data);
    boolean LFirst(T[] data);
    boolean LNext(T[] data);
    boolean LPrevious(T[] data);

    T LRemove();
    int LCount();
}
