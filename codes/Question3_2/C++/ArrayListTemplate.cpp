#include <iostream>
#include "ArrayListTemplate.h"

template <typename T> ArrayList<T>::ArrayList() : arr{}, numOfData(0), curPosition(-1)
{
	
}

template <typename T> void ArrayList<T>::LInsert(T data)
{
	if (this->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	this->arr[this->numOfData] = data;
	(this->numOfData)++;
}

template <typename T> int ArrayList<T>::LFirst(T& r_data)
{
	if (this->numOfData == 0)
		return false;

	this->curPosition = 0;
	r_data = this->arr[0];
	return true;
}

template <typename T> int ArrayList<T>::LNext(T& r_data)
{
	if (this->curPosition >= (this->numOfData) - 1)
		return false;

	(this->curPosition)++;
	r_data = this->arr[this->curPosition];
	return true;
}

template <typename T> T ArrayList<T>::LRemove()
{
	int rpos = this->curPosition;
	int num = this->numOfData;
	T rdata = this->arr[rpos];

	for (int i = rpos; i < num - 1; i++)
		this->arr[i] = this->arr[i + 1];

	(this->numOfData)--;
	(this->curPosition)--;
	return rdata;
}
template <typename T> int ArrayList<T>::LCount()
{
	return this->numOfData;
}