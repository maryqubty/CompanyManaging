#pragma once

#include <string>
using std::string;

class Manager {
private:
	int id;
	string firstName;
	string lastName;
	int birthYear;

public:
//	Manager();
	Manager(int id=0, const string& firstName="~", const string& lastName="~", int birthYear=0);
	Manager(const Manager& copy);
	Manager& operator=(const Manager& that);

	int getId() const;
	int getBirthYear() const;
	string getFirstName() const;
	string getLastName() const;

	void setId(int id);
	void setBirthYear(int birthYear);
	void setFirstName(const string& firstName);
	void setLastName(const string& lasttName);

	void print() const;
};
