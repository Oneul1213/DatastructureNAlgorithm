#pragma once

template <typename K, typename T> class Slot
{
private:
	K key;
	T value;
public:
	void SetKey(K k);
	K GetKey();

	void SetValue(T v);
	T GetValue();
};