package ExpressionTree;

public class ExpressionTreeMain {
    public static void main(String[] args) {
        char exp[] = "12+7*".toCharArray();
        BinaryTree2<Character> eTree = ExpressionTree.MakeExpTree(exp);

        System.out.print("전위 표기법 수식: ");
        ExpressionTree.ShowPrefixTypeExp(eTree);
        System.out.println();

        System.out.print("중위 표기법 수식: ");
        ExpressionTree.ShowInfixTypeExp(eTree);
        System.out.println();

        System.out.print("후위 표기법 수식: ");
        ExpressionTree.ShowPostfixTypeExp(eTree);
        System.out.println();

        System.out.println("연산의 결과: "+ExpressionTree.EvaluateTree(eTree));
    }
}
