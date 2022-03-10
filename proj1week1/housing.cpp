//===============================================================
// housing.cpp
// Purpose: Set up houses and be able to edit them.
// Edit by: Eddy Zhang, Mar 3rd 2022
// 
// IMPORTANT NOTE: Only write where the starter indicates "YOUR
// CODE GOES HERE." Do not change anything unless comments tell
// you to do so, OR YOU MAY GET NO CREDIT ON THIS ASSIGNMENT!
// 
//===============================================================

#include <iostream>
#include <fstream>

using namespace std;

// DO NOT CHANGE THE FOLLOWING CONSTANTS. WHEN YOU SUBMIT,
// THEY MUST HAVE THESE VALUES AND THEY MUST BE USED
// AS THE DIMENSIONS FOR YOUR all_houses ARRAY.
const int ROWS = 50;
const int COLS = 20;

//===============================================================
//
//                             House
//
//     Each House struct records the information about one
//     house.  Three of the fields are declared for you and
//     you MUST use them as given.  You should declare below
//     them any additional members that you need.
//
//     Note that if the "no_house_here" member field is set
//     to true, then the other fields are not used.  Of course,
//     if no_house_here is false; then all the fields should
//     be set.
//
//===============================================================

struct House
{
    bool   no_house_here;  // true if there is NO house on this location
    int    id;             // id from the data file, converted to int
    string lot_code;       // lot_code string from the data file

    // DO NOT CHANGE ANYTHING ABOVE THIS LINE
    // ===================================================

    float price;
    int num_bedroom;
    string color;
    string states;

    // ===================================================
};


/*===============================================================
                   Required Function Prototypes

        DO NOT CHANGE ANYTHING IN THIS SECTION. YOUR CODE
        MUST ADHERE TO THESE FUNCTION DECLARATIONS OR YOU WILL
        RECEIVE NO CREDIT.
  ===============================================================*/

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions operating on a single house
// - - - - - - - - - - - - - - - - - - - - - - - - - - -
House read_one_house(ifstream& input_file);
void print_house(House h);

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions relating to the array of houses
// - - - - - - - - - - - - - - - - - - - - - - - - - - -
int col_from_lot(string lot);
int row_from_lot(string lot);
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS]);
bool read_all_house_data(string filename, House all_houses[ROWS][COLS]);

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions for week 2 (ignore during week 1)
// - - - - - - - - - - - - - - - - - - - - - - - - - - -
// bool is_available(int house_id, House all_houses[ROWS][COLS]);
/* int matching_houses(float max_price, string desired_color,
                       int desired_bedrooms, House all_houses[ROWS][COLS],
                       House results[ROWS * COLS]); */
// int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
// int rent_house(int house_id, House all_houses[ROWS][COLS]);


/*===============================================================
                   Additional Function Prototypes

        Write any additional function prototypes that you
        define here. You may not need any, or you may choose
        to write several
  ===============================================================*/

// YOUR FUNCTION PROTOTYPES HERE



//======================================================================
//                              main
//======================================================================

int main(int argc, char *argv[])
{
    if (argc != 2) 
    {
        cerr << "ERROR: You must provide the name of the file." << endl;
        return 1;
    }

    string filename = argv[1];

    House all_houses[ROWS][COLS];

    fill_with_no_houses(ROWS, COLS, all_houses);

    if (not read_all_house_data(filename, all_houses))
    {
        cerr << "fileread.cpp: could not open file: " << filename << endl;
        return 1;
    }

    int row;
    int col;

    while(true)
    {
        cout << "Enter row: ";
        cin  >> row;
        if (row < 0)
            return 0;

        cout << "Enter col: ";
        cin  >> col;
        if (col < 0)
            return 0;
    
        print_house(all_houses[row][col]);
    }

    return 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions operating on a single house
// - - - - - - - - - - - - - - - - - - - - - - - - - - -

// read one line of the input_file; return corresponding House
House read_one_house(ifstream& input_file)
{
    House house_to_return;

    input_file >> house_to_return.id;
    input_file >> house_to_return.lot_code;
    input_file >> house_to_return.price;
    input_file >> house_to_return.num_bedroom;
    input_file >> house_to_return.color;
    input_file >> house_to_return.states;

    house_to_return.no_house_here = false;
    
    return house_to_return;
}

// print information about a single house
void print_house(House h)
{
    if (h.no_house_here == true)
        cout << "No house" << endl;
    else
    {
        string ava;
        
        if (h.states == "available")
            ava = "Yes";
        else if (h.states == "booked")
            ava = "No";

        cout << "Id: " << h.id << " Lot: " << h.lot_code << " Color: " 
             << h.color << " Price: " << h.price << " Bedrooms: " 
             << h.num_bedroom << " Available: " << ava << endl;
    }
    return;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions relating to the array of houses
// - - - - - - - - - - - - - - - - - - - - - - - - - - -

// given a lot code, return the column and row (respectively)
// in the all_houses array
int col_from_lot(string lot)
{
    return lot[0] - 17 - 48;
}

int row_from_lot(string lot)
{
    if (lot.length() == 2)
        return lot[1] - 48 - 1;
    else
        return (lot[1] - 48) * 10 + (lot[2] - 48) - 1;
}

//  set the no_house_here marker for every position
//  in the array
void fill_with_no_houses(int rows, int cols, House all_houses[ROWS][COLS])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            all_houses[i][j].no_house_here = true;
        }
    }
    return;
}

//  given a file with a count n at the top
//  read the count and then n lines of house data
//  into appropriate positions in the array
//
//   return true if file was successfully read
//          false if file could not be opened
bool read_all_house_data(string filename, House all_houses[ROWS][COLS])
{
    ifstream input_file;

    input_file.open(filename);

    if (not input_file.is_open()) 
        return false;

    int house_num;
    input_file >> house_num;
    
    int count = 0;
    while (count < house_num)
    {
        House temp = read_one_house(input_file);
        all_houses[row_from_lot(temp.lot_code)][col_from_lot(temp.lot_code)]
        = temp;
        count ++;
    }

    input_file.close();
    return true;
}


// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions for week 2 (ignore during week 1)
// - - - - - - - - - - - - - - - - - - - - - - - - - - -

/*
bool is_available(int house_id, House all_houses[ROWS][COLS])
{
    // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
    // ===================================================
    // 
    // YOUR CODE GOES HERE
    //
    // ===================================================

    (void)house_id;         // DELETE THIS LINE
    (void)all_houses;       // DELETE THIS LINE
    return false; // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}
*/


/*
int matching_houses(float max_price, string desired_color,
                    int desired_bedrooms, House all_houses[ROWS][COLS],
                    House results[ROWS * COLS])
{
    // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
    // ===================================================
    //
    // YOUR CODE GOES HERE
    //
    // ===================================================

    (void)max_price;        // DELETE THIS LINE
    (void)desired_color;    // DELETE THIS LINE
    (void)desired_bedrooms; // DELETE THIS LINE
    (void)all_houses;       // DELETE THIS LINE
    (void)results;          // DELETE THIS LINE
    return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}
*/


/*
int num_neighbors(int house_id, House all_houses[ROWS][COLS])
{
    // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
    // ===================================================
    //
    // YOUR CODE GOES HERE
    //
    // ===================================================

    (void)house_id;         // DELETE THIS LINE
    (void)all_houses;       // DELETE THIS LINE
    return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}
*/


/*
int rent_house(int house_id, House all_houses[ROWS][COLS])
{
    // DO NOT CHANGE THE LINE IMMEDIATELY ABOVE
    // ===================================================
    //
    // YOUR CODE GOES HERE
    //
    // ===================================================
    
    (void)house_id;         // DELETE THIS LINE
    (void)all_houses;       // DELETE THIS LINE
    return 0;  // REPLACE THIS WITH WHAT YOU REALLY WANT TO RETURN!
}
*/

// ============================================================
//     INCLUDE CS11 TESTING CODE
//
//   LEAVE THIS STATEMENT IN PLACE. IT MUST BE THE 
//   LAST LINE OF CODE IN YOUR housing.cpp FILE!
// ============================================================

#include "housing_hooks.hpp"
