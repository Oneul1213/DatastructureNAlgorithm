#include <iostream>
#include "PostCalculatorCpp.h"

int main(void)
{
	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	std::cout << postExp1 << " = " << PostCalculator::EvalRPNExp(postExp1) << std::endl;
	std::cout << postExp2 << " = " << PostCalculator::EvalRPNExp(postExp2) << std::endl;
	
	return 0;
}