class Node:
    def __init__(self):
        self.data = None
        self.next = None

class CircularLinkedList:
    def __init__(self):
        self.tail = None
        self.cur = None
        self.before = None
        self.numOfData = 0
    
    def LInsert(self, data):
        newNode = Node()
        newNode.data = data

        if self.tail is None:
            self.tail = newNode
            newNode.next = newNode
        else:
            newNode.next = self.tail.next
            self.tail.next = newNode
            self.tail = newNode
        self.numOfData += 1
    
    def LInsertFront(self, data):
        newNode = Node()
        newNode.data = data

        if self.tail is None:
            self.tail = newNode
            newNode.next = newNode
        else:
            newNode.next = self.tail.next
            self.tail.next = newNode
        self.numOfData += 1
    
    def LFirst(self):
        if self.tail is None:
            return False, -1
        
        self.before = self.tail
        self.cur = self.tail.next

        return True, self.cur.data
    
    def LNext(self):
        if self.tail is None:
            return False, -1
        
        self.before = self.cur
        self.cur = self.cur.next

        return True, self.cur.data
    
    def LRemove(self):
        rpos = self.cur
        rdata = rpos.data

        if rpos == self.tail:
            if self.tail == self.tail.next:
                self.tail = None
            else:
                self.tail = self.before
        
        self.before.next = self.cur.next
        self.cur = self.before

        self.numOfData -= 1
        return rdata
    
    def LCount(self):
        return self.numOfData
