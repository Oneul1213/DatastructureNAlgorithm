import ListQueueModule as lqm

BUCKET_NUM = 10

def RadixSort(arr, maxLen):
    buckets = []
    for i in range(BUCKET_NUM):
        buckets.append(lqm.ListQueue())

    divfac = 1

    for pos in range(maxLen):                   # 가장 긴 자릿수(maxLen)까지 반복
        for idx, elem in enumerate(arr):        # 데이터 전체 반복
            radix = (elem // divfac) % 10       # 각 자릿수의 기수 구하기

            buckets[radix].Enqueue(elem)        # 올바른(각 기수에 맞는) 버킷에 넣기
        
        dataIndex = 0
        for idx, q in enumerate(buckets):
            while q.QIsEmpty() is False:
                arr[dataIndex] = q.Dequeue()    # 버킷에서 순서대로 꺼내기
                dataIndex += 1
        
        divfac *= 10                            # 다음 자릿수로 바꾸기

arr = [ 13, 212, 14, 7141, 10981, 6, 15 ]

RadixSort(arr, 5)

for idx, elem in enumerate(arr):
    print(elem, end=' ')
print()
