#ifndef __SINGLY_LINKED_LIST_CPP_H__
#define __SINGLY_LINKED_LIST_CPP_H__

#include<functional>

template <typename T> class Node
{
public:
	T data;
	Node<T>* next;
};

template <typename T> class SinglyLinkedList
{
private:
	Node<T>* head;
	Node<T>* cur;
	Node<T>* before;
	int numOfData;
	std::function<int(T, T)> comp;

	void FInsert(T data);
	void SInsert(T data);
public:
	SinglyLinkedList();
	void LInsert(T data);

	bool LFirst(T& data);
	bool LNext(T& data);

	T LRemove();
	int LCount();

	void SetSortRule(std::function<int(T, T)> comp);
};

#endif