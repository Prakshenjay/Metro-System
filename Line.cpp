#include "Line.hpp"

Line::Line(char dir , int x , int y)
{
    direction = dir;
    start_x = x;
    start_y = y;
    counter = 0;
}

void Line::addStation(std::string name , float distance)
{
    if(direction == 'H')
    {
        Grid[start_x + counter][start_y] = name;
    }
}