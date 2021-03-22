package CircularLinkedList;

public class CircularLinkedListMain {
   public static void main(String[] args) {
       CircularLinkedList<Integer> list = new CircularLinkedList<Integer>();
       Integer data[] = new Integer[1] ;
       int nodeNum;

       list.LInsert(3);
       list.LInsert(4);
       list.LInsert(5);
       list.LInsertFront(2);
       list.LInsertFront(1);

       if (list.LFirst(data)) {
           System.out.print(data[0]+" ");

           for (int i = 0; i < list.LCount()*3-1; i++) {
               if (list.LNext(data))
                   System.out.print(data[0]+" ");
           }
       }
       System.out.println();

       nodeNum = list.LCount();

       if (nodeNum != 0) {
           list.LFirst(data);
           if (data[0]%2 == 0)
               list.LRemove();

           for (int i=0; i < nodeNum-1; i++) {
               list.LNext(data);
               if (data[0]%2 == 0)
                   list.LRemove();
           }
       }

       if (list.LFirst(data)) {
           System.out.print(data[0]+" ");

           for (int i = 0; i < list.LCount()-1; i++) {
               if (list.LNext(data))
                   System.out.print(data[0]+" ");
           }
       }
       System.out.println();
   }
}
