import Person as p
import Table as t

def MyHashFunc1(k):
    return k % 100

def MyHashFunc2(k):
    return 1 + (k % 7)

myTbl = t.Table(MyHashFunc1, MyHashFunc2)

np = p.Person(20120003, "LEE", "Seoul")
myTbl.TBLInsert(np.ssn, np)

np = p.Person(20130012, "KIM", "Jeju")
myTbl.TBLInsert(np.ssn, np)

np = p.Person(20170049, "HAN", "Kangwon")
myTbl.TBLInsert(np.ssn, np)

sp = myTbl.TBLSearch(20120003)
if sp is not None:
    sp.ShowPerInfo()

sp = myTbl.TBLSearch(20130012)
if sp is not None:
    sp.ShowPerInfo()

sp = myTbl.TBLSearch(20170049)
if sp is not None:
    sp.ShowPerInfo()

rp = myTbl.TBLDelete(20120003)
rp = myTbl.TBLDelete(20130012)
rp = myTbl.TBLDelete(20170049)
