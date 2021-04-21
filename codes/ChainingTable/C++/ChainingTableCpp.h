#pragma once
#include <functional>
#include "ChainingSlotCpp.h"
#include "ChainingSlotCpp.cpp"
#include "SinglyLinkedListCpp.h"
#include "SinglyLinkedListCpp.cpp"

#define MAX_TBL 100

template <typename K, typename T> class Table
{
private:
	SinglyLinkedList<Slot<K, T>> tbl[MAX_TBL];
	std::function<int(K)> hashFunc;
public:
	Table(std::function<int(K)> hf);

	void TBLInsert(K k, T v);
	T TBLDelete(K k);
	T TBLSearch(K k);
};