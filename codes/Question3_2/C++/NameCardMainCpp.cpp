#include <iostream>
#include "ArrayListTemplate.h"
#include "ArrayListTemplate.cpp"
#include "NameCardCpp.h"

int main(void)
{
	ArrayList<NameCard*> list;
	NameCard* data;
	NameCard* rdata;

	// 3명의 정보 저장
	list.LInsert(new NameCard("바름", "010-1234-5678"));
	list.LInsert(new NameCard("유연", "010-9123-4567"));
	list.LInsert(new NameCard("재현", "010-8912-3456"));

	// 특정 한 명의 이름 탐색 및 정보 출력
	if (list.LFirst(data))
	{
		if (!(data->NameCompare("바름")))
			data->ShowNameCardInfo();
		
		while (list.LNext(data))
			if (!((data->NameCompare("바름"))))
				data->ShowNameCardInfo();
	}
	std::cout << std::endl;

	// 특정 한 명의 이름 탐색 및 전화번호 변경
	if (list.LFirst(data))
	{
		if (!((data->NameCompare("유연"))))
			data->ChangePhoneNum("010-7891-2345");

		while (list.LNext(data))
			if (!((data->NameCompare("유연"))))
				data->ChangePhoneNum("010-7891-2345");
	}

	// 특정 한 명의 이름 탐색 및 삭제
	if (list.LFirst(data))
	{
		if (!((data->NameCompare("재현"))))
		{
			rdata = list.LRemove();
			delete rdata;
		}

		while (list.LNext(data))
			if (!((data->NameCompare("재현"))))
			{
				rdata = list.LRemove();
				delete rdata;
			}
	}

	// 남아있는 데이터 출력
	if (list.LFirst(data))
	{
		data->ShowNameCardInfo();

		while (list.LNext(data))
			data->ShowNameCardInfo();
	}
	std::cout << std::endl;

	return 0;
}