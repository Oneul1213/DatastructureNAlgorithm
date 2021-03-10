def BSearchRecur(ar, first, last, target):
    if first > last:
        return -1
    mid = int((first + last) / 2)

    if ar[mid] == target:
        return mid
    elif target < ar[mid]:
        return BSearchRecur(ar, first, mid-1, target)
    else:
        return BSearchRecur(ar, mid+1, last, target)

arr = [1, 3, 5, 7, 9]

idx = BSearchRecur(arr, 0, len(arr)-1, 7)
if idx == -1:
    print("탐색 실패")
else:
    print("타겟 저장 인덱스: "+str(idx))

idx = BSearchRecur(arr, 0, len(arr)-1, 4)
if idx == -1:
    print("탐색 실패")
else:
    print("타겟 저장 인덱스: "+str(idx))
