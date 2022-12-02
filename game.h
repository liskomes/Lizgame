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

#define MAXCARDS 5                      //Käsikortit

using namespace std;

class Game
{
private:
    int MAXCARD;                        //Maksimikortit pakassa
    int MAXMAA;                         //Maksimimaat pakassa
    string type_number = "0";           //input
    int type_number2 = 0;               //input
    int tavoiteNumero = 21;             //tavoiteltu numero
    int points[2] = {0,0};              //Pisteet
    int startCard;                      //Pakan maan aloituskortti
    int endCard;                        //Maassa oleva määrä kortteja alkaen aloituskortista

    int random_card = 0;                //satunnainen luku

    int total = 0;                      //nostetut kortit
    int totalSum = 0;                   //pelaajan summa
    int AItotalSum = 0;                 //AI:n summa
    BasicDeck Bdeck;                    //Korttipakka
    Card CardGraph;                     //Kortin "grafiikka"
    AI AI1;                             //Vastustaja
    Graph UI;                           //Pelin "grafiikka"
    int playedCards[MAXCARDS][2];       //Pelaajan kortit
    int AICards[MAXCARDS][2];           //AI:n kortit
public:
    Game();
    void setDeckValues();
    void StartGame();
    void PlayerTurn();
    void AITurn();
    void showResults();
    void FinalResults();
    void Menu();
    void ShowWinner();
    void SaveGame();
    void LoadGame();
    void showDeckBox();
    void Settings();
    void checkInput();
};

#endif // GAME_H
