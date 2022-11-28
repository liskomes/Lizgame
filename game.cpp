#include "game.h"
#include <iostream>
#include "card.h"
#include "ai.h"
#include "graph.h"
#include <string>
#include <list>
#include <iterator>
#include <fstream>
#include "basicdeck.h"

using namespace std;

Game::Game()
{
}

void Game::StartGame()
{
    while(true)
    {
        UI.showOptions(points); //Uusi kortti yms.

        cin >> type_number;
        if (type_number == "9")
        {
            points[0] = 0;
            points[1] = 0;
            FinalResults();
            Menu();
        }
        if (type_number == "1")
        {
            PlayerTurn();       //Pelaajan vuoro
            total = 0;
            AITurn();           //AI:n vuoro

            showResults();      //Näytä kädet ja tulokset

            FinalResults();     //lasketaan pisteet ja nollataan pakka
        }
        if (type_number == "7")
        {
            ofstream tiedosto;
            tiedosto.open("save.dat", std::ios_base::app);
            if (tiedosto.is_open())
            {
                tiedosto << "Pisteet:\n";
                tiedosto << points[0] << endl;
                tiedosto << points[1] << endl;
                tiedosto.close();
                //cout << "data.dat avattu" << endl;
            }
            else
            {
                //cout << "data.dat -tiedosto puuttuu" << endl;
            }
        }
        if (type_number == "8")
        {
            ofstream tiedosto;
            tiedosto.open("save.dat", std::ios_base::app);
            if (tiedosto.is_open())
            {
                tiedosto << "Pisteet:\n";
                tiedosto << points[0] << endl;
                tiedosto << points[1] << endl;
                tiedosto.close();
                //cout << "data.dat avattu" << endl;
            }
            else
            {
                //cout << "data.dat -tiedosto puuttuu" << endl;
            }
        }
    }
}

void Game::PlayerTurn()
{
    for(int i = 0; i < MAXCARDS; i++)
    {
        random_card = Bdeck.RandomCard();

        playedCards[total][0] = Bdeck.CheckMaa(random_card);    //Siirrä kortti pelattujen listaan
        playedCards[total][1] = Bdeck.CheckCard(random_card);

        CardGraph.showCard(playedCards, total+1, true);         //Näytä kortit

        UI.showCardOptions(totalSum, playedCards[total][0],points);    //Näytä vaihtoehdot. Lisää tai vähennä

        while(true)
        {
            cin >> type_number;                                     //Valinta
            if (type_number == "1")                                 //1: vähennä, 2: lisää
            {
                totalSum -= playedCards[total][0];
                break;
            }
            else if (type_number == "2")
            {
                totalSum += playedCards[total][0];
                break;
            }

        }

        total += 1;
    }
}

void Game::AITurn()
{
    for(int i = 0; i < MAXCARDS; i++)
    {
        random_card = Bdeck.RandomCard();

        AICards[total][0] = Bdeck.CheckMaa(random_card);
        AICards[total][1] = Bdeck.CheckCard(random_card);

        if (AI1.NegPosCalc(tavoiteNumero, AItotalSum, total, AICards[total][0]))
        {
            AItotalSum -= AICards[total][0];
        }
        else
        {
            AItotalSum += AICards[total][0];
        }

        total += 1;
    }
}

void Game::showResults()
{
    CardGraph.showCard(playedCards, total, false);
    UI.ShowResults(totalSum,true);
    CardGraph.showCard(AICards, total, false);
    UI.ShowResults(AItotalSum,false);
}

void Game::FinalResults()
{
    totalSum = tavoiteNumero - totalSum;
    AItotalSum = tavoiteNumero - AItotalSum;

    if (totalSum < 0)
    {
        totalSum*=-1;
    }
    if (AItotalSum < 0)
    {
        AItotalSum*=-1;
    }

    if (totalSum < AItotalSum)
    {
        points[0] += 1;
    }
    else if (totalSum == AItotalSum)
    {
    }
    else
    {
        points[1] += 1;
    }

    total = 0;
    totalSum = 0;
    AItotalSum = 0;

    Bdeck.CreateDeck();
}

int Game::Menu()
{
    int type_number2 = 0;
    cout << "   _________________________________________________________________ " << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          1: Aloita                              |" << endl;
    cout << "  |                          2: Lopeta                              |" << endl;
    cout << "  |_________________________________________________________________|" << endl;
    cin >> type_number2;
    switch(type_number2)
    {
    case 1:
        this->StartGame();
        break;
    case 2:
        return 0;
        break;
    default:
        return 0;
        break;
    }
}
