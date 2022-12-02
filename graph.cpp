#include "graph.h"
#include <iostream>
using namespace std;

Graph::Graph()
{

}
void Graph::showOptions(int points[2])
{
    drawArrow(65,1);
    cout << "   Pisteesi: " << points[0] << " / Vastapelaajan pisteet: " << points[1] << endl;
    drawLine(65,1,true);
    cout << "  |"; drawNumber(points[0]);
    cout << "                                                           "; drawNumber2(points[1]);
    cout << "|" << endl;
    cout << "  |                          1: Uudet kortit                        |" << endl;
    drawMiddlePart(65,1);
    cout << "  |                          7: Tallenna peli                       |" << endl;
    cout << "  |                          8: Lataa peli                          |" << endl;
    cout << "  |                          9: Palaa valikkoon                     |" << endl;
    drawMiddlePart(65,1);
    drawLine(65,1,false);
}

void Graph::modifyDeck()
{
    cout << "   Uuden pakan luominen;" << endl;
    cout << "   -Valitse pakkaasi maita 1-8" << endl;
    cout << "   -Valitse kortti josta pakkasi alkaa, mieluusti 1-15" << endl;
    cout << "   -Valitse korttilukema maata kohden. Esim: valitset aloituskortiksi 4," << endl;
    cout << "    valitset sitten kortteja maata kohden 4; Pakkaan tulee yhteen maahan" << endl;
    cout << "    kortit 4,5,6,7." << endl;
    cout << "   -Kortteja tulee olla pakassa 12-52" << endl << endl;
}

void Graph::showMainMenu()
{
    cout << "   _________________________________________________________________ " << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          1: Aloita                              |" << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          2: Katsele pakkaa                      |" << endl;
    cout << "  |                          3: Muokkaa pakkaa                      |" << endl;
    cout << "  |                          4: Palauta normaali pakka              |" << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          5: Lataa peli                          |" << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          9: Lopeta                              |" << endl;
    cout << "  |_________________________________________________________________|" << endl;
}

void Graph::showCardOptions(int sum, int num, int points[2])
{
    drawLine(65,1,true);
    cout << "  |";
    drawNumber(points[0]);
    cout << "                                                           ";
    drawNumber2(points[1]);
    cout << "|" << endl;

    cout << "  |                     1: Summaa tulokseesi: "; drawNumber(num); cout << "                   |" << endl;
    cout << "  |                     2: Poista tuloksestasi: "; drawNumber(num); cout << "                 |" << endl;

    drawMiddlePart(65,1);

    cout << "  |                     Kokonaistuloksesi on: "; drawNumber(sum); cout << "                   |" << endl;

    drawLine(65,1,false);
}

void Graph::ShowResults(int sum, bool player)
{
    if (player == true)
    {
        cout << "  |__________________Tuloksesi on: "; drawNumber(sum); cout << "______________________________|" << endl;
    }
    if (player == false)
    {
        cout << "  |_________________Vastustajan tulos on: "; drawNumber(sum); cout << "_______________________|" << endl;
    }

}

void Graph::drawNumber(int num)
{
    if (num >= 10)
    {
        cout << num << " ";
    }
    else if (num <= -10)
    {
        cout << num << "";
    }
    else if (num < 0)
    {
        cout << num << " ";
    }
    else
    {
        cout << num << "  ";
    }
}

void Graph::drawNumber2(int num)
{
    if (num >= 10)
    {
        cout << " " << num;
    }
    else if (num <= -10)
    {
        cout << "" << num;
    }
    else if (num < 0)
    {
        cout << " " << num;
    }
    else
    {
        cout << "  " << num;
    }
}

void Graph::drawLine(int pituus, int kerrat, bool top)
{
    for(int i = kerrat; i > 0; i--)
    {
        if (top == true)
        {
            cout << "   ";
        }
        else
        {
            cout << "  |";
        }

        for(int a = pituus; a > 0; a--)
        {
            cout << "_";
        }

        if (top == false)
        {
            cout << "|";
        }

        cout << "\n";
    }
}

void Graph::drawMiddlePart(int pituus, int kerrat)
{
    for(int i = kerrat; i > 0; i--)
    {
        cout << "  |";

        for(int a = pituus; a > 0; a--)
        {
            cout << " ";
        }
        cout << "|\n";
    }
}
void Graph::drawArrow(int pituus, int kerrat)
{
    cout << "  <";
    for(int i = kerrat; i > 0; i--)
    {
        for(int a = pituus; a > 0; a--)
        {
            cout << "-";
        }
        cout << ">\n";
    }
}
