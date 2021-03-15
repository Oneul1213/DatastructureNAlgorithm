#ifndef __NAMECARD_CPP_H__
#define __NAMECARD_CPP_H__

#include <string>

class NameCard
{
public:
	NameCard(std::string name, std::string phone);
	void ShowNameCardInfo();
	int NameCompare(std::string name);
	void ChangePhoneNum(std::string phone);

private:
	std::string name;
	std::string phone;
};

#endif