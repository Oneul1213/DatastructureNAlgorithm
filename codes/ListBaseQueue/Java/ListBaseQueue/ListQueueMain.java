package ListBaseQueue;

public class ListQueueMain {
    public static void  main(String[] args) {
        ListQueue<Integer> q = new ListQueue<>();

        q.Enqueue(1); q.Enqueue(2);
        q.Enqueue(3); q.Enqueue(4);
        q.Enqueue(5);

        while (!q.QIsEmpty())
            System.out.print(q.Dequeue()+" ");
    }
}
