#include <stdio.h>

int ISearch(int ar[], int low, int high, int target)
{
	int s;

	// Ž�� ����� Ž�� ������ ���� ���
	if (ar[low] > target || ar[high] < target)
		return -1;

	s = ((double)(target - ar[low]) / (ar[high] - ar[low]) * (high - low)) + low;

	if (ar[s] == target)
		return s;
	else if (target < ar[s])
		return ISearch(ar, low, s - 1, target);
	else
		return ISearch(ar, s + 1, high, target);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 7);
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 10);
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	idx = ISearch(arr, 1, 4, 2);
	if (idx == -1)
		printf("Ž�� ���� \n");
	else
		printf("Ÿ�� ���� �ε���: %d \n", idx);

	return 0;
}