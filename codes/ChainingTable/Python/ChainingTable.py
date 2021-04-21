import ChainingSlot as cs
import SinglyLinkedListModule as slm


class ChainingTable:
    MAX_TBL = 100

    def __init__(self, hf):
        self.tbl = []

        for i in range(ChainingTable.MAX_TBL):
            self.tbl.append(slm.SinglyLinkedList())
        
        self.hash_func = hf
    
    def TBLInsert(self, k, v):
        hv = self.hash_func(k)
        ns = cs.ChainingSlot()
        ns.key = k
        ns.value = v

        # 키가 중복되었다면
        if self.TBLSearch(k) is not None:
            print("키 중복 오류 발생")
            return
        else:
            self.tbl[hv].LInsert(ns)
    
    def TBLDelete(self, k):
        hv = self.hash_func(k)
        
        data = self.tbl[hv].LFirst()
        if data[0] is True:
            if data[1].key is k:
                self.tbl[hv].LRemove()
                return data[1].value
            else:
                data = self.tbl[hv].LNext()
                while data[0] is True:
                    if data[1].key is k:
                        self.tbl[hv].LRemove()
                        return data[1].value
                    data = self.tbl[hv].LNext()
        
        return None
    
    def TBLSearch(self, k):
        hv = self.hash_func(k)
        
        data = self.tbl[hv].LFirst()
        if data[0] is True:
            if data[1].key is k:
                return data[1].value
            else:
                data = self.tbl[hv].LNext()
                while data[0] is True:
                    if data[1].key is k:
                        return data[1].value
                    data = self.tbl[hv].LNext()
        
        return None

            