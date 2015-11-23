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
#include "User.h"
#include "Message.h"
#include "BBoard.h"
using namespace std;

int main(int argc, char *argv[])
{
    // makes sure there is 5 command line arguments
    if (argc != 2)
    {
        cout << "Usage: ./a.out "
             << "input_file_name "
            //  << "BBoard.h "
            //  << "Message.h "
            //  << "User.h"
             << endl;
        return 0;
    }
    
    string file = argv[1];
    
    BBoard test;
    test.setup(file);
    test.run();
    
    return 0;
}