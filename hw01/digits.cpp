// digits.cpp
//      purpose: report the number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//         
//  modified by: Eddy Zhang
//         date: Fri Jan 28 2002
//

#include <iostream>

using namespace std;

int main()
{
        int input;
        bool tem;

        cout << "Enter a number: ";
        cin  >> input;
        
        /*Using a boolean variable tem to represent if the number 
        is negative.*/
        if (input < 0){
                tem = true;
                input = -input;
        } else {
                tem = false;
        }
        if (input >= 100) {
                cout << "input has three or more digits" << endl;
        } else if ( input >= 10) {
                cout << "input has two digits" << endl;
        } else if ( input >= 0) {
                cout << "input has one digit" << endl;
        }
        if (tem == true) {
                cout << "and input is negative" << endl;
        }

        return 0;
}
