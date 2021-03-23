package DbDLinkedList;

public class DbDLinkedList<T> implements DbDLinkedListInterface<T>{
    private Node<T> head;
    private Node<T> tail;
    private Node<T> cur;
    private int numOfData;

    public DbDLinkedList() {
        this.cur = null;
        this.numOfData = 0;

        Node<T> hDummyNode = new Node<T>();
        Node<T> tDummyNode = new Node<T>();

        this.head = hDummyNode;
        this.tail = hDummyNode;

        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    @Override
    public void LInsert(T data) {
        Node<T> newNode = new Node<T>();
        newNode.data = data;

        newNode.prev = this.tail.prev;
        newNode.next = this.tail;

        this.tail.prev.next = newNode;
        this.tail.prev = newNode;

        this.numOfData++;
    }

    @Override
    public boolean LFirst(T[] data) {
        if (this.tail.prev == this.head)
            return false;

        this.cur = this.head.next;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public boolean LNext(T[] data) {
        if (this.cur.next == this.tail)
            return false;

        this.cur = this.cur.next;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public T LRemove() {
        Node<T> rpos = new Node<T>();
        T rdata = this.cur.data;

        this.cur.prev.next = this.cur.next;
        this.cur.next.prev = this.cur.prev;

        this.cur = this.cur.prev;
        this.numOfData--;
        return rdata;
    }

    @Override
    public int LCount() {
        return this.numOfData;
    }
}
