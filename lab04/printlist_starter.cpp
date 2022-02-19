/*
 * CS 11 Lab 04
 * 
 * printlist.cpp
 * Purpose: Reading in a list of numbers into an array and using loops
 * 
 * Updated for Spring 2022 by: Samuel J. Berman (sberma04)
 * 
 * Modified by:
 * Date:
 *
 */

#include <iostream>

using namespace std;

const int CAPACITY = 5;     // change as needed

int main() 
{
    int bdays[CAPACITY];    // birthday data
    int used;               // number of spaces used so far
    int pos;                // position in array

    // read in CAPACITY values
    pos = 0;
    while (pos < CAPACITY) {
        cin >> bdays[pos];
        pos++;
    }
    used = pos;             // position is how far we got

    // now to print out the list
    // you can switch to a for loop if you know about those
    pos = 0;

    while (pos < used) {
        cout << pos << ". " << bdays[pos] << endl;
        ++pos;
    }

    return 0;
}
