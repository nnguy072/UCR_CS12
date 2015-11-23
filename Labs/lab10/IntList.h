struct IntNode 
{
   int data; 
   IntNode *next; 
   IntNode(int data) : data(data), next(0) {}
};
class IntList
{
  private:
   IntNode *head;
   IntNode *tail;
  public:
   IntList();
   void push_front(int value);
   void pop_front();
   void displayReverse() const;
  private:
   void displayReverse(IntNode *curr) const;
};