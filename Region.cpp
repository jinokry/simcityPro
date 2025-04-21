#include "Region.h"
#include <fstream>
#include <sstream>
#include <iostream>

void readRegionLayout(const string& filename, vector<vector<Cell>>& region) { // Reads a CSV-formatted region layout file
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            vector<Cell> row;
            stringstream ss(line);
            string cell;
            while (getline(ss, cell, ',')) {
                Cell c;
                c.type = cell[0];
                c.population = 0;
                c.adjPop = 0;
                row.push_back(c);
            }
            region.push_back(row);
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void printRegion(const vector<vector<Cell>>& region) {

    int rows = region.size();
    int cols = region[0].size();

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            const Cell& cell = region[i][j];

            if ((cell.type == 'R' || cell.type == 'C' || cell.type == 'I') && cell.population > 0) { // - If the cell is zoned (R, C, I) and has population > 0, the population number is printed
                cout << cell.population;
            } else {
                cout << cell.type;
            }

            cout << ","; 
        }
        cout << endl;
    }
}


