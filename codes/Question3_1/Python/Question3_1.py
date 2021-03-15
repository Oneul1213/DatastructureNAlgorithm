import ArrayListModule as alm

# 리스트 초기화
arlist = alm.ArrayList()

# 정수 1~9 리스트에 저장
for i in range(1, 10):
    arlist.LInsert(i)

# 리스트 순차 참조 후 저장된 값들의 합 출력
data = arlist.LFirst()
if data[0]:
    cnt = 0
    cnt += data[1]

    data = arlist.LNext()
    while data[0]:
        cnt += data[1]
        data = arlist.LNext()
    print("리스트에 저장된 값의 합 : {}".format(cnt))

# 리스트에 저장된 값 중 2의 배수, 3의 배수 모두 삭제
data = arlist.LFirst()
if data[0]:
    if data[1] % 2 == 0 or data[1] % 3 == 0:
        arlist.LRemove()
    
    data = arlist.LNext()
    while data[0]:
        if data[1]  % 2 == 0 or data[1] % 3 == 0:
            arlist.LRemove()
        data = arlist.LNext()

# 저장된 데이터를 순서대로 출력
data = arlist.LFirst()
if data[0]:
    print(data[1], end=' ')

    data = arlist.LNext()
    while data[0]:
        print(data[1], end=' ')
        data = arlist.LNext()
print()
