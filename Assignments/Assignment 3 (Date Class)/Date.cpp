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
// dank memes
#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
    :day(1), month(1), year(2000), monthName("January")
{}

Date::Date(unsigned m, unsigned d, unsigned y)
{
    month = m;
    day = d;
    year = y;
    bool workie = false;
    
    if(day > 31)
    {
        workie = true;
        day = daysPerMonth(m, y);
    }
    else if((m == 4 || m == 6 | m == 9 || m == 11) && (d >= 31))
    {
        workie = true;
        day = daysPerMonth(m, y);
    }
    else if((d > 28 && m == 2 && !isLeap(y)) || (d > 29 && m ==2 && isLeap(y)))
    {
        day = daysPerMonth(m, y);
        workie = true;
    }
    
    if(month > 12)
    {
        month = 12;
        workie = true;
    }
    else if (month < 1)
    {
        month = 1;
        workie = true;
    }
    
    if (workie)
    {
        cout << "Invalid date values: Date corrected to " 
            << month << "/" << day << "/" << year << "." << endl;
    }
    
    monthName = name(month);
}

Date::Date(const string &mn, unsigned d, unsigned y)
{
    year = y;
    day = d;
    bool workie = false;
    
    if (mn == "January" || mn == "january")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "February" || mn == "february")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "March" || mn == "march")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "April" || mn == "april")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "May" || mn == "may")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "June" || mn == "june")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "July" || mn == "july")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "August" || mn == "august")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "September" || mn == "september")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "October" || mn == "october")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "November" || mn == "november")
    {
        workie = true;
        monthName = mn;
    }
    else if(mn == "December" || mn == "december")
    {
        workie = true;
        monthName = mn;
    }
    
    if (!workie)
    {
        monthName = "January";
        day = 1;
        year = 2000;
        cout << "Invalid month name: the Date was set to 1/1/2000" << endl;
        workie = true;
    }
    
    // days
    if((number(monthName) == 4 || number(monthName) == 6 || 
        number(monthName) == 9 || number(monthName) == 11) && (d >= 31))
    {
        workie = true;
        d = daysPerMonth(number(monthName), y);
    }
    else if (d > 31)
    {
        workie = true;
        d = daysPerMonth(number(monthName), y);
    }
    else if ((number(monthName) == 2 && d > 28 && !isLeap(y)) || 
        (number(monthName) == 2 && d > 29 && isLeap(y)))
    {
        workie = true;
        d = daysPerMonth(number(monthName), y);
    }
    
    if (!workie)
    {
        cout << "Invalid date values: Date corrected to " 
            << number(monthName) << "/" << d << "/" << y << "." << endl;
    }
    
    month = number(monthName);
}

void Date::printNumeric() const
{
    cout << month << "/" << day << "/" << year;
}

void Date::printAlpha() const
{
    cout << monthName << " " << day << ", " << year;
}

bool Date::isLeap(unsigned y) const
{
    if ((year % 4 == 0 && (year % 400 == 0 || !(year % 100 == 0))))
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned Date::daysPerMonth(unsigned m, unsigned y)
{
    if (m == 2  && !isLeap(y))
    {
        return 28;
    }
    else if (m == 2 && isLeap(y))
    {
        return 29;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
    else
    {
        return 31;
    }
}

unsigned Date::number(const string &mn) const
{
    if (mn == "January" || mn == "january")
    {
        return 1;
    }
    else if(mn == "February" || mn == "february")
    {
        return 2;
    }
    else if(mn == "March" || mn == "march")
    {
        return 3;
    }
    else if(mn == "April" || mn == "april")
    {
        return 4;
    }
    else if(mn == "May" || mn == "may")
    {
        return 5;
    }
    else if(mn == "June" || mn == "june")
    {
        return 6;
    }
    else if(mn == "July" || mn == "july")
    {
        return 7;
    }
    else if(mn == "August" || mn == "august")
    {
        return 8;
    }
    else if(mn == "September" || mn == "september")
    {
        return 9;
    }
    else if(mn == "October" || mn == "october")
    {
        return 10;
    }
    else if(mn == "November" || mn == "november")
    {
        return 11;
    }
    else if(mn == "December" || mn == "december")
    {
        return 12;
    }
    else 
    {
        return 0;
    }
}

string Date::name(unsigned m) const
{
    if (m == 1)
    {
        return "January";
    }
    else if(m == 2)
    {
        return "February";
    }
    else if(m == 3)
    {
        return "March";
    }
    else if(m == 4)
    {
        return "April";
    }
    else if(m == 5)
    {
        return "May";
    }
    else if(m == 6)
    {
        return "June";
    }
    else if(m == 7)
    {
        return "July";
    }
    else if(m == 8)
    {
        return "August";
    }
    else if(m == 9)
    {
        return "September";
    }
    else if(m == 10)
    {
        return "October";
    }
    else if(m == 11)
    {
        return "November";
    }
    else if(m == 12)
    {
        return "December";
    }
    else
    {
        return " ";
    }
}
