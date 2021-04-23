package SinglyLinkedList;

public class SinglyLinkedList<T> implements SinglyLinkedListInterface<T>{
    private Node<T> head;
    private Node<T> cur;
    private Node<T> before;

    private int numOfData;
    private WhoIsPrecede<T> comp;

    private void FInsert(T data) {
        Node<T> newNode = new Node<T>();
        newNode.data = data;

        newNode.next = this.head.next;
        this.head.next = newNode;

        this.numOfData++;
    }

    private void SInsert(T data) {
        Node<T> newNode = new Node<T>();
        Node<T> pred = this.head;

        newNode.data = data;

        while (pred.next != null && this.comp.comp(data, pred.next.data) != 0)
            pred = pred.next;

        newNode.next = pred.next;
        pred.next = newNode;

        this.numOfData++;
    }

    public SinglyLinkedList() {
        head = new Node<T>();
        head.next = null;
        cur = null;
        before = null;
        numOfData = 0;
        comp = null;
    }

    @Override
    public void LInsert(T data) {
        if (this.comp == null)
            this.FInsert(data);
        else
            this.SInsert(data);
    }

    @Override
    public boolean LFirst(T[] data) {
        if (this.head.next == null)
            return false;

        this.before = this.head;
        this.cur = this.head.next;

        data[0] = this.cur.data;
        return true;
    }

    @Override
    public boolean LNext(T[] data) {
        if (this.cur.next == null)
            return false;

        this.before = this.cur;
        this.cur = this.cur.next;

        data[0] = this.cur.data;
        return true;
    }

    @Override
    public T LRemove() {
        Node<T> rpos = this.cur;
        T rdata = rpos.data;

        this.before.next = this.cur.next;
        this.cur = this.before;

        this.numOfData--;
        return rdata;
    }

    @Override
    public int LCount() {
        return this.numOfData;
    }

    @Override
    public void SetSortRule(WhoIsPrecede<T> comp) {
        this.comp = comp;
    }
}
