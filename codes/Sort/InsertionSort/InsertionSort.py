def InsertionSort(arr):
    j = 0
    n = len(arr)

    for i in range(1, n):               # 정렬할 데이터
        insData = arr[i]

        for j in reversed(range(i)):    # 제자리 찾기
            if arr[j] > insData:
                arr[j+1] = arr[j]
            else:
                j += 1
                break
        
        arr[j] = insData

arr = [5, 3, 2, 4, 1]

InsertionSort(arr)

for i in range(5):
    print(arr[i], end=' ')
