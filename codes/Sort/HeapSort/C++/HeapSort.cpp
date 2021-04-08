#include <iostream>
#include "HeapCpp.h"
#include "HeapCpp.cpp"

int PriComp(int d1, int d2)
{
	return d2 - d1;		// ��������
}

void HeapSort(int arr[], int n, int (*pc)(int, int))
{
	Heap<int> heap(pc);

	for (int i = 0; i < n; i++)		// ���� ������ �ֱ�
		heap.HInsert(arr[i]);

	for (int i = 0; i < n; i++)		// ������ ������ ����
		arr[i] = heap.HDelete();
}

int main(void)
{
	int arr[4] = { 3, 4, 2, 1 };

	HeapSort(arr, sizeof(arr) / sizeof(int), PriComp);

	for (int i = 0; i < 4; i++)
		std::cout << arr[i] << " ";

	std::cout << std::endl;
	return 0;
}