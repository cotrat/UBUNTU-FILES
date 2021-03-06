#ifndef CARD_H
#define CARD_H
#include <string>
enum Suit {
    HEART,
    SPADE,
    DIAMOND,
    CLUB
};

/**
 * Class that represents a card from standard deck of cards.
 *
 * @author      Christopher Johnson
 * @date        Thu  6 Sep 2012 16:39:58 CST
 */
class Card {
    public:
        /**
         * Card constructor - sets suit and value
         *
         * @param suit the suit of the card
         * @param value the value of the card in order from A=1 to K=13
         **/
        Card(Suit suit, int value);

        /**
         * Compares this card to an other card and determines if this card is less
         * than the other card.  Both suits and card values have an order.
         *
         * @param the other card
         * @return true if this card is less than the other card, false otherwise
         *
         * note: this is an example of overloading the < operator
         **/
        bool operator<(const Card &rhs) const;

        /**
         * Compares this card to an other card and determines if this card is greater 
         * than the other card.  Both suits and card values have an order.
         *
         * @param the other card
         * @return true if this card is less than the other card, false otherwise
         *
         * note: this is an example of overloading the < operator
         **/
        bool operator>(const Card &rhs) const;

        /**
         * Compares this card to an other card and determines if they are equal
         *
         * @param the other card
         * @return true if both cards have the same suit and value
         *
         * note: this is an example of overloading the == operator
         **/
        bool operator==(const Card &rhs) const;

        /**
         * accessor method for Card's suit
         *
         * @return the suit of this card
         *
         **/
        Suit getSuit() const;

        /**
         * accessor method for Card's suit
         *
         * @return the suit of this card
         *
         **/
        int getValue() const;

    private:
        Suit m_suit;
        int m_value;
};

#endif
