/*
 * CS 11: Lab 06
 * bike_rack.cpp
 *
 * Purpose: To practice reading in data from a file, interacting with
 *          command line arguments, and initializing 2D arrays of structs
 *
 * Written by: Samuel J. Berman (sberma04), Fall 2021
 *
 * Modified by: Eddy Zhang, Spring 2022
 *
 */

#include <iostream>
#include <fstream>    // Needed to use ifstream

using namespace std;

// Global constants indicating the size of the 2D array
const int NUM_ROWS = 4;
const int NUM_COLS = 5;

struct Bike
{
    bool   no_bike_here;
    string color;
    int    price;
    string bike_type;
    string owner;
};

// Function declarations
Bike read_one_bike(ifstream &infile);
void print_one_bike(Bike bike_to_print);

int main(int argc, char *argv[])
{
    //
    // (void) argc and (void) argv are here in order to silence the
    // compiler from giving you a warning with "unused variables"
    // until you actually use them in a later part. Feel free to
    // delete these two lines of code below if you get to the part
    // where you're using argc and argv.
    //
    
    if (argc != 2) 
    {
        cerr << "ERROR: You must provide the name of the file." << endl;
        return 1;
    }

    string filename = argv[1];

    // ================================================================
    //                       Opening The File 
    // 
    // The following code creates a variable of type ifstream ("if" 
    // stands for "input file") used for reading input files, "opens" it
    // for reading, then makes sure there were no errors. The Lab 06
    // spec has a detailed explanation of each of these parts.
    //
    // There's no need to change any of this code.
    //

    ifstream input_file;

    input_file.open(filename);

    if (not input_file.is_open()) {
        cerr << "fileread.cpp: could not open file: "
             << filename << endl;
        return 1; // non-zero return from main means error
    }
    // ================================================================


    //
    // TODO: Put your solutions to Programming Problems 1-3 here
    //
    
    //problem 1
    int bikes_num;
    input_file >> bikes_num;
    
    // Bike test_bike = read_one_bike(input_file);
    // print_one_bike(test_bike);
    
    //problem 2
    Bike bike_rack[NUM_ROWS][NUM_COLS];
    
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            bike_rack[i][j].no_bike_here = true;
        }
    }
    
    //problem 3
    int count = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {
        for (int j = 0; j < NUM_COLS; j++)
        {
            if (count < bikes_num)
            {
                bike_rack[i][j] = read_one_bike(input_file);
                count ++;
            }
        }
    }
    
    print_one_bike(bike_rack[0][3]);
    
    //
    // When you are done with a file, you "close" it, which tells C++ 
    // do any cleaning up that is necessary.
    //
    input_file.close();

    return 0;
}

/*
 * read_one_bike
 *
 * Parameters: A reference to an ifstream object
 * Returns:    A single Bike struct
 * Purpose:    Read one line of the input file and return that
 *             corresponding Bike
 * Notes:      Not finished -- needs to be completed by students in lab
 * 
 */
Bike read_one_bike(ifstream &infile)
{
    //
    // TODO: Programming Problem #1
    //
    Bike bike_to_return;
    
    infile >> bike_to_return.color;
    infile >> bike_to_return.price;
    infile >> bike_to_return.bike_type;
    infile >> bike_to_return.owner;
    
    bike_to_return.no_bike_here = false;
    
    return bike_to_return;
}

/*
 * print_one_bike
 *
 * Parameters: A single Bike struct, the one to print
 * Returns:    None
 * Purpose:    Print all the attributes of a single Bike struct
 * Notes:      None
 * 
 */
void print_one_bike(Bike bike_to_print)
{
    cout << "Printing Bike's attributes:" << endl;
    cout << "Color: "        << bike_to_print.color << endl;
    cout << "Price: $"       << bike_to_print.price << endl;
    cout << "Bike type: "    << bike_to_print.bike_type << endl;
    cout << "Owner's name: " << bike_to_print.owner << endl;

    cout << endl;            // for visual clarity when printing
}

