package ListBaseQueue;

public class ListQueue<T> implements ListQueueInterface<T> {
    private Node<T> front;
    private Node<T> rear;

    public ListQueue() {
        this.front = null;
        this.rear = null;
    }

    @Override
    public boolean QIsEmpty() {
        if (this.front == null)
            return true;
        else
            return false;
    }

    @Override
    public void Enqueue(T data) {
        Node<T> newNode = new Node<>();
        newNode.setData(data);
        newNode.setNext(null);

        if (this.QIsEmpty())
            this.front = newNode;
        else
            this.rear.setNext(newNode);

        this.rear = newNode;
    }

    @Override
    public T Dequeue() {
        if (this.QIsEmpty()) {
            System.out.println("Queue Memory Error!");
            System.exit(-1);
        }

        Node<T> delNode = this.front;
        T retData = delNode.getData();
        this.front = this.front.getNext();

        return retData;
    }

    @Override
    public T QPeek() {
        if (this.QIsEmpty()) {
            System.out.println("Queue Memory Error!");
            System.exit(-1);
        }

        return this.front.getData();
    }
}
