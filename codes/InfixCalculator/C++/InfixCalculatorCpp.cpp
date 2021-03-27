#include <cstring>
#include <cstdlib>
#include "InfixToPostfixCpp.h"
#include "PostCalculatorCpp.h"
#include "InfixCalculatorCpp.h"

int InfixCalculator::EvalInfixExp(char exp[])
{
	int len = strlen(exp);
	int ret;
	char* expcpy = (char*)malloc(len + 1);
	strcpy(expcpy, exp);

	RPNConverter::ConvToRPNExp(expcpy);
	ret = PostCalculator::EvalRPNExp(expcpy);

	free(expcpy);
	return ret;
}