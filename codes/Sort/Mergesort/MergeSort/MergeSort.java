package MergeSort;

public class MergeSort {
    private static void MergeTwoArea(int[] arr, int left, int mid, int right) {
        int fIdx = left;        // 왼쪽 영역의 시작 인덱스
        int rIdx = mid + 1;     // 오른쪽 영역의 시작 인덱스

        int[] sortArr = new int[arr.length];
        int sIdx = left;

        while (fIdx <= mid && rIdx <= right) {      // 둘 중 한 영역이라도 빌 때까지 반복
            if (arr[fIdx] <= arr[rIdx])
                sortArr[sIdx] = arr[fIdx++];
            else
                sortArr[sIdx] = arr[rIdx++];

            sIdx++;
        }

        // 남은 한 영역 붙이기
        if (fIdx > mid) {
            for (int i = rIdx; i <= right; i++, sIdx++)
                sortArr[sIdx] = arr[i];
        } else {
            for (int i = fIdx; i <=mid; i++, sIdx++)
                sortArr[sIdx] = arr[i];
        }

        for (int i = left; i <= right; i++)
            arr[i] = sortArr[i];
    }

    public static void MergeSort(int[] arr, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;

            MergeSort.MergeSort(arr, left, mid);            // 왼쪽 나누기
            MergeSort.MergeSort(arr, mid + 1, right);   // 오른쪽 나누기

            MergeSort.MergeTwoArea(arr, left, mid, right);  // 정렬된 두 영역 병합합
        }
    }
}
