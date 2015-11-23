class IntVector
{
   private:
      unsigned sz;
      unsigned cap;
      int *data;
   public:
      IntVector();
      IntVector(unsigned size);
      IntVector(unsigned size, int value);
      unsigned size() const;
      unsigned capacity() const;
      bool empty() const;
      const int & at(unsigned index) const;
};
