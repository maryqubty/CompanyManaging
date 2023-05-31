// Nasem Sawaid 209290733
// Mary Qubty 206528275

#include "Company.h"
#include "iostream"
#include <algorithm>

//constructor
Company::Company(const string& name, Shop* shops, int shopsNumber)
    : name(name), shopsNumber(shopsNumber)
{
    // Checking the name requirement
    if (name.length() > 10) {
        std::cout << "Company name length is too long" << std::endl;
        this->name = "~";
    }

    for (int i = 0; i < shopsNumber && i < MAX_SHOPS_NUMBER; i++) {
        this->shops[i] = shops[i];
    }
    //just in case the num is greater than max:
    if (shopsNumber > MAX_SHOPS_NUMBER) this->shopsNumber = MAX_SHOPS_NUMBER;

}

// copy constructor
Company::Company(const Company &copy) {
    this->name=copy.name;
    this->shopsNumber=copy.shopsNumber;
    for(int i=0; i<shopsNumber && i<MAX_SHOPS_NUMBER;i++){
        this->shops[i]=copy.shops[i];
    }
}

// Operator overloading - The = operator
Company &Company::operator=(const Company &equal) {

    this->name=equal.name;
    this->shopsNumber=equal.shopsNumber;
    for(int i=0; i<shopsNumber && i<MAX_SHOPS_NUMBER;i++){
        this->shops[i]=equal.shops[i];
    }
    return *this;
}

// The get methods - to retrieve the data from the class
string Company::getName() const {
    return this->name;
}
int Company::getShopNumber() const {
    return this->shopsNumber;
}

Shop* Company::getShops()  {
    return this->shops;
}

// The set methods - to adjust the class fields
void Company::setName(const string& name) {
    this->name=name;
    if(name.length()>10){
        std::cout<<"Company name length is too long"<<std::endl;
        this->name="~";
    }
}

void Company::addShop(const Shop& shop) {
    if (this->shopsNumber == MAX_SHOPS_NUMBER) {
        std::cout << "There is no place for new shops! " << std::endl;
        return;
    }
    this->shops[this->shopsNumber] = shop;
    this->shopsNumber++;
}

// The print functions
// We used the sort function from the algorithms' library, this function uses nlogn time complexity.

void Company::printShopsByDay() {
    if (shopsNumber == 0) {
        std::cout << "There are no shops in this company." << std::endl;
        return;
    }
    
    std::cout << "There are " << shopsNumber << " shops in this company. The shops details are : "<<std::endl;

    Shop sortedShops[MAX_SHOPS_NUMBER];
    for (int i = 0; i < shopsNumber; i++) {
        sortedShops[i] = this->shops[i]; //copy array
    }
    std::sort(sortedShops, sortedShops+this->shopsNumber, sortByDay);
   //now we print sorted array
    for (int i = 0; i < shopsNumber; i++) {
        std::cout << "Shop #" << i + 1 << " :" << std::endl;
        sortedShops[i].print();
        std::cout << std::endl;
    }
}

bool sortByDay(const Shop& sh1, const Shop& sh2) { return sh1.getClosedDay() < sh1.getClosedDay(); }

void Company::printShopsByName() {

    if (shopsNumber == 0) {
        std::cout << "There are no shops in this company." << std::endl;

    }
    std::sort(shops, shops + shopsNumber, [](const Shop& s1, const Shop& s2) {
        return s1.getName() < s2.getName();
        });
    std::cout << "There are " << shopsNumber << " shops in this company. The shops details are : "<<std::endl;
    for (int i = 0; i < shopsNumber; ++i) {
        std::cout << "Shop #" << i + 1 << " :" << std::endl;
        shops[i].print();
        std::cout<<std::endl;
    }
}



