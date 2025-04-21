#include "Config.h"
#include "Region.h"
#include "residential.h"
#include "industrial.h"
#include "commercial.h"
#include <iostream>
#include "pollution.h"

using namespace std;

bool isRegionChanged(const vector<vector<Cell>>& a, const vector<vector<Cell>>& b) {
    if (a.size() != b.size() || a[0].size() != b[0].size()) return true;

    for (size_t r = 0; r < a.size(); ++r) {
        for (size_t c = 0; c < a[0].size(); ++c) {
            if (a[r][c].type != b[r][c].type || a[r][c].population != b[r][c].population)
                return true;
        }
    }
    return false;
}


int main() {

    string configFilename;
    cout << "Enter the configuration file name: ";
    cin >> configFilename;
    
    string regionFilename;
    int maxTimeSteps;
    int refreshRate;
    
    
    readConfigFile(configFilename, regionFilename,maxTimeSteps, refreshRate);

    vector<vector<Cell>> region; // 2d vector to represent cells
    readRegionLayout(regionFilename, region);

    vector<vector<int>> pollution(region.size(), vector<int>(region[0].size(), 0));
    
    int workers = 0; //tracks available workers
    int goods = 0;  //tracks available goods
    int timeStep = 0; //keeps track of current time step

    cout << "Time Step: " << timeStep << endl; //while max time steps has not been reached
    cout << "Available Workers: " << workers << ", Available Goods: " << goods << endl;
    printRegion(region);

    
    Residential Res;
    Industrial Ind;
    Commercial Com;
    Pollution Pol;

    //stages
    for (int step = 1; step <= 3; ++step) {
        bool updated = true;
        while (updated) {
            updated = false;
            int prevWorkers = workers;
            int prevGoods = goods;
            vector<vector<Cell>> prevRegion = region;

            Res.newResidentialzone(region, workers);
            Ind.newIndustrial(region, workers, goods);
            Com.newCommercial(region, workers, goods);

            if (isRegionChanged(region, prevRegion) || workers != prevWorkers || goods != prevGoods)
                updated = true;
        }

        Pol.updatePoll(region,pollution); //update pollution 

        cout << "\nState " << step << endl;
        cout << "Available Workers: " << workers << ", Available Goods: " << goods << endl;
        printRegion(region);

        cout << "\nPollution Map:" << endl;
        Pol.printPoll(region,pollution);
    }

    return 0;
} 