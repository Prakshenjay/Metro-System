#include "MetroSystem.hpp"
#include "Line.hpp"

int main()
{
    MetroSystem Delhi_Metro;

    Line redLine('H' , 2 , 0);

    Delhi_Metro.displayMap();

    return 0;
}