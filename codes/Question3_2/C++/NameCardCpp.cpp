#include <iostream>
#include "NameCardCpp.h"

NameCard::NameCard(std::string name, std::string phone) : name(name), phone(phone)
{

}
void NameCard::ShowNameCardInfo()
{
	std::cout << "�̸� : " << this->name << std::endl;
	std::cout << "��ȣ : " << this->phone << std::endl;
}
int NameCard::NameCompare(std::string name)
{
	return this->name.compare(name);
}
void NameCard::ChangePhoneNum(std::string phone)
{
	this->phone = phone;
}