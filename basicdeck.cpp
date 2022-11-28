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
    this->totalCards = (this->maat + 1) * this->cards;
    this->MAXCARD = (this->maat + 1) * this->cards;
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
    //this->ShowDeck();
}

int BasicDeck::CheckMaa(int cCard)
{
    //cout << cCard << endl;
    int tempCard = this->cardbox[cCard][0];
    this->cardbox[cCard][0] = -1;
    return tempCard;
}

int BasicDeck::CheckCard(int cCard)
{
    //cout << cCard << endl;
    int tempCard = this->cardbox[cCard][1];
    this->cardbox[cCard][1] = -1;
    return tempCard;
}

int BasicDeck::RandomCard()
{
    while(true)
    {
        this->randomCard = rand() % this->MAXCARD;
        if(this->cardbox[this->randomCard][0] != -1)
        {
            //this->ShowDeck();
            break;
        }
    }
    return this->randomCard;
}

void BasicDeck::ShowDeck()
{
    for(int i = 0; i < 52; i++)
    {
        cout << this->cardbox[i][0] << "-" << this->cardbox[i][1] << endl;
    }
}
