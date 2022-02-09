/*
 * bicycles.cpp
 * CS 11 Spring 2022
 * hw 02
 *
 * Purpose: Compute how many bicycles the user can make 
 *          based on the material he/she has.
 * 
 * Modified by: Eddy Zhang
 * Date: Wed Feb 3 2022
 */

#include <iostream>
#include <limits>

using namespace std;

/*
getSmall
Parameters: Three integers.
Purpose: Find the smallest integer among three.
Returns: The smallest integer.
*/
int getSmall(int num1, int num2, int num3);

/*
ifPlu
Parameters: An integer and a string.
Purpose: Determine to print single or plural based on the integer.
Returns: the number of the string with correct single/plural form.
*/
string ifPlu(int numPlu, string strPlu);

//main class
int main()
{
    int numWheel, numFrame, numLink;
    
    //Check if the numbers are non-negative, if not, ask them again.
    cout << "Enter the number of wheels: "; 
    cin >> numWheel;
    while (cin.fail() or numWheel < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please give a valid non-negative integer!" << endl;
        cout << "Enter the number of wheels: ";
        cin  >> numWheel; 
    }
    
    cout << "Enter the number of frames: ";
    cin  >> numFrame;
    while (cin.fail() or numFrame < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please give a valid non-negative integer!" << endl;
        cout << "Enter the number of frames: ";
        cin  >> numFrame;
    }
    
    cout << "Enter the number of links: ";
    cin  >> numLink;
    while (cin.fail() or numLink < 0)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please give a valid non-negative integer!" << endl;
        cout << "Enter the number of links: ";
        cin  >> numLink;
    }
    
    //numBike represents the number of bikes the user can make
    //determined by the least material
    int numBike = getSmall(numWheel / 2, numFrame / 1, numLink / 50);
    
    cout << "You can make " << ifPlu(numBike, "bike") << ". There are ";
    cout << ifPlu(numWheel - 2 * numBike, "wheel") << ", "; 
    cout << ifPlu(numFrame - numBike, "frame") << ", ";
    cout << ifPlu(numLink - 50 * numBike, "link") << " leftover." << endl;

    return 0;
}

int getSmall(int num1, int num2, int num3)
{
    int tem;
    
    if (num1 > num2)
    {
        tem = num2;
    }
    else
    {
        tem = num1;
    }
    
    if (tem > num3)
    {
        tem = num3;
    }
    
    return tem;
}

string ifPlu(int numPlu, string strPlu)
{
    if (numPlu == 1)
    {
        return "1 " + strPlu;
    }
    else
    {
        return to_string(numPlu) + " " + strPlu + "s";
    }
}