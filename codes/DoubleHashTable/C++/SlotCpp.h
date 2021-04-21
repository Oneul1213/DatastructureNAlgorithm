#pragma once

#define MAX_TBL 100

enum SlotStatus { EMPTY, DELETED, INUSE };

template <typename K, typename T> class Slot
{
private:
	K key;
	T value;
	SlotStatus status;
public:
	void SetKey(K k);
	K GetKey();

	void SetValue(T v);
	T GetValue();

	void SetStatus(SlotStatus ss);
	SlotStatus GetStatus();
};