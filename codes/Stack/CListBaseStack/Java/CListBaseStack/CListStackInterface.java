package CListBaseStack;

public interface CListStackInterface<T> {
    boolean SIsEmpty();

    void SPush(T data);
    T SPop();
    T SPeek();
}
