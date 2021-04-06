import PriorityQueueModule as pqm

pq = pqm.PriorityQueue(lambda ch1, ch2: ord(ch2)-ord(ch1))

pq.PEnqueue('A')
pq.PEnqueue('B')
pq.PEnqueue('C')
print(pq.PDequeue())

pq.PEnqueue('A')
pq.PEnqueue('B')
pq.PEnqueue('C')
print(pq.PDequeue())

while pq.PQIsEmpty() is not True:
    print(pq.PDequeue())
