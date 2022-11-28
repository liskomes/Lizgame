#include <iostream>
#include <string>
#include <list>
#include <iterator>
#include "game.h"

using namespace std;

int main()
{
    cout << "           _        _   ______   ______   _____   _        _ " << endl;
    cout << "          | |      | | |___   | |  __  | |  ___| | |      | |" << endl;
    cout << "          | |      | |    /  /  | |__| | | |___  | |      | |" << endl;
    cout << "          | |      | |   /  /   |  ____| |  ___| | |      | |" << endl;
    cout << "          | |____  | |  /  /__  | |      | |___  | |____  | |" << endl;
    cout << "          |______| |_| |______| |_|      |_____| |______| |_|" << endl;

    Game Peli;
    Peli.Menu();

    return 0;
}
