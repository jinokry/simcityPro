#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Region.h"

class Industrial{
    public:
    void newIndustrial(vector<vector<Cell>> &region, int& workers, int& goods); // new industrial area
    int adjacentPopulation(const vector<vector<Cell>> &cord, int x, int y, int miniPop); // to check the adjacent
    bool isPowered(const vector<vector<Cell>>& region, int x, int y); // to see if it has a powerline
};
#endif