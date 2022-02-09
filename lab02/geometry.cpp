/*
 * geometry.cpp
 * CS 11 Spring 2022
 * Lab 02
 *
 * Purpose: Practice using functions to easily calculate various 
 *          geometric equations.
 * 
 * Modified by: Eddy Zhang
 * Date: Wed Feb 2 2022
 */

#include <iostream>

using namespace std;

// function prototypes (aka function declarations)
/*
triangle_area
Parameters: Two integers, base and height. 
Purpose: Compute the area of the triangle.
Returns: the area of the triangle in integer.
*/
int triangle_area(int base, int height);

/*
sqaure_perimeter
Parameters: An integer, the length of the sides of the sqaure
Purpose: Compute the perimeter of the sqaure
Returns: the perimeter of the square in integer.
*/
int square_perimeter(int sides);

/*
regular_perimeter
Parameters: Two integers, the number of side and the sidelength of 
the shape.
Purpose: Compute the perimeter of the shape.
Returns: the perimeter of the shape in integer.
*/
int regular_perimeter(int sides_num, int sidelength);

/*
regular_perimeter
Parameters: Three integers, base, height, and a minimum area.
Purpose: Decide if the area of the given triangle greater than the
minimum area.
Returns: Boolean operator True or False.
*/
bool area_greater_than(int base, int height, int minimum);

/*
sayHi
Parameters: No Parameters.
Purpose: Talk to you based on your answer
Returns: Void.
*/
void sayHi();

int main()
{
    int base = 4;
    int height = 6;
    int area = triangle_area(base, height);
    cout << area << endl;

    // replace this comment with your lab solution!
    sayHi();
    
    return 0;
} 

// function declarations
int triangle_area(int base, int height)
{
    return 0.5*base*height;
}

int sqaure_perimeter(int sides)
{
    return sides*2;
}

int regular_perimeter(int sides_num, int sidelength)
{
    return sides_num*sidelength;
}

bool area_greater_than(int base, int height, int minimum)
{
    return base*height > minimum;
}

void sayHi()
{
    string ans;
    string anss;
    cout << "Are you happy today? y/n" << endl;
    cin  >> ans;
    if(ans == "y")
    {
        cout << "Nice to hear that~ Keep your great mood going!" << endl;
    }
    else if(ans == "n")
    {
        cout << "Sorry to hear that. But friend, rainbow always" << endl; 
        cout << "comes after the storm, just hang on in there and" << endl;
        cout << "you'll make a difference!" << endl;
        cout << endl;
    }
    else
    {
        cout << "Please answer y(means yes) or n(means no)!";
    }
    
    cout << "Do you want to answer again? y/n" << endl;
    cin  >> anss;
    if(anss == "y")
    {
        sayHi();
    }
    else if(anss == "n")
    {
        cout << "Thank you ~" << endl;
    }
    else
    {
        cout << "Please answer y(means yes) or n(means no)!";
    }
}