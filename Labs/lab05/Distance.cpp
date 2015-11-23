#include <iostream>
#include "Distance.h"
#include <cmath>

using namespace std;

Distance::Distance()
   :feet(0), inches(0)
{}

Distance::Distance(unsigned ft, double in)
{
   feet = ft;
   
   if (in < 0)
   {
      inches = abs(in);
   }
   else
   {
      inches = in;  
   }
   
   init();
}

Distance::Distance(double in)
{
   feet = 0;
   
   if (in < 12 && in >= 0)
   {
      inches = in;
   }
   else
   {
      
      inches = abs(in);
      init();
   }
}

void Distance::init()
{
   while (inches >= 12)
   {
      inches -= 12;
      feet++;
   }
}

void Distance::display() const
{
   cout << feet << "\' " << inches << "\"";
}

double Distance::convertToInches() const
{
   double tempInches = 0.0;
   
   tempInches = feet * 12;
   return tempInches + inches;
}

const Distance Distance::operator+(const Distance &a) const
{
   Distance b;

   b.inches = convertToInches() + a.convertToInches();
   b.init();
   
   return b;
}

const Distance Distance::operator-(const Distance &a) const
{
   Distance b;
   
   if (feet > a.feet)
   {
      b.inches = abs(convertToInches() - a.convertToInches()); 
   }
   else
   {
      b.inches = abs(a.convertToInches() - convertToInches());
   }
   b.init();
   
   return b;
}