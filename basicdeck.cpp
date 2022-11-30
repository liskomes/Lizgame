#include "basicdeck.h"
#include <iostream>
#include <ostream>

using namespace std;

BasicDeck::BasicDeck() : Deck()
{
    this->maat = 3;                                     //Pakassa olevat maat
    this->cards = 13;                                   //Pakassa olevat kortit
    this->startingCard = 1;                             //Aloituskortti josta maan kortit lähtevät ylöspäin
    this->totalCards = (this->maat + 1) * this->cards;  //Kortit yhteensä pakassa
    this->MAXCARD = (this->maat + 1) * this->cards;
    this->CreateDeck();                                 //Tee pakka
}

void BasicDeck::CreateDeck()                            //Tee normaali pakka
{
    this->totalCards = 0;
    for(int y = 0; y <= this->maat; y++)                //Täytä tyhjä tai vajaa pakka korteilla
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
void BasicDeck::CreateDeck(int sCard, int mCard, int mMaat) //Tee customoitu pakka
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

int BasicDeck::CheckMaa(int cCard)                  //Siirrä pakan maa
{
    int tempCard = this->cardbox[cCard][0];
    this->cardbox[cCard][0] = -1;
    return tempCard;
}

int BasicDeck::CheckCard(int cCard)                 //Siirrä pakan kortin numeroarvo
{
    int tempCard = this->cardbox[cCard][1];
    this->cardbox[cCard][1] = -1;
    return tempCard;
}

int BasicDeck::RandomCard()                         //Arvo uusi kortti
{
  while(true)
    {
    this->randomCard = rand() % this->MAXCARD;
        if(this->cardbox[this->randomCard][0] != -1)
        {
        break;
        }
    }
  return this->randomCard;
}

void BasicDeck::ShowDeck()                          //Työkalu
{
    for(int i = 0; i < this->MAXCARD; i++)
    {
        cout << this->cardbox[i][0] << "-" << this->cardbox[i][1] << endl;
    }
}

float BasicDeck::GiveAverage()                      //Kerro keskiarvo pakassa olevista korteista
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
