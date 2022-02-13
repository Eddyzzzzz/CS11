/*
 * flights.cpp
 *
 * CS 11 Spring 2022
 * hw 03
 *
 * Purpose: Compares two flights to see if they form a possible pair of
 *          connecting flights.
 *
 * Modified by: Eddy Zhang
 * Date: Wed Feb 10 2022
 *
 */

#include <iostream>

using namespace std;

/*
   to_Min
   Parameters: Two integers.
   Purpose: Convert hours and minutes to only minutes.
   Returns: An integer that refers to the total minutes.
 */
int to_Min(int hr, int min)
{
        return hr * 60 + min;
}

/*
   elapsed
   Parameters: An integers.
   Purpose: Print the result in hours/mins format.
   Returns: void.
 */
void elapsed(int min)
{
        cout << min / 60 << " hr " << min % 60 << " min" << endl;
}

/*
   elapsed
   Note: This is an overloading of the previous function.
   Parameters: Two integers.
   Purpose: Get the time elapsed in minutes.
   Returns: An integer.
 */
int elapsed(int min1, int min2)
{
        if (min1 > min2)
                return 1440 - min1 + min2;
        else
                return min2 - min1;
}

int main()
{
        int leahr1, leamin1, arrhr1, arrmin1;
        int leahr2, leamin2, arrhr2, arrmin2;

        //user input
        cout << "Flight 1: ";
        cin  >> leahr1 >> leamin1 >> arrhr1 >> arrmin1;
        cout << "Flight 2: ";
        cin  >> leahr2 >> leamin2 >> arrhr2 >> arrmin2;

        cout << "Layover: ";
        elapsed(elapsed(to_Min(arrhr1, arrmin1),to_Min(leahr2, leamin2)));
        cout << "Total: ";
        elapsed(elapsed(to_Min(leahr1, leamin1),to_Min(arrhr2, arrmin2)));

        return 0;
}