// CSCI 331 Project 1 Zip Code Version 1.0
// TEAM 4: Minh Quan Tran, Mitchell Rogers, Carson Kariniemi, Abel Asfaw, Mahad Farah
// This main1.cpp will output to the screen a table of postal sorted by state

#include <string>
#include "PostalCodeItem.h"
#include "PostalList.h"
#include "readCSV.cpp"

using namespace std;

int main()
{
    PostalList myPostalList;
    string fileName = "us_postal_codes.csv";

    inputCSVtoList(myPostalList, fileName);

    cout << "A table of all the postal sorted by state:" << endl
         << endl;
    cout << left << setw(10) << "Zip Code"
         << setw(20) << "Place Name"
         << setw(10) << "State"
         << setw(30) << "County"
         << setw(12) << "Latitude"
         << setw(12) << "Longitude"
         << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    myPostalList.printSortedByState();

    return 0;
}