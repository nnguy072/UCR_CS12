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
class IntVector
{
   private:
      unsigned sz;
      unsigned cap;
      int *data;
   public:
      // default constructor
      IntVector();
      
      // constructor: assigns sz/capp to size, sets array to 0
      IntVector(unsigned size);
      
      // constructor: assigns sz/cap to size, sets array to value 
      IntVector(unsigned size, int value);
      
      // desctructor: deletes dynamically allocated stuff
      ~IntVector();
      
      // accessor: returns size
      unsigned size() const;
      
      // accessor: returns capacity
      unsigned capacity() const;
      
      // tells whether array is empty
      bool empty() const;
      
      // accessor: gives the value at the index
      const int & at(unsigned index) const;
      
      // mutator: access value at index and can change it
      int & at(unsigned index);
      
      // mutator: inserts a value into data then shifts everything -> by 1
      void insert(unsigned index, int value);
      
      // mutator: "erases" value at index, shifts everything <- by 1, size - 1
      void erase(unsigned index);
      
      // accessor: returns value in front of data
      const int & front() const;
      
      // mutator: gets/change value in front
      int & front();
      
      // accessor: returns value in back
      const int & back() const;
      
      // mutator: gets/change value in back
      int & back();
      
      // resizes size/cap of vector and initializes elements to value
      void assign(unsigned n, int value);
      
      // mutator: adds value to the end of data
      void push_back(int value);
      
      // mutator: deletes last value of data
      void pop_back();
      
      // sets size to 0
      void clear();
      
      // changes the size of data given a new size
      void resize(unsigned size);
      
      // changes the size of data give na new size, assigns value to new element
      void resize(unsigned size, int value);
      
      // reserves space for vector, increases cap to double
      // or value n (only if n > cap)
      void reserve(unsigned n);
      
   private:
      // doubles capacity
      void expand();
      
      // expands by given amount
      void expand(unsigned amount);
};
