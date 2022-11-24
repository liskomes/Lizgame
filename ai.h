#ifndef AI_H
#define AI_H


class AI
{
private:
    double risk;
    double risk_g;
public:
    AI();
    bool NegPosCalc(int tavoite, int nykyinen);
};

#endif // AI_H
