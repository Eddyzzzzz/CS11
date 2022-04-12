//
//                         CardLinkedList.cpp
//
//           A class that manages a linked list of cards
//
//  The data are stored as a singly-linked sequence of nodes accessed
//  from a single pointer (in the data member 'm_front') to the first
//  node in the list (or the nullptr if the list is empty). Each node
//  has a Card instance named card.
//
//  Author: Noah Mendelsohn
//
//  Tufts University, Fall 2021
//  CS 11: Project 2
//
//  Modified by: Eddy Zhang
//  Date: Apr 12 2022
//
//  Anything else you would like to include:
//

/**********************************************************/
/***      Students: Fill in the TODO items below        ***/
/***  You may add additional private member functions   ***/
/**********************************************************/

#include <iostream>
#include <iomanip>     // gets setw for debug printing
#include <string>

#include "CardLinkedList.h"

using namespace std;

/*------------------------------------------------------------------
 *                    Constructor(s) and Destructor
 *----------------------------------------------------------------*/

//
// Purpose:  Constructor initializes an empty list
//
CardLinkedList::CardLinkedList()
{
    m_front = nullptr;
    m_list_length = 0;
}

//
// Purpose:  Destructor recycles the space associated with all nodes
//           in the list
//
CardLinkedList::~CardLinkedList()
{
    while (m_front != nullptr) {
                Node *toDelete = m_front;
                m_front = m_front -> next;
                delete toDelete;
        }
}

/*------------------------------------------------------------------
 *          Public functions to manipulate and query the list
 *----------------------------------------------------------------*/

//
// Purpose:  Return the current size of the list
//           i. e., the number of words/nodes in the list
//
unsigned int CardLinkedList::num_cards()
{
    return m_list_length;
}

//
// Purpose:  Add Card node to the list at the specified position. If index is
//           out of range then return quietly
//
//           Recycles the node containing the word (and its count)
//
void CardLinkedList::add_card_at(unsigned int index, Card c)
{
    // if out of range just return without any operation
    if (index < 0 or index > num_cards()) {
        return;
    } else {
        Node* toadd = new Node();
        toadd->card = c;
        Node* tem = m_front;
    // add to the front, especially useful with empty List
        if (index == 0) {
            toadd->next = m_front;
            m_front = toadd;
        } else {
    // add to any else positions, including the back
            for (int i = 0; i < index - 1; i++) {
                tem = tem->next; 
            }
            toadd->next = tem->next;
            tem->next = toadd;
        }
    // update the number of cards and recycle the pointer
        m_list_length ++;
        toadd = nullptr;
    }
}

//
// Purpose:  Remove word from the list.  That is, it removes and
//           recycles the node containing the word (and its count)
//
void CardLinkedList::remove_card_at(unsigned int index)
{
    if (index < 0 or index > num_cards() or num_cards() == 0) {
        return;
    } else {
        Node* tem = m_front;
        if (index == 0) {
            m_front = m_front->next;
            delete tem;
            tem = nullptr;
        } else {
            for (int i = 0; i < index - 1; i++) {
                tem = tem->next;
            }
            Node* newtem = tem->next;
            tem->next = newtem->next;
            delete newtem;
            newtem = nullptr;
        }
        m_list_length --;     
    }
}


//
// Purpose:  Return the index-th element of the list
// Params:   index must be in range [0 .. size) where
//           size is the number of words stored in the list
// Effects:  if index is out of range, prints error message and returns
//           NO_CARD_HERE
Card CardLinkedList::get_card_at(unsigned int index)
{
    if (index < 0 or index > num_cards()) {
        cerr << "The index is out of range!" << endl;
        Card c;
        return c;
    } else {
        Node* tem = m_front;
        for (int i = 0; i < index; i++) {
            tem = tem->next; 
        }
        return tem->card;
    }
}

//
// Purpose:  Print out the underlying list to cout
// Effects:  Prints to cout
// Notes:    This function is here for debugging purposes.
//           It will not be called in the final version of the program.
//           Still LEAVE IT AS-IS:  WE WILL USE IT FOR TESTING.
//
void CardLinkedList::debug_print()
{
    int index_num = 0;

    cout << "DEBUG: CardLinked List (num_cards = " << num_cards()
         << ") ["  << endl;
    cout <<  "  Index_num   Node Address  Face Value" << endl;
    for (Node *curr_p = m_front; curr_p != nullptr; curr_p = curr_p->next) {
        cout <<  setw(9) << index_num++;
        cout <<  setw(16) << curr_p;
        cout <<  "       ";
        curr_p->card.debug_print();
        cout << endl;
    }
    cout << "]" << endl;
}

