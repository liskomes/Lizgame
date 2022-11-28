#ifndef GRAPH_H
#define GRAPH_H

#include <string>

using namespace std;

class Graph
{
public:
    Graph();
    void showOptions(int points[2]);
    void showCardOptions(int sum, int num, int points[2]);
    void ShowResults(int sum, bool player);
    void drawNumber(int num);
    void drawNumber2(int num);

    void drawLine(int pituus,int kerrat, bool top);
    void drawBottomLine(int pituus,int kerrat);
    void drawMiddlePart(int pituus,int kerrat);
    void drawArrow(int pituus,int kerrat);
};

#endif // GRAPH_H
