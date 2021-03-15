#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	LData data;
	int i, cnt;

	// ����Ʈ �ʱ�ȭ
	ListInit(&list);

	// ���� 1~9 ����Ʈ�� ����
	for (i = 1; i < 10; i++)
		LInsert(&list, i);

	// ����Ʈ ���� ���� �� ����� ������ �� ���
	if (LFirst(&list, &data))
	{
		cnt = 0;
		cnt += data;
		
		while (LNext(&list, &data))
		{
			cnt += data;
		}
		printf("����Ʈ�� ����� ���� �� : %d \n", cnt);
	}

	// ����Ʈ�� ����� �� �� 2�� ���, 3�� ��� ��� ����
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
	}
	
	// ����� �����͸� ������� ���
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n");
}