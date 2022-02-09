// add8.cpp
//      purpose: report the sum of the eight 
//               digits that the user enters
//  modified by: Eddy Zhang
//         date: Fri Jan 28 2002
//
#include <iostream>

using namespace std;

int main()
{   
        float sum = 0;
        float input;
        
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
            
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
            
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
            
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
            
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
            
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
            
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
            
            cout << "Enter a floating point number: ";
            cin  >> input;
            sum += input;
        
        cout << "The sum is: " << sum << endl;

        return 0;
}