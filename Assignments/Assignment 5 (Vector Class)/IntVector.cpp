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
#include "IntVector.h"
#include <cstdlib>

// -----------------------------------------------------------------------------
// Constructors
// -----------------------------------------------------------------------------
IntVector::IntVector()
   :sz(0), cap(0), data(0)
{}

IntVector::IntVector(unsigned size)
{
   sz = size;
   cap = size;
   data = new int[size];
   
   for (unsigned i = 0; i < size; i++)
   {
      data[i] = 0;
   }
}

IntVector::IntVector(unsigned size, int value)
{
   sz = size;
   cap = size;
   data = new int[size];
   
   for (unsigned i = 0; i < size; i++)
   {
      data[i] = value;
   }
}

// -----------------------------------------------------------------------------
// Accessors
// -----------------------------------------------------------------------------
unsigned IntVector::size() const
{
   return sz;
}

unsigned IntVector::capacity() const
{
   return cap;
}

bool IntVector::empty() const
{
   if (sz == 0)
   {
      return true;
   }
   return false;
}

const int & IntVector::at(unsigned index) const
{
   if (index >= sz)
   {
      exit(1);
   }
   
   return data[index];
}

const int & IntVector::front() const
{
   return data[0];
}

const int & IntVector::back() const
{
   return data[sz - 1];  
}

// -----------------------------------------------------------------------------
// Destructor, Mutators, Private Helper Functions
// -----------------------------------------------------------------------------
IntVector::~IntVector()
{
   delete[] data;
}

// temp holds address of data, data points to new cap, copies old stuff to new
// deletes old stuff
void IntVector::expand()
{
   int *temp = data;
   
   cap *= 2;
   if (cap == 0)
   {
      cap += 1;
   }
   
   data = new int[cap];
   for (unsigned i = 0; i < sz; i++)
   {
      data[i] = temp[i];
   }
   
   delete[] temp;
}

void IntVector::expand(unsigned amount)
{
   int *temp = data;
   
   cap += amount;
   
   data = new int[cap];
   for (unsigned i = 0; i < sz; i++)
   {
      data[i] = temp[i];
   }
   
   delete[] temp;
}

void IntVector::insert(unsigned index, int value)
{
   sz += 1;
   if (sz > cap)
   {
      expand();
   }
   
   if (index >= sz)
   {
      exit(1);
   }
   
   // starts from the end of the array and shifts everything beginning at the 
   // index to the right
   for (unsigned i = sz - 1; i > index; i--)
   {
      data[i] = data[i - 1];
   }
   
   data[index] = value;
}

void IntVector::erase(unsigned index)
{
   if (index >= sz)
   {
      exit(1);
   }
   
   // deleting part: starts at index then shifts everything <-
   for (unsigned i = index; i < sz; i++)
   {
      data[i] = data[i + 1];
   }
   
   sz -= 1;
}

void IntVector::push_back(int value)
{
   sz += 1;
 
   if (sz == 1)
   {
      data = new int[sz];
   }
   
   if (sz > cap)
   {
      expand();
   }
   
   data[sz - 1] = value;
}

void IntVector::pop_back()
{
   if (empty())
   {
      exit(1);
   }
   
   sz -= 1;
}

void IntVector::clear()
{
   sz = 0;
}

void IntVector::resize(unsigned size)
{
   if (size <= sz)
   {
      sz = size;
   }
   else if (size > sz)
   {
      // chooses to expand() or expand(unsigned amount)
      // depends on largest amount
      if (size > cap)
      {
         if (cap * 2 <= size - cap)
         {
            expand(size - cap);
         }
         else
         {
            expand();
         }
      }
      
      // starts at old size then goes to new size, assigning 0 to elements
      for (unsigned i = sz; i < size; i++)
      {
         data[i] = 0;
      }
      
      sz = size;
   }
}

void IntVector::resize(unsigned size, int value)
{
   // this part is the same as the other resize
   if (size <= sz)
   {
      sz = size;
   }
   else if (size > sz)
   {
      if (size > cap)
      {
         if (cap * 2 <= size - cap)
         {
            expand(size - cap);
         }
         else
         {
            expand();
         }
      }
   }
   
   // assigns value to the new elements
   for (unsigned i = sz; i < size; i++)
   {
      data[i] = value;
   }
   
   sz = size;
}

void IntVector::reserve(unsigned n)
{
   if (n > cap)
   {
      if (cap * 2 < n)
      {
         expand(n - cap);
      }
      else
      {
         expand();  
      }
   }
}

void IntVector::assign(unsigned n, int value)
{
   reserve(n);
   
   sz = n;
   for (unsigned i = 0; i < sz; i++)
   {
      data[i] = value;
   }
}

int & IntVector::at(unsigned index)
{
   if (index >= sz)
   {
      exit(1);  
   }
   
   return data[index];
}

int & IntVector::front()
{
   return data[0];
}

int & IntVector::back()
{
   return data[sz - 1];
}