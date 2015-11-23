//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<7>/main.cpp BBoard.cpp BBoard.h Message.cpp Message.h
///               User.h User.cpp Topic.h Topic.cpp Reply.h Reply.cpp Makefile
/// @brief Assignment/Lab<4> for CS 12 <spring 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <June 3rd, 2015>
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
        const User *current_user;
        vector<Message *> message_list;
        void display() const;
        void add_topic();
        void add_reply();
        const User * get_user(const string &name, const string &pw) const;
        
    public:
        // default constuctor
        BBoard();
        // assigns user's title as title of bboard
        BBoard( const string &ttl);
        // destructor
        ~BBoard();
        bool load_users(const string &userfile);
        bool load_messages(const string &datafile);
        bool save_messages(const string &datafile);
        void login();
        void run();
};

#endif