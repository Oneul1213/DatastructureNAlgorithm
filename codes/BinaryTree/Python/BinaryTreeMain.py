import BinaryTreeModule as bm

bt1 = bm.BinaryTree()
bt2 = bm.BinaryTree()
bt3 = bm.BinaryTree()
bt4 = bm.BinaryTree()

bt1.SetData(1)
bt2.SetData(2)
bt3.SetData(3)
bt4.SetData(4)

bt1.MakeLeftSubTree(bt2)
bt1.MakeRightSubTree(bt3)
bt2.MakeLeftSubTree(bt4)

print(bt1.GetLeftSubTree().GetData())
print(bt1.GetLeftSubTree().GetLeftSubTree().GetData())
