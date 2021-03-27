#include <iostream>
#include "InfixCalculatorCpp.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";

	std::cout << exp1 << " = " << InfixCalculator::EvalInfixExp(exp1) << std::endl;
	std::cout << exp2 << " = " << InfixCalculator::EvalInfixExp(exp2) << std::endl;
	std::cout << exp3 << " = " << InfixCalculator::EvalInfixExp(exp3) << std::endl;
	return 0;
}