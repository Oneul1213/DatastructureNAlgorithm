#include <stdio.h>

int ISearch(int ar[], int low, int high, int target)
{
	int s;

	// Å½»ö ´ë»óÀÌ Å½»ö ¹üÀ§¿¡ ¾øÀ» °æ¿ì
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
		printf("Å½»ö ½ÇÆÐ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

	idx = ISearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 10);
	if (idx == -1)
		printf("Å½»ö ½ÇÆÐ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

	idx = ISearch(arr, 1, 4, 2);
	if (idx == -1)
		printf("Å½»ö ½ÇÆÐ \n");
	else
		printf("Å¸°Ù ÀúÀå ÀÎµ¦½º: %d \n", idx);

	return 0;
}