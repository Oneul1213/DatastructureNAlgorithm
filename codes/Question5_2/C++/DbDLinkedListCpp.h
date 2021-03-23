#ifndef __DB_D_LINKED_LIST_H__
#define __DB_D_LINKED_LIST_H__

template <typename T> class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T> class DbDLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
	Node<T>* cur;
	int numOfData;
public:
	DbDLinkedList();
	void LInsert(T data);

	bool LFirst(T& data);
	bool LNext(T& data);

	T LRemove();
	int LCount();
};

#endif