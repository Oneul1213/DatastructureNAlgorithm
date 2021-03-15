class ArrayList:
    def __init__(self):
        self.arr = []
        self.numOfData = 0
        self.curPosition = -1
    
    def LInsert(self, data):
        self.arr.append(data)
        self.numOfData += 1
    
    def LFirst(self):
        if self.numOfData == 0:
            return False, -1
        
        self.curPosition = 0
        return True, self.arr[0]
    
    def LNext(self):
        if self.curPosition >= self.numOfData-1:
            return False, -1
        
        self.curPosition += 1
        return True, self.arr[self.curPosition]
    
    def LRemove(self):
        rpos = self.curPosition
        num = self.numOfData
        rdata = self.arr[rpos]

        for i in range(rpos, num-1):
            self.arr[i] = self.arr[i+1]
        
        self.numOfData -= 1
        self.curPosition -= 1
        return rdata
    
    def LCount(self):
        return self.numOfData
