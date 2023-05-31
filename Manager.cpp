// hw1-oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Manager.h"

//default constructor
/*Manager::Manager() {
	this->id = 0;
	this->firstName = "~";
	this->lastName = "~";
	this->birthYear = 0;
}*/
//constructor
Manager::Manager(int id, const string& firstName, const string& lastName, int birthYear)
	: id(id), firstName(firstName), lastName(lastName), birthYear(birthYear)
{
	if (firstName.length() > 10) {
		std::cout << "Manager first name length is too long" << std::endl; 
		this->firstName = "~";
	}
	if (lastName.length() > 10) {
		std::cout << "Manager last name length is too long" << std::endl;
		this->lastName = "~";
	}
}

//copy
Manager::Manager (const Manager& copy) {
	this->id = copy.id;
	this->firstName = copy.firstName;
	this->lastName = copy.lastName;
	this->birthYear = copy.birthYear;
}

//= operation
Manager& Manager::operator=(const Manager& that) {
	if (this == &that) return *this;
	this->id = that.id;
	this->firstName = that.firstName;
	this->lastName = that.lastName;
	this->birthYear = that.birthYear;
	return *this;
}

int Manager::getId() const{
	return this->id;
}

int Manager::getBirthYear() const{
	return this->birthYear;		
}

string Manager::getFirstName() const{
	return this->firstName;
}

string Manager::getLastName() const{
	return this->lastName;
}

void Manager::setId(int id) {
	this->id = id;
}

void Manager::setBirthYear(int birthYear) {
	this->birthYear = birthYear;
}

void Manager::setFirstName(const string& firstName) {
	this->firstName = firstName;
	if (firstName.length() > 10) {
		std::cout << "Manager first name length is too long" << std::endl;
		this->firstName = "~";
	}
}

void Manager::setLastName(const string& lastName) {
	this->lastName = lastName;
	if (lastName.length() > 10) {
		std::cout << "Manager last name length is too long" << std::endl;
		this->lastName = "~";
	}
}

void Manager::print() const{
	std::cout << "Printing manager: " << std::endl;
	std::cout << "Id : " << this->id << std::endl;
	std::cout << "First name : " << this->firstName << std::endl;
	std::cout << "Last name : " << this->lastName << std::endl;
	std::cout << "Birth year : " << this->birthYear << std::endl;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
