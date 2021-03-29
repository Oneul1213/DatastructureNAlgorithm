#include "DequeBaseQueueCpp.h"

template <typename T> bool DBQueue<T>::QIsEmpty()
{
	return this->deq.DQIsEmpty();
}

template <typename T> void DBQueue<T>::Enqueue(T data)
{
	this->deq.DQAddLast(data);
}

template <typename T> T DBQueue<T>::Dequeue()
{
	return this->deq.DQRemoveFirst();
}

template <typename T> T DBQueue<T>::QPeek()
{
	return this->deq.DQGetFirst();
}