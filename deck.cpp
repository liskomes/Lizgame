#include "deck.h"
#include <cstdlib>

Deck::Deck()
{
    this->maat = 3;
    this->cards = 13;
    this->totalCards = (this->maat + 1) * this->cards;
    this->MAXCARD = (this->maat + 1) * this->cards;
}

