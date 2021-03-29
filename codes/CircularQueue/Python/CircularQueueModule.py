import sys

class CircularQueue:
    def __init__(self):
        self.QUE_LEN = 100

        self.front = 0
        self.rear = 0
        self.queArr = []
        self.queArr.append(0)
    
    def NextPosIdx(self, pos):
        if pos is self.QUE_LEN - 1:
            return 0
        else:
            return pos + 1
    
    def QIsEmpty(self):
        if self.front is self.rear:
            return True
        else:
            return False
    
    def Enqueue(self, data):
        if self.NextPosIdx(self.rear) is self.front:
            print("Queue Memory Error!")
            sys.exit(-1)
        
        self.rear = self.NextPosIdx(self.rear)
        self.queArr.append(data)

    def Dequeue(self):
        if self.QIsEmpty():
            print("Queue Memory Error!")
            sys.exit(-1)
        
        self.front = self.NextPosIdx(self.front)
        return self.queArr[self.front]
    
    def QPeek(self):
        if self.QIsEmpty():
            print("Queue Memory Error!")
            sys.exit(-1)
        
        return self.queArr[self.NextPosIdx(self.front)]
