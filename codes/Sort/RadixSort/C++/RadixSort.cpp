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
	
	for (int pos = 0; pos < maxLen; pos++)													// 가장 긴 자릿수(maxLen)까지 반복
	{
		for (dataIndex = 0; dataIndex < num; dataIndex++)									// 데이터 전체 반복
		{
			int radix = (arr[dataIndex] / divfac) % 10;										// 각 자릿수의 기수 구하기

			buckets[radix].Enqueue(arr[dataIndex]);											// 올바른(각 기수에 맞는) 버킷에 넣기
		}

		for (bucketIndex = 0, dataIndex = 0; bucketIndex < BUCKET_NUM; bucketIndex++)
		{
			while(!buckets[bucketIndex].QIsEmpty())											// 버킷에서 순서대로 꺼내기
				arr[dataIndex++] = buckets[bucketIndex].Dequeue();
		}

		divfac *= 10;																		// 다음 자릿수로 바꾸기
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