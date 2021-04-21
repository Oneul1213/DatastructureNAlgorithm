#pragma once
#include <string>

class Person
{
private:
	int ssn;
	std::string name;
	std::string address;
public:
	Person();
	Person(int _ssn, std::string _name, std::string _address);

	int GetSSN();
	void ShowPerInfo();
};