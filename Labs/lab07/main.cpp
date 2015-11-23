#include <iostream>
#include "IntVector.h"
using namespace std;

string divider = string(60, '-');

int main()
{
    cout << divider << endl;
    
    IntVector v1;        // default constructor
    IntVector v2(3);     // (size/capp)
    IntVector v3(4, 5);  // (size/cap, value)
    
    // tests outputs for constructors
    cout << "vector 1 (should display 0, 0)\ncapacity: " << v1.capacity() 
         << " size: " << v1.size() << endl;
    cout << "vector 2 (should display 3, 3)\ncapacity: " << v2.capacity() 
         << " size: " << v2.size() << endl;
    cout << "vector 3 (should display 4, 4)\ncapacity: " << v3.capacity() 
         << " size: " << v3.size() << endl;
    
    cout << divider << endl;
    
    // test empty member function
    cout << "Vector 1 is empty. This should return true: " << boolalpha 
         << v1.empty() << endl;
    cout << "Vector 2 is not empty. This should return false: " << v2.empty()
         << endl;
    cout << "Vector 3 is not empty. This should return false: " << v3.empty()
         << endl;
    
    cout << divider << endl;
    
    // tests at function
    // cout << "Vector 1 at 3 should exit program: " << v1.at(3) << endl;
    cout << "Vector 2 at 2 should be 0: " << v2.at(2) << endl;
    cout << "Vector 3 at 3 should be 5: " << v3.at(3) << endl;
    
    return 0;
}