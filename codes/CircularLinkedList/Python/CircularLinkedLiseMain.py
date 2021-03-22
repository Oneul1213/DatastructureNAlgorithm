import CircularLinkedListModule as clm

clist = clm.CircularLinkedList()

clist.LInsert(3)
clist.LInsert(4)
clist.LInsert(5)
clist.LInsertFront(2)
clist.LInsertFront(1)

data = clist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    for i in range(clist.LCount()*3-1):
        data = clist.LNext()
        if data[0] is True:
            print(data[1], end=' ')
print()

nodeNum = clist.LCount()

if nodeNum is not 0:
    data = clist.LFirst()
    if data[1]%2 is 0:
        clist.LRemove()
    
    for i in range(nodeNum-1):
        data = clist.LNext()
        if data[1]%2 is 0:
            clist.LRemove()

data = clist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    for i in range(clist.LCount()-1):
        data = clist.LNext()
        if data[0] is True:
            print(data[1], end=' ')
print()
