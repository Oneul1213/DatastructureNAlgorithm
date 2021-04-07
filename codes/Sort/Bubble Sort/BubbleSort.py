def BubbleSort(arr):
    n = len(arr)

    for i in range(n-1):
        for j in range((n-i)-1):
            if arr[j] > arr[j+1]:
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp

arr = [3, 2, 4, 1]
BubbleSort(arr)
for i in range(len(arr)):
    print(arr[i], end=' ')
