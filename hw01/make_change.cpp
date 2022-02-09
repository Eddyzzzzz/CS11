// make_change.cpp
//      purpose: print the number of quarters,
//               dimes, nickels, and pennies to 
//               dispense for a specified amount
//               of change. 
//  modified by: Eddy Zhang
//         date: Fri Jan 28 2002
//
#include <iostream>

using namespace std;

int main()
{   
        int input;
        
        cout << "Amount of change in cents: ";
        cin  >> input;
        
        cout 
        << input/25 << " quarters, " 
        << input%25/10 << " dimes, "
        << input%25%10/5 << " nickels, " 
        << input%25%10%5 << " pennies" 
        <<endl;
        
        return 0;
}