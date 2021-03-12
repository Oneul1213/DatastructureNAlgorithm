import ArrayListModule as alm

arlist = alm.ArrayList()

arlist.LInsert(11)
arlist.LInsert(11)
arlist.LInsert(22)
arlist.LInsert(22)
arlist.LInsert(33)

print("현재 데이터의 수: {}".format(arlist.LCount()))

data = arlist.LFirst()
if data[0]:
    print(data[1], end=' ')

    data = arlist.LNext()
    while data[0]:
        print(data[1], end=' ')
        data = arlist.LNext()
print('\n')

data = arlist.LFirst()
if data[0]:
    if data[1] == 22:
        arlist.LRemove()
    
    data = arlist.LNext()
    while data[0]:
        if data[1] == 22:
            arlist.LRemove()
        
        data = arlist.LNext()

print("현재 데이터의 수: {}".format(arlist.LCount()))

data = arlist.LFirst()
if data[0]:
    print(data[1], end=' ')

    data = arlist.LNext()
    while data[0]:
        print(data[1], end=' ')
        data = arlist.LNext()
print('\n')
