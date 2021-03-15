import ArrayListModule as alm
import PointModule as pm

arlist = alm.ArrayList()

arlist.LInsert(pm.Point(2, 1))
arlist.LInsert(pm.Point(2, 2))
arlist.LInsert(pm.Point(3, 1))
arlist.LInsert(pm.Point(3, 2))

print("현재 데이터의 수: {}".format(arlist.LCount()))

data = arlist.LFirst()
if data[0] is True:
    data[1].ShowPointPos()

    data = arlist.LNext()
    while data[0] is True:
        data[1].ShowPointPos()
        data = arlist.LNext()
print()

compPos = pm.Point(2, 0)

data = arlist.LFirst()
if data[0] is True:
    if data[1].PointComp(compPos) == 1:
        arlist.LRemove()
    
    data = arlist.LNext()
    while data[0] is True:
        if data[1].PointComp(compPos) == 1:
            arlist.LRemove()
        data = arlist.LNext()

print("현재 데이터의 수: {}".format(arlist.LCount()))

data = arlist.LFirst()
if data[0] is True:
    data[1].ShowPointPos()

    data = arlist.LNext()
    while data[0] is True:
        data[1].ShowPointPos()
        data = arlist.LNext()
print()
