#include <iostream>
#include "DBLinkedListCpp.h"

template <typename T> DoublyLinkedList<T>::DoublyLinkedList() : head(NULL), before(NULL), cur(NULL), after(NULL), numOfData(0)
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
	this->before = this->cur->prev;
	this->after = this->cur->next;
	data = this->cur->data;

	return true;
}

template <typename T> bool DoublyLinkedList<T>::LNext(T& data)
{
	if (this->after == NULL)
		return false;

	if (this->cur == NULL)
		this->cur = this->before;

	this->cur = this->cur->next;
	this->before = this->cur->prev;
	this->after = this->cur->next;
	data = this->cur->data;

	return true;
}

template <typename T> bool DoublyLinkedList<T>::LPrevious(T& data)
{
	if (this->before == NULL)
		return false;

	if (this->cur == NULL)
		this->cur = this->after;

	this->cur = this->cur->prev;
	this->before = this->cur->prev;
	this->after = this->cur->next;
	data = this->cur->data;

	return true;
}

template <typename T> T DoublyLinkedList<T>::LRemove()
{
	Node<T>* rpos = this->cur;
	T rdata = rpos->data;

	if (this->cur == this->head && this->after == NULL)	// 마지막 노드인 head를 삭제
	{
		this->head = NULL;
	}
	else if (this->cur == this->head)							// 마지막 노드가 아닌 head를 삭제
	{
		this->after->prev = NULL;
		this->head = this->after;
		this->before = this->head;
	}
	else if (this->after == NULL)							// 마지막 노드를 삭제
	{
		this->before->next = NULL;
		this->after = this->before;
	}
	else
	{
		this->before->next = this->after;
		this->after->prev = this->before;
	}

	this->cur = NULL;
	(this->numOfData)--;
	return rdata;
}

template <typename T> int DoublyLinkedList<T>::LCount()
{
	return this->numOfData;
}