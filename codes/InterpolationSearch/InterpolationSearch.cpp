#include <iostream>

int InterpolationSearch(int arr[], int low, int high, int target)
{
	// Ž�� ����� Ž�� ������ ���� ���
	if (arr[low] > target || arr[high] < target)
		return -1;

	int s = ((double)(target - arr[low]) / (arr[high] - arr[low]) * (high - low)) + low;

	if (arr[s] == target)
		return s;
	else if (target < arr[s])
		return InterpolationSearch(arr, low, s - 1, target);
	else
		return InterpolationSearch(arr, s + 1, high, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;
	
	idx = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		std::cout << "Ž�� ����" << std::endl;
	else
		std::cout << "Ÿ�� ���� �ε���: " << idx << std::endl;

	idx = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 10);
	if (idx == -1)
		std::cout << "Ž�� ����" << std::endl;
	else
		std::cout << "Ÿ�� ���� �ε���: " << idx << std::endl;

	idx = InterpolationSearch(arr, 1, 4, 2);
	if (idx == -1)
		std::cout << "Ž�� ����" << std::endl;
	else
		std::cout << "Ÿ�� ���� �ε���: " << idx << std::endl;
}