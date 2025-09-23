// CSCI 331 Project 1 Zip Code Version 1.0
// TEAM 4: Minh Quan Tran, Mitchell Rogers, Carson Kariniemi, Abel Asfaw

// This is the draft version but it already satisfied the requirement of generating the output data that sorted by zip code and state.
// To run the program, the following command work for me
// g++ .\main.cpp -o .\main.exe
// .\main.exe

#include <string>
#include "PostalCodeItem.h"
#include "PostalArray.h"
#include <fstream>

using namespace std;

int main()
{
    PostalArray arr;
    PostalCodeItem item;
    string line = "";
    int location = 0;

    ifstream myFile;
    myFile.open("us_postal_codes.csv");

    getline(myFile, line);

    while (getline(myFile, line))
    {
        location = line.find(",");
        item.setZip(stoi(line.substr(0, location)));
        line = line.substr(location + 1, line.length());

        location = line.find(",");
        item.setPlace(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        location = line.find(",");
        item.setState(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        location = line.find(",");
        item.setCounty(line.substr(0, location));
        line = line.substr(location + 1, line.length());

        location = line.find(",");
        item.setLatitude(stod(line.substr(0, location)));
        line = line.substr(location + 1, line.length());

        item.setLongitude(stod(line));

        arr.addItem(item);
    }

    myFile.close();

    arr.printSortedByZip();
    // arr.printSortedByState();

    return 0;
}