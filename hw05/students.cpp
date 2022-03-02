/*
* COMP11
* Spring 2021
* students.cpp
* Purpose: repair the SIS system; search and print the students' information
* Edited by: Eddy Zhang Fri Feb 25 2022
*/

#include <iostream>
#include <string>

using namespace std;

// declare the Student struct
struct Student {
    int    id;
    string firstName;
    char   lastInitial;
    float  gpa; 
};

const int TOTAL_STUDENTS = 10;


// Function Prototypes
int  find_student(int id, Student students[], int num_students);
void print_student(int index, Student students[]);


int main() {

    // declare and initialize array of 
    // student structs of size TOTAL_STUDENTS
    Student students [TOTAL_STUDENTS] = {
        {268, "Dana",     'J', 4.0},
        {123, "Rachel",   'G', 3.42},
        {126, "Sam",      'B', 3.8},
        {431, "Keisha",   'M', 3.9},
        {231, "Joe",      'W', 2.7},
        {272, "Isabella", 'U', 3.73},
        {112, "Sook-Hee", 'E', 3.54},
        {289, "Molly",    'C', 3.6},
        {345, "Talia",    'K', 3.63},
        {228, "Jackson",  'P', 3.33}
    };

    // YOUR CODE GOES HERE
    // GET INPUT AND FIND THE STUDENT
    int id;
    cin >> id;
    print_student(find_student(id, students, TOTAL_STUDENTS), students);

    return 0;
}

//THE FUNCTION THAT FINDS THE INDEX OF THE STUDENT BASED ON ID
int  find_student(int id, Student students[], int num_students)
{
    for (int i = 0; i < num_students; i++)
    {
        if (id == students[i].id)
        return i;
    }
    return -1;
}

//THE FUNCTION THAT PRINTS THE STUDENT'S NAME BASED ON INDEX
void print_student(int index, Student students[])
{
    if (index == -1)
    {
        cout << "Sorry, the student is not found :)" << endl;
        return;
    }
    
    cout << "Name: " << students[index].firstName << " ";
    cout << students[index].lastInitial << endl;
    cout << "GPA: " << students[index].gpa << endl;
    return;  
}