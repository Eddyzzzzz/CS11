/*
 * CS 11 Lab 04
 * 
 * printlist.cpp
 * Purpose: Reading in a list of numbers into an array and using loops
 * 
 * Updated for Spring 2022 by: Samuel J. Berman (sberma04)
 * 
 * Modified by: Eddy Zhang
 * Date: Feb 16 2022
 *
 */

#include <iostream>

using namespace std;

const int CAPACITY = 1000;     // change as needed

int main() 
{
    int bdays[CAPACITY];    // birthday data
    //int used;               // number of spaces used so far
    int pos;                // position in array

    // read in CAPACITY values
    pos = 0;
    while (pos < CAPACITY) {
        cin >> bdays[pos];
        pos++;
    }
    //used = pos;             // position is how far we got

    // now to print out the list
    // you can switch to a for loop if you know about those
    
    int month[12] = { };
    for (int i = 0; i < CAPACITY; ++i)
    {
        ++month[bdays[i] / 100 - 1]; 
    }
    
    
    pos = 0;

    while (pos < 12) {
        cout << pos + 1 << ". " << month[pos] << endl;
        ++pos;
    }
    
    int most = 0;
    int mostmonth;
    for (int j = 0; j < 12; ++j)
    {
        if (month[j] > most)
        {
            most = month[j];
            mostmonth = j + 1;
        }    
    }
    
    cout << mostmonth << " has the most birthdays, "
        "which is " << most << "." << endl;

    return 0;
}
