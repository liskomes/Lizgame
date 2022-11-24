#include "card.h"
#include <iostream>
#include <ostream>
using namespace std;

void Card::drawTopPart(int times)
{
    for(int i = times; i > 0; i--)
    {
        cout << "  ___________ ";
    }
}
void Card::drawBottomPart(int times, bool played)
{
    for(int i = times; i > 0; i--)
    {
        if ((i != times) or (played == false))
        {
           cout << " |___________/";
        }
        else
        {
           cout << " |____UUSI___|";
        }
    }
}
void Card::drawSidePart(int cardlist[5][2], int times)
{

    for(int i = times; i > 0; i--)
    {
        cout << " |           |";
    }
}
void Card::drawMiddlePart(int cardlist[5][2], int times)
{

    for(int i = times; i > 0; i--)
    {
        if (cardlist[i-1][0] == 1)
        {
            cout << " |     A     |";
        }
        else if (cardlist[i-1][0] == 13)
        {
            cout << " |     K     |";
        }
        else if (cardlist[i-1][0] == 12)
        {
            cout << " |     Q     |";
        }
        else if (cardlist[i-1][0] == 11)
        {
            cout << " |     J     |";
        }
        else
        {
            cout << " |           |";
        }
    }
}
void Card::drawChangeLine(int times)
{
    for(int i = times; i > 0; i--)
    {
        cout << endl;
    }
}
void Card::drawNumberPart(int cardlist[5][2],int times)
{
    for(int i = times; i > 0; i--)
    {
        if (cardlist[i-1][0] != 0)
        {
            if (cardlist[i-1][0] >= 10)
            {
                cout << " | " << cardlist[i-1][0] << "        |";
            }
            else
            {
                cout << " | " << cardlist[i-1][0] << "         |";
            }
        }
    }
}
void Card::drawMaa(int cardlist[5][2],int times)
{
    for(int i = times; i > 0; i--)
    {
        if (cardlist[i-1][0] != 0)
        {
            if (cardlist[i-1][1] == 0)
            {
                cout << " | ruutu     |";
            }
            else if (cardlist[i-1][1] == 1)
            {
                cout << " | risti     |";
            }
            else if (cardlist[i-1][1] == 2)
            {
                cout << " | hertta    |";
            }
            else if (cardlist[i-1][1] == 3)
            {
                cout << " | pata      |";
            }
        }
    }
}
void Card::showCard(int cardlist[5][2], int total, bool played)
{
            drawTopPart(total);
            drawChangeLine(1);
            drawMaa(cardlist,total);
            drawChangeLine(1);
            drawNumberPart(cardlist,total);
            drawChangeLine(1);
            drawSidePart(cardlist,total);
            drawChangeLine(1);
            drawMiddlePart(cardlist,total);
            drawChangeLine(1);
            drawSidePart(cardlist,total);
            drawChangeLine(1);
            drawSidePart(cardlist,total);
            drawChangeLine(1);
            drawBottomPart(total, played);
            drawChangeLine(1);
}
