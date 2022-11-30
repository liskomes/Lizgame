#include "ai.h"
#include <cstdlib>
#include <iostream>

using namespace std;

AI::AI()
{
    double temp = 0.4 * ((rand() % 20) / 10.00);        //Lisää AI:lle hieman persoonaa
    this->risk = 0.7 + temp;                            //"Riski"
}
bool AI::NegPosCalc(int tavoite, int nykyinen, int total, int card, float average)
{
    average *=(5-total)-1;
    if (average > 6.5) average*=0.65*this->risk;        //average*kerroin (kerroin 1 tarkottaisi keskiarvon mukaista tavoitenumeroa läheltä lopullista tavoitenumeroa*jäljellä olevat kierrokset)
    cout << average << endl;

    this->tavoite1 = tavoite-average;                   //Laske vaihtoehdot
    this->tavoite2 = tavoite+average;
    this->plus = nykyinen + card;
    this->miinus = nykyinen - card;
    this->vaihtoehdot[0] = this->tavoite1-this->miinus; if (this->vaihtoehdot[0] < 0) this->vaihtoehdot[0]*=-1;//MIINUS
    this->vaihtoehdot[1] = this->tavoite2-this->miinus; if (this->vaihtoehdot[1] < 0) this->vaihtoehdot[1]*=-1;//MIINUS
    this->vaihtoehdot[2] = this->tavoite1-this->plus; if (this->vaihtoehdot[2] < 0) this->vaihtoehdot[2]*=-1;//PLUS
    this->vaihtoehdot[3] = this->tavoite2-this->plus; if (this->vaihtoehdot[3] < 0) this->vaihtoehdot[3]*=-1;//PLUS

    float index = 1000;

    for(int i = 0; i < 4; i++)                          //Tarkasta vaihtoehdot
    {
        if ((index > this->vaihtoehdot[i]))
        {
            index = this->vaihtoehdot[i];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if (index == this->vaihtoehdot[i])
        {
            index = i;
            break;
        }
    }

    if ((index >= 0) && (index < 2))                    //Toteuta paras vaihtoehto
    {
        cout << "  --MIINUS-- Tulos: " << nykyinen - card << " / Siirto: " << total+1 << endl << endl;
        return true;
    }
    else
    {
        cout << "  ---PLUS--- Tulos: " << nykyinen + card << " / Siirto: " << total+1 << endl << endl;
        return false;
    }
}

