#pragma once

#include "DequeCpp.h"
#include "DequeCpp.cpp"

template <typename T> class DBQueue
{
private:
	Deque<T> deq;
public:
	bool QIsEmpty();

	void Enqueue(T data);
	T Dequeue();
	T QPeek();
};