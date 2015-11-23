#include "IntVector.h"
#include <cstdlib>

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
