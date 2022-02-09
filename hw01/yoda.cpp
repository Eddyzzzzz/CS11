// yoda.cpp
//      purpose: print the 4 words that the user
//               enters in a reverse order.
//  modified by: Eddy Zhang
//         date: Fri Jan 28 2002
//
#include <iostream>

using namespace std;

int main()
{   
        string input1, input2, input3, input4;
        
        cout << "Type in four words: ";
        cin  >> input1 >> input2 >> input3 >> input4;
        
        cout << input4+" " << input3+" " << input2+" " 
        << input1 << endl;
        
        return 0;
}