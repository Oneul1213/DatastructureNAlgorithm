package Qustion10_1;

public class QuickSort {
    private static int MedianOfThree(int[] arr, int left, int right) {
        int mid = (left + right) / 2;

        // 중간 값에서 다른 두 값을 빼면 하나는 양수, 하나는 음수
        if ((arr[left] - arr[mid]) * (arr[left] - arr[right]) < 0) {
            return left;
        }
        else if ((arr[mid] - arr[left]) * (arr[mid] - arr[right]) < 0) {
            return mid;
        }
        else {
            return right;
        }
    }

    private static void Swap(int[] arr, int idx1, int idx2) {
        int temp = arr[idx1];
        arr[idx1] = arr[idx2];
        arr[idx2] = temp;
    }

    private static int Partition(int[] arr, int left, int right) {
        int pivIndex = QuickSort.MedianOfThree(arr, left, right);

        int pivot = arr[pivIndex];
        int low = left + 1;
        int high = right;

        QuickSort.Swap(arr, left, pivIndex);                    // 중간 값인 피벗을 제일 왼쪽에 둠(코드 변경 최소화)
        System.out.println("피벗: " + pivot);

        while (low <= high) {
            while (low <= right && pivot >= arr[low])           // low가 pivot보다 큰 값을 가리키도록
                low++;

            while (high >= (left + 1) && pivot <= arr[high])      // high가 pivot보다 작은 값을 가리키도록
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
