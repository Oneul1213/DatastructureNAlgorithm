#include <iostream>
#include "ExpressionTreeCpp.h"

int main(void)
{
	char exp[] = "12+7*";
	BinaryTree<char>* eTree = ExpressionTree<char>::MakeExpTree(exp);

	std::cout << "���� ǥ��� ����: ";
	ExpressionTree<char>::ShowPrefixTypeExp(eTree);
	std::cout << std::endl;

	std::cout << "���� ǥ��� ����: ";
	ExpressionTree<char>::ShowInfixTypeExp(eTree);
	std::cout << std::endl;

	std::cout << "���� ǥ��� ����: ";
	ExpressionTree<char>::ShowPostfixTypeExp(eTree);
	std::cout << std::endl;

	std::cout << "������ ���: " << ExpressionTree<char>::EvaluateTree(eTree) << std::endl;

	return 0;
}