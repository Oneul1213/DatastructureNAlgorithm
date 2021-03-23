#include <iostream>
#include "DBLinkedListCpp.h"

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() : head(NULL), cur(NULL), numOfData(0)
{

}

template <typename T> void DoublyLinkedList<T>::LInsert(T data)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	newNode->next = this->head;
	if (this->head != NULL)
		this->head->prev = newNode;

	newNode->prev = NULL;
	this->head = newNode;

	(this->numOfData)++;
}

template <typename T> bool DoublyLinkedList<T>::LFirst(T& data)
{
	if (this->head == NULL)
		return false;

	this->cur = this->head;
	data = this->cur->data;

	return true;
}

template <typename T> bool DoublyLinkedList<T>::LNext(T& data)
{
	if (this->cur->next == NULL)
		return false;

	this->cur = this->cur->next;
	data = this->cur->data;

	return true;
}

template <typename T> bool DoublyLinkedList<T>::LPrevious(T& data)
{
	if (this->cur->prev == NULL)
		return false;

	this->cur = this->cur->prev;
	data = this->cur->data;

	return true;
}

template <typename T> int DoublyLinkedList<T>::LCount()
{
	return this->numOfData;
}