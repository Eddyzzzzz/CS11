//===============================================================
// housing.cpp
// Purpose: Set up houses and be able to edit them.
// Edit by: Eddy Zhang, Mar 17th 2022
//===============================================================

#include <fstream>
#include <iostream>

using namespace std;

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
    bool no_house_here; // true if there is NO house on this location
    int id;             // id from the data file, converted to int
    string lot_code;    // lot_code string from the data file
    float price;
    int num_bedroom;
    string color;
    string states;
};

/*===============================================================
                   Required Function Prototypes
  ===============================================================*/

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions operating on a single house
// - - - - - - - - - - - - - - - - - - - - - - - - - - -
House read_one_house(ifstream &input_file);
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
bool is_available(int house_id, House all_houses[ROWS][COLS]);
int matching_houses(float max_price, string desired_color,
                       int desired_bedrooms, House all_houses[ROWS][COLS],
                       House results[ROWS * COLS]); 
int num_neighbors(int house_id, House all_houses[ROWS][COLS]);
int rent_house(int house_id, House all_houses[ROWS][COLS]);


/*===============================================================
                   Additional Function Prototypes

        Write any additional function prototypes that you
        define here. You may not need any, or you may choose
        to write several
  ===============================================================*/

House find_house(int id, House all_houses[ROWS][COLS]);
void read_command(string s, House all_houses[ROWS][COLS]);
void printa(int id, House all_houses[ROWS][COLS]);
void printm(float price, string color, 
            int num_bed, House all_houses[ROWS][COLS]);
void printn(int id, House all_houses[ROWS][COLS]);
bool printr(int id, House all_houses[ROWS][COLS]);

//======================================================================
//                              main
//======================================================================

int main(int argc, char *argv[])
{
    if (argc != 2){
        cerr << "ERROR: You must provide the name of the file." << endl;
        return 1;}
    string filename = argv[1];
    House all_houses[ROWS][COLS];
    fill_with_no_houses(ROWS, COLS, all_houses);
    if (not read_all_house_data(filename, all_houses)){
        cerr << "fileread.cpp: could not open file: " << filename << endl;
        return 1;}
    while(true)
    {
        string command;
        cin >> command;
        if (command == "q")
            return 0;
        else if (command == "r") 
        {
            int id;
            cin >> id;
            if (printr(id, all_houses))
                return 0;
        }
        else
            read_command(command, all_houses);
    }
    return 0;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - -
//   Functions operating on a single house
// - - - - - - - - - - - - - - - - - - - - - - - - - - -

// read one line of the input_file; return corresponding House
House read_one_house(ifstream &input_file)
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

        cout << "Id: " << h.id << " Lot: " << h.lot_code
             << " Color: " << h.color << " Price: " << h.price
             << " Bedrooms: " << h.num_bedroom << " Available: " << ava 
             << endl;
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

    if (not input_file.is_open()) return false;

    int house_num;
    input_file >> house_num;

    int count = 0;
    while (count < house_num)
    {
        House temp = read_one_house(input_file);
        all_houses[row_from_lot(temp.lot_code)][col_from_lot(temp.lot_code)] =
            temp;
        count++;
    }

    input_file.close();
    return true;
}

// Purpose: this function checks to see if the inputted house_id is available. 
//          It returns true if it's available, and false otherwise. Of course, 
//          if there's no house with a given ID, then that's considered 
//          unavailable, too.
bool is_available(int house_id, House all_houses[ROWS][COLS])
{
    if (find_house(house_id, all_houses).states == "available")
        return true;
    else
        return false;
    return false;
}

// Purpose: this function goes through the housing array and finds every house 
//          that matches the price, color, and bedroom specifications that are 
//          inputted. It copies each matching house into the results array. The 
//          first match goes into slot 0, the second into slot 1, etc.
int matching_houses(float max_price, string desired_color,int desired_bedrooms,
                    House all_houses[ROWS][COLS], House results[ROWS * COLS])
{
    int n = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (all_houses[i][j].price <= max_price and 
                all_houses[i][j].color == desired_color and 
                all_houses[i][j].num_bedroom >= desired_bedrooms)
            {
                results[n] = all_houses[i][j];
                n++;
            }
        }
    }
    return n;
}

// Purpose: this function counts how many neighbors the given house_id has and 
//          returns the number of neighbors. A neighbor is an occupied house 
//          within 1 lot of the given house in the grid, either to the right, 
//          left, top, bottom, or diagonally.
int num_neighbors(int house_id, House all_houses[ROWS][COLS])
{
    int num_nei = 0;
    int i = row_from_lot(find_house(house_id, all_houses).lot_code);
    int j = col_from_lot(find_house(house_id, all_houses).lot_code);
    if (all_houses[i][j].states == "booked")
        num_nei -= 1;
    for (int s = i - 1; s <= i + 1; s++)
    {
        for (int t = j - 1; t <= j + 1; t++)
        {
            if (s < ROWS and t < COLS and s >= 0 and t >= 0 
                and all_houses[s][t].states == "booked")
                num_nei++;
        }
    }
    return num_nei;
}

// Purpose: this function attempts to rent a house. If the given house does not
//          exist, it returns 0. If the given house exists and is available,the 
//          function updates the House structure to record that the house is 
//          booked and returns 1. If the given house exists but is unavailable, 
//          the function returns 2.
int rent_house(int house_id, House all_houses[ROWS][COLS])
{
    int i = row_from_lot(find_house(house_id, all_houses).lot_code);
    int j = col_from_lot(find_house(house_id, all_houses).lot_code);
    if (all_houses[i][j].states == "available")
    {
        all_houses[i][j].states = "booked";
        return 1;
    }
    else if (all_houses[i][j].states == "booked")
        return 2;
    return 0;
}

// Purpose: find and return the house by id.
House find_house(int id, House all_houses[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (all_houses[i][j].id == id)
                return all_houses[i][j];
        }
    }
    House house = {};
    return house;
}

// Purpose: read the command from user and operate based on the input.
// Type   : a , m , n , any other unknown commands
void read_command(string s, House all_houses[ROWS][COLS])
{
    if (s == "a") {
        int id;
        cin >> id;
        printa(id, all_houses);
    } else if (s == "m") {
        float price;
        string color; 
        int num_bed;
        cin >> price >> color >> num_bed;
        printm(price, color, num_bed, all_houses);
    } else if (s == "n") {
        int id;
        cin >> id;
        printn(id, all_houses);
    } else {
        cout << "Unknown command " << s << endl;
    }
    return;
}

// Purpose: print the command a.
void printa(int id, House all_houses[ROWS][COLS])
{
    if (is_available(id, all_houses))
        cout << "House " << id << " is available" << endl;
    else 
        cout << "Sorry, House " << id << " is not available" << endl;
    return;
}

// Purpose: print the command m.
void printm(float price, string color,int num_bed,House all_houses[ROWS][COLS])
{
    House results[ROWS * COLS];
    int n = matching_houses(price, color, num_bed, all_houses, results);
    cout << "Matching Houses:" << endl;
    for (int i = 0; i < n; i++)
        print_house(results[i]);
    return;
}

// Purpose: print the command n.
void printn(int id, House all_houses[ROWS][COLS])
{
    if (num_neighbors(id, all_houses) == 0)
        cout << "You have no neighbors, practice your drums!" << endl;
    else
        cout << "You have " << num_neighbors(id, all_houses) << " neighbors!"
        << endl;
    return;
}

// Purpose: print the command r.
bool printr(int id, House all_houses[ROWS][COLS])
{
    if (rent_house(id, all_houses) == 2)
    {
        cout << 
        "Too late...I hear the dumpster behind hill has some spaces open"
        << endl;
        return false;
    }
    else if (rent_house(id, all_houses) == 1)
    {
        cout <<
        "Congrats, you rented a house! Hope your door knobs don't fall off"
        << endl;
        return false;
    }
    else if (rent_house(id, all_houses) == 0)
    {
        cout <<
        "You can't rent a house that doesn't exist, but good try"
        << endl;
        return true;
    }
    return false;
}

// ============================================================
//     INCLUDE CS11 TESTING CODE
//
//   LEAVE THIS STATEMENT IN PLACE. IT MUST BE THE
//   LAST LINE OF CODE IN YOUR housing.cpp FILE!
// ============================================================

#include "housing_hooks.hpp"
