#include <iostream>

using namespace std;

class Rational
{
   private:
      int numer;
      int denom;
   public:
      Rational();
      Rational(int);
      Rational(int, int);
      const Rational add(const Rational &) const;
      const Rational subtract(const Rational &) const;
      const Rational multiply(const Rational &) const;
      const Rational divide(const Rational &) const;
      void display() const;
};

Rational::Rational()
{
     numer = 0;
     denom = 1;
}

Rational::Rational(int a)
{
   numer = a;
   denom = 1;
}

Rational::Rational(int a, int b)
{
   numer = a;
   denom = b;
}

Rational const Rational::add(const Rational &a) const
{
  Rational n;
  n.numer = (numer * a.denom) + (denom * a.numer);  
  n.denom = (denom * a.denom);
  return n;
}

Rational const Rational::subtract(const Rational &a) const
{
   Rational n;
   n.numer = (numer * a.denom) - (denom * a.numer);
   n.denom = (denom * a.denom);
   return n;
}

Rational const Rational::multiply(const Rational &a) const
{
   Rational n;
   n.numer = (a.numer * numer);
   n.denom = (a.denom * denom);
   return n;
}

Rational const Rational::divide(const Rational &a) const
{
   Rational n;
   n.numer = (numer * a.denom);
   n.denom = (a.numer * denom);
   return n;
}

void Rational::display() const
{
   cout << numer << "/" << denom;  
}

int main()
{
   
   return 0;
}