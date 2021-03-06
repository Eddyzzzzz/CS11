//
// search.cpp - search for jumbo and save the world
// Add your code after the main function
//
//  Modified by: Eddy Zhang
//           on: April 22 2022
//

#include <cstdlib>
#include <iostream>

using namespace std;

// --- Data Types ---
struct Item {
        int      num;
        string  *wordptr;
};

struct Link {
        Item  data;
        Link *next;
};

// --- Constants ---
const int ARRAY_SIZE = 100;
const string SECRET  = "Jumbo";

// -- Prototypes for code that finds the secret info --

int search_parallel_arrays(int nums[], string *words[]);
int search_array_of_structs(Item list[]);
int search_array_of_ptrs_to_structs(Item *list[]);
int search_array_of_ptrs_to_arrays(Item *list[]);
int search_linkedlist(Link*);

// -- Prototypes for code that hides the secret info --

int *numgen();
string **strptrgen();
Item *itemlistgen();
Item **itemptrlistgen(bool singlenode);
Link *ll_gen();

int main() 
{
        int     num;

        num = search_parallel_arrays(numgen(), strptrgen());
        cout << endl << " First number: " << num << endl;

        num = search_array_of_structs(itemlistgen());
        cout << endl << "Second number: " << num << endl;

        num = search_array_of_ptrs_to_structs(itemptrlistgen(true));
        cout << endl << " Third number: " << num << endl;

        num = search_array_of_ptrs_to_arrays(itemptrlistgen(false));
        cout << endl << "Fourth number: " << num << endl;

        num = search_linkedlist(ll_gen());
        cout << endl << "Powerball: " << num << endl;

        cout << endl;
        
        return 0;
}

// --------------- your code goes down here -------------------
// Given: An two arrays of ARRAY_SIZE: ints and ptrs to strings
// Return: the sum of all the numbers paired with SECRET

int search_parallel_arrays(int nums[], string *words[])
{
        int sum = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
                if (words[i] == nullptr) {
                        continue;
                } else if (*words[i] == SECRET) {
                        sum += nums[i];
                }
        }
        return sum;
}

// Given: An array of ARRAY_SIZE Items
// Return: The sum of all numbers paired with SECRET

int search_array_of_structs(Item list[])
{
        int sum = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
                if (list[i].wordptr == nullptr) {
                        continue;
                } else if (*(list[i].wordptr) == SECRET) {
                        sum += list[i].num;
                }
        }
        return sum;
}

// Given: An array of ARRAY_SIZE pointers to Items
// Return: The sum of all numbers paired with SECRET

int search_array_of_ptrs_to_structs(Item *list[])
{
        int sum = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
                if (list[i] == nullptr or list[i]->wordptr == nullptr) {
                        continue;
                } else if (*(list[i]->wordptr) == SECRET) {
                        sum += list[i]->num;
                }
        }
        
        return sum;
}

// Given: An array of ARRAY_SIZE pointers to arrays of Items
// Return: The sum of all numbers paired with SECRET

int search_array_of_ptrs_to_arrays(Item *list[])
{
        int sum = 0;
        for (int i = 0; i < ARRAY_SIZE; i++) {
                if (list[i] == nullptr) {
                        continue;
                } else {
                        int j = 0;
                        while (list[i][j].wordptr != nullptr) {
                                if (*(list[i][j].wordptr) == SECRET) {
                                        sum += list[i][j].num;
                                }
                                j++;
                        }
                }
        }
        return sum;
}
//
// Given: A linked list of nodes holding Items
// Return: The sum of all numbers paired with SECRET
int search_linkedlist(Link *head)
{
        int sum = 0;
        Link *tem = head;
        while (tem->next != nullptr and tem->data.wordptr != nullptr) {
                if (*(tem->data.wordptr) == SECRET) {
                        sum += tem->data.num;
                }
                tem = tem->next;
        }
        return sum;
}
