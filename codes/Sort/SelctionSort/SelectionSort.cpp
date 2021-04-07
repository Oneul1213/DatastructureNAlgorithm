#include <iostream>

void SelectionSort(int arr[], int n)
{
	int temp;
	int minIdx;

	for (int i = 0; i < n - 1; i++)			// �� ���� ���ĵǾ�����
	{
		minIdx = i;

		for (int j = i + 1; j < n; j++)		// �ּڰ� ã��
		{
			if (arr[j] < arr[minIdx])
				minIdx = j;
		}

		temp = arr[i];
		arr[i] = arr[minIdx];
		arr[minIdx] = temp;
	}
}

int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };

	SelectionSort(arr, sizeof(arr) / sizeof(int));

	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;

	return 0;
}