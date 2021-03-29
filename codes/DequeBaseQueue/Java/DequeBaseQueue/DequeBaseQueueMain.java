package DequeBaseQueue;

public class DequeBaseQueueMain {
    public static void  main(String[] args) {
        DequeBaseQueue<Integer> q = new DequeBaseQueue<Integer>();

        q.Enqueue(1); q.Enqueue(2);
        q.Enqueue(3); q.Enqueue(4);
        q.Enqueue(5);

        while (!q.QIsEmpty())
            System.out.print(q.Dequeue()+" ");
    }
}
