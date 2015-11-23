//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<6>/main.cpp IntList.h IntList.cpp
///               
/// @brief Assignment/Lab<8> for CS 12 <spring 2015>
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

#include "IntList.h"
#include <iostream>
using namespace std;

int main()
{
   IntList a;
   IntList b;
   
   string divider = string(68, '-');
   
   cout << divider << endl;
   
   // testing push_front function
   a.push_front(1);
   a.push_front(4);
   a.push_front(412);
   
   // tests display
   cout << "IntList 1: testing push_front function" << endl;
   cout << "(should display 412 4 1): ";
   a.display(); cout << endl;
   
   cout << "IntList 2: testing empty list" << endl;
   cout << "(should display nothing): ";
   b.display(); cout << endl;
   
   cout << divider << endl;
   
   // tests pop_front;
   a.pop_front();
   cout << "IntList 1: testing pop_front function" << endl;
   cout << "(should display 4 1): ";
   a.display(); cout << endl;
   
   cout << "IntList 2: testing pop_front on empty" << endl;
   cout << "(should do nothing): ";
   b.pop_front();
   b.display(); cout << endl;
   
   b.push_front(4);
   cout << "IntList 2: testing pop_front on 1 element" << endl;
   cout << "(should see nothing): ";
   b.pop_front();
   b.display(); cout << endl;
   
   cout << divider << endl;
   
   a.push_back(3);
   a.push_back(213);
   a.push_back(61);
   
   // testing select_sort
   cout << "IntList 1: testing select_sort function" << endl;
   cout << "(should display 1 3 4 61 213): ";
   a.select_sort();
   a.display(); cout << endl;
   cout << "IntList 2: testing empty list" << endl;
   b.select_sort();
   b.display(); cout << endl;
   
   cout << divider << endl;
   
   // testing insert_sorted()
   
   cout << "IntList 1: testing insert_sorted function" << endl;
   cout << "(should display 1 2 3 4 61 213 400): ";
   a.insert_sorted(2);
   a.insert_sorted(400);
   a.display(); cout << endl;
   
   cout << "IntList 2: testing_sorted on empty list" << endl;
   cout << "(should display 4): ";
   b.insert_sorted(4);
   b.display(); cout << endl;
   
   cout << divider << endl;
   return 0;
}