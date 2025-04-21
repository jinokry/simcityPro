#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Region.h"

class Residential{

    public:
    void newResidentialzone(vector<vector<Cell>>& region, int& workers); //new stages
    int adjacentPopulation(const std::vector<std::vector<Cell>> &grid, int x, int y, int minPop); // to check adjacent
    bool isPowered(const vector<vector<Cell>>& region, int x, int y); // to see if it has a powerline 
};

#endif