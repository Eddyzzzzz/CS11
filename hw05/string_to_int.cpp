/*
 * string_converter.cpp
 * Program to test the string_to_int function, whose contract appears below
 * Essential idea:  extract digits from a string and return the integer that
 *                  results.  E. g., "a1b2c3" should produce the integer 123
 *
 * By:  Eddy Zhang
 */

#include <iostream>
#include <math.h> 

using namespace std;

int string_to_int(string s);
void test(string s, int a);
// TODO:  Add any extra function prototypes you like here

/*
 * main function tests the string_to_int function
 */
int main()
{
        test("sa78ds6fs8", 7868);
        test("456", 456);
        test("-47", 47);
        test("", 0);
        
        return 0;
}

/*
 * Purpose:   extract an integer from the digit characters in a string
 * Arg:       string that may or may not contain digit characters ('0' -- '9')
 * Returns:   the integer that result from extracting digits from string s
 * Notes:     only digit characters are considered.  
 *            Sign characters ('+', '-') are non-digits and are ignored
 * Examples:  "123abc56"   => 12356
 *            "   2times3" => 23
 *            "help me!"   => 0
 *            ""           => 0
 */
int string_to_int(string s)
{
    int t = 0;
    int result = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if ((int)s[i] >= 48 and (int)s[i] <= 57)
        {
            result += ((int)s[i] - 48) * pow(10, t);
            t++; 
        }
    }
    
    return result;
}

/*
 * the test function for the main function
 */
void test(string s, int num)
{
    cout << "TESTING: " << s << endl;
    if (string_to_int(s) == num)
    cout << "SUCCESS: " << string_to_int(s) << endl;
    else
    cout << "FAILURE: " << string_to_int(s) << endl;
}
