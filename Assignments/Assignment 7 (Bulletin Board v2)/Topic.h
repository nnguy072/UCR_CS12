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
#ifndef TOPIC_H
#define TOPIC_H

#include <iostream>
#include "Message.h"
#include "Reply.h"
using namespace std;

class Topic : public Message
{   
    // no new member variables
    public:
    
        //default constructor
        Topic();

        //Parameterized constructor
        Topic(const string &athr, 
              const string &sbjct, 
              const string &body, 
              unsigned id);
	
	    virtual bool is_reply() const;  // Returns false
       
        /* to_formatted_string writes the contents of the Topic to a 
         * string in the following format:
    
          <begin_topic>
          :id: 4
          :subject: single line
          :from: author
          :children: 5 6 [this line should not be printed if there are no children.]
          :body: multiple lines - line 1
          line 2
          line 3
          <end>
    
         * line starting with :children: has the id's of all children (See file specs. 
         * for details)
         * This function should not assume the last character in body is a newline.
         * In other words, this function must manually add a newline after the last line
         * of the body (line 3 in this example).
         * Also, the last character in the string must be a newline.
         */
        virtual string to_formatted_string() const;  // New !!
};

#endif
