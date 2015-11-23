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
#include "User.h"
#include "BBoard.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

BBoard::BBoard()
    : title("Jack's Amazing Bulletin Board")
{}

BBoard::BBoard(const string &ttl)
{
    title = ttl;
}

void BBoard::setup(const string &input_file)
{
    ifstream fin;
    string uname, pw;
    
    fin.open(input_file.c_str());
    
    fin >> uname;
    
    while(uname != "end")
    {
        fin >> pw;
        
        user_list.push_back(User(uname, pw));
        
        fin >> uname;
    }
    
    fin.close();
}

void BBoard::login()
{
    string uname, pw;
    bool exist = false;
    while(!exist)
    {
        cout << "Enter your username (\'Q\' or \'q\' to quit): ";
        cin >> uname;
        
        if(uname == "Q" || uname == "q")
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        cout << "Enter your password: ";
        cin >> pw;
        
        exist = user_exists(uname, pw);
        
        if(!exist)
        {
            cout << "Invalid Username or Password!\n" << endl;
        }
    }
    
    current_user = User(uname, pw);
    
    cout << "Welcome back " << current_user.get_username() << "!" << endl;
}

void BBoard::run()
{
    char a;
    
    cout << "Welcome to " << title << endl;
    
    login();
    
    do
    {
        cout << "\nMenu" << endl;
        cout << "  - Display Message (\'D\' or \'d\')" << endl;
        cout << "  - Add New Message (\'N\' or \'n\')" << endl;
        cout << "  - Quit (\'Q\' or \'q\')" << endl;
        cout << "Choose an action: ";
        cin >> a;
        cout << endl;
    
        if ((a != 'D' && a != 'd') && (a != 'N' && a != 'n') && 
            (a != 'Q' && a != 'q'))
        {
            cout << "\nInvalid action. Please try again.\n" << endl;
            continue;
        }
    
        if (a == 'D' || a == 'd')
        {
            display();
        }
        else if (a == 'N' || a == 'n')
        {
            add_message(); 
        }
    } while (a != 'Q' && a != 'q');
    
    cout << "Bye!" << endl;
    return;
}

bool BBoard::user_exists(const string &name, const string &pass) const
{
    for (unsigned i = 0; i < user_list.size(); i++)
    {
        if (user_list.at(i).check(name, pass))
        {
            return true;
            break;
        }
    }
    
    return false;
}

void BBoard::display() const
{
    if (message_list.size() == 0)
    {
        cout << "\nNothing to Display.\n" << endl;
        return;
    }
    
    cout << string(48, '-') << endl;
    for (unsigned i = 0; i < message_list.size(); i++)
    {
        cout << "Message #" << i + 1 << ": ";
        message_list.at(i).display();
        cout << string(48, '-') << endl;
    }
}

void BBoard::add_message()
{
    string sub, msg, a;
    
    cout << "\nEnter Subject: ";
    getline(cin, sub);
    getline(cin, sub);
    cout << "Enter Body: ";
    getline(cin, msg);
    // getline(cin, msg);
    
    message_list.push_back(Message(current_user.get_username(), sub, msg));
    
    cout << "Message Recorded!" << endl;
}