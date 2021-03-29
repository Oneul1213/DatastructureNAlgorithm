package Deque;

public class DequeMain {
    public static void main(String[] args) {
        Deque<Integer> deq = new Deque<Integer>();

        deq.DQAddFirst(3);
        deq.DQAddFirst(2);
        deq.DQAddFirst(1);

        deq.DQAddLast(4);
        deq.DQAddLast(5);
        deq.DQAddLast(6);

        while (!deq.DQIsEmpty())
            System.out.print(deq.DQRemoveFirst());

        System.out.println();

        deq.DQAddFirst(3);
        deq.DQAddFirst(2);
        deq.DQAddFirst(1);

        deq.DQAddLast(4);
        deq.DQAddLast(5);
        deq.DQAddLast(6);

        while (!deq.DQIsEmpty())
            System.out.print(deq.DQRemoveLast());
    }
}
