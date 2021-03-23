class Node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

class DbDLinkedList:
    def __init__(self):
        self.cur = None
        self.numOfData = 0

        hDummyNode = Node()
        tDummyNode = Node()

        self.head = hDummyNode
        self.tail = tDummyNode

        self.head.next = self.tail
        self.tail.prev = self.head

    def LInsert(self, data):
        newNode = Node()
        newNode.data = data

        newNode.prev = self.tail.prev
        newNode.next = self.tail

        self.tail.prev.next = newNode
        self.tail.prev = newNode

        self.numOfData += 1
    
    def LFirst(self):
        if self.tail.prev is self.head:
            return False, -1
        
        self.cur = self.head.next
        
        return True, self.cur.data
    
    def LNext(self):
        if self.cur.next is self.tail:
            return False, -1
        
        self.cur = self.cur.next

        return True, self.cur.data
    
    def LRemove(self):
        rpos = self.cur
        rdata = rpos.data

        self.cur.prev.next = self.cur.next
        self.cur.next.prev = self.cur.prev

        self.cur = self.cur.prev
        self.numOfData -= 1

        return rdata
    
    def LCount(self):
        return self.numOfData
