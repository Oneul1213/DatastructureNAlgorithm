#include <iostream>
#include "ExpressionTreeCpp.h"

int main(void)
{
	char exp[] = "12+7*";
	BinaryTree<char>* eTree = ExpressionTree<char>::MakeExpTree(exp);

	std::cout << "전위 표기법 수식: ";
	ExpressionTree<char>::ShowPrefixTypeExp(eTree);
	std::cout << std::endl;

	std::cout << "중위 표기법 수식: ";
	ExpressionTree<char>::ShowInfixTypeExp(eTree);
	std::cout << std::endl;

	std::cout << "후위 표기법 수식: ";
	ExpressionTree<char>::ShowPostfixTypeExp(eTree);
	std::cout << std::endl;

	std::cout << "연산의 결과: " << ExpressionTree<char>::EvaluateTree(eTree) << std::endl;

	return 0;
}