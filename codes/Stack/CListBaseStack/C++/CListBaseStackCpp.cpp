#include <iostream>
#include "CListBaseStackCpp.h"

template <typename T> bool CListStack<T>::SIsEmpty()
{
	if (this->list.LCount() == 0)
		return true;
	else
		return false;
}

template <typename T> void CListStack<T>::SPush(T data)
{
	this->list.LInsertFront(data);
}

template <typename T> T CListStack<T>::SPop()
{
	T data;

	if (this->SIsEmpty())
	{
		std::cout << "Stack Memory Error!";
		exit(-1);
	}

	this->list.LFirst(data);
	return this->list.LRemove();
}

template <typename T> T CListStack<T>::SPeek()
{
	T data;

	if (this->SIsEmpty())
	{
		std::cout << "Stack Memory Error!";
		exit(-1);
	}

	this->list.LFirst(data);
	return data;
}