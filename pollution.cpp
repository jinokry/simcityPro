#include "pollution.h"
#include<iostream>

void Pollution::updatePoll(const vector<vector<Cell>>& region, vector<vector<int>>& pollution) {
    int rows = region.size();
    int cols = region[0].size();

    // Reset the map
    for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
            pollution[r][c] = 0;

    // Spread pollution from industrial zones
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            const Cell& cell = region[r][c];

            if (cell.type == 'I' && cell.population > 0) {
                int pop = cell.population;

            for (int i = r - pop; i <= r + pop; ++i) {
                for (int j = c - pop; j <= c + pop; ++j) {
                    if (i >= 0 && i < rows && j >= 0 && j < cols) {
                        int distRow = (i > r) ? (i - r) : (r - i);
                        int distCol = (j > c) ? (j - c) : (c - j);
                        int distance = distRow + distCol;

                        int spread = pop - distance;
                        if (spread > 0) {
                        pollution[i][j] += spread;
                        }
                    }
                }
            }
        }
    }
}
}
//printout the condition of pollution 
void Pollution::printPoll(const vector<vector<Cell>>& region, const vector<vector<int>>& pollution) {
    int rows = region.size();
    int cols = region[0].size();

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if ((region[r][c].type == 'R' || region[r][c].type == 'C' || region[r][c].type == 'I') && region[r][c].population > 0) {
                cout << region[r][c].population;
            } else {
                cout << region[r][c].type;
            }

            // Print pollution as subscript style value
            if (pollution[r][c] > 0)
                cout << "(" << pollution[r][c] << ")";
            else
                cout << "   "; // spacing for cleaner grid

            cout << "  "; 
        }
        cout << endl;
    }
}
