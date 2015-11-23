#include "Music_collection.h"

int main()
{
    Tune a("1");
    Tune b("one");
    Tune c("one-two-three");
    
    Music_collection A;
    Music_collection B;
    
    A.add_tune(a);
    B.add_tune(b);
    B.set_tune(0, b);
    
    Music_collection C;
    
    A = B;
    
    C.set_tune(0, a);
    
    cout << A << endl;
    cout << B << endl;
    cout << C << endl;
    
}