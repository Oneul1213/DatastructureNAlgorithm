def Swap(arr, idx1, idx2):
    temp = arr[idx1]
    arr[idx1] = arr[idx2]
    arr[idx2] = temp

def Partition(arr, left, right):
    pivot = arr[left]
    low = left + 1
    high = right

    while low <= high:
        while low <= right and pivot >= arr[low]:
            low += 1

        while high >= left + 1 and pivot <= arr[high]:
            high -= 1
        
        if low <= high:
            Swap(arr, low, high)
    
    Swap(arr, left, high)
    return high

def QuickSort(arr, left, right):
    if left <= right:
        pivot = Partition(arr, left, right)

        QuickSort(arr, left, pivot - 1)
        QuickSort(arr, pivot + 1, right)

arr = [3, 2, 4, 1, 7, 6]

QuickSort(arr, 0, len(arr) - 1)

for i, e in enumerate(arr):
    print(e, end=' ')

print()
