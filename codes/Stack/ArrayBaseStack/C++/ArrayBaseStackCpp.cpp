#include <iostream>
#include "ArrayBaseStackCpp.h"

template <typename T> ArrayStack<T>::ArrayStack() : stackArr{ 0 }, topIndex(-1)
{
	
}

template <typename T> bool ArrayStack<T>::SIsEmpty()
{
	if (this->topIndex == -1)
		return true;
	else
		return false;
}

template <typename T> void ArrayStack<T>::SPush(T data)
{
	this->topIndex += 1;
	this->stackArr[this->topIndex] = data;
}

template <typename T> T ArrayStack<T>::SPop()
{
	int rIdx;

	if (this->SIsEmpty())
	{
		std::cout << "Stack Memory Error!";
		exit(-1);
	}

	rIdx = this->topIndex;
	this->topIndex -= 1;

	return this->stackArr[rIdx];
}

template <typename T> T ArrayStack<T>::SPeek()
{
	if (this->SIsEmpty())
	{
		std::cout << "Stack Memory Error!";
		exit(-1);
	}

	return this->stackArr[this->topIndex];
}