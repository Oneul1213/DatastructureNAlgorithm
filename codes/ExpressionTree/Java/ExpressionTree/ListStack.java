package ExpressionTree;

import ListBaseStack.ListStackInterface;
import ListBaseStack.Node;

public class ListStack<T> implements ListStackInterface<T> {
    private Node<T> head;

    public ListStack() {
        this.head = null;
    }

    @Override
    public boolean SIsEmpty() {
        if (this.head == null)
            return true;
        else
            return false;
    }

    @Override
    public void SPush(T data) {
        Node<T> newNode = new Node<>();

        newNode.setData(data);
        newNode.setNext(this.head);

        this.head = newNode;
    }

    @Override
    public T SPop() {
        T rdata;

        if (this.SIsEmpty()) {
            System.out.println("Stack Memory Error!");
            System.exit(-1);
        }

        rdata = this.head.getData();

        this.head = this.head.getNext();

        return rdata;
    }

    @Override
    public T SPeek() {
        if (this.SIsEmpty()) {
            System.out.println("Stack Memory Error!");
            System.exit(-1);
        }

        return this.head.getData();
    }
}
