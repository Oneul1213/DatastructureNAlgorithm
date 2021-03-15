#ifndef __ARRAY_LIST_TEMPLATE_H__
#define __ARRAY_LIST_TEMPLATE_H__

#define LIST_LEN	100

template <typename T> class ArrayList
{
public:
	ArrayList();

	void LInsert(T data);
	int LFirst(T& r_data);
	int LNext(T& r_data);
	T LRemove();
	int LCount();
private:
	T arr[LIST_LEN];
	int numOfData;
	int curPosition;
};

#endif