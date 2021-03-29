import sys

class Node:
    def __init__(self):
        self.data = None
        self.next = None
        self.prev = None

class Deque:
    def __init__(self):
        self.head = None
        self.tail = None
    
    def DQIsEmpty(self):
        if self.head is None:
            return True
        else:
            return False
    
    def DQAddFirst(self, data):
        newNode = Node()
        newNode.data = data

        if self.DQIsEmpty() is True:
            self.tail = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
        self.head = newNode
    
    def DQAddLast(self, data):
        newNode = Node()
        newNode.data = data

        if self.tail is None:
            self.head = newNode
        else:
            newNode.prev = self.tail
            self.tail.next = newNode
        self.tail = newNode
    
    def DQRemoveFirst(self):
        delNode = self.head
        retData = delNode.data

        if self.DQIsEmpty() is True:
            print("Deque Memory Error!")
            sys.exit(-1)
        
        if self.head is self.tail:
            self.head = None
            self.tail = None
        else:
            self.head = delNode.next
            self.head.prev = None
        
        return retData
    
    def DQRemoveLast(self):
        delNode = self.tail
        retData = delNode.data

        if self.DQIsEmpty() is True:
            print("Deque Memory Error!")
            sys.exit(-1)
        
        if self.head is self.tail:
            self.head = None
            self.tail = None
        else:
            self.tail = delNode.prev
            self.tail.next = None
        
        return retData
    
    def DQGetFirst(self):
        if self.DQIsEmpty() is True:
            print("Deque Memory Error!")
            sys.exit(-1)
        
        return self.head.data
    
    def DQGetLast(self):
        if self.DQIsEmpty() is True:
            print("Deque Memory Error!")
            sys.exit(-1)
        
        return self.tail.data
