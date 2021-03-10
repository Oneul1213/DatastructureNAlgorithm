#include <iostream>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if (num == 1)
	{
		std::cout << "원반1을 " << from << "에서 " << to << "로 이동" << std::endl;
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		std::cout << "원반" << num << "을(를) " << from << "에서 " << to << "로 이동" << std::endl;
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main(void)
{
	HanoiTowerMove(3, 'A', 'B', 'C');
	return 0;
}