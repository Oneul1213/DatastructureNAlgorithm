class ArrayStack:
    def __init__(self):
        self.stackArr = []
        self.topIndex = -1
    
    def SIsEmpty(self):
        if self.topIndex is -1:
            return True
        else:
            return False
    
    def SPush(self, data):
        self.topIndex += 1
        self.stackArr.append(data)
    
    def SPop(self):
        if self.SIsEmpty() is True:
            print("Stack Memory Error!")
            sys.exit(-1)
        
        self.topIndex -= 1

        return self.stackArr.pop()
    
    def SPeek(self):
        if self.SIsEmpty() is True:
            print("Stack Memory Error!")
            sys.exit(-1)
        
        return self.stackArr[self.topIndex]
