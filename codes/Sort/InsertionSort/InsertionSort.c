#include <stdio.h>

void InsertionSort(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++)				// 정렬할 데이터
	{
		insData = arr[i];

		for (j = i - 1; j >= 0; j--)	// 제자리 찾기
		{
			if (arr[j] > insData)
				arr[j + 1] = arr[j];
			else
				break;
		}

		arr[j + 1] = insData;
	}
}

int main(void)
{
	int arr[5] = { 5, 3, 2, 4, 1 };
	int i;

	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 5; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}