#include "industrial.h"

int Industrial::adjacentPopulation(const vector<vector<Cell>> &region, int x, int y, int miniPop){ // check the adjacent
    int count = 0;
    int rows = region.size();
    int cols = region[0].size();

    for(int i = x-1; i <= x+1; i++){
        for (int j = y-1; j <= y+1; j++){
            if (i == 0 && j == 0) 
                continue;

            int newX = i;
            int newY = j;

            if (newX >= 0 && newX < region[0].size() && newY >= 0 && newY < region.size()) {
                const Cell& neighbor = region[newY][newX];
                if (neighbor.type == 'I' && neighbor.population >= miniPop) {
                    count++;
            }
        }
        }
    }
    return count;
}


void Industrial::newIndustrial(vector<vector<Cell>> &region, int& workers, int& goods) { // new industrail zone
    int rows = region.size();
    int cols = region[0].size();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (region[r][c].type == 'I') {
                int pop = region[r][c].population;

                if (pop == 0 && (isPowered(region, r, c) || adjacentPopulation(region, r, c, 1) >= 1) && workers >= 2) {
                    region[r][c].population = 1;
                    workers -= 1;
                    goods++;
                    return;
                }
                else if (pop == 1 && adjacentPopulation(region, r, c, 1) >= 2 && workers >= 2) {
                    region[r][c].population = 2;
                    workers -= 1;
                    goods++;
                    return;
                }
                else if (pop == 2 && adjacentPopulation(region, r, c, 2) >= 4 && workers >= 2) {
                    region[r][c].population = 3;
                    workers -= 1;
                    goods++;
                    return;
                }
            }
        }
    }
}

bool Industrial::isPowered(const vector<vector<Cell>>& region, int x, int y) { // check to see it has a powerline
    int rows = region.size(); 
    int cols = region[0].size();

    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (i == x && j == y) continue;
            if (i >= 0 && i < rows && j >= 0 && j < cols) {
                char type = region[i][j].type;
                if (type == 'T' || type == '#' || type == 'P') {
                    return true;
                }
            }
        }
    }
    return false;
}