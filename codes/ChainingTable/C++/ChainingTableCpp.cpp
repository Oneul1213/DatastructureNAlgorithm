#include <iostream>
#include "ChainingTableCpp.h"

template <typename K, typename T> Table<K, T>::Table(std::function<int(K)> hf) : hashFunc(hf)
{

}

template <typename K, typename T> void Table<K, T>::TBLInsert(K k, T v)
{
	int hv = this->hashFunc(k);
	Slot<K, T> ns;
	ns.SetKey(k);
	ns.SetValue(v);

	// 키가 중복되었다면
	if (this->TBLSearch(k) != NULL)
	{
		std::cout << "키 중복 오류 발생" << std::endl;
		return;
	}
	else
	{
		this->tbl[hv].LInsert(ns);
	}
}

template <typename K, typename T> T Table<K, T>::TBLDelete(K k)
{
	int hv = this->hashFunc(k);
	Slot<K, T> cSlot;

	if (this->tbl[hv].LFirst(cSlot))
	{
		if (cSlot.GetKey() == k)
		{
			this->tbl[hv].LRemove();
			return cSlot.GetValue();
		}
		else
		{
			while (this->tbl[hv].LNext(cSlot))
			{
				if (cSlot.GetKey() == k)
				{
					this->tbl[hv].LRemove();
					return cSlot.GetValue();
				}
			}
		}
	}

	return NULL;
}

template <typename K, typename T> T Table<K, T>::TBLSearch(K k)
{
	int hv = this->hashFunc(k);
	Slot<K, T> cSlot;

	if (this->tbl[hv].LFirst(cSlot))
	{
		if (cSlot.GetKey() == k)
			return cSlot.GetValue();
		else
		{
			while (this->tbl[hv].LNext(cSlot))
			{
				if (cSlot.GetKey() == k)
					return cSlot.GetValue();
			}
		}
	}

	return NULL;
}