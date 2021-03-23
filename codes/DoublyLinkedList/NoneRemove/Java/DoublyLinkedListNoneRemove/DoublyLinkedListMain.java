package DoublyLinkedListNoneRemove;

public class DoublyLinkedListMain {
    public static void main(String[] args) {
        DoublyLinkedList<Integer> list = new DoublyLinkedList<>();
        Integer[] data = new Integer[1];

        for (int i = 1; i < 9; i++)
            list.LInsert(i);

        if(list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while(list.LNext(data))
                System.out.print(data[0]+" ");

            while(list.LPrevious(data))
                System.out.print(data[0]+" ");

            System.out.println("\n");
        }
    }
}
