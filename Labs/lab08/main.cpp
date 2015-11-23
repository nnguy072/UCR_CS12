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
   cout << "IntList 1(should display 412 4 1): ";
   a.display(); cout << endl;
   
   cout << divider << endl;
   
   // tests pop_front;
   a.pop_front();
   cout << "IntList 1(should display 4 1): ";
   a.display(); cout << endl;
   
   cout << divider << endl;
   
   return 0;
}