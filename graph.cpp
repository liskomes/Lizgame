#include "graph.h"
#include <iostream>
using namespace std;

Graph::Graph()
{

}
void Graph::showOptions(int points[2])
{
    cout << " \n <------------------------------------------------------------------>" << endl;
    cout << "   Pisteesi: " << points[0] << " / Vastapelaajan pisteet: " << points[1] << endl;
    cout << "   _________________________________________________________________ " << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          1: Uusi kortti                         |" << endl;
    cout << "  |                          2: Valmis                              |" << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          9: Poistu                              |" << endl;
    cout << "  |_________________________________________________________________|" << endl;
}

void Graph::showCardOptions(int sum, int num)
{
    cout << "   _________________________________________________________________ " << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                     1: Poista tuloksestasi: ";
    if (num >= 10)
    {
        cout << num << "                  |" << endl;
    }
    else
    {
        cout << num << "                   |" << endl;
    }
    cout << "  |                     2: Summaa tulokseesi: ";
    if (num >= 10)
    {
        cout << num << "                    |" << endl;
    }
    else
    {
        cout << num << "                     |" << endl;
    }
    cout << "  |                                                                 |" << endl;
    char luku = sum;
    if (luku <= -10)
    {
        cout << "  |                     Kokonaistuloksesi on: " << sum << "                   |" << endl;
    }
    else if (luku < 0)
    {
        cout << "  |                     Kokonaistuloksesi on: " << sum << "                    |" << endl;
    }
    else if (luku >= 10)
    {
        cout << "  |                     Kokonaistuloksesi on: " << sum << "                    |" << endl;
    }
    else
    {
        cout << "  |                     Kokonaistuloksesi on: " << sum << "                     |" << endl;
    }
    cout << "  |_________________________________________________________________|" << endl;
}

void Graph::ShowResults(int sum, bool player)
{
    if (player == true)
    {
        cout << "  |__________________Tuloksesi on: " << sum << "______________________________|" << endl;
    }
    if (player == false)
    {
        cout << "  |_________________Vastustajan tulos on: " << sum << "_______________________|" << endl;
    }

}
