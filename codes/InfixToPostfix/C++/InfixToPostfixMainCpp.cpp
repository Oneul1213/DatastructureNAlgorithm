#include <iostream>
#include "InfixToPostfixCpp.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	RPNConverter::ConvToRPNExp(exp1);
	RPNConverter::ConvToRPNExp(exp2);
	RPNConverter::ConvToRPNExp(exp3);

	std::cout << exp1 << std::endl;
	std::cout << exp2 << std::endl;
	std::cout << exp3 << std::endl;
	return 0;
}