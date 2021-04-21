#include "ChainingSlotCpp.h"

template <typename K, typename T> void Slot<K, T>::SetKey(K k)
{
	this->key = k;
}

template <typename K, typename T> K Slot<K, T>::GetKey()
{
	return this->key;
}

template <typename K, typename T> void Slot<K, T>::SetValue(T v)
{
	this->value = v;
}

template <typename K, typename T> T Slot<K, T>::GetValue()
{
	return this->value;
}