package ArrayList;

public class ListMain {
    public static void main(String[] args) {
        ArrayList list = new ArrayList();
        int[] data = new int[1];

        list.LInsert(11); list.LInsert(11);
        list.LInsert(22); list.LInsert(22);
        list.LInsert(33);

        System.out.println("현재 데이터의 수: "+list.LCount());

        if (list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while (list.LNext(data))
                System.out.print(data[0]+" ");
        }
        System.out.println('\n');

        if (list.LFirst(data)) {
            if (data[0] == 22)
                list.LRemove();

            while (list.LNext(data)) {
                if (data[0] == 22)
                    list.LRemove();
            }
        }

        System.out.println("현재 데이터의 수: "+list.LCount());

        if (list.LFirst(data)) {
            System.out.print(data[0]+" ");

            while (list.LNext(data))
                System.out.print(data[0]+" ");
        }
        System.out.println('\n');
    }
}
