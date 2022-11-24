#include "ai.h"
#include <cstdlib>
#include <iostream>

using namespace std;

AI::AI()
{
    this->risk = (rand() % 100) / 50.00;
    this->risk_g = (rand() % 100) / 100.00;
}
bool AI::NegPosCalc(int tavoite, int nykyinen)
{
    cout << "" << (this->risk - this->risk_g) << endl;
    this->risk_g = (rand() % 10) / 20.00;

    if ((tavoite-nykyinen > -6.5 * (this->risk - this->risk_g)) && (tavoite-nykyinen < 6.5 * (this->risk - this->risk_g)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
