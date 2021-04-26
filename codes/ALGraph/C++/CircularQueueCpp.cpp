#include <iostream>
#include "CircularQueueCpp.h"

template <typename T> CircularQueue<T>::CircularQueue() : front(0), rear(0)
{

}

template <typename T> bool CircularQueue<T>::QIsEmpty()
{
	if (this->front == this->rear)
		return true;
	else
		return false;
}

template <typename T> int CircularQueue<T>::NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;
	else
		return pos + 1;
}

template <typename T> void CircularQueue<T>::Enqueue(T data)
{
	if (this->NextPosIdx(this->rear) == this->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	this->rear = NextPosIdx(this->rear);
	this->queArr[this->rear] = data;
}

template <typename T> T CircularQueue<T>::Dequeue()
{
	if (this->QIsEmpty())
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	this->front = NextPosIdx(this->front);
	return this->queArr[this->front];
}

template <typename T> T CircularQueue<T>::QPeek()
{
	if (this->QIsEmpty())
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return this->queArr[this->NextPosIdx(this->front)];
}