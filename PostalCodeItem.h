#ifndef POSTAL_CODE_ITEM
#define POSTAL_CODE_ITEM

using namespace std;

class PostalCodeItem
{
private:
    int zip;
    string place;
    string state;
    string county;
    double latitude;
    double longitude;

public:
    PostalCodeItem();
    PostalCodeItem(int z, const string &p, const string &s, const string &c, double lat, double lon);

    int getZip() const;
    string getPlace() const;
    string getState() const;
    string getCounty() const;
    double getLatitude() const;
    double getLongitude() const;

    void setZip(int newZip);
    void setPlace(const string &newPlace);
    void setState(const string &newState);
    void setCounty(const string &newCounty);
    void setLatitude(double newLat);
    void setLongitude(double newLon);

    void printInfo() const;
};

#include "PostalCodeItem.cpp"
#endif