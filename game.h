#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "card.h"
#include "ai.h"
#include "graph.h"
#include <string>
#include <list>
#include <iterator>
#include "basicdeck.h"
using namespace std;

class Game
{
private:
#define MAXCARD 52                  //Kortit pakassa
#define MAXMAA 4                    //maat
#define MAXCARDS 5                  //Käsikortit

    string type_number = "0";           //input
    int type_number2 = 0;               //input
    int playedCards[MAXCARDS][2];       //pelatut kortit
    int AICards[MAXCARDS][2];           //AI pelatut kortit
    int tavoiteNumero = 21;             //tavoiteltu numero
    int points[2] = {0,0};              //Pisteet

    int random_card = 0;                //satunnainen luku

    int total = 0;                      //nostetut kortit
    int totalSum = 0;                   //pelaajan summa
    int AItotalSum = 0;                 //AI:n summa
    BasicDeck Bdeck;                    //Korttipakka
    Card CardGraph;                     //Kortin "grafiikka"
    AI AI1;                             //Vastustaja
    Graph UI;                           //Pelin "grafiikka"
public:
    Game();
    void StartGame();
    void PlayerTurn();
    void AITurn();
    void showResults();
    void FinalResults();
    int Menu();
};

#endif // GAME_H
