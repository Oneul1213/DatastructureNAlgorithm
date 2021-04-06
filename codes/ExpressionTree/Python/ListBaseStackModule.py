import sys

class Node:
    def __init__(self):
        self.data = None
        self.next = None

class ListStack:
    def __init__(self):
        self.head = None
    
    def SIsEmpty(self):
        if self.head is None:
            return True
        else:
            return False
    
    def SPush(self, data):
        newNode = Node()

        newNode.data = data
        newNode.next = self.head

        self.head = newNode

    def SPop(self):
        if self.SIsEmpty() is True:
            print("Stack Memory Error!")
            sys.exit(-1)
        
        rdata = self.head.data

        self.head = self.head.next

        return rdata
    
    def SPeek(self):
        if self.SIsEmpty() is True:
            print("Stack Memory Error!")
            sys.exit(-1)
        
        return self.head.data
