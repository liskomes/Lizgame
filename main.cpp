#include <iostream>
#include "card.h"
#include "ai.h"
#include "graph.h"
#include <string>
#include <list>
#include <iterator>
#include "basicdeck.h"

using namespace std;

int Game()
{
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

    while(true)
    {
        UI.showOptions(points);       //Uusi kortti yms.
        cin >> type_number2;
        switch(type_number2)
        {
        case 1:
            //Pelaajan vuoro
            for(int i = 0; i < MAXCARDS; i++)
            {
                random_card = Bdeck.RandomCard();

                playedCards[total][0] = Bdeck.CheckMaa(random_card);    //Siirrä kortti pelattujen listaan
                playedCards[total][1] = Bdeck.CheckCard(random_card);

                CardGraph.showCard(playedCards, total+1, true);         //Näytä kortit

                UI.showCardOptions(totalSum, playedCards[total][0]);    //Näytä vaihtoehdot. Lisää tai vähennä
                cin >> type_number;                                     //Valinta
                if (type_number == "1")                                 //1: vähennä, 2: lisää
                {
                    totalSum -= playedCards[total][0];
                }
                else
                {
                    totalSum += playedCards[total][0];
                }

                total += 1;
            }
            total = 0;

            //AI:n vuoro
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


            CardGraph.showCard(playedCards, total, false);
            UI.ShowResults(totalSum,true);
            CardGraph.showCard(AICards, total, false);
            UI.ShowResults(AItotalSum,false);
            //lasketaan pisteet
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
            break;
        case 9:
            return 1;
            break;
        default:
            break;
        }
    }
}

int StartGame()
{
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
            Game();
            break;
        case 2:
            return 0;
            break;
        default:
            return 0;
            break;
    }
}

int main()
{
    StartGame();

    return 0;
}
