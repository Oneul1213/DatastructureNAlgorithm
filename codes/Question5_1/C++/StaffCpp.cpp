#include <iostream>
#include "StaffCpp.h"

Staff::Staff() : o_num(0), name("")
{

}

Staff::Staff(int o_num, std::string name) : o_num(o_num), name(name)
{

}

void Staff::ShowStaffInfo()
{
	std::cout << "��� : " << this->o_num << std::endl;
	std::cout << "�̸� : " << this->name << std::endl;
}