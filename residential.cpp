#include"residential.h"

int Residential::adjacentPopulation(const vector<vector<Cell>> &region, int x, int y, int miniPop){ //check the adjacent
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
                if (neighbor.type == 'R' && neighbor.population >= miniPop) {
                    count++;
            }
        }
        }
    }
    return count;
}

bool Residential::isPowered(const vector<vector<Cell>>& region, int x, int y) { //check the powerline
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

void Residential::newResidentialzone(vector<vector<Cell>> &region, int& workers) {
    int rows = region.size();
    int cols = region[0].size();

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (region[r][c].type == 'R') {
                int pop = region[r][c].population;

                if (pop == 0 && (isPowered(region, r, c) || adjacentPopulation(region, r, c, 1) >= 1)) { //updates cell from 'R' to 1
                    int before = region[r][c].population;
                    region[r][c].population = 1;
                    int after = region[r][c].population;
                    workers += (after - before);
                    return;
                }
                else if (pop == 1 && adjacentPopulation(region, r, c, 1) >= 2) { //updates cell from 1 to 2
                    int before = region[r][c].population;
                    region[r][c].population = 2;
                    int after = region[r][c].population;
                    workers += (after - before);
                    return;
                }
                else if (pop == 2 && adjacentPopulation(region, r, c, 2) >= 4) { //updates cell from 2 to 3
                    int before = region[r][c].population;
                    region[r][c].population = 3;
                    int after = region[r][c].population;
                    workers += (after - before);
                    return;
                }
                else if (pop == 3 && adjacentPopulation(region, r, c, 3) >= 6) { //updates cell from 3 to 4
                    int before = region[r][c].population;
                    region[r][c].population = 4;
                    int after = region[r][c].population;
                    workers += (after - before);
                    return;
                }
                else if (pop == 4 && adjacentPopulation(region, r, c, 4) >= 8) { //updates cell from 4 to 5
                    int before = region[r][c].population;
                    region[r][c].population = 5;
                    int after = region[r][c].population;
                    workers += (after - before);
                    return;
                }
            }
        }
    }
}