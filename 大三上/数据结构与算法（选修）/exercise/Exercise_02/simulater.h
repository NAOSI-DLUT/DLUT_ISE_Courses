#ifndef SIMULATER_H
#define SIMULATER_H

#include <iostream>
#include <cstring>
#include <queue>
//custom single linked list header
#include "user.h"
#include "bankwindow.h"

#define NORMAL_BW 3
#define VIP_BW 1
#define OFFICIAL_BW 1

#define TIME_SERVICE 4
#define TIME_INTERVAL 2

using namespace std;

class Simulater
{
public:
    Simulater();
    //customer enter ?
    void customerEnter(User *, int &timePoint);
    //simulate customer enter ?
    void simulateCustomerEnter(int &currentId, int &timePoint);
    //simulate call customer
    void simulateCallCustomer();
    //simulate function
    void simulate();

private:
    //queues for 3 kinds of users
    queue<User *> normalUserQueue;
    queue<User *> VIPUserQueue;
    queue<User *> officialUserQueue;
    //3 linked lists for 3 kinds of bank windows
    BankWindow normalBWArray[NORMAL_BW];
    BankWindow VIPBWArray[VIP_BW];
    BankWindow officialBWArray[OFFICIAL_BW];
    //user enter matrix
    int userEnterMatrix[7][3] = {{3, 1, 1}, {5, 0, 0}, {0, 0, 0}, 
                                    {5, 1, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    
};

#endif