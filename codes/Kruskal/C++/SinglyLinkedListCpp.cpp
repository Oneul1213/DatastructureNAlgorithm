#include <iostream>
#include <functional>
#include "SinglyLinkedListCpp.h"

template <typename T> SinglyLinkedList<T>::SinglyLinkedList() : head(new Node<T>()), cur(NULL), before(NULL), numOfData(0), comp(NULL)
{
	head->next = NULL;
}

template <typename T> void SinglyLinkedList<T>::FInsert(T data)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = data;

	newNode->next = this->head->next;
	this->head->next = newNode;

	(this->numOfData)++;
}

template <typename T> void SinglyLinkedList<T>::SInsert(T data)
{
	Node<T>* newNode = new Node<T>();
	Node<T>* pred = this->head;

	newNode->data = data;

	while (pred->next != NULL && this->comp(data, pred->next->data) != 0)
		pred = pred->next;

	newNode->next = pred->next;
	pred->next = newNode;

	(this->numOfData)++;
}

template <typename T> void SinglyLinkedList<T>::LInsert(T data)
{
	if (this->comp == NULL)
		this->FInsert(data);
	else
		this->SInsert(data);
}

template <typename T> bool SinglyLinkedList<T>::LFirst(T& data)
{
	if (this->head->next == NULL)
		return false;

	this->before = this->head;
	this->cur = this->head->next;

	data = this->cur->data;
	return true;
}

template <typename T> bool SinglyLinkedList<T>:: LNext(T& data)
{
	if (this->cur->next == NULL)
		return false;

	this->before = this->cur;
	this->cur = this->cur->next;

	data = this->cur->data;
	return true;
}

template <typename T> T SinglyLinkedList<T>::LRemove()
{
	Node<T>* rpos = this->cur;
	T rdata = rpos->data;

	this->before->next = this->cur->next;
	this->cur = this->before;

	delete rpos;
	(this->numOfData)--;
	return rdata;
}

template <typename T> int SinglyLinkedList<T>::LCount()
{
	return this->numOfData;
}

template <typename T> void SinglyLinkedList<T>::SetSortRule(std::function<int(T, T)> comp)
{
	this->comp = comp;
}