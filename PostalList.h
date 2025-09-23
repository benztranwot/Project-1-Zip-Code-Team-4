#ifndef POSTAL_LIST_H
#define POSTAL_LIST_H

#include "PostalCodeItem.h"
#include <vector>

using namespace std;

class PostalList
{
private:
    vector<PostalCodeItem> items;

public:
    // Constructors
    PostalList() = default;

    // Add an item
    void addItem(const PostalCodeItem &item);

    // Get item by index
    PostalCodeItem getItem(int index) const;

    // Find item by ZIP code (returns pointer or nullptr)
    const PostalCodeItem *findByZip(int zip) const;

    // Get number of items
    int size() const;

    // Print all postal codes
    void printAll() const;

    // Print items sorted by ZIP
    void printSortedByZip() const;

    // Print items sorted by state
    void printSortedByState() const;
};

#include "PostalList.cpp"
#endif