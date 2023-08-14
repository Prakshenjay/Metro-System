#include <iostream>
#include <string>

#define MAX_STATIONS 8

class MetroSystem
{
private:

public:
    std::string Grid[MAX_STATIONS][MAX_STATIONS];
    float AdjacencyMatrix[MAX_STATIONS * MAX_STATIONS][MAX_STATIONS * MAX_STATIONS];
    int stCounter = 0;

    MetroSystem();
    void displayMap();
    void shortestPath(int src);
};

MetroSystem::MetroSystem()
{
    for (int i = 0; i < MAX_STATIONS; i++)
    {
        for (int j = 0; j < MAX_STATIONS; j++)
        {
            Grid[i][j] = "-";
        }
    }
        
    for (int i = 0; i < MAX_STATIONS * MAX_STATIONS; i++)
    {
        for (int j = 0; j < MAX_STATIONS * MAX_STATIONS; j++)
        {
            AdjacencyMatrix[i][j] = 0;
        }
    }
}

void MetroSystem::displayMap()
{
    for (int i = 0; i < MAX_STATIONS; i++)
    {
        for (int j = 0; j < MAX_STATIONS; j++)
        {
            std::cout << Grid[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    for (int i = 0; i < MAX_STATIONS * MAX_STATIONS; i++)
    {
        for (int j = 0; j < MAX_STATIONS * MAX_STATIONS; j++)
        {
            std::cout << AdjacencyMatrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

void MetroSystem::shortestPath(int src)
{
    
}

class Line
{
private:
    int counter;
    int start_x;
    int start_y;
    char direction;
    MetroSystem* metro;

public:
    Line(MetroSystem* system, char dir, int x, int y);
    void addStation(std::string name, float distance);
};

Line::Line(MetroSystem* ptr, char dir, int x, int y)
{
    metro = ptr;
    direction = dir;
    start_x = x;
    start_y = y;
    counter = 0;
}

void Line::addStation(std::string name, float distance)
{
    if (direction == 'H')
    {
        metro->Grid[start_x][start_y + counter] = name;
    }
    else if (direction == 'V')
    {
        metro->Grid[start_x + counter][start_y] = name;
    }

    counter++;

    int previousIndex = metro->stCounter - 1;
    
    metro->AdjacencyMatrix[metro->stCounter][previousIndex] = distance;
    metro->AdjacencyMatrix[previousIndex][metro->stCounter] = distance;

    metro->stCounter++;
}

int main()
{
    MetroSystem Bangalore_Metro;

    Line PurpleLine(&Bangalore_Metro , 'H', 2 , 0);

    PurpleLine.addStation("", 1);
    
    Line GreenLine(&Bangalore_Metro , 'V' , 1 , 1);
    
    GreenLine.addStation("" , 6);

    Bangalore_Metro.displayMap();

    return 0;
}
