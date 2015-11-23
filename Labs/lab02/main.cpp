#include <iostream>

using namespace std;

const int ARR_CAP = 500;

// my attempt at creating my own strcat function
// the while loop find when the destination ends
// the for loop replaces everything after first 
// string with whatever is in the second string
void mystrcat(char destination[], const char source[])
{
    int count = 0;
    while(destination[count] != '\0')
    {
        count++;
    }
    int end = count;
    for (int i = 0; source[i] != '\0'; i++)
    {
        destination[count + i] = source[i];
        end++;
    }
    destination[end] = '\0';
}

int main()
{
    // test harness for function
    char d[ARR_CAP];      // d for destination
    char s[ARR_CAP];     // s for source
    
    cin >> d;
    cin >> s;

    mystrcat(d, s);
    
    cout << d << endl;
    
    return 0;
}