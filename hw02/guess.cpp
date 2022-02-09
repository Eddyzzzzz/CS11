/*
 * guess.cpp
 * CS 11 Spring 2022
 * hw 02
 *
 * Purpose: Let the user guess a random number for at most 
 *          three times.
 *
 * Modified by: Eddy Zhang
 * Date: Wed Feb 3 2022
 */

#include <iostream>
#include <limits>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;
 
/*
guess
Parameters: Two integers.
Purpose: Determine if the guess number is higher or lower 
than the random number.
Returns: void.
*/
void keepGuess(int numGuess, int numRandom);

int main()
{
    // Leave the following line as the first line of main.
    // Do not call srand() again.  This is enough to enable
    // you to get a different random number each time you
    // call the program. DO NOT EDIT IT
    srand(time(nullptr));

    // Put the rest of your main here:
    
    //Generate a random number between 5 and 15.
    int numRandom = rand()%11+5;
    int numGuess;
    
    // First try
    cout << "Enter a guess: ";
    cin  >> numGuess;
    
    //Check if the guess is valid.
    while (cin.fail() or !(numGuess >= 5 and numGuess <=15))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid number between 5 and 15!" << endl;
        cout << "Enter a guess: ";
        cin  >> numGuess;
    }
    
    if (numGuess == numRandom)
    {
        cout << "You guessed it! Good job!" << endl;
        return 0;
    }
    else
    {
        keepGuess(numGuess, numRandom);
    }
    
    //Second try
    cout << "Enter a guess: ";
    cin  >> numGuess;
    
    while (cin.fail() or !(numGuess >= 5 and numGuess <=15))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid number between 5 and 15!" << endl;
        cout << "Enter a guess: ";
        cin  >> numGuess;
    }
        
    if (numGuess == numRandom)
    {
        cout << "You guessed it! Good job!" << endl;
        return 0;
    }
    else
    {
        keepGuess(numGuess, numRandom);
    }
    
    //Third try
    cout << "Enter a guess: ";
    cin  >> numGuess;
    
    while (cin.fail() or !(numGuess >= 5 and numGuess <=15))
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter a valid number between 5 and 15!" << endl;
        cout << "Enter a guess: ";
        cin  >> numGuess;
    }
        
    if (numGuess == numRandom)
    {
        cout << "You guessed it! Good job!" << endl;
        return 0;
    }
    else
    {
        cout << "The number was " << numRandom;
        cout << ". Better luck next time!" << endl;
    }

    return 0;
}

void keepGuess(int numGuess, int numRandom)
{
    if (numGuess > numRandom)
    {
        cout << "That was too high. ";
    }
    else
    {
        cout << "That was too low. ";
    }
}