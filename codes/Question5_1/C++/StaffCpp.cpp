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
	std::cout << "사번 : " << this->o_num << std::endl;
	std::cout << "이름 : " << this->name << std::endl;
}