package Question5_1;

public class CircularLinkedList<T> implements CircularLinkedListInterface<T> {
    private Node<T> tail;
    private Node<T> cur;
    private Node<T> before;
    private int numOfData;

    public CircularLinkedList() {
        this.tail = null;
        this.cur = null;
        this.before = null;
        this.numOfData = 0;
    }

    public void LInsert(T data) {
        Node<T> newNode = new Node<T>();
        newNode.data = data;

        if (this.tail == null) {
            this.tail = newNode;
            newNode.next = newNode;
        } else {
            newNode.next = this.tail.next;
            this.tail.next = newNode;
            this.tail = newNode;
        }
        this.numOfData++;
    }
    public void LInsertFront(T data) {
        Node<T> newNode = new Node<T>();
        newNode.data = data;

        if (this.tail == null) {
            this.tail = newNode;
            newNode.next = newNode;
        } else {
            newNode.next = this.tail.next;
            this.tail.next = newNode;
        }
        this.numOfData++;
    }
    public boolean LFirst(T[] data) {
        if (this.tail == null)
            return false;

        this.before = this.tail;
        this.cur = this.tail.next;

        data[0] = this.cur.data;
        return true;
    }
    public boolean LNext(T[] data) {
        if (this.tail == null)
            return false;

        this.before = this.cur;
        this.cur = this.cur.next;

        data[0] = this.cur.data;
        return true;
    }
    public T LRemove() {
        Node<T> rpos = this.cur;
        T rdata = rpos.data;

        if (rpos == this.tail) {
            if (this.tail == this.tail.next)
                this.tail = null;
            else
                this.tail = this.before;
        }

        this.before.next = this.cur.next;
        this.cur = this.before;

        this.numOfData--;
        return rdata;
    }
    public int LCount() {
        return this.numOfData;
    }
}
