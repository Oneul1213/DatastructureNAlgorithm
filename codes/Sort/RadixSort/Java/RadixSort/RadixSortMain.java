package RadixSort;

public class RadixSortMain {
    public static void main(String[] args) {
        int[] arr = { 13, 212, 14, 7141, 10981, 6, 15 };

        RadixSort.Sort(arr, 5);

        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i]+" ");
        System.out.println();
    }
}
