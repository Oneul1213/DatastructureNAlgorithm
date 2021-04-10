#include <iostream>
#include "ListBaseQueueCpp.h"

template <typename T> ListQueue<T>::ListQueue() : front(NULL), rear(NULL)
{

}

template <typename T> bool ListQueue<T>::QIsEmpty()
{
	if (this->front == NULL)
		return true;
	else
		return false;
}

template <typename T> void ListQueue<T>::Enqueue(T data)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = data;
	newNode->next = NULL;

	if (this->QIsEmpty())
	{
		this->front = newNode;
		this->rear = newNode;
	}
	else
	{
		this->rear->next = newNode;
		this->rear = newNode;
	}
}

template <typename T> T ListQueue<T>::Dequeue()
{
	Node<T>* delNode;
	T retData;

	if (this->QIsEmpty())
	{
		std::cout << "Queue Memory Error!" << std::endl;
		exit(-1);
	}

	delNode = this->front;
	retData = delNode->data;
	this->front = this->front->next;

	free(delNode);
	return retData;
}

template <typename T> T ListQueue<T>::QPeek()
{
	if (this->QIsEmpty())
	{
		std::cout << "Queue Memory Error!" << std::endl;
		exit(-1);
	}

	return this->front->data;
}