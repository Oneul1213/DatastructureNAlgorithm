def Swap(arr, idx1, idx2):
    temp = arr[idx1]
    arr[idx1] = arr[idx2]
    arr[idx2] = temp

def Partition(arr, left, right):
    pivot = arr[left]
    low = left + 1
    high = right

    while low <= high:
        while low <= right and pivot >= arr[low]:           # low가 pivot보다 큰 값을 가리키도록
            low += 1

        while high >= left + 1 and pivot <= arr[high]:      # high가 pivot보다 작은 값을 가리키도록
            high -= 1
        
        if low <= high:
            Swap(arr, low, high)
    
    Swap(arr, left, high)                                   # pivot을 정렬된 위치에 배치
    return high

def QuickSort(arr, left, right):
    if left < right:
        pivot = Partition(arr, left, right)

        QuickSort(arr, left, pivot - 1)
        QuickSort(arr, pivot + 1, right)

arr = [3, 2, 4, 1, 7, 6]

QuickSort(arr, 0, len(arr) - 1)

for i, e in enumerate(arr):
    print(e, end=' ')

print()
