#ifndef BASICDECK_H
#define BASICDECK_H

#include "deck.h"

class BasicDeck : public Deck
{
private:
    //int cardbox[52][4];
    //int MAXCARD;
    //int cards = 0;
    //int maat = 0;
    //int totalCards = 0;
    //int randomCard = 0;
public:
    BasicDeck();
    int CheckCard(int cCard);
    int CheckMaa(int cCard);
    int RandomCard();
    void ShowDeck();
    void CreateDeck();
    float GiveAverage();
};

#endif // BASICDECK_H
