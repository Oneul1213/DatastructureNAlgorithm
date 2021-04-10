#include <stdio.h>
#include "ListBaseQueue.h"

#define BUCKET_NUM		10

void RadixSort(int arr[], int num, int maxLen)
{
	Queue buckets[BUCKET_NUM];
	int bucketIndex;
	int pos;
	int dataIndex;
	int divfac = 1;
	int radix;

	for (bucketIndex = 0; bucketIndex < BUCKET_NUM; bucketIndex++)
		QueueInit(&buckets[bucketIndex]);

	for (pos = 0; pos < maxLen; pos++)														// ���� �� �ڸ���(maxLen)���� �ݺ�
	{
		for (dataIndex = 0; dataIndex < num; dataIndex++)									// ������ ��ü �ݺ�
		{
			radix = (arr[dataIndex] / divfac) % 10;											// �� �ڸ����� ��� ���ϱ�

			Enqueue(&buckets[radix], arr[dataIndex]);										// �ùٸ�(����� �´�) ��Ŷ�� �ֱ�
		}

		for (bucketIndex = 0, dataIndex = 0; bucketIndex < BUCKET_NUM; bucketIndex++)
		{
			while (!QIsEmpty(&buckets[bucketIndex]))
				arr[dataIndex++] = Dequeue(&buckets[bucketIndex]);							// ��Ŷ���� ������� ������
		}

		divfac *= 10;																		// ���� �ڸ����� �ٲٱ�
	}
}

int main(void)
{
	int arr[7] = { 13, 212, 14, 7141, 10987, 6, 15 };

	int len = sizeof(arr) / sizeof(int);
	int i;

	RadixSort(arr, len, 5);

	for (i = 0; i < len; i++)
		printf("%d ", arr[i]);

	printf("\n");
	return 0;
}