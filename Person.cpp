#include "Person.h"
#include <iostream>

Person::Person() {
	name = "Unknown";
}

Person::Person(std::string n) {
	name = n;
}

void Person::changeName(std::string n) {
	name = n;
}

void Person::showName() const {
	std::cout << name << std::endl;
}