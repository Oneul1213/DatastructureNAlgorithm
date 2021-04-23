package ALGraph;

public interface SinglyLinkedListInterface<T> {
    void LInsert(T data);

    boolean LFirst(T[] data);
    boolean LNext(T[] data);

    T LRemove();
    int LCount();

    void SetSortRule(WhoIsPrecede<T> comp);
}
