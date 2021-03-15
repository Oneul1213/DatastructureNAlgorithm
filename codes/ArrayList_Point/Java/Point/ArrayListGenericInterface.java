package Point;

public interface ArrayListGenericInterface<T> {
    int LIST_LEN = 100;

    void LInsert(T data);

    boolean LFirst(T[] data);
    boolean LNext(T[] data);

    T LRemove();
    int LCount();
}
