#include "ArrayDeck.h"  // replace Deck.h with ArrayDeck.h to use the array based Deck
#include <string>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[]) {
    Deck myCardDeck;
    
    cout << "Printing myCardDeck" << endl;
    myCardDeck.print();

    Deck anotherCardDeck = myCardDeck;
    cout << endl << "Printing anotherCardDeck" << endl;
    anotherCardDeck.print();
    
    myCardDeck.shuffle();

    cout << endl << "Printing myCardDeck after shuffling myCardDeck" << endl;
    myCardDeck.print();

    cout << endl << "Printing anotherCardDeck after shuffling myCardDeck" << endl;
    anotherCardDeck.print();

    cout << endl << "Sorting myCardDeck..." << endl << endl;

    myCardDeck.sort();
    myCardDeck.print();

    return 0;
}
