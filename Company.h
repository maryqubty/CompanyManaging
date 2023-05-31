// Nasem Sawaid 209290733
// Mary Qubty 206528275

#pragma once
#include "Manager.h"
#include "Shop.h"
#include <string>

#define MAX_SHOPS_NUMBER 10

class Company {

    string name;
    Shop shops[MAX_SHOPS_NUMBER];
    int shopsNumber;

public:
  //  Company(); //done
    Company(const string& name= "~", Shop* shop=NULL, int shopsNumber=0); //done
    Company(const Company& copy); //done
    Company& operator=(const Company& equal); //done

    string getName() const; // done
    Shop* getShops() ;
    int getShopNumber() const; //done

    void setName(const string& name); //done
    void addShop(const Shop& shop);

    void printShopsByName();
    void printShopsByDay();

};

bool sortByDay(const Shop& sh1, const Shop& sh2);


