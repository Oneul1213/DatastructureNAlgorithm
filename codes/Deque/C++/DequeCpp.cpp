#include <iostream>
#include "DequeCpp.h"

template <typename T> Deque<T>::Deque() : head(NULL), tail(NULL)
{

}

template <typename T> bool Deque<T>::DQIsEmpty()
{
	if (this->head == NULL)
		return true;
	else
		return false;
}

template <typename T> void Deque<T>::DQAddFirst(T data)
{
	Node<T>* newNode = new Node<T>();
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (this->DQIsEmpty())
	{
		this->tail = newNode;
	}
	else
	{
		newNode->next = this->head;
		this->head->prev = newNode;
	}
	this->head = newNode;
}

template <typename T> void Deque<T>::DQAddLast(T data)
{
	Node<T>* newNode = (Node<T>*)malloc(sizeof(Node<T>));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (this->tail == NULL)
	{
		this->head = newNode;
	}
	else
	{
		newNode->prev = this->tail;
		this->tail->next = newNode;
	}
	this->tail = newNode;
}

template <typename T> T Deque<T>::DQRemoveFirst()
{
	Node<T>* delNode = this->head;
	T retT = delNode->data;

	if (this->DQIsEmpty())
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	if (this->head == this->tail)
	{
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		this->head = delNode->next;
		this->head->prev = NULL;
	}

	free(delNode);
	return retT;
}

template <typename T> T Deque<T>::DQRemoveLast()
{
	Node<T>* delNode = this->tail;
	T retT = delNode->data;

	if (this->DQIsEmpty())
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	if (this->head == this->tail)
	{
		this->head = NULL;
		this->tail = NULL;
	}
	else
	{
		this->tail = delNode->prev;
		this->tail->next = NULL;
	}

	free(delNode);
	return retT;
}

template <typename T> T Deque<T>::DQGetFirst()
{
	if (this->DQIsEmpty())
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return this->head->data;
}

template <typename T> T Deque<T>::DQGetLast()
{
	if (this->DQIsEmpty())
	{
		printf("Deque Memory Error!");
		exit(-1);
	}

	return this->tail->data;
}