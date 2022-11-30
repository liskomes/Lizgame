#include "basicdeck.h"
#include <iostream>
#include <ostream>

using namespace std;

BasicDeck::BasicDeck()
{
    this->maat = 3;
    this->cards = 13;
    this->startingCard = 1;
    this->totalCards = (this->maat + 1) * this->cards;
    this->MAXCARD = (this->maat + 1) * this->cards;
    this->CreateDeck();
}

void BasicDeck::CreateDeck()
{
    this->totalCards = 0;
    //create deck
    for(int y = 0; y <= this->maat; y++)
    {
        for(int i = this->startingCard; i <= this->cards+this->startingCard-1; i++)
        {
            this->cardbox[this->totalCards][0] = i;
            this->cardbox[this->totalCards][1] = y;
            this->totalCards++;
        }
    }

    while(true)
    {
        if (this->totalCards < MAXDECK)
        {
            this->cardbox[this->totalCards][0] = -1;
            this->cardbox[this->totalCards][1] = -1;
            this->totalCards++;
        }
        else
        {
            break;
        }
    }
}
void BasicDeck::CreateDeck(int sCard, int mCard, int mMaat)
{
    this->maat = mMaat-1;
    this->cards = mCard;
    this->startingCard = sCard;
    this->MAXCARD = (this->maat + 1) * this->cards;
    this->totalCards = 0;

    //create deck
    for(int y = 0; y <= this->maat; y++)
    {
        for(int i = this->startingCard; i <= this->cards+this->startingCard-1; i++)
        {
            this->cardbox[this->totalCards][0] = i;
            this->cardbox[this->totalCards][1] = y;
            this->totalCards++;
        }
    }

    while(true)
    {
        if (this->totalCards < MAXDECK)
        {
            this->cardbox[this->totalCards][0] = -1;
            this->cardbox[this->totalCards][1] = -1;
            this->totalCards++;
        }
        else
        {
            break;
        }
    }
}

int BasicDeck::CheckMaa(int cCard)
{
    int tempCard = this->cardbox[cCard][0];
    this->cardbox[cCard][0] = -1;
    return tempCard;
}

int BasicDeck::CheckCard(int cCard)
{
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
        break;
        }
    }
  //ShowDeck();
  return this->randomCard;
}

void BasicDeck::ShowDeck()
{
    for(int i = 0; i < this->MAXCARD; i++)
    {
        cout << this->cardbox[i][0] << "-" << this->cardbox[i][1] << endl;
    }
}

float BasicDeck::GiveAverage()
{
    float average = 0;
    int cardsInGame = 0;
    for(int i = 0; i < this->MAXCARD; i++)
    {
        if (this->cardbox[i][0] != -1)
        {
            average += this->cardbox[i][0];
            cardsInGame += 1;
        }
    }
    return average/cardsInGame;
}
