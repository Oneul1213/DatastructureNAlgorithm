def MergeTwoArea(arr, left, mid, right):
    fIdx = left     # 왼쪽 영역의 시작 인덱스
    rIdx = mid + 1  # 오른쪽 영역의 시작 인덱스

    sortArr = []

    while fIdx <= mid and rIdx <= right:      # 둘 중 한 영역이라도 빌 때까지 반복
        if arr[fIdx] <= arr[rIdx]:
            sortArr.append(arr[fIdx])
            fIdx += 1
        else:
            sortArr.append(arr[rIdx])
            rIdx += 1
    
    # 남은 한 영역 붙이기
    if fIdx > mid:
        for i in range(rIdx, right + 1):
            sortArr.append(arr[rIdx])
            rIdx += 1
    else:
        for i in range(fIdx, mid + 1):
            sortArr.append(arr[fIdx])
            fIdx += 1
    
    for i in range(left, right+1):
        arr[i] = sortArr.pop(0)


def MergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2

        MergeSort(arr, left, mid)               # 왼쪽 나누기
        MergeSort(arr, mid + 1, right)          # 오른쪽 나누기

        MergeTwoArea(arr, left, mid, right)     # 정렬된 두 영역 병합



arr = [ 3, 2, 4, 1, 7, 6, 5 ]

MergeSort(arr, 0, len(arr) - 1)

for idx, e in enumerate(arr):
    print(e, end=' ')
