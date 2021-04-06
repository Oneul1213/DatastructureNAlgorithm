#pragma once

#include "HeapCpp.h"

template <typename T> class PriorityQueue
{
private:
	Heap<T> * heap;
public:
	PriorityQueue(int (*comp)(T, T));
	bool PQIsEmpty();

	void PEnqueue(T data);
	T PDequeue();
};