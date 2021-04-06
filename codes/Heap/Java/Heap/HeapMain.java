package Heap;

public class HeapMain {
    public static void main(String[] args) {
        Heap<Character> heap = new Heap<Character>((ch1, ch2)->ch2-ch1);

        heap.HInsert('A');
        heap.HInsert('B');
        heap.HInsert('C');
        System.out.println(heap.HDelete());

        heap.HInsert('A');
        heap.HInsert('B');
        heap.HInsert('C');
        System.out.println(heap.HDelete());

        while(!heap.HIsEmpty())
            System.out.println(heap.HDelete());
    }
}
