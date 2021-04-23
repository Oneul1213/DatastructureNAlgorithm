package ALGraph;

public interface ArrayStackInterface<T> {
    int STACK_LEN = 1000;

    boolean SIsEmpty();
    void SPush(T data);
    T SPop();
    T SPeek();
}
