#ifndef BASICDECK_H
#define BASICDECK_H

#include "deck.h"

class BasicDeck : public Deck
{
private:
public:
    BasicDeck();
    int CheckCard(int cCard);
    int CheckMaa(int cCard);
    int RandomCard();
    void ShowDeck();
    void CreateDeck();
    void CreateDeck(int sCard, int mCard, int mMaat);
    float GiveAverage();
};

#endif // BASICDECK_H
