package RadixSort;

public class RadixSort {
    private static int BUCKET_NUM = 10;

    public static void Sort(int[] arr, int maxLen) {
        ListQueue<Integer>[] buckets = new ListQueue[BUCKET_NUM];
        for (int i = 0; i < BUCKET_NUM; i++)
            buckets[i] = new ListQueue<Integer>();

        int bucketIndex;
        int dataIndex;
        int divfac = 1;

        for (int pos = 0; pos < maxLen; pos++) {                                                // 가장 긴 자릿수(maxLen)까지 반복
            for(dataIndex = 0; dataIndex < arr.length; dataIndex++) {                           // 데이터 전체 반복
                int radix = (arr[dataIndex] / divfac) % 10;                                     // 각 자릿수의 기수 구하기

                buckets[radix].Enqueue(arr[dataIndex]);                                         // 올바른(각 기수에 맞는) 버킷에 넣기
            }

            for (dataIndex = 0, bucketIndex = 0; bucketIndex < BUCKET_NUM; bucketIndex++) {
                while (!buckets[bucketIndex].QIsEmpty())
                    arr[dataIndex++] = buckets[bucketIndex].Dequeue();                          // 버킷에서 순서대로 꺼내기
            }

            divfac *= 10;                                                                       // 다음 자릿수로 바꾸기
        }
    }
}
