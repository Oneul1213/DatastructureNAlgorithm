#include <iostream>
#include "ListBaseStackCpp.h"

template <typename T> ListStack<T>::ListStack() : head(NULL)
{

}

template <typename T> bool ListStack<T>::SIsEmpty()
{
	if (this->head == NULL)
		return true;
	else
		return false;
}

template <typename T> void ListStack<T>::SPush(T data)
{
	Node<T>* newNode = new Node<T>();

	newNode->data = data;
	newNode->next = this->head;

	this->head = newNode;
}

template <typename T> T ListStack<T>::SPop()
{
	T rdata;
	Node<T>* rnode = new Node<T>();

	if (this->SIsEmpty())
	{
		std::cout << "Stack Memory Error!";
		exit(-1);
	}

	rdata = this->head->data;
	rnode = this->head;

	this->head = this->head->next;
	delete(rnode);

	return rdata;
}

template <typename T> T ListStack<T>::SPeek()
{
	if (this->SIsEmpty())
	{
		std::cout << "Stack Memory Error!";
		exit(-1);
	}

	return this->head->data;
}