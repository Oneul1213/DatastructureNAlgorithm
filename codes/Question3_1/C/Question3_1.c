#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	LData data;
	int i, cnt;

	// 리스트 초기화
	ListInit(&list);

	// 정수 1~9 리스트에 저장
	for (i = 1; i < 10; i++)
		LInsert(&list, i);

	// 리스트 순차 참조 후 저장된 값들의 합 출력
	if (LFirst(&list, &data))
	{
		cnt = 0;
		cnt += data;
		
		while (LNext(&list, &data))
		{
			cnt += data;
		}
		printf("리스트에 저장된 값의 합 : %d \n", cnt);
	}

	// 리스트에 저장된 값 중 2의 배수, 3의 배수 모두 삭제
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
	}
	
	// 저장된 데이터를 순서대로 출력
	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n");
}