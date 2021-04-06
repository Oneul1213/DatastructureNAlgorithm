import BinaryTree2Module as b2m
import ExpressionTreeModule as etm

exp = "12+7*"
eTree = etm.ExpressionTree.MakeExpTree(exp)

print("전위 표기법 수식: ", end='')
etm.ExpressionTree.ShowPrefixTypeExp(eTree)
print()

print("중위 표기법 수식: ", end='')
etm.ExpressionTree.ShowInfixTypeExp(eTree)
print()

print("후위 표기법 수식: ", end='')
etm.ExpressionTree.ShowPostfixTypeExp(eTree)
print()

print("연산의 결과: {}".format(etm.ExpressionTree.EvaluateTree(eTree)))
