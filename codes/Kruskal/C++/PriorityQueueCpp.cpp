#include "HeapCpp.h"
#include "HeapCpp.cpp"
#include "PriorityQueueCpp.h"

template <typename T> PriorityQueue<T>::PriorityQueue(int (*comp)(T, T))
{
	this->heap = new Heap<T>(comp);
}

template <typename T> bool PriorityQueue<T>::PQIsEmpty()
{
	return this->heap->HIsEmpty();
}

template <typename T> void PriorityQueue<T>::PEnqueue(T data)
{
	this->heap->HInsert(data);
}

template <typename T> T PriorityQueue<T>::PDequeue()
{
	return this->heap->HDelete();
}