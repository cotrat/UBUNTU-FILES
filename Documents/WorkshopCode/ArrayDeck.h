#ifndef ARRAYDECK_H
#define ARRAYDECK_H

#include <string>
#include "Card.h"

/**
 * Class that represents a deck of cards
 *
 * @author      Cheryl Pope, Christopher Johnson
 * @date        Wed  11 Sep 2013 07:56:58 CST
 */
class Deck {
public:
    /**
     *  Deck constructor - creates a Deck object containing one of each card
     **/
    Deck();
    
    /**
     * Get a copy of the cards
     * @return a pointer to a copy of the cards
     **/
    Card * getCards() const;
    
    /**
     * Shuffles the deck of cards using random_shuffle from C++ algorithm library
     **/
    void shuffle();
    
    /**
     * Sorts the deck using selection sort
     **/
    void sort();
    
    /**
     * Print the cards in the deck in order
     **/
    void print() const;

	Deck(const Deck& objectToCopy);
    
private:
    // static here means all objects that are created share this
    // same variable.  They don't each have their own copy.
    // const means this variable can not be changed.
    static const int NUM_VALUES = 13;  // A, 2-10, J, Q, K
    static const int DECK_SIZE = 52; // 4 suits of 13 values
    
    Card * m_cards; // dynamic array of pointers to cards
    
    /**
     * private helper methods to convert suit to human readable form
     *
     * @param the suit to be converted
     * @return the human readable version of the suit
     **/
    std::string toString(Suit suit) const;
    
    /**
     * private helper methods to convert value to human readable form
     *
     * @param the value to be converted
     * @return the human readable version of the value
     **/
    std::string toString(int value) const;
};

#endif
