#include <iostream>
#include <fstream>
#include <cstring>

#include "EuropeByRail.h"
// #include "EuropeByRail.cpp"

using namespace std;

// 定义文件路径
string filePath = "./services.txt";

void function(RailSystem &railSystem)
{
    while (true)
    {

        cout << "Enter a start and destination city: ('quit' to exit) " << endl;

        string source, destination;

        cin >> source;

        if (source == "quit")
        {
            break;
        }

        cin >> destination;

        if (railSystem.isValidCity(source) && railSystem.isValidCity(destination))
        {
            if (railSystem.getCheapestRoute(source, destination).getDistance() == INT_MAX)
            {
                cout << "There is no such route. " << endl << endl;
            }
            else
            {
                cout << "The cheapest route from " + source + " to " + destination + " is: " << endl;
                railSystem.outputCheapRoute(source, destination);

                cout << "Which costs " << railSystem.getCheapestRoute(source, destination).getFee()
                     << " Euros and "
                     << railSystem.getCheapestRoute(source, destination).getDistance()
                     << " kilometers. "
                     << endl << endl;
            }
        }
        else
        {
            cout << "Error. Invalid city. " << endl;
        }
    }
}

int main()
{
    RailSystem railSystem(filePath);
    function(railSystem);
    // system("pause");
    return 0;
}
