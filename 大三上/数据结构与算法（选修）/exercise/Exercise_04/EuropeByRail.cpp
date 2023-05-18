#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>

#include "EuropeByRail.h"

using namespace std;

// 构造函数初始化
RailSystem::RailSystem(const string& filename)
{
    loadServices(filename);
}

void RailSystem::reset()
{
    map<string, City*>::iterator iter;
    for(iter = cities.begin(); iter != cities.end(); ++iter)
    {
        // <key, value>
        delete iter->second;
    }
}

// 析构函数，循环删除map和list
RailSystem::~RailSystem()
{
    reset();

    map<string, list<Service*>>::iterator mapIter;
    for(mapIter = outServices.begin(); mapIter != outServices.end(); ++mapIter)
    {
        list<Service*>::iterator listIter; 
        for(listIter = mapIter->second.begin(); listIter != mapIter->second.end(); ++listIter)
        {
            delete *listIter;
        }
    }
}

void RailSystem::loadServices(const string& filename)
{
    ifstream in(filename);
    string line;

    if(!in.is_open())
    {
        cout << "Cannot open the file. " << endl;
        // 中断程序执行
        exit(0);
    }

    while (getline(in, line))
    {
        addService(line);
    }

    in.close();
}

void RailSystem::addService(const string& line)
{
    istringstream iStringStream(line);
    // 源城市，目标城市，花费，距离
    string sourceCity;
    string destinationCity;
    int fee;
    int dist;

    iStringStream >> sourceCity;
    iStringStream >> destinationCity;
    iStringStream >> fee;
    // cout << "fee: " << fee;
    iStringStream >> dist;
    // cout << "distance: " << dist;

    addCity(sourceCity);
    addCity(destinationCity);

    Service* service = new Service(destinationCity, fee, dist);
    // 源城市添加出度
    outServices[sourceCity].push_back(service);
}

void RailSystem::addCity(const string& cityName)
{
    map<string, City*>::iterator iter;

    iter = cities.find(cityName);
    // map中没有找到要添加的城市，则进行添加，此时迭代器指针指在末尾；找到了就不添加。
    if(iter == cities.end())
    {
        City* city = new City(cityName);
        // add city
        cities.insert(pair<string, City*>(cityName, city));
        // add empty services to new city
        outServices.insert(pair<string, list<Service*>>(cityName, list<Service*>())); 
    }
}

// main function
pair<int, int> RailSystem::calculateRoute(string source, string destination)
{
    cityCheck(source);
    cityCheck(destination);
    initialization(source);

    while (true)
    {
        string currCityName = findMinCity();
        // no such city
        if(currCityName == "") 
        {
            break;
        } 

        // visit the node, and set isVisited as true
        visit(currCityName);
        if(currCityName == destination)
        {
            City* lastCity = cities[currCityName];
            return pair<int, int>(lastCity->totalFee, lastCity->totalDistance);
        }
    }

    return pair<int, int>(INT_MAX, INT_MAX);
}

void RailSystem::cityCheck(const string& cityName)
{
    map<string, City*>::iterator mapIter;
    mapIter = cities.find(cityName);
    if(mapIter == cities.end()) // if city was't found in map
        throw invalid_argument("Cannot find " + cityName);
}

void RailSystem::initialization(string& start)
{
    map<string, City*>::iterator mapIter;
    for(mapIter = cities.begin(); mapIter != cities.end(); ++mapIter)
    {
        // 还没有建立railway，因此值都设为正无穷
        mapIter->second->totalFee = INT_MAX;
        mapIter->second->totalDistance = INT_MAX;
        mapIter->second->visited = false;
        mapIter->second->preCity = "";
    }

    cities[start]->totalFee = 0;
    cities[start]->totalDistance = 0;
}

string RailSystem::findMinCity()
{
    string nearestCityName;
    // 附近的花费少的城市
    City* bestCity = nullptr;

    map<string, City*>::iterator mapIter;
    for(mapIter = cities.begin(); mapIter != cities.end(); ++mapIter)
    {
        City* currCity = mapIter->second;
        if (!currCity->visited && currCity->totalFee != INT_MAX 
            && (!bestCity || bestCity->totalFee > currCity->totalFee))
        {
            bestCity = currCity;
            nearestCityName = bestCity->name;
        }
    }

    return nearestCityName;
}

void RailSystem::visit(string& cityName)
{
    City* currCity = cities[cityName];
    list<Service*> services = outServices[cityName];

    list<Service*>::iterator listIter;
    for(listIter = services.begin(); listIter != services.end(); ++listIter)
    {
        // 取得与该城市相邻的城市指针
        City* siblingCity = cities[(*listIter)->destination];
        // 找到一条更短路径，然后对相邻城市的值进行更新
        if(!siblingCity->visited && siblingCity->totalFee > currCity->totalFee + (*listIter)->fee)
        {
            siblingCity->totalFee = currCity->totalFee + (*listIter)->fee;
            siblingCity->totalDistance = currCity->totalDistance + (*listIter)->distance;
            siblingCity->preCity = cityName;
        }
    }

    currCity->visited = true;
}

// 反向遍历route，然后反转
vector<string> RailSystem::recoverRoute(const string& city)
{
    cityCheck(city);
    // if there is no railway
    if(cities[city]->preCity == "")
    {
        return vector<string>();
    }
        
    vector<string> reachedCities;
    string currCityName = city;

    while (currCityName != "")
    {
        reachedCities.push_back(currCityName);
        City* currCity = cities[currCityName];
        currCityName = currCity->preCity;
    }

    reverse(reachedCities.begin(), reachedCities.end());
    return reachedCities;
}

// 判断是否存在这个城市
bool RailSystem::isValidCity(const string& name)
{
    map<string, City*>::iterator mapIter;
    mapIter = cities.find(name);

    return !(mapIter == cities.end());
}

void RailSystem::outputCheapRoute(const string& source, const string& destination)
{
    calculateRoute(source, destination);
    vector<string> cities = recoverRoute(destination);

    vector<string>::iterator city;
    for(city = cities.begin(); city != cities.end(); ++city)
    {
        cout << *city << endl;
    }
}

Route RailSystem::getCheapestRoute(const string& source, const string& destination)
{
    pair<int, int> result = calculateRoute(source, destination);

    return Route(source, destination, result.first, result.second);
}
