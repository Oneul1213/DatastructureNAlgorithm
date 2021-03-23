import DbDLinkedListModule as dblm

dblist = dblm.DbDLinkedList()

for i in range(1, 9):
    dblist.LInsert(i)

data = dblist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    data = dblist.LNext()
    while data[0] is True:
        print(data[1], end=' ')
        data = dblist.LNext()
    
    print()
    print()

data = dblist.LFirst()
if data[0] is True:
    if data[1] % 2 is 0:
        dblist.LRemove()
    
    data = dblist.LNext()
    while data[0] is True:
        if data[1] % 2 is 0:
            dblist.LRemove()
        data = dblist.LNext()

data = dblist.LFirst()
if data[0] is True:
    print(data[1], end=' ')

    data = dblist.LNext()
    while data[0] is True:
        print(data[1], end=' ')
        data = dblist.LNext()
    
    print()
    print()
