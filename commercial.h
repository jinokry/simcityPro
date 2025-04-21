#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Region.h"

class Commercial{
    public:
    void newCommercial(vector<vector<Cell>> &region, int& workers, int& goods);
    int adjacentPopulation(const vector<vector<Cell>> &cord, int x, int y, int miniPop);
    bool isPowered(const vector<vector<Cell>>& region, int x, int y);
};
#endif