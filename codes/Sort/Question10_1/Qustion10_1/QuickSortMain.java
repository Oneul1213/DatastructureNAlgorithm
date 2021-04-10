package Qustion10_1;

public class QuickSortMain {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

        QuickSort.Sort(arr, 0, arr.length - 1);

        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i]+" ");

        System.out.println();
    }
}
