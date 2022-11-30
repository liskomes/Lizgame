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
#include <stdlib.h>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

Game::Game()                                        //Hae peruspakan tiedot
{
    this->MAXCARD = Bdeck.GiveMTOTAL();
    this->MAXMAA = Bdeck.GiveMMAAT();
    this->startCard = Bdeck.GiveMSTARTCARD();
    this->endCard = Bdeck.GiveMCARDS();
}

void Game::checkInput()                             //Tarkasta onko input numero
{
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void Game::Settings()                               //Tee uusi pakka
{
    cout << "   Uuden pakan luominen;" << endl;
    cout << "   -Valitse pakkaasi maita 1-8" << endl;
    cout << "   -Valitse kortti josta pakkasi alkaa, mieluusti 1-15" << endl;
    cout << "   -Valitse korttilukema maata kohden. Esim: valitset aloituskortiksi 4," << endl;
    cout << "    valitset sitten kortteja maata kohden 4; Pakkaan tulee yhteen maahan" << endl;
    cout << "    kortit 4,5,6,7." << endl;
    cout << "   -Kortteja tulee olla pakassa 12-52" << endl << endl;

    cout << "   Maat: ";
    cin >> this->type_number2;
    checkInput();
    this->MAXMAA = this->type_number2;

    cout << "   Aloituskortti: ";
    cin >> this->type_number2;
    checkInput();
    this->startCard = type_number2;

    cout << "   Kortit maata kohden: ";
    cin >> this->type_number2;
    checkInput();
    this->endCard = type_number2;

    if ((this->MAXMAA*this->endCard <= 52) && (this->MAXMAA <= 8) && (this->MAXMAA > 0) && (this->MAXMAA*this->endCard >= 12) && (this->startCard+this->endCard <= 20))
    {
        Bdeck.CreateDeck(this->startCard, this->endCard, this->MAXMAA);
        this->MAXCARD = Bdeck.GiveMTOTAL();
        this->MAXMAA = Bdeck.GiveMMAAT();
        cout << "   Pakka luotu onnistuneesti" << endl;
        //cout << MAXMAA << endl;
        //Bdeck.ShowDeck();
    }
    else
    {
        cout << "   Pakan luontia ei suoritettu. Pakassa saattoi olla liikaa kortteja tai" << endl;
        cout << "   pakassa ei ollut tarpeeksi kortteja. Kortteja tulisi olla 12-52." << endl;
        this->MAXCARD = Bdeck.GiveMTOTAL();
        this->MAXMAA = Bdeck.GiveMMAAT();
        this->startCard = Bdeck.GiveMSTARTCARD();
        this->endCard = Bdeck.GiveMCARDS();
    }
}

void Game::StartGame()                                    //Aloita peli
{
    while(true)
    {
        UI.showOptions(this->points);                     //Uusi kortti yms.
        cout << "   Valitse: ";
        cin >> this->type_number;                         //Valinta
        if (this->type_number == "9")
        {
            this->points[0] = 0;                          //Nollaa pakka ja pisteet
            this->points[1] = 0;
            FinalResults();
            Menu();
        }
        if (this->type_number == "1")
        {
            PlayerTurn();                           //Pelaajan vuoro
            this->total = 0;
            AITurn();                               //AI:n vuoro

            showResults();                          //Näytä kädet ja tulokset

            FinalResults();                         //lasketaan pisteet ja nollataan pakka

            ShowWinner();                           //Tarkista voittaja
        }
        if (this->type_number == "7")                     //Tallenna peli
        {
            SaveGame();
        }
        if (this->type_number == "8")                     //Lataa peli
        {
            LoadGame();
        }
    }
}

void Game::ShowWinner()             //Tarkasta jos toinen on saanut 10 pistettä
{
    if (this->points[0] >= 10)
    {
        this->points[0] = 0;
        this->points[1] = 0;
        FinalResults();
        UI.drawArrow(65,1);
        cout << "          Onneksi olkoon, voitit pelin!" << endl;
        UI.drawArrow(65,1);
        Menu();
    }
    else if (this->points[1] >= 10)
    {
        this->points[0] = 0;
        this->points[1] = 0;
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
        this->random_card = Bdeck.RandomCard();

        this->playedCards[this->total][0] = Bdeck.CheckMaa(this->random_card);            //Siirrä kortti pelattujen listaan
        this->playedCards[this->total][1] = Bdeck.CheckCard(this->random_card);

        CardGraph.showCard(this->playedCards, this->total+1, true);                 //Näytä kortit

        UI.showCardOptions(this->totalSum, this->playedCards[this->total][0],this->points);     //Näytä vaihtoehdot. Lisää tai vähennä

        while(true)
        {
            cout << "   Valitse: ";
            cin >> this->type_number;                                         //Valinta
            if (this->type_number == "1")                                     //1: vähennä, 2: lisää
            {
                this->totalSum += this->playedCards[this->total][0];
                cout << "  --PLUS-- Tulos: " << this->totalSum << " / Siirto: " << this->total+1 << endl << endl;
                break;
            }
            else if (this->type_number == "2")
            {
                this->totalSum -= this->playedCards[this->total][0];
                cout << "  --MIINUS-- Tulos: " << this->totalSum<< " / Siirto: " << this->total+1 << endl << endl;
                break;
            }

        }

        this->total += 1;
    }
}

void Game::AITurn()                                                     //AI:n vuoro
{
    cout << "   AI:n vuoro" << endl;
    UI.drawArrow(65,1);
    for(int i = 0; i < MAXCARDS; i++)
    {
        sleep_for(0.5s);
        this->random_card = Bdeck.RandomCard();

        this->AICards[this->total][0] = Bdeck.CheckMaa(this->random_card);
        this->AICards[this->total][1] = Bdeck.CheckCard(this->random_card);

        CardGraph.showCard(this->AICards, this->total+1, true);

        if (AI1.NegPosCalc(this->tavoiteNumero, this->AItotalSum, this->total, this->AICards[total][0],Bdeck.GiveAverage()))
        {
            this->AItotalSum -= this->AICards[total][0];
        }
        else
        {
            this->AItotalSum += this->AICards[total][0];
        }
        sleep_for(1s);
        this->total += 1;
    }
    UI.drawArrow(65,1);
}

void Game::showResults()                    //Näytä lopulliset kierroksen tulokset ja kortit
{
    CardGraph.showCard(this->playedCards, this->total, false);
    UI.ShowResults(this->totalSum,true);
    CardGraph.showCard(this->AICards, this->total, false);
    UI.ShowResults(this->AItotalSum,false);
}

void Game::showDeckBox()                    //Näytä korttipakka
{
    Bdeck.CreateDeck();
    int total = 0;

        for(int i = 0; i < MAXCARD; i++)
        {
            this->AICards[total][0] = Bdeck.CheckMaa(i);
            this->AICards[total][1] = Bdeck.CheckCard(i);
            total++;

            if ((total > 5) or (i == MAXCARD-1))
            {
                CardGraph.showCard(this->AICards, total, false);
                total = 0;
            }

        }
     this->points[0] = 0;
     this->points[1] = 0;
     Bdeck.CreateDeck();
}

void Game::FinalResults()                   //Tarkasta kierroksen voittaja
{
    this->totalSum = this->tavoiteNumero - this->totalSum;
    this->AItotalSum = this->tavoiteNumero - this->AItotalSum;

    if (this->totalSum < 0)
    {
        this->totalSum*=-1;
    }
    if (this->AItotalSum < 0)
    {
        this->AItotalSum*=-1;
    }

    if (this->totalSum < this->AItotalSum)
    {
        this->points[0] += 1;
    }
    else if (this->totalSum == this->AItotalSum)
    {
    }
    else
    {
        this->points[1] += 1;
    }

    this->total = 0;
    this->totalSum = 0;
    this->AItotalSum = 0;

    Bdeck.CreateDeck();
}

void Game::Menu()
{
    cout << "   _________________________________________________________________ " << endl;
    cout << "  |                                                                 |" << endl;
    cout << "  |                          1: Aloita                              |" << endl;
    cout << "  |                          2: Katsele pakkaa                      |" << endl;
    cout << "  |                          3: Muokkaa pakkaa                      |" << endl;
    cout << "  |                          4: Lataa peli                          |" << endl;
    cout << "  |                          5: Lopeta                              |" << endl;
    cout << "  |_________________________________________________________________|" << endl;
    cout << "   Valitse: ";
    cin >> this->type_number2;
    checkInput();
    switch(this->type_number2)
    {
    case 1:
        this->StartGame();
        break;
    case 2:
        this->showDeckBox();
        this->Menu();
        break;
    case 3:
        this->Settings();
        this->Menu();
        break;
    case 4:
        this->LoadGame();
        Bdeck.CreateDeck();
        if ((this->points[0] > 0) or (this->points[1] > 0))
        {
            this->StartGame();
        }
        else
        {
            this->Menu();
        }
        break;
    case 5:
        exit(0);
    default:
        this->Menu();
    }
    this->type_number2 = 0;
    this->Menu();
}

void Game::LoadGame()
{
    int omatpisteet;
    int vihollispisteet;
    int maxM;
    int maxC;
    int startC;
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
        tiedosto >> maxC;
        tiedosto >> maxM;
        tiedosto >> startC;
        tiedosto.close();
        this->points[0] = omatpisteet;
        this->points[1] = vihollispisteet;
        Bdeck.CreateDeck(startC, maxC, maxM);
        this->MAXCARD = Bdeck.GiveMTOTAL();
        this->MAXMAA = Bdeck.GiveMMAAT();
        this->startCard = Bdeck.GiveMSTARTCARD();
        this->endCard = Bdeck.GiveMCARDS();
        if ((this->points[0] > 0) or (this->points[1] > 0))
        {
            cout << "   " << name << " avattu: " << omatpisteet << "/" << vihollispisteet << "/" << maxC << "/" << maxM << "/" << startC << endl;
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
        tiedosto << this->points[0] << " " << this->points[1] << " " << this->endCard << " " << this->MAXMAA << " " << this->startCard << endl;
        tiedosto.close();
        cout << "   " << name << " tallennettu" << endl;
    }
    else
    {
        cout << "   " << name << " -tiedoston tallentaminen ei onnistunut" << endl;
    }
}
