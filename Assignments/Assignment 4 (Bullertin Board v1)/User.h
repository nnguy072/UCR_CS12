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
#ifndef __USER_H__
#define __USER_H__

//includes
#include <string>

using namespace std;

class User
{
    private:
        string username;
        string password;
    public:
        //creates a user with empty name and password.
        User();

        // creates a user with given username and password.
        User(const string& uname, const string& pass);

        //returns the username
        string get_username() const;
 
        // returns true if the stored username/password matches with the
        // parameters. Otherwise returns false.
        // Note that, even though a User with empty name and password is 
        // actually a valid User object (it is the default User), this 
        // function must still return false if given a empty uname string.
        bool check(const string &uname, const string &pass) const;
 
        // sets a new password. This function will not be used in the 
        // current assignment.
        void set_password(const string &newpass);
};
 
//end inc guards
#endif