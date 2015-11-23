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
#include <iostream>
#include "User.h"
#include "Message.h"
#include "BBoard.h"
#include "Reply.h"
#include "Topic.h"
using namespace std;

int main(int argc, char *argv[])
{
    // makes sure there is 5 command line arguments
    if (argc != 3)
    {
        cout << "ERROR: Invalid program call." << endl;
        cout << "Usage: ./a.out "
             << "userfile "
             << "datafile "
             << endl;
        return 1;
    }
    
    string file = argv[1];
    string file2 = argv[2];
    
    BBoard a("test");
    
    if (!a.load_users(file))
    {
        cout << "Can't load uses from: " << file << endl;
        return 1;
    }
    
    if (!a.load_messages(file2))
    {
        cout << "Can't load messages from: " << file2 << endl;
        return 1;
    }
    
    a.login();
    a.run();
    
    if(!a.save_messages(file2))
    {
        cout << "Can't save messages to: " << file2 << endl;
        return 1;
    }
    
    return 0;
}