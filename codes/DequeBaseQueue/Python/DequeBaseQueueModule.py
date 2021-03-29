import DequeModule as dm

class DBQueue:
    def __init__(self):
        self.deq = dm.Deque()
    
    def QIsEmpty(self):
        return self.deq.DQIsEmpty()
    
    def Enqueue(self, data):
        self.deq.DQAddLast(data)
    
    def Dequeue(self):
        return self.deq.DQRemoveFirst()
    
    def QPeek(self):
        return self.deq.DQGetFirst()
