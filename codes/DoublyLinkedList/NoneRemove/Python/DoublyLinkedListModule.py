class Node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.before = None
        self.cur = None
        self.after = None
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
        self.before = self.cur.prev
        self.after = self.cur.next

        return True, self.cur.data
    
    def LNext(self):
        if self.after is None:
            return False, -1
        
        if self.cur is None:
            self.cur = self.before

        self.cur = self.cur.next
        self.before = self.cur.prev
        self.after = self.cur.next

        return True, self.cur.data
    
    def LPrevious(self):
        if self.before is None:
            return False, -1
        
        if self.cur is None:
            self.cur = self.after

        self.cur = self.cur.prev
        self.before = self.cur.prev
        self.after = self.cur.next

        return True, self.cur.data
    
    def LRemove(self):
        rpos = self.cur
        rdata = rpos.data

        if self.cur is self.head and self.after is None:    # 마지막 노드인 head를 삭제
            self.head = None
        elif self.cur is self.head:                         # 마지막 노드가 아닌 head를 삭제
            self.after.prev = None
            self.head = self.after
            self.before = self.head
        elif self.after is None:                            # 마지막 노드를 삭제
            self.before.next = None
            self.after = self.before
        else:
            self.before.next = self.after
            self.after.prev = self.before
        
        self.cur = None
        self.numOfData -= 1
        return rdata

    def LCount(self):
        return self.numOfData
