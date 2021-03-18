class Node:
    def __init__(self):
        self.data = None
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = Node()
        self.cur = None
        self.before = None

        self.numOfData = 0
        
        self.comp = None
    
    def Finsert(self, data):
        newNode = Node()
        newNode.data = data

        newNode.next = self.head.next
        self.head.next = newNode

        self.numOfData += 1
    
    def SInsert(self, data):
        newNode = Node()
        pred = self.head

        newNode.data = data

        while pred.next != None and self.comp(data, pred.next.data) != 0:
            pred = pred.next
        
        newNode.next = pred.next
        pred.next = newNode

        self.numOfData += 1
    
    def LInsert(self, data):
        if self.comp == None:
            self.FInsert(data)
        else:
            self.SInsert(data)
    
    def LFirst(self):
        if self.head.next == None:
            return False, -1
        
        self.before = self.head
        self.cur = self.head.next

        return True, self.cur.data
    
    def LNext(self):
        if self.cur.next == None:
            return False, -1
        
        self.before = self.cur
        self.cur = self.cur.next

        return True, self.cur.data
    
    def LRemove(self):
        rpos = self.cur
        rdata = rpos.data

        self.before.next = self.cur.next
        self.cur = self.before

        self.numOfData -= 1
        return rdata
    
    def LCount(self):
        return self.numOfData
    
    def SetSortRule(self, comp):
        self.comp = comp
