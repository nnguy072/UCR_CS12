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
#include <iostream>
#include "Message.h"
using namespace std;

Message::Message()
    : author(""), subject(""), body("")
{}

Message::Message(const string &arthr, const string &sbjct, const string &body)
    : author(arthr), subject(sbjct), body(body)
{}

void Message::display() const
{
    cout << subject << endl;
    cout << "from " << author << ": " << body << endl;
}