package InterpolationSearch;

public class InterpolationiSearch {
    public static int Search(int[] arr, int low, int high, int target) {
        // 탐색 대상이 탐색 범위에 없을 경우
        if (target < arr[low] || target > arr[high])
            return -1;

        int s = (int)((double)(target - arr[low]) / (arr[high] - arr[low]) * (high - low)) +low;

        if (arr[s] == target)
            return s;
        else if (target < arr[s])
            return InterpolationiSearch.Search(arr, low, s-1, target);
        else
            return InterpolationiSearch.Search(arr, s+1, high, target);
    }
}
