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
    deck.debug_print();
    return 0;
}