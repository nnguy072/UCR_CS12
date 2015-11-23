#include "IntList.h"
#include <iostream>
using namespace std;

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

void IntList::display() const
{
   for (IntNode *curr = head; curr != 0; curr = curr -> next)
   {
      cout << curr -> data << " ";
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
   }
}