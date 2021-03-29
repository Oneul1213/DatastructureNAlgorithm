#pragma once

template <typename T> class Node
{
public:
	T data;
	Node<T>* next;
};

template <typename T> class ListQueue
{
private:
	Node<T>* front;
	Node<T>* rear;
public:
	ListQueue();
	bool QIsEmpty();

	void Enqueue(T data);
	T Dequeue();
	T QPeek();
};