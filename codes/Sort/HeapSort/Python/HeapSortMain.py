import HeapModule as hm

def HeapSort(arr, pc):
    heap = hm.Heap(pc)

    for i in range(len(arr)):       # 힙에 데이터 넣기
        heap.HInsert(arr[i])
    
    for i in range(len(arr)):       # 힙에서 데이터 꺼내기
        arr[i] = heap.HDelete()

arr = [3, 4, 2, 1]

HeapSort(arr, lambda d1, d2: d2-d1)

for i in range(4):
    print(arr[i], end=' ')
