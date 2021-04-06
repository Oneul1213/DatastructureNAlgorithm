package ExpressionTree;

public class ExpressionTree {
    private static void ShowNodeData(char data) {
        if ( 0 <= data - '0'  && data - '0' <= 9)
            System.out.print((data-'0')+" ");
        else
            System.out.print(data+" ");
    }

    public static BinaryTree2<Character> MakeExpTree(char[] exp) {
        ListStack<BinaryTree2<Character>> stack = new ListStack<BinaryTree2<Character>>();

        for (int i = 0; i < exp.length; i++) {
            BinaryTree2<Character> pnode = new BinaryTree2<Character>();

            if (Character.isDigit(exp[i])) {
                pnode.SetData(exp[i]);
            } else {
                pnode.MakeRightSubTree(stack.SPop());
                pnode.MakeLeftSubTree(stack.SPop());
                pnode.SetData(exp[i]);
            }

            stack.SPush(pnode);
        }

        return stack.SPop();
    }

    public static int EvaluateTree(BinaryTree2<Character> bt) {
        if (bt.GetLeftSubTree() == null && bt.GetRightSubTree() == null)
            return bt.GetData() - '0';

        int op1 = ExpressionTree.EvaluateTree(bt.GetLeftSubTree());
        int op2 = ExpressionTree.EvaluateTree(bt.GetRightSubTree());

        switch (bt.GetData()) {
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
        }

        return 0;
    }

    public static void ShowPrefixTypeExp(BinaryTree2<Character> bt) {
        bt.PreorderTraverse(ExpressionTree::ShowNodeData);
    }

    public static void ShowInfixTypeExp(BinaryTree2<Character> bt) {
        if (0 <= bt.GetData() - '0' && bt.GetData() - '0' <= 9) {
            ExpressionTree.ShowNodeData(bt.GetData());
        } else {
            System.out.print("( ");
            ExpressionTree.ShowInfixTypeExp(bt.GetLeftSubTree());
            ExpressionTree.ShowNodeData(bt.GetData());
            ExpressionTree.ShowInfixTypeExp(bt.GetRightSubTree());
            System.out.print(") ");
        }
    }

    public static void ShowPostfixTypeExp(BinaryTree2<Character> bt) {
        bt.PostorderTraverse(ExpressionTree::ShowNodeData);
    }
}
