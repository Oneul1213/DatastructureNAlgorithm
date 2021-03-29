import DequeModule as dm

deq = dm.Deque()

deq.DQAddFirst(3)
deq.DQAddFirst(2)
deq.DQAddFirst(1)

deq.DQAddLast(4)
deq.DQAddLast(5)
deq.DQAddLast(6)

while deq.DQIsEmpty() is False:
    print(deq.DQRemoveFirst(), end=' ')
print()

deq.DQAddFirst(3)
deq.DQAddFirst(2)
deq.DQAddFirst(1)

deq.DQAddLast(4)
deq.DQAddLast(5)
deq.DQAddLast(6)

while deq.DQIsEmpty() is False:
    print(deq.DQRemoveLast(), end=' ')
print()
