#include <iostream>
#include "CircularLinkedListCpp.h"

template <typename T> CircularLinkedList<T>::CircularLinkedList() : tail(NULL), cur(NULL), before(NULL), numOfData(0)
{

}

template <typename T> void CircularLinkedList<T>::LInsertFront(T data)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	if (this->tail == NULL)
	{
		this->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = this->tail->next;
		this->tail->next = newNode;
	}
	(this->numOfData)++;
}

template <typename T> void CircularLinkedList<T>::LInsert(T data)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	if (this->tail == NULL)
	{
		this->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = this->tail->next;
		this->tail->next = newNode;
		this->tail = newNode;
	}
	(this->numOfData)++;
}

template <typename T> bool CircularLinkedList<T>::LFirst(T& data)
{
	if (this->tail == NULL)
		return false;

	this->before = this->tail;
	this->cur = this->tail->next;

	data = this->cur->data;
	return true;
}

template <typename T> bool CircularLinkedList<T>::LNext(T& data)
{
	if (this->tail == NULL)
		return false;

	this->before = this->cur;
	this->cur = this->cur->next;

	data = this->cur->data;
	return true;
}

template <typename T> T CircularLinkedList<T>::LRemove()
{
	Node<T>* rpos = this->cur;
	T rdata = rpos->data;

	if (rpos == this->tail)
	{
		if (this->tail == this->tail->next)
			this->tail = NULL;
		else
			this->tail = this->before;
	}

	this->before->next = this->cur->next;
	this->cur = this->before;

	free(rpos);
	(this->numOfData)--;
	return rdata;
}

template <typename T> int CircularLinkedList<T>::LCount()
{
	return this->numOfData;
}