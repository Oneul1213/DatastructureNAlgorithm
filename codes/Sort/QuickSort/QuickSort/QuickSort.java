package QuickSort;

public class QuickSort {
    private static void Swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    private static int Partition(int[] arr, int left, int right) {
        int pivot = arr[left];
        int low = left + 1;
        int high = right;

        while (low <= high) {
            while (low <= right && pivot >= arr[low])           // low가 pivot보다 큰 값을 가리키도록
                low++;

            while (high >= left + 1 && pivot <= arr[high])      // high가 pivot보다 작은 값을 가리키도록
                high--;

            if (low <= high)
                QuickSort.Swap(arr, low, high);
        }

        QuickSort.Swap(arr, left, high);                       // pivot을 정렬된 위치에 배치
        return high;
    }

    public static void Sort(int[] arr, int left, int right) {
        if (left < right) {
            int pivot = QuickSort.Partition(arr, left, right);

            QuickSort.Sort(arr, left, pivot - 1);
            QuickSort.Sort(arr, pivot + 1, right);
        }
    }
}
