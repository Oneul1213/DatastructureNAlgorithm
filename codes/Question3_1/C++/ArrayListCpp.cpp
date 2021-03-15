#include <iostream>
#include "ArrayListCpp.h"

// 생성자 : LInit 대체
ArrayList::ArrayList() :arr{}, numOfData(0), curPosition(-1)
{

}

void ArrayList::LInsert(LData data)
{
	if (this->numOfData >= LIST_LEN)
	{
		puts("저장이 불가능합니다.");
		return;
	}

	this->arr[this->numOfData] = data;
	(this->numOfData)++;
}
int ArrayList::LFirst(LData& r_data)
{
	if (this->numOfData == 0)
		return false;

	this->curPosition = 0;
	r_data = this->arr[0];
	return true;
}
int ArrayList::LNext(LData& r_data)
{
	if (this->curPosition >= (this->numOfData) - 1)
		return false;

	(this->curPosition)++;
	r_data = this->arr[this->curPosition];
	return true;
}
LData ArrayList::LRemove()
{
	int rpos = this->curPosition;
	int num = this->numOfData;
	LData rdata = this->arr[rpos];

	for (int i = rpos; i < num - 1; i++)
		this->arr[i] = this->arr[i + 1];

	(this->numOfData)--;
	(this->curPosition)--;
	return rdata;
}
int ArrayList::LCount()
{
	return this->numOfData;
}