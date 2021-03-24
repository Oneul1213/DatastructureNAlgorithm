#ifndef __C_LIST_BASE_STACK_CPP_H__
#define __C_LIST_BASE_STACK_CPP_H__

#include "CircularLinkedListCpp.h"
#include "CircularLinkedListCpp.cpp"

template <typename T> class CListStack
{
private:
	CircularLinkedList<T> list;
public:
	bool SIsEmpty();

	void SPush(T data);
	T SPop();
	T SPeek();
};

#endif