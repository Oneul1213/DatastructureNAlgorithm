#ifndef __AB_STACK_CPP_H__
#define __AB_STACK_CPP_H__

#define STACK_LEN	100

template <typename T> class ArrayStack
{
private:
	T stackArr[STACK_LEN];
	int topIndex;
public:
	ArrayStack();
	bool SIsEmpty();

	void SPush(T data);
	T SPop();
	T SPeek();
};

#endif