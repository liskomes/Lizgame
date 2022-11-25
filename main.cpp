#include <iostream>
//#include "card.h"
//#include "ai.h"
//#include "graph.h"
#include <string>
#include <list>
#include <iterator>
//#include "basicdeck.h"
#include "game.h"

using namespace std;

int StartGame()
{
    Game peli;

    cout << "         _        _   ______   ______   _____   _        _ " << endl;
    cout << "        | |      | | |___   | |  __  | |  ___| | |      | |" << endl;
    cout << "        | |      | |    /  /  | |__| | | |___  | |      | |" << endl;
    cout << "        | |      | |   /  /   |  ____| |  ___| | |      | |" << endl;
    cout << "        | |____  | |  /  /__  | |      | |___  | |____  | |" << endl;
    cout << "        |______| |_| |______| |_|      |_____| |______| |_|" << endl;

    int type_number = 0;
    cout << "   _________________________________________________________________ " << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          1: Aloita                              |" << endl;
    cout << "  |                          2: Lopeta                              |" << endl;
    cout << "  |_________________________________________________________________|" << endl;
    cin >> type_number;
    switch(type_number)
    {
        case 1:
            peli.StartGame();
            break;
        case 2:
            return 0;
            break;
        default:
            return 0;
            break;
    }
    return 0;
}

int main()
{
    StartGame();

    return 0;
}
