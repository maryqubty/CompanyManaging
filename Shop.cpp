
#include <iostream>
#include "Manager.h"
#include "Shop.h"


//constructors
Shop::Shop(const Manager& manager, const string& name, Day closedDay, bool isOnline)
	:manager(manager), name(name), closedDay(closedDay), isOnline(isOnline)
{
	if (name.length() > 10) {
		std::cout << "Shop name length is too long" << std::endl;
		this->name = "~";
	}
	
}

//copy
Shop::Shop(const Shop& copy) {
	this->manager = copy.manager;
	this->name = copy.name;
	this->closedDay = copy.closedDay;
	this->isOnline = copy.isOnline;
}

//= operation
Shop& Shop::operator=(const Shop& that) {
	if (this == &that) return *this;
	this->manager = that.manager;
	this->name = that.name;
	this->closedDay = that.closedDay;
	this->isOnline = that.isOnline;
	return *this;
}

// Get functions to retrieve data from the class

Manager Shop::getManager() const{
	return this->manager;
}

string Shop::getName() const {
	return this->name;
}

Day Shop::getClosedDay() const {
	return this->closedDay;
}

bool Shop::IsOnline() const {
	return this->isOnline;
}

// Set methods to adjust the data in the class

void Shop::setManager(Manager& manager) {
	this->manager = manager;
}

void Shop::setName(const string& name) {
	this->name = name;
	if (name.length() > 10) {
		std::cout << "Shop name length is too long" << std::endl;
		this->name = "~";
	}
}

void Shop::setClosedDay(Day closedDay) {
	this->closedDay = closedDay;
}

void Shop::setIsOnline(bool isOnline) {
	this->isOnline = isOnline;
}

// print functions as required.
void Shop::print() const {

	std::cout << "Printing shop: " << std::endl;
	this->manager.print();
	std::cout << "Name : " << this->name << std::endl;
	std::cout << "Closed day : " << WEEK_DAY[this->closedDay] << std::endl;
	std::cout << "Is Online : " << BOOL_FLAG[this->isOnline] << std::endl;
}
