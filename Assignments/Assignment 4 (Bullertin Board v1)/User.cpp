//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<4>/main.cpp BBoard.cpp BBoard.h Message.cpp Message.h
///               User.h User.cpp
/// @brief Assignment/Lab<4> for CS 12 <spring 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <May 5th, 2015>
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
#include "User.h"
#include <iostream>
using namespace std;

User::User()
    : username(""), password("")
{}

User::User(const string& uname, const string &pass)
    : username(uname), password(pass)
{}

string User::get_username() const
{
    return username;
}

bool User::check(const string &uname, const string &pass) const
{
    if (uname == "" || pass == "")
    {
        return false;
    }
    if (uname == username && pass == password)
    {
        return true;
    }
    
    return false;
}

void User::set_password(const string &newpass)
{
    password = newpass;
}