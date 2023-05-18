#ifndef USER_H
#define USER_H

#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

class User
{
public:
    User();
    void getServed();
    //set members
    void setId(int);
    void setIsWait(bool);
    void setArriveTime(int);
    void setServeTime(int);
    void setUserType(string);
    //get members
    int getId();
    bool getIsWait();
    int getArriveTime();
    int getServeTime();
    string getUserType();

private:
    //id
    int id;
    //is waiting?
    bool isWait;
    //arrive time
    int arriveTime;
    //serve time. If serve time == SERVICE_TIME, reset
    int serveTime;
    //user type: normal, VIP, official
    string userType;
};

#endif