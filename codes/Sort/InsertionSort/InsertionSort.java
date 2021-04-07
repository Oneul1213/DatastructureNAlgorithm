public class InsertionSort {
    public static void InsertionSort(int[] arr) {
        int insData, j;
        int n = arr.length;

        for (int i = 1; i < n; i++) {       // 정렬할 데이터
            insData = arr[i];

            for (j = i-1; j >= 0; j--) {    // 제자리 찾기
                if (arr[j] > insData)
                    arr[j+1] = arr[j];
                else
                    break;
            }

            arr[j+1] = insData;
        }
    }

    public static void  main(String[] args) {
        int[] arr = {5, 3, 2, 4, 1};

        InsertionSort(arr);

        for(int i = 0; i < 5; i++)
            System.out.print(arr[i]+" ");

        System.out.println();
    }
}
