package SinglyLinkedList;

public class SinglyLinkedListMain {
    public static void main(String[] args) {
        SinglyLinkedListInterface<Integer> list = new SinlgyLinkedList<Integer>();
        Integer[] data = new Integer[1];

        list.SetSortRule((Integer d1, Integer d2) -> {
            if (d1.intValue() < d2.intValue())
                return 0;
            else
                return 1;
        });

        list.LInsert(11); list.LInsert(11);
        list.LInsert(22); list.LInsert(22);
        list.LInsert(33);

        System.out.println("현재 데이터의 수 : "+list.LCount());

        if (list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while(list.LNext(data))
                System.out.print(data[0]+" ");
        }
        System.out.println();

        if (list.LFirst(data)) {
            if (data[0] == 22)
                list.LRemove();

            while (list.LNext(data))
                if (data[0] == 22)
                    list.LRemove();
        }

        System.out.println("현재 데이터의 수 : "+list.LCount());

        if (list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while (list.LNext(data))
                System.out.print(data[0]+" ");
        }
        System.out.println();
    }
}
