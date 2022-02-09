/*
 * flights.cpp
 * 
 * CS 11 Spring 2022
 * hw 02
 *
 * Purpose: Compares two flights to see if they form a possible pair of 
 *          connecting flights.
 *
 * Modified by: Eddy Zhang
 * Date: Wed Feb 4 2022
 * 
 */

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int leavehr1, leavemin1, arrivehr1, arrivemin1;
    int leavehr2, leavemin2, arrivehr2, arrivemin2;
    int layhr, laymin, totalhr, totalmin;
    
    //ask for input and check if the inputs are integers
    cout << "Flight 1: ";
    cin  >> leavehr1 >> leavemin1 >> arrivehr1 >> arrivemin1;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter valid integers!" << endl;
        cout << "Flight 1: ";
        cin  >> leavehr1 >> leavemin1 >> arrivehr1 >> arrivemin1;;
    }
    
    cout << "Flight 2: ";
    cin  >> leavehr2 >> leavemin2 >> arrivehr2 >> arrivemin2;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Please enter valid integers!" << endl;
        cout << "Flight 2: ";
        cin  >> leavehr2 >> leavemin2 >> arrivehr2 >> arrivemin2;;
    }
    
    //Determine the layover time
    if (arrivemin1 > leavemin2)
    {
        leavehr2 --;
        leavemin2 += 60;
    }
    
    laymin = leavemin2 - arrivemin1;
    
    if (arrivehr1 > leavehr2)
    {
        layhr = leavehr2 + 24 - arrivehr1;
    }
    else
    {
        layhr = leavehr2 - arrivehr1;
    }
    
    //Determine the total time
    if (leavemin1 > arrivemin2)
    {
        arrivehr2 --;
        arrivemin2 += 60;
    }
    
    totalmin = arrivemin2 - leavemin1;
    
    if (leavehr1 > arrivehr2)
    {
        totalhr = arrivehr2 + 24 - leavehr1;
    }
    else
    {
        totalhr = arrivehr2 - leavehr1;
    }
    
    //Print the results
    cout << "Layover: " << layhr << " hr " << laymin << " min" << endl;
    cout << "Total: " << totalhr << " hr " << totalmin << " min" << endl;
    
    return 0;
}