//
//                       test_linked_list.cpp
//
//     A testing program that creates a CardLinkedList object and
//     tries the basic operations on it, using debug_print to report
//     on the internal state of all objects as it goes.
//
//                   Tufts University, Fall 2021 
//                        CS 11: Project 2
//
//    Modified by: Eddy Zhang
//

#include <iostream>
#include "Card.h"
#include "CardLinkedList.h"
using namespace std;

int main()
{
    // cout << "Making card: value 33" << endl;
    Card c33(33); 
    // c33.debug_print();
    // cout << endl;

    // cout << "Making card: no value" << endl;
    Card c; 
    // c.debug_print();
    // cout << endl;  // newline for viewing convenience

    // cout << "Making linked list" << endl;
    CardLinkedList ll;
    // ll.debug_print();

    cout << "Adding card 33, 34, and 35 to list" << endl;
    Card c34(34);
    Card c35(35);
    ll.add_card_at(0, c33); 
    ll.add_card_at(1, c35);
    ll.add_card_at(1, c34);
    // ll.debug_print();
    // cout << "Get the card at index 2" << endl;
    // cout << ll.get_card_at(2).value() << endl;
    // cout << "Get the card at index 0" << endl;
    // cout << ll.get_card_at(0).value() << endl;
    cout << "remove the second card" << endl;
    ll.remove_card_at(6);
    cout << ll.num_cards() << endl;
    ll.debug_print();
    cout << "remove the first card" << endl;
    ll.remove_card_at(-1);
    cout << ll.num_cards() << endl;
    ll.debug_print();

    


    // Add your own tests here


    return 0;
}

