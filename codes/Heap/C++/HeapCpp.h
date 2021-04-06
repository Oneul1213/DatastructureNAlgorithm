#pragma once

#define HEAP_LEN	100

template <typename T> class Heap
{
private:
	int (*comp)(T, T);
	int numOfData;
	T heapArr[HEAP_LEN];

	int GetParentIDX(int idx);
	int GetLChildIDX(int idx);
	int GetRChildIDX(int idx);
	int GetHiPriChildIDX(int idx);
public:
	Heap(int (*comp)(T, T));
	bool HIsEmpty();

	void HInsert(T data);
	T HDelete();
};