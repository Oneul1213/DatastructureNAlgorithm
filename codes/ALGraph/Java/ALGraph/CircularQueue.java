package ALGraph;

public class CircularQueue<T> implements CircularQueueInterface<T> {
    private int front;
    private int rear;
    private T[] queArr;

    private int NextPosIdx(int pos) {
        if (pos == QUE_LEN - 1)
            return 0;
        else
            return pos+1;
    }

    @SuppressWarnings("unchecked")
    public CircularQueue() {
        this.front = 0;
        this.rear = 0;
        this.queArr = (T[])new Object[QUE_LEN];
    }

    @Override
    public boolean QIsEmpty() {
        if (this.front == this.rear)
            return true;
        else
            return false;
    }

    @Override
    public void Enqueue(T data) {
        if (this.NextPosIdx(this.rear) == this.front) {
            System.out.println("Queue Memory Error!");
            System.exit(-1);
        }

        this.rear = this.NextPosIdx(this.rear);
        this.queArr[this.rear] = data;
    }

    @Override
    public T Dequeue() {
        if (this.QIsEmpty()) {
            System.out.println("Queue Memory Error!");
            System.exit(-1);
        }

        this.front = this.NextPosIdx(this.front);
        return this.queArr[this.front];
    }

    @Override
    public T QPeek() {
        if (this.QIsEmpty()) {
            System.out.println("Queue Memory Error!");
            System.exit(-1);
        }

        return this.queArr[this.NextPosIdx(this.front)];
    }
}
