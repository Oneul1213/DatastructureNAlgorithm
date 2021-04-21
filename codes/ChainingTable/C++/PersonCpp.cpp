#include <iostream>
#include <string>
#include "PersonCpp.h"

Person::Person() : ssn(0), name(""), address("")
{
	
}

Person::Person(int _ssn, std::string _name, std::string _address) : ssn(_ssn), name(_name), address(_address)
{

}

int Person::GetSSN()
{
	return this->ssn;
}

void Person::ShowPerInfo()
{
	std::cout << "주민등록번호: " << this->ssn << std::endl;
	std::cout << "이름: " << this->name << std::endl;
	std::cout << "주소: " << this->address << std::endl;
	std::cout << std::endl;
}