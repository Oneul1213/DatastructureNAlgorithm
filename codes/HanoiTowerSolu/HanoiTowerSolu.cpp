#include <iostream>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		std::cout << "����1�� " << from << "���� " << to << "�� �̵�" << std::endl;
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		std::cout << "����" << num << "��(��) " << from << "���� " << to << "�� �̵�" << std::endl;
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main(void)
{
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}