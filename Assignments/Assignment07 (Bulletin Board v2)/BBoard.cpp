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
#include "User.h"
#include "BBoard.h"
#include "Topic.h"
#include "Message.h"
#include "Reply.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

BBoard::BBoard()
    : title("Jack's Amazing Bulletin Board"), current_user(0)
{}

BBoard::BBoard(const string &ttl)
    : title(ttl), current_user(0)
{}

BBoard::~BBoard()
{
    for(unsigned i = 0; i < message_list.size(); i++)
    {
        if (message_list.at(i) != 0)
        {
            delete message_list.at(i);
        }
    }
}

bool BBoard::load_users(const string &userfile)
{
    ifstream fin;
    string un, pw;
    
    fin.open(userfile.c_str());
    if (!fin.is_open())
    {
        cout << "Error opening file." << endl;
        return false;
    }
    
    fin >> un;
    
    while (un != "end")
    {
        fin >> pw;
        
        user_list.push_back(User(un, pw));
        
        fin >> un;
    }
    
    fin.close();
    return true;
}

bool BBoard::load_messages(const string &datafile)
{
    ifstream fin;
    ofstream fout;
    stringstream ss;
    
    fin.open(datafile.c_str());
    if(!fin.is_open())
    {
        cout << "Error opening file." << endl;
        return false;
    }
    
    unsigned numMessages;
    
    fin >> numMessages;
    
    string ignore;
    string author, subject, userName, body, child;
    unsigned id, child_id;
    vector<string> children;
    Message *newTopic = 0;
    Message *newReply = 0;
    
    while(!fin.eof())
    {
        fin >> ignore;
        
        if(ignore == "<begin_topic>")
        {
            while (ignore != "<end>")
            {
                fin >> ignore;
                if(ignore == ":id:")
                {
                    fin >> id;
                }
                else if (ignore == ":subject:")
                {
                    fin.get();
                    getline(fin, subject);
                }
                else if(ignore == ":from:")
                {
                    fin >> author;
                }
                else if(ignore == ":children:")
                {
                    getline(fin, ignore);
                    children.push_back(ignore);
                }
                else if (ignore == ":body:")
                {
                    body = "";
                    fin.get();
                    while(ignore != "<end>")
                    {
                        getline(fin, ignore);
                        if(ignore != "<end>")
                        {
                            body += ignore;
                        }
                        
                        fin >> ignore;
                        
                        if(ignore != "<end>")
                        {
                            body += ("\n" + ignore);
                        }
                    }
                    
                    if (body.size() != 0 && body.at(body.size() - 1) == '\n')
                    {
                        body.erase(body.size() - 1);
                    }
                    child = "0";
                    children.push_back(child);
                }
            }
            
            newTopic = new Topic(author, subject, body, id);
            message_list.push_back (newTopic);
        }
        else if (ignore == "<begin_reply>")
        {
            while (ignore != "<end>")
                {
                    fin >> ignore;
                    if(ignore == ":id:")
                    {
                        fin >> id;
                    }
                    else if (ignore == ":subject:")
                    {
                        fin.get();
                        fin >> ignore;
                        fin.get();
                        getline(fin, subject);
                    }
                    else if(ignore == ":from:")
                    {
                        fin >> author;
                    }
                    else if(ignore == ":children:")
                    {
                        getline(fin, ignore);
                        children.push_back(ignore);
                    }
                    else if (ignore == ":body:")
                    {
                        body = "";
                        fin.get();
                        while(ignore != "<end>")
                        {
                            getline(fin, ignore);
                            if(ignore != "<end>")
                            {
                                body += ignore;
                            }
                        
                            fin >> ignore;
                        
                            if(ignore != "<end>")
                            {
                                body += ("\n" + ignore);
                            }
                        }
                    
                        if (body.size() != 0 && body.at(body.size() - 1) == '\n')
                        {
                            body.erase(body.size() - 1);
                        }
                        child = "0";
                        children.push_back(child);
                    }
                }
            
                newReply = new Reply(author, subject, body, id);
                message_list.push_back(newReply);
        }
    }

    for (unsigned i = 0; i < children.size(); i++)
    {
        ss << children.at(i) << endl;
    }
    
    for (unsigned i = 0; i < numMessages; i++)
    {
        while(true)
        {
            ss >> child_id;
            if(child_id == 0)
            {
                break;
            }
            
            message_list.at(i)->add_child(message_list.at(child_id - 1));
        }
    }
    
    fin.close();
    
    return true;
}

bool BBoard::save_messages(const string &datafile)
{
    ofstream fout;
    
    fout.open(datafile.c_str());
    
    fout << message_list.size() << endl;
    
    for (unsigned i = 0; i < message_list.size(); i++)
    {
        fout << message_list.at(i)->to_formatted_string();
    }
    
    fout.close();
    
    return true;
}

void BBoard::login()
{
    string un, pw;
    
    cout << "Welcome to " << title << endl;
    
    while (current_user == 0)
    {
        cout << "Enter your username (\'Q\' or \'q\' to quit): ";
        cin >> un;
        
        if(un == "Q" || un == "q")
        {
            cout << "Bye!" << endl;
            exit(0);
        }
        cout << "Enter your password: ";
        cin >> pw;
        
        current_user = get_user(un, pw);
        
        if(current_user == 0)
        {
            cout << "Invalid Username or Password!" << endl;
        }
    }
    
    cout << "\nWelcome back " << current_user->get_username() << "!" << endl;
    cout << endl;
}

const User * BBoard::get_user(const string &name, const string &pw) const
{
    for (unsigned i = 0; i < user_list.size(); i++)
    {
        if (user_list.at(i).check(name, pw))
        {
            return &user_list.at(i);
        }
    }
    
    return 0;
}

void BBoard::run()
{
    char a;
    
    do
    {
        cout << "\nMenu" << endl;
        cout << "\t- Display Message (\'D\' or \'d\')" << endl;
        cout << "\t- Add New Message (\'N\' or \'n\')" << endl;
        cout << "\t- Add Reply (\'R\' or \'r\')" << endl;
        cout << "\t- Quit (\'Q\' or \'q\')" << endl;
        cout << "Choose an action: ";
        cin >> a;
        cout << endl;
    
        if ((a != 'D' && a != 'd') && (a != 'N' && a != 'n') && 
            (a != 'Q' && a != 'q') && (a != 'R' && a != 'r'))
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
            add_topic();
        }
        else if(a == 'R' || a == 'r')
        {
            add_reply();
        }
    } while (a != 'Q' && a != 'q');
    
    cout << "Bye!" << endl;
    return;
}

void BBoard::display() const
{
    if (message_list.size() == 0)
    {
        cout << "No display." << endl;
        return;
    }
    
    for (unsigned i = 0; i < message_list.size(); i++)
    {
        if (!message_list.at(i)->is_reply())
        {
            cout << string(80, '-') << endl;
            message_list.at(i)->print(0);
        }
    }
    cout << string(80, '-') << endl;
}

void BBoard::add_topic()
{
    string temp = "";
    string subject, body, body1 = "";
    
    cout << "Subject: ";
	getline(cin, subject);
	
	cout << "Body: ";
	while(true)
	{
		getline(cin, body);
		if(body.empty())
		{
			break;
		}
		body1 += (body + "\n");
	}
	
	Topic *newTopic = new Topic(current_user->get_username(),
					subject, body1, message_list.size() + 1);
	
	message_list.push_back(newTopic);
}

void BBoard::add_reply()
{
	bool correctIndex = false;
	string body, subject, temp = "";
	string wholeBody = "";
	int searchIndex;
	
	while(!correctIndex)
	{
		cout << "Enter Message ID (-1 for Menu): ";
		cin >> searchIndex;
		
		if(searchIndex == 0 ||
			searchIndex > static_cast<int>(message_list.size()))
		{
			cout << "Invalid Message ID!!" << endl << endl;
		}
		else
		{	
			correctIndex = true;
		}
	}
	
	if(searchIndex < 0)
	{
		cout << endl;
		return;
	}

	cin.ignore();
	cout << "Enter Body: ";
	while(true)
	{
		getline(cin, body);
		if(body.empty())
		{
			break;
		}
		
		wholeBody += (body + "\n");
	}
	
	
	subject = message_list.at(searchIndex - 1)->get_subject();
	
	Reply* userReply = new Reply(current_user->get_username(),
		subject, wholeBody, message_list.size() + 1);
		
	message_list.at(searchIndex - 1)->add_child(userReply);
	message_list.push_back(userReply);
}