#include <iostream>

int InterpolationSearch(int arr[], int low, int high, int target)
{
	// Å½»ö ´ë»óÀÌ Å½»ö ¹üÀ§¿¡ ¾øÀ» °æ¿ì
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
		std::cout << "Å½»ö ½ÇÆÐ" << std::endl;
	else
		std::cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º: " << idx << std::endl;

	idx = InterpolationSearch(arr, 0, sizeof(arr) / sizeof(int) - 1, 10);
	if (idx == -1)
		std::cout << "Å½»ö ½ÇÆÐ" << std::endl;
	else
		std::cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º: " << idx << std::endl;

	idx = InterpolationSearch(arr, 1, 4, 2);
	if (idx == -1)
		std::cout << "Å½»ö ½ÇÆÐ" << std::endl;
	else
		std::cout << "Å¸°Ù ÀúÀå ÀÎµ¦½º: " << idx << std::endl;
}