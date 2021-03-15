#include <iostream>
#include "ArrayListCpp.h"

int main(void)
{
	LData data;

	// ����Ʈ �ʱ�ȭ
	ArrayList list;

	// ���� 1~9 ����Ʈ�� ����
	for (int i = 1; i < 10; i++)
		list.LInsert(i);

	// ����Ʈ ���� ���� �� ����� ������ �� ���
	if (list.LFirst(data))
	{
		int cnt = 0;
		cnt += data;

		while (list.LNext(data))
			cnt += data;
		std::cout << "����� ���� �� : " << data << std::endl;
	}

	// ����Ʈ�� ����� �� �� 2�� ���, 3�� ��� ��� ����
	if (list.LFirst(data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			list.LRemove();

		while (list.LNext(data))
			if (data % 2 == 0 || data % 3 == 0)
				list.LRemove();
	}

	// ����� �����͸� ������� ���
	if (list.LFirst(data))
	{
		std::cout << data << " ";

		while (list.LNext(data))
			std::cout << data << " ";
	}
	std::cout << std::endl;
}