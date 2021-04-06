package Heap;

public interface HeapInterface<T> {
    int HEAP_LEN = 100;

    boolean HIsEmpty();
    void HInsert(T data);
    T HDelete();
}
