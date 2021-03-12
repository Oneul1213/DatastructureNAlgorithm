#ifndef __ARRAY_LIST_CPP_H__
#define __ARRAY_LIST_CPP_H__

#define LIST_LEN	100
typedef int LData;

class ArrayList
{
public:
	ArrayList();

	void LInsert(LData data);

	int LFirst(LData& r_data);
	int LNext(LData& r_data);

	LData LRemove();
	int LCount();

private:
	LData arr[LIST_LEN];
	int numOfData;
	int curPosition;
};

#endif