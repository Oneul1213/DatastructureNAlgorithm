#include <iostream>
#include "ArrayListCpp.h"

int main(void)
{
	LData data;

	// 리스트 초기화
	ArrayList list;

	// 정수 1~9 리스트에 저장
	for (int i = 1; i < 10; i++)
		list.LInsert(i);

	// 리스트 순차 참조 후 저장된 값들의 합 출력
	if (list.LFirst(data))
	{
		int cnt = 0;
		cnt += data;

		while (list.LNext(data))
			cnt += data;
		std::cout << "저장된 값의 합 : " << data << std::endl;
	}

	// 리스트에 저장된 값 중 2의 배수, 3의 배수 모두 삭제
	if (list.LFirst(data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			list.LRemove();

		while (list.LNext(data))
			if (data % 2 == 0 || data % 3 == 0)
				list.LRemove();
	}

	// 저장된 데이터를 순서대로 출력
	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";
	}
	std::cout << std::endl;
}