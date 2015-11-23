struct IntNode
{
    int data;
    IntNode *next;
    IntNode( int data ) : data(data), next(0) {}
};

class IntList
{
   private:
      IntNode *head;
      IntNode *tail;
   public:
      // default constructor
      IntList();
      // default destructor
      ~IntList();
      // displays values in the list
      void display() const;
      // adds a value to the front of the list
      void push_front(int value);
      // deletes the front value
      void pop_front();
};