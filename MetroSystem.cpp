#include <iostream>
#include "MetroSystem.hpp"

void MetroSystem::displayMap()
{
    for(int i = 0 ; i < MAX_STATIONS ; i++)
    {
        for(int j = 0 ; j < MAX_STATIONS ; j++)
        {
            std::cout << Grid[i][j] << "\t";
        }
        std::cout << "\n";
    }
}