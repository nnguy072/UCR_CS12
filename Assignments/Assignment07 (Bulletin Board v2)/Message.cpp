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
#include "Message.h"
using namespace std;

Message::Message()
    : author(""), subject(""), body(""), id(0)
{}

Message::Message(const string &athr,
                 const string &sbjct, 
                 const string &body,
                 const unsigned num)
    : author(athr), subject(sbjct), body(body), id(num)
{}

Message::~Message()
{}

void Message::print(unsigned indentation) const
{
    string indent = "";
    
    string a = body;
    
    for(unsigned i = 0; i < indentation; i++)
    {
        indent += "  ";
    }
    if (is_reply())
    {
        cout << endl;
    }
    cout << indent << "Message #" << get_id() << ": " << get_subject() << endl;
    cout << indent << "from " << author << ": ";
    for (int i = 0; i < static_cast<int>(a.size()) - 1; i++)
    {
        if (a.at(i) == '\n')
        {
            a.insert(i + 1, indent);
        }
        
    }
    cout << a << endl;
    if (child_list.size() != 0)
    {
        for (unsigned i = 0; i < child_list.size(); i++)
        {
            child_list.at(i)->print(indentation + 1);
        }
    }
}

const string & Message::get_subject() const
{
    return subject;
}

unsigned Message::get_id() const
{
    return id;   
}

void Message::add_child(Message* child)
{
    child_list.push_back(child);
}