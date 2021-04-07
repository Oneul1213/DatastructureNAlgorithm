public class BubbleSort {
    public static void BubbleSort(int[] arr) {
        int temp;
        int n = arr.length;

        for (int i = 0; i < n-1; i++) {         // 몇 개가 정렬됐는지
            for (int j = 0; j < (n-i)-1; j++) { // 어디까지 비교할지
                if (arr[j] > arr[j+1]) {
                    temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {3, 2, 4, 1};

        BubbleSort.BubbleSort(arr);

        for (int i = 0; i < arr.length; i++)
            System.out.print(arr[i]+" ");
    }
}
