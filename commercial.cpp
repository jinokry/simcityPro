#include<iostream>
#include "commercial.h"

using namespace std;

int Commercial::adjacentPopulation(const vector<vector<Cell>>& region, int x, int y, int minPop) { //check the adjacent
    int count = 0;
    int rows = region.size();
    int cols = region[0].size();

    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (i == x && j == y) continue;
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                if (region[i][j].type == 'C' && region[i][j].population >= minPop) {
                 count++;
                }
            }
        }
    }
    return count;
}

void Commercial::newCommercial(vector<vector<Cell>> &region, int& workers, int& goods) {
    int rows = region.size();
    int cols = region[0].size();
    
    
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (region[r][c].type == 'C') {
                if ((isPowered(region, r, c) || adjacentPopulation(region, r, c, 1) >= 1) && workers >= 1 && goods >= 1) { //updates cell from 'C' to 1
                    region[r][c].population = 1;
                    workers -= 1;
                    goods -= 1;
                    return;
                }
            } else if (region[r][c].type == 'C' && region[r][c].population == 1) {
                if (adjacentPopulation(region, r, c, 1) >= 2 && workers >= 1 && goods >= 1) { //updates cell from 1 to 2
                    region[r][c].population = 2;
                    workers -= 1;
                    goods -= 1;
                    return;
                }
            } else if (region[r][c].type == 'C' && region[r][c].population == 2) {
                if (adjacentPopulation(region, r, c, 2) >= 3 && workers >= 1 && goods >= 1) { //updates cell from 2 to 3
                    region[r][c].population = 3;
                    workers -= 1;
                    goods -= 1;
                    return;
                }
            }
        }
    }
}



bool Commercial::isPowered(const vector<vector<Cell>>& region, int x, int y) { //check the powerline
    int rows = region.size();
    int cols = region[0].size();

    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (i == x && j == y) continue;
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                char t = region[i][j].type;
                if (t == 'T' || t == '#' || t == 'P') {
                    return true;
                }
            }
        }
    }
    return false;
}
