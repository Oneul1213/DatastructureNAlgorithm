package DoublyLinkedListNoneRemove;

public class DoublyLinkedList<T> implements DoublyLinkedListInterface<T> {
    private Node<T> head;
    private Node<T> cur;
    private int numOfData;

    public DoublyLinkedList() {
        this.head = null;
        this.cur = null;
        this.numOfData = 0;
    }

     @Override
    public void LInsert(T data) {
        Node<T> newNode = new Node<>();
        newNode.data = data;

        newNode.next = this.head;
        if (this.head != null)
            this.head.prev = newNode;

        newNode.prev = null;
        this.head = newNode;

        this.numOfData++;
    }

    @Override
    public boolean LFirst(T[] data) {
        if (this.head == null)
            return false;

        this.cur = this.head;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public boolean LNext(T[] data) {
        if (this.cur.next == null)
            return false;

        this.cur = this.cur.next;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public boolean LPrevious(T[] data) {
        if (this.cur.prev == null)
            return false;

        this.cur = this.cur.prev;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public int LCount() {
        return this.numOfData;
    }
}
