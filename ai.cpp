#include "ai.h"
#include <cstdlib>
#include <iostream>

using namespace std;

AI::AI()
{
    double temp = 0.4 * ((rand() % 20) / 10.00);
    this->risk_g = (rand() % 100) / 250.00;
    this->risk = 0.7 + temp;
}
bool AI::NegPosCalc(int tavoite, int nykyinen, int total, int card, float average)
{
    average *=(5-total)-1;
    if (average > 6.5) average*=0.5*this->risk;
    float tavoite1 = tavoite-average;
    float tavoite2 = tavoite+average;
    float vaihtoehdot[4];
    float plus = nykyinen + card;
    float miinus = nykyinen - card;
    vaihtoehdot[0] = tavoite1-miinus; if (vaihtoehdot[0] < 0) vaihtoehdot[0]*=-1;//MIINUS
    vaihtoehdot[1] = tavoite2-miinus; if (vaihtoehdot[1] < 0) vaihtoehdot[1]*=-1;//MIINUS
    vaihtoehdot[2] = tavoite1-plus; if (vaihtoehdot[2] < 0) vaihtoehdot[2]*=-1;//PLUS
    vaihtoehdot[3] = tavoite2-plus; if (vaihtoehdot[3] < 0) vaihtoehdot[3]*=-1;//PLUS

    float index = 1000;

    for(int i = 0; i < 4; i++)
    {
        if ((index > vaihtoehdot[i]))
        {
            index = vaihtoehdot[i];
        }
    }

    for(int i = 0; i < 4; i++)
    {
        if (index == vaihtoehdot[i])
        {
            index = i;
            break;
        }
    }

    if ((index >= 0) && (index < 2))
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

