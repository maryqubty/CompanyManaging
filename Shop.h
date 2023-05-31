// Nasem Sawaid 209290733
// Mary Qubty 206528275

#pragma once

#include "Manager.h"

enum Day
{
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

const char WEEK_DAY[7][10] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char BOOL_FLAG[2][6] = { "False", "True"};
class Shop {
private:
	Manager manager;
	string name;
	Day closedDay; 
	bool isOnline;

public:
//	Shop();
	Shop(const Manager& manager=NULL, const string& name = "~", Day closedDay = Sunday, bool isOnline = false);
	Shop(const Shop& copy);
	Shop& operator=(const Shop& that);

	Manager getManager() const;
	string getName() const;
	Day getClosedDay() const;
	bool IsOnline() const;

	void setManager(Manager& manager);
	void setName(const string& name);
	void setClosedDay(Day closedDay);
	void setIsOnline(bool isOnline);

	void print() const;


};

