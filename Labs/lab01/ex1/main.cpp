// This program plays a guessing game where you try to guess the number 
// the computer has picked.

    #include <iostream>
    #include <cstdlib>
    #include <ctime>
   
    using namespace std;
    
    int main()
    {
    srand(time(0));
    int number_to_guess = rand()%100 + 1;
    
    cout << "Guess a number between 1 and 100." << std::endl << "? ";
     
    int guess;
    cin >> guess;
    
    while ( number_to_guess != guess )
    {
   
        if ( guess > number_to_guess )
        {
            cout << "Try lower." << endl << "? ";
        }
        else if ( guess < number_to_guess )
        {
            cout << "Try Higher." << endl << "? ";
        }
        cin >> guess;
    }
   
     cout << "You guessed right!!!" << endl;
     return 0;
    }
