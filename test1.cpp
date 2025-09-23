// This file is for testing the PostalCodeItem class

#include <iostream>
#include <string>
#include "PostalCodeItem.h"

using namespace std;

int main()
{
    // Create an object using the parameterized constructor
    PostalCodeItem p1(55401, "Minneapolis", "MN", "Hennepin", 44.9778, -93.2650);

    // Create an object using the default constructor and set values later
    PostalCodeItem p2;
    p2.setZip(90210);
    p2.setPlace("Beverly Hills");
    p2.setState("CA");
    p2.setCounty("Los Angeles");
    p2.setLatitude(34.0901);
    p2.setLongitude(-118.4065);

    // Print the information for both objects
    p1.printInfo();
    std::cout << "--------------------" << std::endl;
    p2.printInfo();

    return 0;
}