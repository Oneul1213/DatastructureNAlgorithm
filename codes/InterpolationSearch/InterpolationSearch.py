def InterpolationSerch(arr, low, high, target):
    # 탐색 대상이 탐색 범위에 없을 경우
    if target < arr[low] or target > arr[high]:
        return -1
    
    s = int(((target - arr[low]) / (arr[high] - arr[low]) * (high - low)) + low)

    if arr[s] is target:
        return s
    elif target < arr[s]:
        InterpolationSerch(arr, low, s - 1, target)
    else:
        InterpolationSerch(arr, s + 1, high, target)

arr = [ 1, 3, 5, 7, 9 ]

idx = InterpolationSerch(arr, 0, len(arr)-1, 7)
if idx is -1:
    print("탐색 실패")
else:
    print("타겟 저장 인덱스: {}".format(idx))

idx = InterpolationSerch(arr, 0, len(arr)-1, 10)
if idx is -1:
    print("탐색 실패")
else:
    print("타겟 저장 인덱스: {}".format(idx))

idx = InterpolationSerch(arr, 1, 4, 2)
if idx is -1:
    print("탐색 실패")
else:
    print("타겟 저장 인덱스: {}".format(idx))
