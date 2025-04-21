#include "Region.h"
#include "Config.h"
#include <iostream>
#include <fstream>
#include <sstream>

void readConfigFile(const string& filename, string& regionFilename, int& maxTimeSteps, int& refreshRate) { // Reads the simulation configuration file and extracts:
    ifstream file(filename); 
    if (file.is_open()) {
        string line;
        getline(file, line);
        regionFilename = line.substr(line.find(':') + 1); // - The region layout file name
 
        
        getline(file, line);
        maxTimeSteps = stoi(line.substr(line.find(':') + 1)); // - The maximum number of simulation time steps

        
        getline(file, line);
        refreshRate = stoi(line.substr(line.find(':') + 1)); // - The refresh rate for printing the region state
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}