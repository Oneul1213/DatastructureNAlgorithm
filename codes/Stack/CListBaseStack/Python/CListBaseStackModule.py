import CircularLinkedListModule as clm

class CListStack:
    def __init__(self):
        self.list = clm.CircularLinkedList()
    
    def SIsEmpty(self):
        if self.list.LCount() is 0:
            return True
        else:
            return False
    
    def SPush(self, data):
        self.list.LInsertFront(data)
    
    def SPop(self):
        if self.SIsEmpty() is True:
            print("Stack Memory Error!")
            sys.exit(-1)
        
        data = self.list.LFirst()
        return self.list.LRemove()
    
    def SPeek(self):
        if self.SIsEmpty() is True:
            print("Stack Memory Error!")
            sys.exit(-1)
        
        data = self.list.LFirst()
        return data[1]
