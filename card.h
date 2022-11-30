#ifndef CARD_H
#define CARD_H


class Card
{
private:
public:
    void showCard(int cardlist[5][2], int total, bool played);
    void drawTopPart(int times);
    void drawBottomPart(int times, bool played);
    void drawSidePart(int times);
    void drawMiddlePart(int cardlist[5][2],int times);
    void drawMaa(int cardlist[5][2],int times);
    void drawChangeLine(int times);
    void drawNumberPart(int cardlist[5][2],int times);
};

#endif // CARD_H
