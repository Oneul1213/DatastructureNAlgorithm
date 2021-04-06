package PriorityQueue;

public class PriorityQueueMain {
    public static void main(String[] args) {
        PriorityQueue<Character> pq = new PriorityQueue<Character>((ch1, ch2)->ch2-ch1);

        pq.PEnqueue('A');
        pq.PEnqueue('B');
        pq.PEnqueue('C');
        System.out.println(pq.PDequeue());

        pq.PEnqueue('A');
        pq.PEnqueue('B');
        pq.PEnqueue('C');
        System.out.println(pq.PDequeue());

        while(!pq.PQIsEmpty())
            System.out.println(pq.PDequeue());
    }
}
