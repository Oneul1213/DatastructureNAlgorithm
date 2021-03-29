#pragma once

template <typename T> class Node
{
public:
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template <typename T> class Deque
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	Deque();
	bool DQIsEmpty();

	void DQAddFirst(T data);
	void DQAddLast(T data);

	T DQRemoveFirst();
	T DQRemoveLast();

	T DQGetFirst();
	T DQGetLast();
};