def SelectionSort(arr):
    n = len(arr)

    for i in range(n-1):            # 몇 개가 정렬되었는지
        minIdx = i

        for j in range(i+1, n):     # 최솟값 찾기
            if arr[j] < arr[minIdx]:
                minIdx = j
        
        temp = arr[i]
        arr[i] = arr[minIdx]
        arr[minIdx] = temp

arr = [3, 4, 2, 1]

SelectionSort(arr)

for i in range(4):
    print(arr[i], end=' ')
