#include "card.h"
#include <iostream>
#include <ostream>
using namespace std;

void Card::drawTopPart(int times)                       //Piirrä kortin yläosa
{
    for(int i = times; i > 0; i--)
    {
        cout << "  ___________ ";
    }
}
void Card::drawBottomPart(int times, bool played)       //Piirrä kortin alaosa
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
void Card::drawSidePart(int times)                      //Piirrä kortin tyhjä keskiosa
{

    for(int i = times; i > 0; i--)
    {
        cout << " |           |";
    }
}
void Card::drawMiddlePart(int cardlist[5][2], int times)    //Piirrä kortin keskiosa
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
        else if (cardlist[i-1][0] == -1)
        {
            cout << " | POISTETTU |";
        }
        else if (cardlist[i-1][0] == 14)
        {
            cout << " |     R     |";
        }
        else if (cardlist[i-1][0] == 15)
        {
            cout << " |     G     |";
        }
        else if (cardlist[i-1][0] == 16)
        {
            cout << " |    JGQ    |";
        }
        else if (cardlist[i-1][0] == 17)
        {
            cout << " |    QGK    |";
        }
        else if (cardlist[i-1][0] == 18)
        {
            cout << " |    KGR    |";
        }
        else if (cardlist[i-1][0] == 19)
        {
            cout << " |    C++    |";
        }
        else if (cardlist[i-1][0] == 20)
        {
            cout << " |   JOKER   |";
        }
        else
        {
            cout << " |           |";
        }
    }
}
void Card::drawChangeLine(int times)                        //Piirrä enter
{
    for(int i = times; i > 0; i--)
    {
        cout << endl;
    }
}
void Card::drawNumberPart(int cardlist[5][2],int times)     //Piirrä kortin numero-osa
{
    for(int i = times; i > 0; i--)
    {
        if (cardlist[i-1][0] != 0)
        {
            if (cardlist[i-1][0] >= 10)
            {
                cout << " | " << cardlist[i-1][0] << "        |";
            }
            else if (cardlist[i-1][0] == -1)
            {
                cout << " | " << "P" << "         |";
            }
            else
            {
                cout << " | " << cardlist[i-1][0] << "         |";
            }
        }
    }
}
void Card::drawMaa(int cardlist[5][2],int times)        //Piirrä kortin maa
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
            else if (cardlist[i-1][1] == 4)
            {
                cout << " | sahti     |";
            }
            else if (cardlist[i-1][1] == 5)
            {
                cout << " | hurtta    |";
            }
            else if (cardlist[i-1][1] == 6)
            {
                cout << " | sika      |";
            }
            else if (cardlist[i-1][1] == 7)
            {
                cout << " | kato      |";
            }
            else
            {
                cout << " |           |";
            }
        }
    }
}
void Card::showCard(int cardlist[5][2], int total, bool played) //Piirrä piirrettävät kortit
{
            drawTopPart(total);
            drawChangeLine(1);
            drawMaa(cardlist,total);
            drawChangeLine(1);
            drawNumberPart(cardlist,total);
            drawChangeLine(1);
            drawSidePart(total);
            drawChangeLine(1);
            drawMiddlePart(cardlist,total);
            drawChangeLine(1);
            drawSidePart(total);
            drawChangeLine(1);
            drawSidePart(total);
            drawChangeLine(1);
            drawBottomPart(total, played);
            drawChangeLine(1);
}
