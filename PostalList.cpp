#include "PostalList.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Add an item
void PostalList::addItem(const PostalCodeItem &item)
{
    items.push_back(item);
}

// Get item by index
PostalCodeItem PostalList::getItem(int index) const
{
    if (index < items.size())
    {
        return items[index];
    }
    throw out_of_range("Index out of range in PostalList::getItem");
}

// Find item by ZIP code
const PostalCodeItem *PostalList::findByZip(int zip) const
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
int PostalList::size() const
{
    return items.size();
}

// Print all
void PostalList::printAll() const
{
    for (int i = 0; i < items.size(); i++)
    {
        items[i].printInfo();
        cout << "-------------------" << endl;
    }
}

// Print items sorted by ZIP
void PostalList::printSortedByZip() const
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
void PostalList::printSortedByState() const
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