#include <iostream>
#include "ArrayBaseStackCpp.h"
#include "ArrayBaseStackCpp.cpp"

int main(void)
{
	ArrayStack<int> stack;

	stack.SPush(1); stack.SPush(2);
	stack.SPush(3); stack.SPush(4);
	stack.SPush(5);

	if (!stack.SIsEmpty())
	{
		for (int i = 0; i < 3; i++)
			std::cout << stack.SPeek() << " ";
	}
	std::cout << std::endl << std::endl;

	while (!stack.SIsEmpty())
		std::cout << stack.SPop() << " ";
	std::cout << std::endl;

	return 0;
}