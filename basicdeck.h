#ifndef BASICDECK_H
#define BASICDECK_H

#include "deck.h"

class BasicDeck: Deck
{
private:
    int cardbox[52][4];
    int MAXCARD;
public:
    BasicDeck();
    int CheckCard(int cCard);
    int CheckMaa(int cCard);
    int RandomCard();
    void ShowDeck();
    void CreateDeck();
};

#endif // BASICDECK_H
