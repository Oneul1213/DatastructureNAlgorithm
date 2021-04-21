#include <iostream>
#include <functional>
#include "TableCpp.h"

template <typename K, typename T> Table<K, T>::Table(std::function<int(K)> hf1, std::function<int(K)> hf2) : hashFunc1(hf1), hashFunc2(hf2)
{
	for (int i = 0; i < MAX_TBL; i++)
		this->tbl[i].SetStatus(EMPTY);
}

template <typename K, typename T> void Table<K, T>::TBLInsert(K k, T v)
{
	int hv = this->hashFunc1(k);

	// 키가 중복되었다면
	if (this->TBLSearch(k) != NULL)
	{
		std::cout << "키 중복 오류 발생" << std::endl;
		return;
	}

	// 충돌 발생 시 빈 자리를 찾을 때까지 반복
	while (this->tbl[hv].GetStatus() == INUSE || this->tbl[hv].GetStatus() == DELETED)
		hv = hv + this->hashFunc2(k);

	this->tbl[hv].SetValue(v);
	this->tbl[hv].SetKey(k);
	this->tbl[hv].SetStatus(INUSE);
}

template <typename K, typename T> T Table<K, T>::TBLDelete(K k)
{
	int hv = this->hashFunc1(k);

	// 충돌 발생 시 빈 자리를 찾을 때까지 반복
	while (this->tbl[hv].GetStatus() == DELETED)
		hv = hv + this->hashFunc2(k);

	if (this->tbl[hv].GetStatus() != INUSE)
		return NULL;
	else
	{
		this->tbl[hv].SetStatus(DELETED);
		return this->tbl[hv].GetValue();
	}
}

template <typename K, typename T> T Table<K, T>::TBLSearch(K k)
{
	int hv = this->hashFunc1(k);

	// 충돌 발생 시 빈 자리를 찾을 때까지 반복
	while (this->tbl[hv].GetStatus() == DELETED)
		hv = hv + this->hashFunc2(k);

	if (this->tbl[hv].GetStatus() != INUSE)
		return NULL;
	else
		return this->tbl[hv].GetValue();
}