#include <iostream>
#include "DbDLinkedListCpp.h"

template <typename T> DbDLinkedList<T>::DbDLinkedList() : head(NULL), tail(NULL), cur(NULL), numOfData(0)
{
	Node<T>* hDummyNode = new Node<T>();
	Node<T>* tDummyNode = new Node<T>();

	this->head = hDummyNode;
	this->tail = tDummyNode;

	this->head->next = this->tail;
	this->tail->prev = this->head;
}

template <typename T> void DbDLinkedList<T>::LInsert(T data)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	newNode->prev = this->tail->prev;
	newNode->next = this->tail;

	this->tail->prev->next = newNode;
	this->tail->prev = newNode;

	(this->numOfData)++;
}

template <typename T> bool DbDLinkedList<T>::LFirst(T& data)
{
	if (this->tail->prev == this->head)
		return false;

	this->cur = this->head->next;
	data = this->cur->data;

	return true;
}

template <typename T> bool DbDLinkedList<T>::LNext(T& data)
{
	if (this->cur->next == this->tail)
		return false;

	this->cur = this->cur->next;
	data = this->cur->data;

	return true;
}

template <typename T> T DbDLinkedList<T>::LRemove()
{
	Node<T>* rpos = this->cur;
	T rdata = this->cur->data;

	this->cur->prev->next = this->cur->next;
	this->cur->next->prev = this->cur->prev;

	this->cur = this->cur->prev;
	(this->numOfData)--;
	return rdata;
}

template <typename T> int DbDLinkedList<T>::LCount()
{
	return this->numOfData;
}