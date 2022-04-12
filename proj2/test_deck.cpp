//
//                       test_deck.cpp
//
//                   Tufts University, Fall 2021 
//                        CS 11: Project 2
//
//    Modified by: Eddy Zhang
//

#include <iostream>
#include "Card.h"
#include "CardLinkedList.h"
#include "Deck.h"
using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2){
        cerr << "ERROR: You must provide the name of the file." << endl;
        return 1;}
    string filename = argv[1];
    Deck deck(filename);
    Card c;
    cout << deck.number_of_cards() << endl;

    c = deck.inspect_top_card();
    c.debug_print();
    cout << endl;
    deck.debug_print();

    c = deck.draw_top_card();
    c.debug_print();
    cout << endl;
    deck.debug_print();

    Card c33(33);
    deck.put_card_on_top(c33);
    deck.debug_print();

    return 0;
}