/*
 * dictionary.cpp
 *
 * CS 11 Spring 2022
 * hw 03
 *
 * Purpose: To give the definition of the given word.
 *
 * Modified by: Eddy Zhang
 * Date: Wed Feb 10 2022
 *
 */

#include <iostream>

using namespace std;

/*
   if_Match
   Parameters: A string.
   Purpose: Check if the word is matched in the dictionary.
   Return: true or false.
 */
bool if_Match(string word)
{
        if (word == "Pseudocode"  or word == "Function"  or
            word == "Conditional" or word == "CS11"      or
            word == "Variable"    or word == "Parameter" or
            word == "Recursion")
                return true;
        else
                return false;
}

/*
   yes_Match
   Parameters: A string.
   Purpose: Print the yes_Match of the given word.
 */
void yes_Match(string word)
{
        if (word == "Conditional")
                cout << "A method to execute a block of code depending on "
                     <<  "the outcome of an expression" << endl;
        else if (word == "Recursion")
                cout << "A situation in which a definition refers to the "
                     << "term it is defining" << endl;
        else if (word == "Function")
                cout << "A named block of code that can be invoked as a "
                     << "statement or within an expression" << endl;
        else if (word == "Variable")
                cout << "A location in the computer's memory that can store "
                     << "a value" << endl;
        else if (word == "CS11")
                cout << "Below CS15" << endl;
        else if (word == "Pseudocode")
                cout << "Fake code" << endl;
        else if (word == "Parameter")
                cout << "Disposiable variable" << endl;
}

/*
   no_Match
   Purpose: Print the negative response.
 */
void no_Match()
{
        cout << "Definition Not Found" << endl;
}

/*
   input
   Purpose: Get the word from the user.
 */
void input()
{
        string word;
        cin >> word;

        if (if_Match(word) == true)
                yes_Match(word);
        else
                no_Match();
}

int main()
{
        input();
        return 0;
}