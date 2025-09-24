#include "PostalCodeItem.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

PostalCodeItem::PostalCodeItem()
{
    zip = 0;
    place = "";
    state = "";
    county = "";
    latitude = 0;
    longitude = 0;
}

PostalCodeItem::PostalCodeItem(int z, const string &p, const string &s, const string &c, double lat, double lon)
{
    zip = z;
    place = p;
    state = s;
    county = c;
    latitude = lat;
    longitude = lon;
}

int PostalCodeItem::getZip() const
{
    return zip;
}

string PostalCodeItem::getPlace() const
{
    return place;
}

string PostalCodeItem::getState() const
{
    return state;
}

string PostalCodeItem::getCounty() const
{
    return county;
}

double PostalCodeItem::getLatitude() const
{
    return latitude;
}

double PostalCodeItem::getLongitude() const
{
    return longitude;
}

void PostalCodeItem::setZip(int newZip)
{
    zip = newZip;
}

void PostalCodeItem::setPlace(const string &newPlace)
{
    place = newPlace;
}

void PostalCodeItem::setState(const string &newState)
{
    state = newState;
}

void PostalCodeItem::setCounty(const string &newCounty)
{
    county = newCounty;
}

void PostalCodeItem::setLatitude(double newLat)
{
    latitude = newLat;
}

void PostalCodeItem::setLongitude(double newLon)
{
    longitude = newLon;
}

void PostalCodeItem::printInfo() const
{
    cout << left << setw(10) << zip
         << setw(20) << place
         << setw(10) << state
         << setw(30) << county
         << setw(12) << latitude
         << setw(12) << longitude
         << endl;
}