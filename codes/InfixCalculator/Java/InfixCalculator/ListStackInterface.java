package InfixCalculator;

public interface ListStackInterface<T> {
    boolean SIsEmpty();

    void SPush(T data);
    T SPop();
    T SPeek();
}
