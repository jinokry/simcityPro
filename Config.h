#ifndef CONFIG_H
#define CONFIG_H

#include <string>

using namespace std;


void readConfigFile(const string& filename,string& regionFilename, int& maxTimeSteps, int& refreshRate); //read a file

#endif // CONFIG_H