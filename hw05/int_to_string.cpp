/*
 * int_to_string.cpp
 * Essential idea:  Turn the given integer to string and return it.
 * E. g., 123 should produce the string "123"
 *
 * By:  Eddy Zhang
 */
#include <iostream>

using namespace std;

string int_to_string(int num);
void test(int num, string s);
// TODO:  Add any extra function prototypes you like here

/*
 * main function tests the int_to_string function
 */
int main()
{
        test(123, "123");
        test(-7834, "-7834");
        test(0, "0");
        test(1010, "1010");
        
        return 0;
}

/*
 * the main function that turn a input integer to string output
 */
string int_to_string(int num)
{
    string s;
    if (num < 0){
        s = (char)((char)(-num % 10) + '0');
        if(num > -10)
            return "-" + s;
        return int_to_string(num / 10) + s;}
    s = (char)((char)(num % 10) + '0');
    if(num < 10)
        return s;
    return int_to_string(num / 10) + s;
}

/*
 * the test function for the main function
 */
void test(int num, string s)
{
    cout << "TESTING: " << num << endl;
    if (int_to_string(num) == s)
    cout << "SUCCESS: " << int_to_string(num) << endl;
    else
    cout << "FAILURE: " << int_to_string(num) << endl;
}

