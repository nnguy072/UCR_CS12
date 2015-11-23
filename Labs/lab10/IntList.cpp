#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList()
{
   head = 0;
   tail = 0;
}

void IntList::displayReverse(IntNode *curr) const
{
   if (curr == 0)
   {
      return;
   }
   displayReverse(curr->next);
   cout << curr->data;
   if (curr != head)
   {
      cout << ' ';
   }
}

void IntList::displayReverse() const
{
   if (head != 0)
   {
      displayReverse(head);
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