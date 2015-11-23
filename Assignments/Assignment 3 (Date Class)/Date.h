//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<1>/main.cpp 
/// @brief Assignment #3 for CS 12 <Spring & 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <April 22th, 2015>
///
/// @par Enrollment Notes 
///     Lecture Section: 1
/// @par
///     Lab Section: 22
/// @par
///     TA: <TA name>
///
/// @par Plagiarism Section
/// I hereby certify that the code in this file
/// is ENTIRELY my own original work.
//  ================== END ASSESSMENT HEADER ===============
#include <string>

using namespace std;

class Date
{
    private:
        unsigned day;
        unsigned month;
        string monthName;
        unsigned year;
        
        // checks for leap year
        bool isLeap(unsigned) const;
        
        // gives the number of days for a certain month
        unsigned daysPerMonth(unsigned m, unsigned y);
        
        // gives the name of the month using the number
        string name(unsigned m) const;
        
        // gives the name of the month using the number
        unsigned number(const string &mn) const;
        
    public:
        // default constructor: creates the date January 1st, 2000
        Date();
        
        // parameteerized constructor: creates March 1st, 2010 w/ (3, 1, 2010)
        Date(unsigned m, unsigned d, unsigned y);
        
        // parameterized constructor: creates March 1st, 2010 w/ parameters
        Date(const string &mn, unsigned d, unsigned y);
        
        // prints "1/1/1234"
        void printNumeric() const;
        
        // prints "January 1, 2015"
        void printAlpha() const;
};