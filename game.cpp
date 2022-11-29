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
#include <thread>
#include <chrono>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

Game::Game()
{
}

void Game::StartGame()
{
    while(true)
    {
        UI.showOptions(points);                     //Uusi kortti yms.
        cout << "   Valitse: ";
        cin >> type_number;                         //Valinta
        if (type_number == "9")
        {
            points[0] = 0;                          //Nollaa pakka ja pisteet
            points[1] = 0;
            FinalResults();
            Menu();
        }
        if (type_number == "1")
        {
            PlayerTurn();                           //Pelaajan vuoro
            total = 0;
            AITurn();                               //AI:n vuoro

            showResults();                          //Näytä kädet ja tulokset

            FinalResults();                         //lasketaan pisteet ja nollataan pakka

            ShowWinner();                           //Tarkista voittaja
        }
        if (type_number == "7")                     //Tallenna peli
        {
            SaveGame();
        }
        if (type_number == "8")                     //Lataa peli
        {
            LoadGame();
        }
    }
}

void Game::ShowWinner()             //Tarkasta jos toinen on saanut 10 pistettä
{
    if (points[0] >= 10)
    {
        points[0] = 0;
        points[1] = 0;
        FinalResults();
        UI.drawArrow(65,1);
        cout << "          Onneksi olkoon, voitit pelin!" << endl;
        UI.drawArrow(65,1);
        Menu();
    }
    else if (points[1] >= 10)
    {
        points[0] = 0;
        points[1] = 0;
        UI.drawArrow(65,1);
        cout << "          Nyt ei tullut voittoa!" << endl;
        UI.drawArrow(65,1);
        FinalResults();
        Menu();
    }
}
void Game::PlayerTurn()                                                 //Pelaajan vuoro
{
    for(int i = 0; i < MAXCARDS; i++)
    {
        random_card = Bdeck.RandomCard();

        playedCards[total][0] = Bdeck.CheckMaa(random_card);            //Siirrä kortti pelattujen listaan
        playedCards[total][1] = Bdeck.CheckCard(random_card);

        CardGraph.showCard(playedCards, total+1, true);                 //Näytä kortit

        UI.showCardOptions(totalSum, playedCards[total][0],points);     //Näytä vaihtoehdot. Lisää tai vähennä

        while(true)
        {
            cout << "   Valitse: ";
            cin >> type_number;                                         //Valinta
            if (type_number == "1")                                     //1: vähennä, 2: lisää
            {
                totalSum += playedCards[total][0];
                cout << "  --PLUS-- Tulos: " << totalSum << " / Siirto: " << total+1 << endl << endl;
                break;
            }
            else if (type_number == "2")
            {
                totalSum -= playedCards[total][0];
                cout << "  --MIINUS-- Tulos: " << totalSum<< " / Siirto: " << total+1 << endl << endl;
                break;
            }

        }

        total += 1;
    }
}

void Game::AITurn()                                                     //AI:n vuoro
{
    cout << "   AI:n vuoro" << endl;
    UI.drawArrow(65,1);
    for(int i = 0; i < MAXCARDS; i++)
    {
        sleep_for(0.5s);
        random_card = Bdeck.RandomCard();

        AICards[total][0] = Bdeck.CheckMaa(random_card);
        AICards[total][1] = Bdeck.CheckCard(random_card);

        CardGraph.showCard(AICards, total+1, true);

        if (AI1.NegPosCalc(tavoiteNumero, AItotalSum, total, AICards[total][0],Bdeck.GiveAverage()))
        {
            AItotalSum -= AICards[total][0];
        }
        else
        {
            AItotalSum += AICards[total][0];
        }
        sleep_for(1.5s);
        total += 1;
    }
    UI.drawArrow(65,1);
}

void Game::showResults()
{
    CardGraph.showCard(playedCards, total, false);
    UI.ShowResults(totalSum,true);
    CardGraph.showCard(AICards, total, false);
    UI.ShowResults(AItotalSum,false);
}

void Game::showDeckBox()
{
    Bdeck.CreateDeck();
    int total = 0;

        for(int i = 0; i < MAXCARD; i++)
        {
            AICards[total][0] = Bdeck.CheckMaa(i);
            AICards[total][1] = Bdeck.CheckCard(i);
            total++;

            if ((total > 5) or (i == 51))
            {
                CardGraph.showCard(AICards, total, false);
                total = 0;
            }

        }
     points[0] = 0;
     points[1] = 0;
     Bdeck.CreateDeck();
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

void Game::Menu()
{
    int type_number2 = 0;
    cout << "   _________________________________________________________________ " << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          1: Aloita                              |" << endl;
    cout << "  |                          2: Katsele pakkaa                      |" << endl;
    cout << "  |                          3: Lataa peli                          |" << endl;
    cout << "  |                          Muu: Lopeta                            |" << endl;
    cout << "  |_________________________________________________________________|" << endl;
    cout << "   Valitse: ";
    cin >> type_number2;
    switch(type_number2)
    {
    case 1:
        this->StartGame();
        break;
    case 2:
        this->showDeckBox();
        this->Menu();
        break;
    case 3:
        this->LoadGame();
        Bdeck.CreateDeck();
        if ((points[0] > 0) or (points[1] > 0))
        {
            this->StartGame();
        }
        else
        {
            this->Menu();
        }
        break;
    case 4:
        return;
        break;
    default:
        return;
    }
}

void Game::LoadGame()
{
    int omatpisteet;
    int vihollispisteet;
    ifstream tiedosto;
    cout << "   Anna tallennuksesi nimi: ";
    string name;
    cin >> name;
    name = name + ".lzk";
    tiedosto.open(name);
    if (tiedosto.is_open())
    {
        tiedosto >> omatpisteet;
        tiedosto >> vihollispisteet;
        tiedosto.close();
        points[0] = omatpisteet;
        points[1] = vihollispisteet;
        if ((points[0] > 0) or (points[1] > 0))
        {
            cout << "   " << name << " avattu: " << omatpisteet << "/" << vihollispisteet << endl;
        }
        else
        {
            cout << "   Tiedoston lataaminen onnistui, mutta se ei toimi tai tilanne on 0-0" << endl;
        }
    }
    else
    {
        cout << "   " << name << " -tiedoston avaaminen ei onnistunut" << endl;
    }
}

void Game::SaveGame()
{
    ofstream tiedosto;
    cout << "   Tallennusnimi: ";
    string name;
    cin >> name;
    name = name + ".lzk";
    tiedosto.open(name);
    if (tiedosto.is_open())
    {
        tiedosto << points[0] << " " << points[1] << endl;
        tiedosto.close();
        cout << "   " << name << " tallennettu" << endl;
    }
    else
    {
        cout << "   " << name << " -tiedoston tallentaminen ei onnistunut" << endl;
    }
}
