#ifndef BASICDECK_H
#define BASICDECK_H

#include "deck.h"

class BasicDeck: Deck
{
private:
    int cardbox[52][4];
    void CreateDeck();
public:
    BasicDeck();
    int CheckCard(int cCard, int MAXCARD);
    int CheckMaa(int cCard, int MAXCARD);
};

#endif // BASICDECK_H
