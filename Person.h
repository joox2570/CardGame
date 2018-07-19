#pragma once
#include <string>

class Person {
	std::string name;
public:
	Person();
	Person(std::string);
	void changeName(std::string);
	void showName() const;
};