import BinaryTree2Module as b2m
import ListBaseStackModule as lsm

class ExpressionTree:
    @classmethod
    def ShowNodeData(cls, data):
        print(data, end=' ')
    
    @classmethod
    def MakeExpTree(cls, exp):
        stack = lsm.ListStack()

        for i in range(len(exp)):
            pnode = b2m.BinaryTree()

            if (exp[i].isdigit()):
                pnode.SetData(exp[i])
            else:
                pnode.MakeRightSubTree(stack.SPop())
                pnode.MakeLeftSubTree(stack.SPop())
                pnode.SetData(exp[i])
            
            stack.SPush(pnode)
        
        return stack.SPop()
    
    @classmethod
    def EvaluateTree(cls, bt):
        if (bt.GetLeftSubTree() is None and bt.GetRightSubTree() is None):
            return bt.GetData()
        
        op1 = int(ExpressionTree.EvaluateTree(bt.GetLeftSubTree()))
        op2 = int(ExpressionTree.EvaluateTree(bt.GetRightSubTree()))

        if bt.GetData() is '+':
            return op1 + op2
        elif bt.GetData() is '-':
            return op1 - op2
        elif bt.GetData() is '*':
            return op1 * op2
        elif bt.GetData() is '/':
            return op1 / op2

        return 0

    @classmethod
    def ShowPrefixTypeExp(cls, bt):
        bt.PreorderTraverse(ExpressionTree.ShowNodeData)

    @classmethod
    def ShowInfixTypeExp(cls, bt):
        if (bt.GetData().isdigit()):
            ExpressionTree.ShowNodeData(bt.GetData())
        else:
            print("( ", end='')
            ExpressionTree.ShowInfixTypeExp(bt.GetLeftSubTree())
            ExpressionTree.ShowNodeData(bt.GetData())
            ExpressionTree.ShowInfixTypeExp(bt.GetRightSubTree())
            print(") ", end='')

    @classmethod
    def ShowPostfixTypeExp(cls, bt):
        bt.PostorderTraverse(ExpressionTree.ShowNodeData)
 