#include <iostream>

void InsertionSort(int arr[], int n)
{
	int insData, j;

	for (int i = 1; i < n; i++)			// 정렬할 데이터
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

	InsertionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 5; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
	return 0;
}