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
#include <sstream>
#include "Message.h"
#include "Reply.h"
#include "Topic.h"
using namespace std;

Reply::Reply()
    : Message()
{}

Reply::Reply(const string &athr, 
             const string &sbjct, 
             const string &body, 
             unsigned id)
    : Message(athr, "Re: " + sbjct, body, id)
{}

bool Reply::is_reply() const
{
    return true;
}

string Reply::to_formatted_string() const
{
    stringstream ss;
    
    string whole;
    
    ss << "<begin_reply>" << endl;
	ss << ":id: " << id  << endl;
	ss << ":subject: " << subject << endl;
	ss << ":from: " << author << endl;
	if(child_list.size() != 0)
	{
		ss << ":children: ";
		for(unsigned i = 0; i < child_list.size(); i++)
		{
			ss << child_list.at(i)->get_id();
			if(i != child_list.size() - 1)
				ss << " ";
		}
		ss << endl;
	}
	
	ss << ":body: " << body << endl;
	ss << "<end>" << endl;
	whole = ss.str();
	
	return whole;
}