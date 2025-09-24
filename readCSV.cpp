#include <string>
#include "PostalCodeItem.h"
#include "PostalList.h"
#include <fstream>

using namespace std;

void inputCSVtoList(PostalList &inputList, string fileName)
{
    PostalCodeItem item;
    string line = "";
    int location = 0;

    ifstream myFile;
    myFile.open(fileName);

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

        inputList.addItem(item);
    }

    myFile.close();
}