import BinaryTree2Module as b2m

bt1 = b2m.BinaryTree()
bt2 = b2m.BinaryTree()
bt3 = b2m.BinaryTree()
bt4 = b2m.BinaryTree()
bt5 = b2m.BinaryTree()
bt6 = b2m.BinaryTree()

bt1.SetData(1)
bt2.SetData(2)
bt3.SetData(3)
bt4.SetData(4)
bt5.SetData(5)
bt6.SetData(6)

bt1.MakeLeftSubTree(bt2)
bt1.MakeRightSubTree(bt3)
bt2.MakeLeftSubTree(bt4)
bt2.MakeRightSubTree(bt5)
bt3.MakeRightSubTree(bt6)

bt1.PreorderTraverse(lambda x: print(x, end=' '))
print()
bt1.InorderTraverse(lambda x: print(x, end=' '))
print()
bt1.PostorderTraverse(lambda x: print(x, end=' '))
print()

