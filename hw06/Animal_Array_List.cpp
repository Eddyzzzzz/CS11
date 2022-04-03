//*********************************************************************
//
//                       Animal_Array_list.cpp
//       
//        Member function and constructor/destructor implementations for 
//        the Animal_Array_List class.
//
//  Author: Eddy Zhang
//  Date: April 1st
//
//  Purpose: Member function and constructor/destructor implementations for 
//           the Animal_Array_List class which contains an array of Animal 
//           instances.
//
//  Known bugs: 11test Abort() fault.
//
//  Testing performed: The program works as expected.
//
//*********************************************************************

#include <fstream>
#include <iostream>

using namespace std;

#include "Animal.h"
#include "Animal_Array_List.h"


// *****************************************************************
//         STARTER CODE PROVIDES EMPTY FUNCTION BODIES
// *****************************************************************

//                  ****STUDENT CODE NEEDED HERE***             //

//   
//   FILL IN THE REMAINDER OF THIS FILE WITH DEFINITIONS OF 
//   ALL THE MEMBER FUNCTIONS REQUIRED FOR THE AnimalArrayList
//   TYPE.
//
//   You do not need to update the function contracts.  We have not
//   provided full contracts according to the style guide, but
//   we believe the abbreviated contracts are sufficient here.
//   Just complete the functions.
//

//
// Default constructor with private initial capacity, and 0 animal.
//
Animal_Array_List::Animal_Array_List()
{
        animals = new Animal[INITIAL_CAPACITY];
        m_num_animals = 0;
        m_capacity = INITIAL_CAPACITY;
}

//
// Destructor: Frees heap-allocated memory associated with arraylist
//
Animal_Array_List::~Animal_Array_List()
{
        delete []animals;
        animals = nullptr;
}

//
// Adds a to the back of the list.
// Effects: may expand if necessary
// variable: an Animal instance
// returns: none
//
void 
Animal_Array_List::add(Animal a)
{
        if (m_num_animals == m_capacity) {
                expand();
        }
        animals[m_num_animals] = a;
        m_num_animals++;
}

//
// Returns the number of Animals currently stored
// variable: none
int
Animal_Array_List::num_animals()
{
        return m_num_animals;
}

//
// Returns the Animal located at position index  
// variable: an int representing the index
Animal 
Animal_Array_List::animal_at(int index)
{
        return animals[index];
}

//
// Doubles the capacity of the animals array
// variable: none
// return: none
void
Animal_Array_List::expand()
{
        Animal *newarr = new Animal[m_capacity * 2];
        for (int i = 0; i < m_num_animals; i++){
                newarr[i] = animals[i];
        }
        delete []animals;
        animals = newarr;
        newarr = nullptr;
        m_capacity *= 2;
}

//
//                       print
//
//       Ask all the Animals in the list to print themselves
//
void
Animal_Array_List::print()
{
        for (int i = 0; i < m_num_animals; i++){
                animals[i].print();
        }
}
