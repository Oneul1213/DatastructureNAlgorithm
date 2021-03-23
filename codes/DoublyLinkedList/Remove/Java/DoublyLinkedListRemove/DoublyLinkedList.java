package DoublyLinkedListRemove;

public class DoublyLinkedList<T> implements DoublyLinkedListInterface<T> {
    private Node<T> head;
    private Node<T> before;
    private Node<T> cur;
    private Node<T> after;
    private int numOfData;

    public DoublyLinkedList() {
        this.head = null;
        this.before = null;
        this.cur = null;
        this.after = null;
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
        this.before = this.cur.prev;
        this.after = this.cur.next;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public boolean LNext(T[] data) {
        if (this.after == null)
            return false;

        if (this.cur == null)
            this.cur = this.before;

        this.cur = this.cur.next;
        this.before = this.cur.prev;
        this.after = this.cur.next;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public boolean LPrevious(T[] data) {
        if (this.before == null)
            return false;

        if (this.cur == null)
            this.cur = this.after;

        this.cur = this.cur.prev;
        this.before = this.cur.prev;
        this.after = this.cur.next;
        data[0] = this.cur.data;

        return true;
    }

    @Override
    public T LRemove() {
        Node<T> rpos = this.cur;
        T rdata = rpos.data;

        if (this.cur == this.head && this.after == null) {  // 마지막 노드인 head를 삭제
            this.head = null;
        } else if (this.cur == this.head) {                 // 마지막 노드가 아닌 head를 삭제
            this.after.prev = null;
            this.head = this.after;
            this.before = this.head;
        } else if (this.after == null) {                    // 마지막 노드를 삭제
            this.before.next = null;
            this.after = this.before;
        } else {
            this.before.next = this.after;
            this.after.prev = this.before;
        }

        this.cur = null;
        this.numOfData--;
        return rdata;
    }

    @Override
    public int LCount() {
        return this.numOfData;
    }
}
