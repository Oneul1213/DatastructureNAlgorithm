import SinglyLinkedListModule as slm


def WhoIsPrecede(d1, d2):
    if d1 < d2:
        return 0
    else:
        return 1


slist = slm.SinglyLinkedList()
data = []

slist.SetSortRule(WhoIsPrecede)

slist.LInsert(11)
slist.LInsert(11)
slist.LInsert(22)
slist.LInsert(22)
slist.LInsert(33)

print("현재 데이터의 수 : {}".format(slist.LCount()))

data = slist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    data = slist.LNext()
    while data[0] is True:
        print(data[1], end=' ')
        data = slist.LNext()
print()

data = slist.LFirst()
if data[0] is True:
    if data[1] == 22:
        slist.LRemove()
    
    data = slist.LNext()
    while data[0] is True:
        if data[1] == 22:
            slist.LRemove()
        data = slist.LNext()

print("현재 데이터의 수 : {}".format(slist.LCount()))

data = slist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    data = slist.LNext()
    while data[0] is True:
        print(data[1], end=' ')
        data = slist.LNext()
print()
