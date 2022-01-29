// camp.cpp
// CS 11 Spring 2022
//
// Purpose: Practice using variables and conditionals to organize
//          your new campers at Summer Camp.
//
// Modified by: Eddy
// Date: Wed Jan 26
//

#include <iostream>

using namespace std;

int main()
{
    /* - - - - - - - - - - - - - - - - - - - - - - - - - - -
     *         Exercise One: Taking in User Input
     * - - - - - - - - - - - - - - - - - - - - - - - - - - */

    string name; 
    string emotion;

    //Get the user's names
    cout << endl;
    cout << "Hi! Welcome to the camp!\n";
    cout << endl;
    cout << "Now, can you please tell me your name?\n";
    cout << "Type your name here: ";
    cin  >> name;
    cout << endl;

    //Get the user's emotion
    cout << "Great! Now, how do you feel?";
    cout << endl;
    cout << "Type your emotion here: ";
    cin  >> emotion;

    //Print them out
    cout << endl;
    cout << "Hello, "<< name << "! ";
    cout << endl;
    cout << "Welocme to camp! You are feeling " << emotion << " today. \n";
    cout << endl;

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - -
     *        Exercise Two: Manipulating User Input
     * - - - - - - - - - - - - - - - - - - - - - - - - - - */

    int first;
    int second;

    //Get two numbers
    cout << "Good job! Now, can you please give me two numbers for you ID?";
    cout << endl;
    cout << "The first number: ";
    cin  >> first;
    cout << "The second number: ";
    cin  >> second;
    cout << endl;

    //Multiply them
    int id = first * second;

    //Print out the new product
    cout << "Your new ID number is: " << id << ". \n";
    cout << endl;

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - -
     *   Exercise Three: Basic Conditionals With Numbers
     * - - - - - - - - - - - - - - - - - - - - - - - - - - */
    int age;

    //Ask for their age
    cout << "Now, can you tell me your age?";
    cout << endl;
    cout << "Type your age here: ";
    cin  >> age;
    cout << endl;

    //Determine and print out which campus to go
    if (age <= 10)
    {
        cout << "Your age is " << age << ". You should go to lower campus.\n";
    }
    if (age > 10)
    {
        cout << "Your age is " << age << ". You should go to upper campus.\n";
    }
    cout << endl;

    /* - - - - - - - - - - - - - - - - - - - - - - - - - - -
     *               Exercise Four: if/else
     * - - - - - - - - - - - - - - - - - - - - - - - - - - */
    //Ask for their age
    cout << "Let's do it again with if-else statements.\n";
    cout << endl;
    cout << "Now, can you tell me your age?";
    cout << endl;
    cout << "Type your age here: ";
    cin  >> age;
    cout << endl;

    //Determine and print out which campus to go
    if (age <= 10)
    {
        cout << "Your age is " << age << ". You should go to lower campus.\n";
    }
    else
    {
        cout << "Your age is " << age << ". You should go to upper campus.\n";
    }
    cout << endl;

    return 0;
} 
