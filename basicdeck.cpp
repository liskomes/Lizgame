#include "basicdeck.h"
#include "deck.h"
#include <iostream>
#include <ostream>

using namespace std;

BasicDeck::BasicDeck()
{
    this->maat = 3;
    this->cards = 13;
    this->CreateDeck();
    this->totalCards = (this->maat + 1) * cards;
}

void BasicDeck::CreateDeck()
{
    this->totalCards = 0;

    //create deck
    for(int y = 0; y <= this->maat; y++)
    {
        for(int i = 1; i <= this->cards; i++)
        {
            this->cardbox[this->totalCards][0] = i;
            this->cardbox[this->totalCards][1] = y;
            //cout << this->cardbox[this->totalCards][0] << "-" << this->cardbox[this->totalCards][1] << endl;
            this->totalCards++;
        }
    }
    for(int i = 0; i < 52; i++)
    {
        cout << this->cardbox[i][0] << "-" << this->cardbox[i][1] << endl;
    }
}

int BasicDeck::CheckMaa(int cCard,int MAXCARD)
{
    //cout << cCard << endl;
    return this->cardbox[cCard][0];
}

int BasicDeck::CheckCard(int cCard,int MAXCARD)
{
    //cout << cCard << endl;
    return this->cardbox[cCard][1];
}
