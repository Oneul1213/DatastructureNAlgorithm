import sys

class Node:
    def __init__(self):
        self.data = None
        self.next = None

class ListQueue:
    def __init__(self):
        self.front = None
        self.rear = None
    
    def QIsEmpty(self):
        if self.front is None:
            return True
        else:
            return False
    
    def Enqueue(self, data):
        newNode = Node()
        newNode.data = data
        newNode.next = None

        if self.QIsEmpty() is True:
            self.front = newNode
        else:
            self.rear.next = newNode
        
        self.rear = newNode
    
    def Dequeue(self):
        if self.QIsEmpty() is True:
            print("Queue Memory Error!")
            sys.exit(-1)
        
        delNode = self.front
        retData = delNode.data
        self.front = self.front.next

        return retData
    
    def QPeek(self):
        if self.QIsEmpty() is True:
            print("Queue Memory Error!")
            sys.exit(-1)
        
        return self.front.data
