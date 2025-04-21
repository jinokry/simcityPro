#ifndef READREGIONLAYOUT_H
#define READREGIONLAYOUT_H

#include <vector>
#include <string>

using namespace std;

struct Cell{
    char type; // - type: the character representing the cell type (e.g., 'R', 'C', 'I', 'T', '#', 'P')
    int row; // - row, col: the coordinates of the cell within the grid
    int col;
    int population = 0; // - population: current population in the cell (used for R, C, I)
    int adjPop = 0; // - adjPop: adjacent population used for prioritization or growth logic
};

void readRegionLayout(const string& filename, vector<vector<Cell>>& region); // Reads a region CSV file 
void printRegion(const vector<vector<Cell>>& region); //Outputs the current state


#endif