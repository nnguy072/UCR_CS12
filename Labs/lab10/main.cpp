#include <iostream>
using namespace std;

void reverse(string &s)
{
   unsigned n = s.size();
   if (n <= 1)
   {
      return;
   }
   else
   {
      string a = s.substr(1, s.size() - 2);
      reverse(a);
      s = s.substr(s.size() - 1) + a + s.at(0);
   }
}

int main()
{
   string a;
   cout << "Enter a string: ";
   cin >> a;
   
   reverse(a);
   cout << "Reversed: " << a << endl;
   
   reverse(a);
   cout << "Normal: " << a << endl;
}