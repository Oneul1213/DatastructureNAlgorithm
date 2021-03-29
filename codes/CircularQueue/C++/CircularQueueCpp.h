#pragma once

#define QUE_LEN	100

template <typename T> class CircularQueue
{
private:
	int front;
	int rear;
	T queArr[QUE_LEN];

	int NextPosIdx(int pos);
public:
	CircularQueue();
	bool QIsEmpty();

	void Enqueue(T data);
	T Dequeue();
	T QPeek();
};