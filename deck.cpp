#include "deck.h"
#include <cstdlib>

Deck::Deck()
{
    this->startingCard = 1;
    this->maat = 0;
    this->cards = 0;
    this->totalCards = (this->maat + 1) * this->cards;
    this->MAXCARD = (this->maat + 1) * this->cards;
}

int Deck::GiveMCARDS()
{
    return this->cards;
}

int Deck::GiveMMAAT()
{
    return this->maat+1;
}

int Deck::GiveMSTARTCARD()
{
    return this->startingCard;
}

int Deck::GiveMTOTAL()
{
    return (this->maat + 1) * this->cards;
}

