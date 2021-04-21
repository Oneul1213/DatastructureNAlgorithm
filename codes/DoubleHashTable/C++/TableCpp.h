#pragma once
#include <functional>
#include "SlotCpp.h";
#include "SlotCpp.cpp"

template <typename K, typename T> class Table
{
private:
	Slot<K, T> tbl[MAX_TBL];
	std::function<int(K)> hashFunc1;
	std::function<int(K)> hashFunc2;
public:
	Table(std::function<int(K)> hf1, std::function<int(K)> hf2);

	void TBLInsert(K k, T v);
	T TBLDelete(K k);
	T TBLSearch(K k);
};