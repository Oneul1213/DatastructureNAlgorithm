public class SelctionSort {
    public static void SelctionSort(int[] arr) {
        int temp;
        int minIdx;
        int n = arr.length;

        for (int i = 0; i < n-1; i++) {         // 몇 개가 정렬되었는지
            minIdx = i;

            for (int j = i+1; j < n; j++) {     // 최솟값 찾기
                if (arr[j] < arr[minIdx])
                    minIdx = j;
            }

            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }

    public static void main(String[] args) {
        int[] arr = { 3, 4, 2, 1 };

        SelctionSort.SelctionSort(arr);

        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i]+" ");

        System.out.println();
    }
}
