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
//inclusion guards
#ifndef __MESSAGE_H__
#define __MESSAGE_H__

//includes
#include <string>
using namespace std;

class Message
{
    private:
        string author;
        string subject;
        string body;

    public:
        //default constructor
        Message();

        //Constructor with parameters
        Message(const string &athr, 
                const string &sbjct, 
                const string &body);

        //displays the message in the given format. See output specs.
        //Note: R’Sub will require an endl as the last output of this
        //function.
        void display() const;
};

//end inc guards
#endif