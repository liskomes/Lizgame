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
bool AI::NegPosCalc(int tavoite, int nykyinen, int total, int card)
{
    int calc1 = tavoite-nykyinen-card;
    int calc2 = tavoite-nykyinen+card;

    if (calc1 < 0)
    {
        calc1 *= -1;
    }
    if (calc2 < 0)
    {
        calc2 *= -1;
    }

    if (calc1 < calc2)
    {
        cout << "  ---PLUS--- Tulos: " << nykyinen + card << " / Siirto: " << total+1 << endl << endl;
        return false;
    }
    else
    {
        cout << "  --MIINUS-- Tulos: " << nykyinen - card << " / Siirto: " << total+1 << endl << endl;
        return true;
    }
}

