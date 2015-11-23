//  =============== BEGIN ASSESSMENT HEADER ================
/// @file assn<6>/main.cpp IntList.h IntList.cpp
///              
/// @brief Assignment/Lab<8> for CS 12 <spring 2015>
///
/// @author <Nam Nguyen> [nnguy072@ucr.edu]
/// @date <May 19th, 2015>
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

#include "IntList.h"
#include <iostream>
using namespace std;

// points head/tail to 0
IntList::IntList()
{
   head = 0;
   tail = 0;
}

IntList::~IntList()
{
   while(head != 0)
   {
      pop_front();
   }
}

// displays elements in the linked list, or nothing if empty.
void IntList::display() const
{
    if (head != 0)
    {
        IntNode *temp = head->next;
        cout << head->data;
        while (temp != 0)
        {
            cout << " " << temp->data;
            temp = temp->next;
        }
    }
}

void IntList::push_front(int value)
{
    if (head != 0)
    {
        IntNode *temp = new IntNode(value);
        temp->next = head;
        head = temp;
    }
    else
    {
        head = new IntNode(value);
        tail = head;
    }
}

void IntList::pop_front()
{
    if (head == 0)
    {
        return;
    }
    else if (head != 0)
    {
	    IntNode *temp = head->next;
	    delete head;
	    head = temp;
	    tail = 0;
    }
}

void IntList::push_back(int value)
{
    if (head == 0)
    {
        head = tail = new IntNode(value);
        return;
    }
    
    IntNode *temp = new IntNode(value);
    tail->next = temp;
    tail = temp;
}

void IntList::select_sort()
{
    // outer loop compares index w/ the rest of the list
    for (IntNode *i = head; i != 0; i = i->next)
    {
        int min = i->data;
        // inner loop compares the indexes to the one in the outer loop
        for (IntNode *j = i-> next; j != 0; j = j->next)
        {
            // if small then swap the index values
            if (j->data < min)
            {
                min = j->data;
                j->data = i-> data;
                i->data = min;
            }
        }
    }
}

void IntList::insert_sorted(int value)
{
    // if no list, the value goes infront
    if (head == 0)
    {
        push_front(value);
    }
    else if (head->next == 0)
    {
        // if there is only one element, value goes front or back
        if (head->data >= value)
        {
            push_front(value);
        }
        else
        {
            push_back(value);   
        }
    }
    else if (tail->data <= value)
    {
        // if value is >= element in the back, then put value at the end
        push_back(value);
    }
    else if (head->data >= value)
    {
        // if value <= element infront then we put the value in the front
        push_front(value);
    }
    else
    {
        // if between elements we have to move through the list and keep
        // track of the elmements. if value > than current value < than the next
        // it goes between
        IntNode *current = head;
        IntNode *after = head->next;
        IntNode *i = 0;
        
        // loop to traverse the list
        for (i = head; !(current->data <= value && value <= after->data);
             i = i->next)
        {
            current = i->next;
            after = i->next->next;
        }
        
        // we get the index from the loop then insert the value into it
        IntNode *temp = new IntNode(value);
        temp->next = after;
        current->next = temp;
    }
}

void IntList::remove_duplicates()
{
    // outer loop: gets numbers to compare
    for (IntNode *i = head; i != 0; i = i->next)
    {
        int compare = i->data;
        IntNode *prev = i;
        
        // inner loop: finds any duplicates
        for (IntNode *j = i->next; j != 0;)
        {
            // if the value is equal to the node pointed by j, it will delete it
            if (compare == j->data && j->next != 0)
            {
                prev->next = j->next;
                delete j;
                j = prev;
            }
            else if (compare == j->data && j == tail)
            {
                // if j is equal to the tail, then the end points to the prev
                // node, then deletes the tail
                tail = prev;
                delete j;
                tail->next = 0;
            }
            
            // to make sure we are comparing the next node after deleting the
            // one in front of it
            if (j == prev)
            {
                j = j->next;
            }
            else
            {
                j = j->next;
                prev = prev->next;
            }
        }
    }
}