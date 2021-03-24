#ifndef __LB_STACK_CPP_H__
#define __LB_STACK_CPP_H__

template <typename T> class Node
{
public:
	T data;
	Node<T>* next;
};

template <typename T> class ListStack
{
private:
	Node<T>* head;
public:
	ListStack();
	bool SIsEmpty();

	void SPush(T data);
	T SPop();
	T SPeek();
};

#endif