#include <cstring>
#include <cctype>
#include "ListBaseStackCpp.h"
#include "ListBaseStackCpp.cpp"
#include "PostCalculatorCpp.h"

int PostCalculator::EvalRPNExp(char exp[])
{
	ListStack<char> stack;
	int expLen = strlen(exp);
	char tok, op1, op2;

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];

		if (isdigit(tok))
		{
			stack.SPush(tok - '0');
		}
		else
		{
			op2 = stack.SPop();
			op1 = stack.SPop();

			switch (tok)
			{
			case '+':
				stack.SPush(op1 + op2);
				break;
			case '-':
				stack.SPush(op1 - op2);
				break;
			case '*':
				stack.SPush(op1 * op2);
				break;
			case '/':
				stack.SPush(op1 / op2);
				break;
			}
		}
	}
	return stack.SPop();
}