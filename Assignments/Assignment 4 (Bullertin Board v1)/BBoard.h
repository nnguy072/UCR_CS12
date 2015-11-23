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
#ifndef __BBOARD_H__
#define __BBOARD_H__

#include <string>
#include "User.h"
#include "Message.h"
#include <vector>
#include <fstream>

using namespace std;

class BBoard
{
    private:
        string title;
        vector<User> user_list;
        User current_user;
        vector<Message> message_list;
    public:
        // default constuctor
        BBoard();
        // assigns user's title as title of bboard
        BBoard( const string &ttl);
        // sets up user_lists with a list from a file
        void setup(const string &input_file); 
        // login process for bboard; loops if incorrect
        void login();  
        // basically the main menu for this whole bboard
        void run();
        // checks if user exists
        bool user_exists(const string &name, const string &pass) const;  
        // displays all messages in the vector message_list
        void display() const; 
        // adds a new message into the vector message_list
        void add_message(); 
};

#endif