#pragma once

#include <iostream>
#include <cstring>
#include <cctype>
#include "ListBaseStackCpp.h"
#include "ListBaseStackCpp.cpp"
#include "BinaryTree2Cpp.h"
#include "BinaryTree2Cpp.cpp"

template <typename T> class ExpressionTree
{
private:
	static void ShowNodeData(T data)
	{
		if (0 <= (int)data && (int)data <= 9)
			std::cout << (int)data << " ";
		else
			std::cout << data << " ";
	}
public:
	static BinaryTree<T>* MakeExpTree(char exp[])
	{
		ListStack<BinaryTree<char>*> stack;
		BinaryTree<char>* pnode;

		int expLen = strlen(exp);

		for (int i = 0; i < expLen; i++)
		{
			pnode = new BinaryTree<char>();

			if (isdigit(exp[i]))
			{
				pnode->SetData(exp[i]);
			}
			else
			{
				pnode->MakeRightSubTree(stack.SPop());
				pnode->MakeLeftSubTree(stack.SPop());
				pnode->SetData(exp[i]);
			}

			stack.SPush(pnode);
		}

		return stack.SPop();
	}

	static int EvaluateTree(BinaryTree<T>* bt)
	{
		int op1, op2;

		if (bt->GetLeftSubTree() == NULL && bt->GetRightSubTree() == NULL)
			return bt->GetData() - '0';

		op1 = ExpressionTree<T>::EvaluateTree(bt->GetLeftSubTree());
		op2 = ExpressionTree<T>::EvaluateTree(bt->GetRightSubTree());

		switch (bt->GetData())
		{
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
	static void ShowPrefixTypeExp(BinaryTree<T>* bt)
	{
		bt->PreorderTraverse(ExpressionTree<T>::ShowNodeData);
	}

	static void ShowInfixTypeExp(BinaryTree<T>* bt)
	{
		if (0 <= bt->GetData() - '0' && bt->GetData() - '0' <= 9)
		{
			ExpressionTree<T>::ShowNodeData(bt->GetData() - '0');
		}
		else
		{
			std::cout << "( ";
			ExpressionTree<T>::ShowInfixTypeExp(bt->GetLeftSubTree());
			ExpressionTree<T>::ShowNodeData(bt->GetData());
			ExpressionTree<T>::ShowInfixTypeExp(bt->GetRightSubTree());
			std::cout << ") ";
		}
	}
	static void ShowPostfixTypeExp(BinaryTree<T>* bt)
	{
		bt->PostorderTraverse(ExpressionTree<T>::ShowNodeData);
	}
};