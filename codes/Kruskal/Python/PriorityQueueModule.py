import HeapModule as hm

class PriorityQueue:
    def __init__(self, pc):
        self.heap = hm.Heap(pc)
    
    def PQIsEmpty(self):
        return self.heap.HIsEmpty()
    
    def PEnqueue(self, data):
        self.heap.HInsert(data)
    
    def PDequeue(self):
        return self.heap.HDelete()
