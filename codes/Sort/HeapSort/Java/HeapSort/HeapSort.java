package HeapSort;

public class HeapSort {
    public static void HeapSort(int[] arr, PriorityComp<Integer> pc) {
        Heap<Integer> heap = new Heap<Integer>(pc);

        for (int i = 0; i < arr.length; i++)    // 힙에 데이터 넣기
            heap.HInsert(arr[i]);

        for (int i = 0; i < arr.length; i++)    // 힙에서 데이터 꺼내기
            arr[i] = heap.HDelete();
    }

    public static void main(String[] args) {
        int[] arr = { 3, 4, 2, 1 };

        HeapSort.HeapSort(arr, (d1, d2)->d2-d1);

        for (int i = 0; i < 4; i++)
            System.out.print(arr[i]+" ");

        System.out.println();
    }
}
