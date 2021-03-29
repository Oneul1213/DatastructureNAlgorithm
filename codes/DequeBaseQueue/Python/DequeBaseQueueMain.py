import DequeBaseQueueModule as dqm

q = dqm.DBQueue()

for i in range(5):
    q.Enqueue(i+1)

while q.QIsEmpty() is False:
    print(q.Dequeue(), end=' ')
