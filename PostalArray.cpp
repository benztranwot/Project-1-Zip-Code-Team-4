#include "PostalArray.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Add an item
void PostalArray::addItem(const PostalCodeItem &item)
{
    items.push_back(item);
}

// Get item by index
PostalCodeItem PostalArray::getItem(int index) const
{
    if (index < items.size())
    {
        return items[index];
    }
    throw out_of_range("Index out of range in PostalArray::getItem");
}

// Find item by ZIP code
const PostalCodeItem *PostalArray::findByZip(int zip) const
{
    for (const auto &item : items)
    {
        if (item.getZip() == zip)
        {
            return &item;
        }
    }
    return nullptr;
}

// Get size
int PostalArray::size() const
{
    return items.size();
}

// Print all
void PostalArray::printAll() const
{
    for (int i = 0; i < items.size(); i++)
    {
        items[i].printInfo();
        cout << "-------------------" << endl;
    }
}

// Print items sorted by ZIP
void PostalArray::printSortedByZip() const
{
    // Make a copy so original order is preserved
    vector<PostalCodeItem> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(),
         [](const PostalCodeItem &a, const PostalCodeItem &b)
         {
             return a.getZip() < b.getZip();
         });

    for (const auto &item : sortedItems)
    {
        item.printInfo();
        cout << "-------------------" << endl;
    }
}

// Print items sorted by state
void PostalArray::printSortedByState() const
{
    // Copy items so we don’t change the internal order
    vector<PostalCodeItem> sortedItems = items;

    sort(sortedItems.begin(), sortedItems.end(),
         [](const PostalCodeItem &a, const PostalCodeItem &b)
         {
             if (a.getState() == b.getState())
             {
                 return a.getZip() < b.getZip(); // secondary sort by ZIP
             }
             return a.getState() < b.getState();
         });

    for (const auto &item : sortedItems)
    {
        item.printInfo();
        cout << "-------------------" << endl;
    }
}