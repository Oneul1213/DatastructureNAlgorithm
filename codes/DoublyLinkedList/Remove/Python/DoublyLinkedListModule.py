class Node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.cur = None
        self.numOfData = 0
    
    def LInsert(self, data):
        newNode = Node()
        newNode.data = data

        newNode.next = self.head
        if self.head is not None:
            self.head.prev = newNode
        
        newNode.prev = None
        self.head = newNode
    
    def LFirst(self):
        if self.head is None:
            return False, -1
        
        self.cur = self.head

        return True, self.cur.data
    
    def LNext(self):
        if self.cur.next is None:
            return False, -1
        
        self.cur = self.cur.next

        return True, self.cur.data
    
    def LPrevious(self):
        if self.cur.prev is None:
            return False, -1
        
        self.cur = self.cur.prev

        return True, self.cur.data
    
    def LCount(self):
        return self.numOfData
