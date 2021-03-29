package DequeBaseQueue;

public class Deque<T> implements DequeInterface<T> {
    private Node<T> head;
    private Node<T> tail;

    public Deque() {
        this.head = null;
        this.tail = null;
    }

    @Override
    public boolean DQIsEmpty() {
        if (this.head == null)
            return true;
        else
            return false;
    }

    @Override
    public void DQAddFirst(T data) {
        Node<T> newNode = new Node<T>();
        newNode.setData(data);
        newNode.setNext(null);
        newNode.setPrev(null);

        if (this.DQIsEmpty())
            this.tail = newNode;
        else {
            newNode.setNext(this.head);
            this.head.setPrev(newNode);
        }
        this.head = newNode;
    }

    @Override
    public void DQAddLast(T data) {
        Node<T> newNode = new Node<T>();
        newNode.setData(data);
        newNode.setNext(null);
        newNode.setPrev(null);

        if (this.tail == null)
            this.head = newNode;
        else {
            newNode.setPrev(this.tail);
            this.tail.setNext(newNode);
        }
        this.tail = newNode;
    }

    @Override
    public T DQRemoveFirst() {
        Node<T> delNode = this.head;
        T retData = delNode.getData();

        if (this.DQIsEmpty()) {
            System.out.println("Deque Memory Error!");
            System.exit(-1);
        }

        if (this.head == this.tail) {
            this.head = null;
            this.tail = null;
        } else {
            this.head = delNode.getNext();
            this.head.setPrev(null);
        }

        return retData;
    }

    @Override
    public T DQRemoveLast() {
        Node<T> delNode = this.tail;
        T retData = delNode.getData();

        if (this.DQIsEmpty()) {
            System.out.println("Deque Memory Error!");
            System.exit(-1);
        }

        if (this.head == this.tail) {
            this.head = null;
            this.tail = null;
        } else {
            this.tail = delNode.getPrev();
            this.tail.setNext(null);
        }

        return retData;
    }

    @Override
    public T DQGetFirst() {
        if (this.DQIsEmpty()) {
            System.out.println("Deque Memory Error!");
            System.exit(-1);
        }

        return this.head.getData();
    }

    @Override
    public T DQGetLast() {
        if (this.DQIsEmpty()) {
            System.out.println("Deque Memory Error!");
            System.exit(-1);
        }

        return this.tail.getData();
    }
}
