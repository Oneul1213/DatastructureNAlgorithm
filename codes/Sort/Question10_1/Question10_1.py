def MedianOfThree(arr, left, right):
    mid = (left + right) // 2
    
    # 중간 값에서 다른 두 값을 빼면 하나는 양수, 하나는 음수
    if (arr[left] - arr[mid]) * (arr[left] - arr[right]) < 0:
        return left
    elif (arr[mid] - arr[left]) * (arr[mid] - arr[right]) < 0:
        return mid
    else:
        return right

def Swap(arr, idx1, idx2):
    temp = arr[idx1]
    arr[idx1] = arr[idx2]
    arr[idx2] = temp

def Partition(arr, left, right):
    pivIndex = MedianOfThree(arr, left, right)
    pivot = arr[pivIndex]
    low = left + 1
    high = right

    Swap(arr, left, pivIndex)                               # 중간 값인 피벗을 왼쪽에 둠(코드 변경 최소화)
    print("피벗: {}".format(pivot))

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

arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]

QuickSort(arr, 0, len(arr) - 1)

for i, e in enumerate(arr):
    print(e, end=' ')

print()
