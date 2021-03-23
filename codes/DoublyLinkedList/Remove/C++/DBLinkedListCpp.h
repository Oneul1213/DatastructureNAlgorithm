#ifndef __DB_LINKED_LIST_CPP_H__
#define __DB_LINKED_LIST_CPP_H__

template <typename T> class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T> class DoublyLinkedList
{
private:
	Node<T>* head;
	Node<T>* before;
	Node<T>* cur;
	Node<T>* after;
	int numOfData;
public:
	DoublyLinkedList();
	void LInsert(T data);

	bool LFirst(T& data);
	bool LNext(T& pdata);
	bool LPrevious(T& pdata);

	T LRemove();
	int LCount();
};

#endif