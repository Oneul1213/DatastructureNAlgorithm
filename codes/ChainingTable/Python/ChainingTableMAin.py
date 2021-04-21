import ChainingTable as ct
import Person as p


def MyHashFunc(k):
    return k % 100


myTbl = ct.ChainingTable(MyHashFunc)

np = p.Person(900254, "LEE", "Seoul")
myTbl.TBLInsert(np.ssn, np)

np = p.Person(900139, "KIM", "Jeju")
myTbl.TBLInsert(np.ssn, np)

np = p.Person(900827, "HAN", "Kangwon")
myTbl.TBLInsert(np.ssn, np)

sp = myTbl.TBLSearch(900254)
if sp is not None:
    sp.ShowPerInfo()

sp = myTbl.TBLSearch(900139)
if sp is not None:
    sp.ShowPerInfo()

sp = myTbl.TBLSearch(900827)
if sp is not None:
    sp.ShowPerInfo()

rp = myTbl.TBLDelete(900254)
rp = myTbl.TBLDelete(900139)
rp = myTbl.TBLDelete(900827)
