// generate_hello.cpp
//      purpose: wait for the user to type name
//               and prints a C++ program that 
//               will be used to greet.
//  modified by: Eddy Zhang
//         date: Fri Jan 28 2002
//
#include <iostream>

using namespace std;

int main()
{
    string name;
    cin  >> name;
    //cout << "Whats up " << name <<endl;
    
    cout << "#include <iostream>" << endl;
    cout << "using namespace std;" << endl;
    cout << "int main()" << endl;
    cout << "{" << endl;
    cout << "       cout << \"What's up " << name << "\" << endl;" << endl;
    cout << "       return 0;"  << endl;
    cout << "}" << endl;
    
    return 0;
}