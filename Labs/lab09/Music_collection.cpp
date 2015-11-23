#include "Music_collection.h"
using namespace std;

Music_collection::Music_collection()
   :number(0), max(100), collection(new Tune[max])
{}

Music_collection::~Music_collection()
{
   delete[] collection;
}

Music_collection::Music_collection(int n)
   :max(n), number(0), collection(new Tune[max])
{}

Music_collection::Music_collection(const Music_collection &m)
{
   number = m.number;
   max = m.max;
   collection = new Tune[m.max];
   for (int i = 0; i < m.number; i++)
   {
      collection[i] = m.collection[i];
   }
}

bool Music_collection::add_tune(const Tune &t)
{
   if (number == max)
   {
      return false;
   }
   number++;
   collection[number - 1] = t;
   return true;
}

bool Music_collection::set_tune(int index, const Tune &t)
{
   if (index >= number)
   {
      return false;
   }
   collection[index] = t;
   return true;
}

Music_collection& Music_collection::operator=(const Music_collection &m)
{
   number = m.number;
   max = m.max;
   for (int i =0; i < m.number; i++)
   {
      collection[i] = m.collection[i];
   }
   return *this;
}

ostream & operator<<(ostream &out, const Music_collection &m)
{
   for (int i = 0; i < m.number; i++)
   {
      out << m.collection[i].get_title() << '\n';
   }
   return out;
}