/*
 * pattern.cpp
 *
 * CS 11 Spring 2022
 * hw 03
 *
 * Purpose: Print woven textiles with texts.
 *
 * Modified by: Eddy Zhang
 * Date: Wed Feb 10 2022
 *
 */

#include <iostream>

using namespace std;

/*
   output
   Parameters: Two strings and an integer.
   Purpose: Print the columns.
 */
void output(string s1, string s2, int n)
{
        if (n > 0 and n % 2 == 0)
        {
                cout << s1;
                output(s1, s2, n-1);
        }
        else if (n > 0 and n % 2 == 1)
        {
                cout << s2;
                output(s1, s2, n-1);
        }

        return;
}

/*
   output_pattern
   Parameters: Two strings and an integer.
   Purpose: Print the rows.
 */
void output_pattern(string s1, string s2, int n)
{
        if (n > 0)
        {
                output(s1, s2, 10);
                cout << endl;
                output_pattern(s2, s1, n-1);
        }

        return;
}

/*
   int main()
   {
    output_pattern("", "", 5);
    return 0;
   }
 */

/*
   int main()
   {
    output_pattern("123", "abc", 1);
    return 0;
   }
 */

int main()
{
        string s1, s2;
        int n;
        cin >> s1 >> s2 >> n;
        output_pattern(s1, s2, n);
        return 0;
}