package DbDLinkedList;

public class DbDLinkedListMain {
    public static void main(String[] args) {
        DbDLinkedList<Integer> list = new DbDLinkedList<Integer>();
        Integer[] data = new Integer[1];

        list.LInsert(1); list.LInsert(2);
        list.LInsert(3); list.LInsert(4);
        list.LInsert(5); list.LInsert(6);
        list.LInsert(7); list.LInsert(8);

        if (list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while (list.LNext(data))
                System.out.print(data[0]+" ");

            System.out.println("\n");
        }

        if (list.LFirst(data)) {
            if (data[0] % 2 == 0)
                list.LRemove();

            while (list.LNext(data))
                if (data[0] % 2 == 0)
                    list.LRemove();
        }

        if (list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while (list.LNext(data))
                System.out.print(data[0]+" ");

            System.out.println("\n");
        }
    }
}
