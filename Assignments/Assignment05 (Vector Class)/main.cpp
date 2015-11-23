//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<5>/main.cpp IntVector.cpp IntVector.h
///               User.h User.cpp
/// @brief Assignment/Lab<7> for CS 12 <spring 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <May 11th, 2015>
///
/// @par Enrollment Notes 
///     Lecture Section: <1>
/// @par
///     Lab Section: <22>
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
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
    v2.at(2) = 4;
    cout << "Vector 2 at 2 changing to 4: " << v2.at(2) << endl;
    cout << "Vector 3 at 3 should be 5: " << v3.at(3) << endl;
    v3.at(3) = 100;
    cout << "Vector 3 at 3 changing to 100: " << v3.at(3) << endl;

    
    cout << divider << endl;
    
    // tests front/back function
    cout << "Vector 3 (should display 5, 5)\nfront: " << v3.front() << " back: "
         << v3.back() << endl;
    v3.front() = 3;
    v3.back() = 6;
    cout << "Vector 3 (should display 3, 6)\nfront: " << v3.front() << " back: "
         << v3.back() << endl;
    
    cout << divider << endl;
    
    // testing insert
    cout << "Vector 3 before insert: ";
    for (unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << " ";
    }
    cout << endl;
    cout << "Vector 3 after (should display 3 4 5 5 6): ";
    v3.insert(1, 4);
    for (unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << " ";
    }
    cout << endl;

    cout << divider << endl;
    
    // testing pop_back, push_back, erase
    cout << "vector 1 push_back a 3 (should see 3 4 5 5 6 3): ";
    v3.push_back(3);
    for (unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << " ";
    }
    cout << "\nVector 1 pop_back (should see 3 4 5 5 6): ";
    v3.pop_back();
    for (unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << " ";
    }
    cout << endl;
    cout << "Vector 1 erasing index 2 (should see 3 4 5 6): ";
    v3.erase(2); cout << endl;
    
    cout << divider << endl;
    
    // testing resize
    cout << "Vector 3 resizing(should see 4, 7):\n" << "current size: " << v3.size() 
         << " ";
    v3.resize(7);
    cout << "new size: " << v3.size() << endl;
    
    cout << divider << endl;
    
    // testing assign
    cout << "Vector 3 assigning new size/cap to 7 and values to 10:" << endl;
    v3.assign(7,10);
    cout << "(Should display 10 10 10 10 10 10 10):";
    for (unsigned i = 0; i < v3.size(); i++)
    {
        cout << v3.at(i) << " ";
    } cout << endl;
    
    cout << divider << endl;
    
    return 0;
}