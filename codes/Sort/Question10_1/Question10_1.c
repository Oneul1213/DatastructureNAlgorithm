#include <stdio.h>

int MedianOfThree(int arr[], int left, int right)
{
	int mid = (left + right) / 2;

	// 중간 값에서 다른 두 값을 빼면 하나는 양수, 하나는 음수
	if ((arr[left] - arr[mid]) * (arr[left] - arr[right]) < 0)
		return left;
	else if ((arr[mid] - arr[left]) * (arr[mid] - arr[right]) < 0)
		return mid;
	else
		return right;
}

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivIndex = MedianOfThree(arr, left, right);
	int pivot = arr[pivIndex];
	int low = left;
	int high = right;


	Swap(arr, left, pivIndex);									// 중간 값인 피벗을 제일 왼쪽에 둠(코드 변경 최소화)
	printf("피벗: %d \n", pivot);

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)				// low가 pivot보다 큰 값을 가리키도록
			low++;

		while (pivot <= arr[high] && high >= left + 1)			// high가 piviot보다 작은 값을 가리키도록
			high--;

		if (low <= high)
			Swap(arr, low, high);
	}

	Swap(arr, left, high);										// pivot을 정렬된 위치에 배치
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}

int main(void)
{
	int arr[15] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	QuickSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}