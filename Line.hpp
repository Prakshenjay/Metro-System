#include "MetroSystem.hpp"

class Line : public MetroSystem
{
private :
        int counter;
        int start_x;
        int start_y;
        char direction;

public :
        Line(char dir , int x , int y);
        void addStation(std::string name , float distance);
};