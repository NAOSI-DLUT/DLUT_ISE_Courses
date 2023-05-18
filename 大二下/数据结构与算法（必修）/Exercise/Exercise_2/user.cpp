#include "user.h"
using namespace std;

User::User()
{
    this->id = -1;
    this->isWait = true;
    this->arriveTime = -1;
    this->serveTime = -1;
    this->userType = "";
}

string User::getUserType()
{
    return this->userType;
}

void User::setUserType(string userType)
{
    this->userType = userType;
}

int User::getId()
{
    return this->id;
}

void User::setId(int id)
{
    this->id = id;
}

int User::getServeTime()
{
    return this->serveTime;
}

void User::setServeTime(int serveTime)
{
    this->serveTime = serveTime;
}

int User::getArriveTime()
{
    return this->arriveTime;
}

void User::setArriveTime(int arriveTime)
{
    this->arriveTime = arriveTime;
}

void User::getServed()
{
    //if get served, then set serve time as intial time '0'
    this->serveTime = 0;
}