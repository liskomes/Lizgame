#ifndef DECK_H
#define DECK_H
#define MAXDECK 52

class Deck
{
protected:
    int cardbox[52][4];
    int MAXCARD;
    int cards;
    int maat;
    int totalCards;
    int randomCard;
    int startingCard;
public:
    Deck();
    int GiveMCARDS();
    int GiveMMAAT();
    int GiveMSTARTCARD();
    int GiveMTOTAL();
};

#endif // DECK_H
