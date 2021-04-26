package Kruskal;

public class ArrayStack<T> implements ArrayStackInterface<T> {
    private T[] stackArr;
    private int topIndex;

    @SuppressWarnings("unchecked")
    public ArrayStack() {
        this.stackArr = (T[])new Object[STACK_LEN];
        this.topIndex = -1;
    }

    @Override
    public boolean SIsEmpty() {
        if (this.topIndex == -1)
            return true;
        else
            return false;
    }

    @Override
    public void SPush(T data) {
        this.topIndex += 1;
        this.stackArr[this.topIndex] = data;
    }

    @Override
    public T SPop() {
        int rIdx;

        if (this.SIsEmpty()) {
            System.out.println("Stack Memory Error!");
            System.exit(-1);
        }

        rIdx = this.topIndex;
        this.topIndex -= 1;

        return this.stackArr[rIdx];
    }

    @Override
    public T SPeek() {
        if (this.SIsEmpty()) {
            System.out.println("Stack Memory Error!");
            System.exit(-1);
        }

        return this.stackArr[this.topIndex];
    }
}
