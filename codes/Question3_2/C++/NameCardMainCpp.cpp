#include <iostream>
#include "ArrayListTemplate.h"
#include "ArrayListTemplate.cpp"
#include "NameCardCpp.h"

int main(void)
{
	ArrayList<NameCard*> list;
	NameCard* data;
	NameCard* rdata;

	// 3���� ���� ����
	list.LInsert(new NameCard("�ٸ�", "010-1234-5678"));
	list.LInsert(new NameCard("����", "010-9123-4567"));
	list.LInsert(new NameCard("����", "010-8912-3456"));

	// Ư�� �� ���� �̸� Ž�� �� ���� ���
	if (list.LFirst(data))
	{
		if (!(data->NameCompare("�ٸ�")))
			data->ShowNameCardInfo();
		
		while (list.LNext(data))
			if (!((data->NameCompare("�ٸ�"))))
				data->ShowNameCardInfo();
	}
	std::cout << std::endl;

	// Ư�� �� ���� �̸� Ž�� �� ��ȭ��ȣ ����
	if (list.LFirst(data))
	{
		if (!((data->NameCompare("����"))))
			data->ChangePhoneNum("010-7891-2345");

		while (list.LNext(data))
			if (!((data->NameCompare("����"))))
				data->ChangePhoneNum("010-7891-2345");
	}

	// Ư�� �� ���� �̸� Ž�� �� ����
	if (list.LFirst(data))
	{
		if (!((data->NameCompare("����"))))
		{
			rdata = list.LRemove();
			delete rdata;
		}

		while (list.LNext(data))
			if (!((data->NameCompare("����"))))
			{
				rdata = list.LRemove();
				delete rdata;
			}
	}

	// �����ִ� ������ ���
	if (list.LFirst(data))
	{
		data->ShowNameCardInfo();

		while (list.LNext(data))
			data->ShowNameCardInfo();
	}
	std::cout << std::endl;

	return 0;
}