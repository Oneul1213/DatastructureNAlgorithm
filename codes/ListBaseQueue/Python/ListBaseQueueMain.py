import ListQueueModule as lqm

q = lqm.ListQueue()

for i in range(5):
    q.Enqueue(i+1)

while q.QIsEmpty() is False:
    print(q.Dequeue(), end=' ')
