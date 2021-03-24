package CListBaseStack;

public class CListStack<T> implements CListStackInterface<T> {
    private CircularLinkedList<T> list;

    public CListStack() {
        this.list = new CircularLinkedList<>();
    }

    @Override
    public boolean SIsEmpty() {
        if (this.list.LCount() == 0)
            return true;
        else
            return false;
    }

    @Override
    public void SPush(T data) {
        this.list.LInsertFront(data);
    }

    @Override
    @SuppressWarnings("unchecked")
    public T SPop() {
        T[] data = (T[])new Object[1];

        if (this.SIsEmpty()) {
            System.out.println("Stack Memory Error!");
            System.exit(-1);
        }

        this.list.LFirst(data);
        return this.list.LRemove();
    }

    @Override
    public T SPeek() {
        T[] data = (T[])new Object[1];

        if (this.SIsEmpty()) {
            System.out.println("Stack Memory Error!");
            System.exit(-1);
        }

        this.list.LFirst(data);
        return data[0];
    }
}
