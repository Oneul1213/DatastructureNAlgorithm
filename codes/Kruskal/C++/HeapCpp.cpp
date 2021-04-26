#include "HeapCpp.h"

template <typename T> Heap<T>::Heap(int (*comp)(T, T)) : comp(comp), numOfData(0)
{

}

template <typename T> int Heap<T>::GetParentIDX(int idx)
{
	return idx / 2;
}

template <typename T> int Heap<T>::GetLChildIDX(int idx)
{
	return idx * 2;
}

template <typename T> int Heap<T>::GetRChildIDX(int idx)
{
	return this->GetLChildIDX(idx) + 1;
}

template <typename T> int Heap<T>::GetHiPriChildIDX(int idx)
{
	if (this->GetLChildIDX(idx) > this->numOfData)
		return 0;
	else if (this->GetLChildIDX(idx) == this->numOfData)
		return this->GetLChildIDX(idx);
	else
	{
		if (this->comp(this->heapArr[this->GetLChildIDX(idx)], this->heapArr[this->GetRChildIDX(idx)]) < 0)
			return this->GetRChildIDX(idx);
		else
			return this->GetLChildIDX(idx);
	}
}

template <typename T> bool Heap<T>::HIsEmpty()
{
	if (this->numOfData == 0)
		return true;
	else
		return false;
}

template <typename T> void Heap<T>::HInsert(T data)
{
	int idx = this->numOfData + 1;

	while (idx != 1)
	{
		if (this->comp(data, this->heapArr[this->GetParentIDX(idx)]) > 0)
		{
			this->heapArr[idx] = this->heapArr[this->GetParentIDX(idx)];
			idx = this->GetParentIDX(idx);
		}
		else
			break;
	}

	this->heapArr[idx] = data;
	this->numOfData += 1;
}

template <typename T> T Heap<T>::HDelete()
{
	T retData = this->heapArr[1];
	T lastElem = this->heapArr[this->numOfData];

	int parentIdx = 1;
	int childIdx;

	while (childIdx = this->GetHiPriChildIDX(parentIdx))
	{
		if (this->comp(lastElem, this->heapArr[childIdx]) >= 0)
			break;

		this->heapArr[parentIdx] = this->heapArr[childIdx];
		parentIdx = childIdx;
	}

	this->heapArr[parentIdx] = lastElem;
	this->numOfData -= 1;
	return retData;
}