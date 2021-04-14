import BinarySearchTreeModule as bstm

bstRoot = bstm.BinarySearchTree()

bstRoot.BSTInsert(5)
bstRoot.BSTInsert(8)
bstRoot.BSTInsert(1)
bstRoot.BSTInsert(6)
bstRoot.BSTInsert(4)
bstRoot.BSTInsert(9)
bstRoot.BSTInsert(3)
bstRoot.BSTInsert(7)
bstRoot.BSTInsert(2)

bstRoot.BSTShowAll()
print()
sNode = bstRoot.BSTRemove(3)

bstRoot.BSTShowAll()
print()
sNode = bstRoot.BSTRemove(8)

bstRoot.BSTShowAll()
print()
sNode = bstRoot.BSTRemove(1)

bstRoot.BSTShowAll()
print()
sNode = bstRoot.BSTRemove(6)

bstRoot.BSTShowAll()
print()
