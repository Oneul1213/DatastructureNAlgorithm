#ifndef __STAFF_CPP_H__
#define __STAFF_CPP_H__

#include <string>

class Staff
{
public:
	int o_num;
	std::string name;

	Staff();
	Staff(int o_num, std::string name);
	void ShowStaffInfo();
};

#endif