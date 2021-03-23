import DoublyLinkedListModule as dlm

dlist = dlm.DoublyLinkedList()

for i in range(1, 9):
    dlist.LInsert(i)

data = dlist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    data = dlist.LNext()
    while data[0] is True:
        print(data[1], end=' ')
        data = dlist.LNext()
    
    data = dlist.LPrevious()
    while data[0] is True:
        print(data[1], end=' ')
        data = dlist.LPrevious()
    
    print()
    print()

data = dlist.LFirst()
if data[0] is True:
    if data[1] % 2 is 0:
        dlist.LRemove()
    
    data = dlist.LNext()
    while data[0] is True:
        if data[1] % 2 is 0:
            dlist.LRemove()
        data = dlist.LNext()

data = dlist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    data = dlist.LNext()
    while data[0] is True:
        print(data[1], end=' ')
        data = dlist.LNext()
    
    print()
    print()
