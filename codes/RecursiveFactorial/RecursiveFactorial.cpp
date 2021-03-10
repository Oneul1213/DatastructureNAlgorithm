#include <iostream>

int Factorial(int n)
{
	if (n == 0)
		return 1;
	else
		return n * Factorial(n - 1);
}

int main(void)
{
	std::cout << "1! = " << Factorial(1) << std::endl;
	std::cout << "2! = " << Factorial(2) << std::endl;
	std::cout << "3! = " << Factorial(3) << std::endl;
	std::cout << "4! = " << Factorial(4) << std::endl;
	std::cout << "9! = " << Factorial(9) << std::endl;
	return 0;
}