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

	// 3���� ���� ����
	data = MakeNameCard("�ٸ�", "010-1234-5678");
	LInsert(&list, data);

	data = MakeNameCard("����", "010-9123-4567");
	LInsert(&list, data);

	data = MakeNameCard("����", "010-8912-3456");
	LInsert(&list, data);

	// Ư�� �� ���� �̸� Ž�� �� ���� ���
	if (LFirst(&list, &data))
	{
		if (!strcmp(data->name, "�ٸ�"))
			ShowNameCardInfo(data);

		while (LNext(&list, &data))
			if (!strcmp(data->name, "�ٸ�"))
				ShowNameCardInfo(data);
	}
	printf("\n");

	// Ư�� �� ���� �̸� Ž�� �� ��ȭ��ȣ ����
	if (LFirst(&list, &data))
	{
		if (!strcmp(data->name, "����"))
			ChangePhoneNum(data, "010-7891-2345");

		while (LNext(&list, &data))
			if (!strcmp(data->name, "����"))
				ChangePhoneNum(data, "010-7891-2345");
	}

	// Ư�� �� ���� �̸� Ž�� �� ����
	if (LFirst(&list, &data))
	{
		if (!strcmp(data->name, "����"))
		{
			rdata = LRemove(&list);
			free(rdata);
		}

		while (LNext(&list, &data))
			if (!strcmp(data->name, "����"))
			{
				rdata = LRemove(&list);
				free(rdata);
			}
	}

	// �����ִ� ������ ���
	if (LFirst(&list, &data))
	{
		ShowNameCardInfo(data);

		while (LNext(&list, &data))
			ShowNameCardInfo(data);
	}
	printf("\n");

	return 0;
}