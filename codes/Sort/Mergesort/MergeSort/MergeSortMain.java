package MergeSort;

public class MergeSortMain {
    public static void main(String[] args) {
        int[] arr = { 3, 2, 4, 1, 7, 6, 5 };

        MergeSort.MergeSort(arr, 0, arr.length-1);

        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i]+" ");

        System.out.println();
    }
}
