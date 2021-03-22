#ifndef __CIRCURLAR_LINKED_LIST_CPP_H__
#define __CIRCURLAR_LINKED_LIST_CPP_H__

template <typename T> class Node
{
public:
	T data;
	Node<T>* next;
};

template <typename T> class CircularLinkedList
{
private:
	Node<T>* tail;
	Node<T>* cur;
	Node<T>* before;
	int numOfData;
public:
	CircularLinkedList();
	void LInsert(T data);
	void LInsertFront(T data);

	bool LFirst(T& data);
	bool LNext(T& data);

	T LRemove();
	int LCount();
};

#endif