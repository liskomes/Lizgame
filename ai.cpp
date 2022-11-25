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
    //cout << this-> risk << endl;
    //cout << "Riski: " << (this->risk + this->risk_g) << endl;
    //cout << "Turn: " << total << endl;
    cout << "Kortti: " << card << endl;
    cout << "Nykyinen tulos: " << nykyinen << endl;
    int calc1 = tavoite-nykyinen-card;
    int calc2 = tavoite-nykyinen+card;
    cout << "MINUS: " << calc2 << " / " << "PLUS: " << calc1 << endl;

    if (calc1 < 0)
    {
        calc1 *= -1;
    }
    if (calc2 < 0)
    {
        calc2 *= -1;
    }

    cout << calc1 << " / " << calc2 << endl;
    if (calc1 < calc2)
    {
        cout << "--PLUS--\n" << endl;
        return false;
    }
    else
    {
        cout << "--MINUS--\n" << endl;
        return true;
    }
}
