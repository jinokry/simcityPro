SimCity Project:

Compilation Instructions:
------------------------
To compile the program, use a C++ compiler (g++ recommended) with the following command:

g++  -o simcity main.cpp Config.cpp Region.cpp residential.cpp industrial.cpp commercial.cpp pollution.cpp

Running Instructions:
--------------------
1. Run the compiled program:
   ./simcity

2. The program will automatically:
   - Read the configuration from config1.txt
   - Load the region layout from the specified CSV file
   - Display the initial state of the region (Time step 0)

Required Files:
--------------
- main.cpp  
- Region.cpp  
- Region.h  
- Config.h  
- Config.cpp  
- residential.cpp  
- residential.h  
- industrial.cpp  
- industrial.h  
- commercial.cpp  
- commercial.h  
- pollution.cpp  
- pollution.h  
- config1.txt (configuration file)
- region1.csv (region layout file)

Note: Make sure all files are in the same directory when running the program.


Config and region file:
-----------------------
This program reads config1.txt, includeing the region layout, maximum number of time steps, refresh rate.
It also loads the region csv to 2d vector.

Residential Zone:
-----------------------
This population is grow based on adjacent powerline, population. Also this produce workers.

Rules:
Powered or adjacent to R zone -> population increases.
additonal population growth occurs as adjacent increase.


Commercial Zone:
-----------------------
This area for producing product so It require workers and goods.
If both goods and workers are available (Powered || near commercial zone) then its increase in population.

Industrial Zone:
-----------------------
This area grow with 2 workers per populatin increase and goods.
It also produce pollution.
Rules are similar to other zone.

Pollution:
Pollution based calculation from industrial zones.
This spreads out itself to adjacent.

Analysis of the Region:

Based on this simulation of region growth, will allow for focused urban analysis depending on how to expand this project.
