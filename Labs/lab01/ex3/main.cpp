#include <iostream>
#include <vector>

using namespace std;

int search(const vector<int> &v, int a);
void remove(vector<int> &v, int a, vector<int> &v1);
void printVector(const vector<int> &v);

int main()
{
   vector<int> listNum;
   int input, searchNum;
   vector<int> listNew;
   
   //get a list of numbers, press 0 to stop
   cout << "Please enter in integers (0 to stop): ";
   do
   {
      cin >> input;
      listNum.push_back(input);
   } while (input != 0);
   listNum.pop_back();
   
   //get number to find\remove
   cout << "What number would you like to find and remove?: ";
   cin >> searchNum;

   //gives the index the number was found at
   cout << "Found: " << search(listNum, searchNum) << endl;
   //removes the number
   remove(listNum, searchNum, listNew);

   cout << "Results: ";
   //displays the new vector
   printVector(listNew);
   
   return 0;
}

//functions
int search(const vector<int> &v, int a)
{
   int index = 0;
   for (int i = 0; i < v.size(); i++)
   {
      if (v.at(i) == a)
      {
         index = i;
         return index;
      }
   }
   return -1;
}

// basically replaces the search number with 0, then puts all non-zeroes
// into a new vector
void remove(vector<int> &v, int a, vector<int> &v1)
{
   for (int i = 0; i < v.size(); i++)
   {
      if (v.at(i) == a)
      {
         v.at(i) = 0;
         break;
      }
   }
   for (int i = 0; i < v.size(); i++)
   {
      if (v.at(i) != 0)
      {
         v1.push_back(v.at(i));
      }
   }
}

void printVector(const vector<int> &v)
{
   for (int i = 0; i < v.size(); i++)
   {
      cout << v.at(i) << " ";
   }
   cout << endl;
}