class Heap:
    def __init__(self, comp):
        self.comp = comp
        self.numOfData = 0
        self.heapArr = [None for i in range(100)]
    
    def GetParentIDX(self, idx):
        return idx // 2
    
    def GetLChildIDX(self, idx):
        return idx * 2
    
    def GetRChildIDX(self, idx):
        return self.GetLChildIDX(idx) + 1
    
    def GetHiPriChildIDx(self, idx):
        if self.GetLChildIDX(idx) > self.numOfData:
            return 0
        elif self.GetLChildIDX(idx) is self.numOfData:
            return self.GetLChildIDX(idx)
        else:
            if self.comp(self.heapArr[self.GetLChildIDX(idx)], self.heapArr[self.GetRChildIDX(idx)]) < 0:
                return self.GetRChildIDX(idx)
            else:
                return self.GetLChildIDX(idx)
    
    def HIsEmpty(self):
        if self.numOfData is 0:
            return True
        else:
            return False
    
    def HInsert(self, data):
        idx = self.numOfData + 1

        while idx is not 1:
            if self.comp(data, self.heapArr[self.GetParentIDX(idx)]) > 0:
                self.heapArr[idx] = self.heapArr[self.GetParentIDX(idx)]
                idx = self.GetParentIDX(idx)
            else:
                break
        
        self.heapArr[idx] = data
        self.numOfData += 1
    
    def HDelete(self):
        retData = self.heapArr[1]
        lastElem = self.heapArr[self.numOfData]

        parentIdx = 1

        while self.GetHiPriChildIDx(parentIdx) is not 0:
            childIdx = self.GetHiPriChildIDx(parentIdx)

            if self.comp(lastElem, self.heapArr[childIdx]) >= 0:
                break
            
            self.heapArr[parentIdx] = self.heapArr[childIdx]
            parentIdx = childIdx
        
        self.heapArr[parentIdx] = lastElem
        self.numOfData -= 1
        return retData
