import Slot as s

class Table:
    def __init__(self, hf1, hf2):
        self.tbl = []

        for i in range(s.Slot.MAX_TBL):
            self.tbl.append(s.Slot())
        
        self.hash_func1 = hf1
        self.hash_func2 = hf2
    
    def TBLInsert(self, k, v):
        hv = self.hash_func1(k)

        # 키가 중복되었다면
        if self.TBLSearch(k) is not None:
            print("키 중복 오류 발생")
            return
        
        # 충돌 발생 시 빈 자리를 찾을 때까지 반복
        while self.tbl[hv].status is s.SlotStatus.INUSE or self.tbl[hv].status is s.SlotStatus.DELETED:
            hv = hv + self.hash_func2(k)
        
        self.tbl[hv].value = v
        self.tbl[hv].key = k
        self.tbl[hv].status = s.SlotStatus.INUSE
    
    def TBLDelete(self, k):
        hv = self.hash_func1(k)

        # 충돌 발생 시 빈 자리를 찾을 때까지 반복
        while self.tbl[hv].status is s.SlotStatus.DELETED:
            hv = hv + self.hash_func2(k)
        
        if self.tbl[hv].status is not s.SlotStatus.INUSE:
            return None
        else:
            self.tbl[hv].status = s.SlotStatus.DELETED
            return self.tbl[hv].value
    
    def TBLSearch(self, k):
        hv = self.hash_func1(k)

        # 충돌 발생 시 빈 자리를 찾을 때까지 반복
        while self.tbl[hv].status is s.SlotStatus.DELETED:
            hv = hv + self.hash_func2(k)
        
        if self.tbl[hv].status is not s.SlotStatus.INUSE:
            return None
        else:
            return self.tbl[hv].value
