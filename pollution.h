#ifndef POLLUTION_H
#define POLLUTION_H

#include "Region.h"
#include <vector>

using namespace std;

class Pollution{
    public:
    void updatePoll(const vector<vector<Cell>>& region, vector<vector<int>>& pollution);
    void printPoll(const vector<vector<Cell>>& region, const vector<vector<int>>& pollution);
};
#endif