#include <cstring>
#include <cstdlib>
#include <cctype>
#include "ListBaseStackCpp.h"
#include "ListBaseStackCpp.cpp"
#include "InfixToPostfixCpp.h"

int RPNConverter::GetOpPrec(char op)
{
	switch (op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}

	return -1;
}

int RPNConverter::WhoPrecOp(char op1, char op2)
{
	int op1Prec = RPNConverter::GetOpPrec(op1);
	int op2Prec = RPNConverter::GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void RPNConverter::ConvToRPNExp(char exp[])
{
	ListStack<char> stack;
	int expLen = strlen(exp);
	char* convExp = (char*)malloc(expLen + 1);

	int idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1);
	
	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i];
		if (isdigit(tok))
		{
			convExp[idx++] = tok;
		}
		else
		{
			switch (tok)
			{
			case '(':
				stack.SPush(tok);
				break;

			case')':
				while (1)
				{
					popOp = stack.SPop();
					if (popOp == '(')
						break;
					convExp[idx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while (!stack.SIsEmpty() && RPNConverter::WhoPrecOp(stack.SPeek(), tok) >= 0)
					convExp[idx++] = stack.SPop();

				stack.SPush(tok);
				break;
			}
		}
	}

	while (!stack.SIsEmpty())
		convExp[idx++] = stack.SPop();

	strcpy(exp, convExp);
	free(convExp);
}