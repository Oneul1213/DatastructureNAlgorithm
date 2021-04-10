#include <iostream>
#include "ListBaseQueueCpp.h"
#include "ListBaseQueueCpp.cpp"

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)
{
	ListQueue<int> buckets[BUCKET_NUM];

	int bucketIndex;
	int dataIndex;
	int divfac = 1;
	
	for (int pos = 0; pos < maxLen; pos++)													// ���� �� �ڸ���(maxLen)���� �ݺ�
	{
		for (dataIndex = 0; dataIndex < num; dataIndex++)									// ������ ��ü �ݺ�
		{
			int radix = (arr[dataIndex] / divfac) % 10;										// �� �ڸ����� ��� ���ϱ�

			buckets[radix].Enqueue(arr[dataIndex]);											// �ùٸ�(�� ����� �´�) ��Ŷ�� �ֱ�
		}

		for (bucketIndex = 0, dataIndex = 0; bucketIndex < BUCKET_NUM; bucketIndex++)
		{
			while(!buckets[bucketIndex].QIsEmpty())											// ��Ŷ���� ������� ������
				arr[dataIndex++] = buckets[bucketIndex].Dequeue();
		}

		divfac *= 10;																		// ���� �ڸ����� �ٲٱ�
	}
}

int main(void)
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len, 5);

	for (int i = 0; i < len; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
	return 0;
}