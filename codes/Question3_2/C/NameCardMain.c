#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	LData data;
	LData rdata;

	ListInit(&list);

	// 3명의 정보 저장
	data = MakeNameCard("바름", "010-1234-5678");
	LInsert(&list, data);

	data = MakeNameCard("유연", "010-9123-4567");
	LInsert(&list, data);

	data = MakeNameCard("재현", "010-8912-3456");
	LInsert(&list, data);

	// 특정 한 명의 이름 탐색 및 정보 출력
	if (LFirst(&list, &data))
	{
		if (!strcmp(data->name, "바름"))
			ShowNameCardInfo(data);

		while (LNext(&list, &data))
			if (!strcmp(data->name, "바름"))
				ShowNameCardInfo(data);
	}
	printf("\n");

	// 특정 한 명의 이름 탐색 및 전화번호 변경
	if (LFirst(&list, &data))
	{
		if (!strcmp(data->name, "유연"))
			ChangePhoneNum(data, "010-7891-2345");

		while (LNext(&list, &data))
			if (!strcmp(data->name, "유연"))
				ChangePhoneNum(data, "010-7891-2345");
	}

	// 특정 한 명의 이름 탐색 및 삭제
	if (LFirst(&list, &data))
	{
		if (!strcmp(data->name, "재현"))
		{
			rdata = LRemove(&list);
			free(rdata);
		}

		while (LNext(&list, &data))
			if (!strcmp(data->name, "재현"))
			{
				rdata = LRemove(&list);
				free(rdata);
			}
	}

	// 남아있는 데이터 출력
	if (LFirst(&list, &data))
	{
		ShowNameCardInfo(data);

		while (LNext(&list, &data))
			ShowNameCardInfo(data);
	}
	printf("\n");

	return 0;
}