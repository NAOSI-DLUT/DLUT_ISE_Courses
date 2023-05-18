#pragma once

#ifndef _EUROPEBYRAIL_H_
#define _EUROPEBYRAIL_H_

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
// INT_MAX用来表示正无穷
#include <climits>
#include <algorithm>

using namespace std;

class City {

public:

    // name of the city
    string name;

    // bookkeeping info
    // 是否被访问
    bool visited;
    // 总花费
    int totalFee;
    // 总距离
    int totalDistance;
    // 前驱节点（城市）
    string preCity;

    City()
    {
        name = ""; 
        visited = false; 
        totalFee = 0; 
        totalDistance = 0;
        preCity = "";
    }

    City(string const &name)
    {
        this->name = name;
        visited = false;
        totalFee = 0;
        totalDistance = 0; 
        preCity = "";
    }
};

// rail service
class Service 
{
public:
    int fee;
    int distance;
    string destination;

    Service(string city, int fee, int distance)
    {
        this->fee = fee;
        this->distance = distance;
        this->destination = city;
    }
};


class Cheapest
{
public:
    Cheapest()
    {

    }

    bool operator()(const City* city1, const City* city2)
    {
        return city1->totalFee > city2->totalFee;
    }

    bool operator()(const City& city1, const City& city2)
    {
        return city1.totalFee > city2.totalFee;
    }

};

class Route
{
private:
    string source;
    string destination;
    int fee;
    int distance;
    
public:
    Route(const string& source, const string& destination, 
            int fee, int distance)
    {
        this->source = source;
        this->destination = destination, 
        this->fee = fee, 
        this->distance = distance; 
    }

    int getFee()
    {
        return this->fee;
    }

    int getDistance()
    {
        return this->distance;
    }

    bool operator==(Route const& route) const
    {
        return route.source == this->source
               && route.destination == this->destination
               && route.fee == this->fee
               && route.distance == this->distance;
    };
};


class RailSystem
{
protected:
    // <城市, 铁路(出)>
    map<string, list<Service*>> outServices;
    // <城市, 城市>
    map<string, City*> cities;
    
    // 读取services.txt文件
    void loadServices(const string&);

    void addService(const string&);

    void addCity(const string&);

    void reset();

    vector<string> recoverRoute(const string&);

    pair<int, int> calculateRoute(string source, string destination);

    void initialization(string& startCity);

    string findMinCity();

    void visit(string& cityName);

    void cityCheck(const string& cityName);

public:

    // 读取文件
    RailSystem(const string&);

    ~RailSystem();

    void outputCheapRoute(const string& source, const string& destination);

    bool isValidCity(const string& name);

    /// For test only.
    Route getCheapestRoute(const string& source, const string& destination);
};

#endif
