#include <string>

# define MAX_STATIONS 10

class MetroSystem
{
private :

public :
        std::string Grid[MAX_STATIONS][MAX_STATIONS];
        void displayMap();
};