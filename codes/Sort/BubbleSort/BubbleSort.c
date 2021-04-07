#include <stdio.h>

void BubbleSort(int arr[], int n)
{
	int i, j;
	int temp;

	for (i = 0; i < n - 1; i++)				// 몇 개가 정렬되었는지
	{
		for (j = 0; j < (n - i) - 1; j++)	// 어디까지 비교할지
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void)
{
	int arr[4] = { 3, 2, 4, 1 };
	int i;

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (i = 0; i < 4; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}