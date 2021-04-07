#include <iostream>

void BubbleSort(int arr[], int n)
{
	int temp;

	for (int i = 0; i < n - 1; i++)				// 몇 개가 정렬됐는지
	{
		for (int j = 0; j < (n - i) - 1; j++)	// 어디까지 비교할지
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

	BubbleSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	return 0;
}