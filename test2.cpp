// This file is for testing the PostalList

#include <string>
#include "PostalCodeItem.h"
#include "PostalList.h"

using namespace std;

int main()
{
    PostalList arr;
    arr.addItem(PostalCodeItem(90210, "Beverly Hills", "CA", "Los Angeles", 34.09, -118.40));
    arr.addItem(PostalCodeItem(60601, "Chicago", "IL", "Cook", 41.88, -87.62));
    arr.addItem(PostalCodeItem(12345, "Springfield", "IL", "Sangamon", 39.78, -89.64));
    arr.addItem(PostalCodeItem(77001, "Houston", "TX", "Harris", 29.76, -95.36));

    // arr.printAll();

    // const PostalCodeItem *found = arr.findByZip(90210);
    // if (found)
    // {
    //     std::cout << "Found ZIP 90210:" << std::endl;
    //     found->printInfo();
    // }

    cout << "Sorted by ZIP:\n";
    arr.printSortedByZip();

    // cout << "Sorted by State:\n";
    // arr.printSortedByState();
}