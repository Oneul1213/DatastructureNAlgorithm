#include <iostream>
#include "ArrayListCpp.h"
#include "PointCpp.h"

int main(void)
{
	ArrayList list;
	MyPoint compPos(2, 0);
	MyPoint* ppos;

	ppos = new MyPoint(2, 1);
	list.LInsert(ppos);

	ppos = new MyPoint(2, 2);
	list.LInsert(ppos);

	ppos = new MyPoint(3, 1);
	list.LInsert(ppos);

	ppos = new MyPoint(3, 2);
	list.LInsert(ppos);

	std::cout << "현재 데이터의 수: " << list.LCount() << std::endl;

	if (list.LFirst(ppos))
	{
		ppos->ShowPointPos();

		while (list.LNext(ppos))
			ppos->ShowPointPos();
	}
	std::cout << std::endl;

	if (list.LFirst(ppos))
	{
		if (ppos->PointComp(&compPos) == 1)
		{
			ppos = list.LRemove();
			delete ppos;
		}

		while (list.LNext(ppos))
		{
			if (ppos->PointComp(&compPos) == 1)
			{
				ppos = list.LRemove();
				delete ppos;
			}
		}
	}

	std::cout << "현재 데이터의 수: " << list.LCount() << std::endl;

	if (list.LFirst(ppos))
	{
		ppos->ShowPointPos();

		while (list.LNext(ppos))
			ppos->ShowPointPos();
	}
	std::cout << std::endl;

	return 0;
}