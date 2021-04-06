import HeapModule as hm

heap = hm.Heap(lambda ch1, ch2: ord(ch2)-ord(ch1))

heap.HInsert('A')
heap.HInsert('B')
heap.HInsert('C')
print(heap.HDelete())

heap.HInsert('A')
heap.HInsert('B')
heap.HInsert('C')
print(heap.HDelete())

while heap.HIsEmpty() is not True:
    print(heap.HDelete())
