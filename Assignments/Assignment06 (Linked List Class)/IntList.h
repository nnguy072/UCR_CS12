//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<6>/main.cpp IntList.h IntList.cpp
///              
/// @brief Assignment/Lab<8> for CS 12 <spring 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <May 19th, 2015>
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

struct IntNode
{
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};

class IntList
{
   private:
      IntNode *head;
      IntNode *tail;
   public:
      // default constructor
      IntList();
      // default destructor
      ~IntList();
      // displays values in the list
      void display() const;
      // adds a value to the front of the list
      void push_front(int value);
      void push_back(int value);
      // deletes the front value
      void pop_front();
      // does a selection sort on the list
      void select_sort();
      // inserts value into the list
      void insert_sorted(int value);
      // removes duplicate elements with the same value
      void remove_duplicates();
      
};