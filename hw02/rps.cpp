/*
 * rps.cpp
 * 
 * CS 11 Spring 2022
 * hw 02
 *
 * Purpose: Play Rock Paper Scissors with the user.
 *
 * Modified by: Eddy Zhang
 * Date: Wed Feb 3 2022
 * 
 */

#include <iostream>

// The following are for srand() and time()
// for random numbers. Leave them 
// in your program.
#include <cstdlib>
#include <ctime>

using namespace std;

/*
get
Parameters: An integer between 0 and 2.
Purpose: Get the symbol of the integer.
Returns: A string among "rock", "paper", and "scissors".
*/
string get(int numGet);

/*
rps
Parameters: An integer between 0 and 2 and a string among "r", "p", and "s".
Purpose: Determine and print the result of the game.
Returns: void.
*/
void rps(int numRps, string strRps);

int main()
{
    // Leave the following line as the first line of main.
    // Do not call srand() again.  This is enough to enable
    // you to get a different random number each time you
    // call the program. DO NOT EDIT IT
    srand(time(nullptr));

    // Put the rest of your main here:
    string userInput;
    int numRandom = rand()%3;
    
    cout << "Enter rock (r), paper (p), or scissors (s): ";
    cin  >> userInput;
    
    //Check if the input is valid.
    if (userInput != "r" and userInput != "p" and userInput != "s" and 
        userInput != "R" and userInput != "P" and userInput != "S")
    {
        cout << "Please enter r (rock), p (paper), or s (scissors)!" << endl;
        main();
        return 0;
    }
    
    rps(numRandom,userInput);

    return 0;
}

void rps(int numRps, string strRps)
{
    int numUser;
    
    if (strRps == "r" or strRps == "R")
    {
        numUser = 0;
    }
    else if (strRps == "p" or strRps == "P")
    {
        numUser = 1;
    }
    else
    {
        numUser = 2;
    }
    
    if (numUser - numRps == 1 or numUser - numRps == -2)
    {
        cout << "You won! The computer chose " << get(numRps) << endl;
        return;
    }
    else if (numUser - numRps == 0)
    {
        cout << "It's a tie. The computer also chose " << get(numRps) << endl;
        return;
    }
    else if (numUser - numRps == -1 or numUser - numRps == 2)
    {
        cout << "You lost. The computer chose " << get(numRps) << endl;
        return;
    }
}

string get(int numGet)
{
    if (numGet == 0)
    {
        return "rock.";
    }
    else if (numGet == 1)
    {
        return "paper.";    
    }
    else
    {
        return "scissors.";
    }
}