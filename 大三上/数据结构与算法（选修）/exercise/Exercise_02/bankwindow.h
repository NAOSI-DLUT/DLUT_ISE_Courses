#ifndef BANKWINDOW_H
#define BANKWINDOW_H

#include <iostream>
#include <time.h>
#include "user.h"
#include <cstring>
using namespace std;

class BankWindow
{
public:
    BankWindow();

    //set members
    void setIsBusy(bool);
    //replace for the handle user function
    void setClient(User *);
    void setId(int);
    void setWindowType(string);
    //get members
    bool getIsBusy();
    User *getClient();
    int getId();
    string getWindowType();

private:
    //is busy?
    bool isBusy;
    //current client
    User *client;
    //window id
    int id;
    //bank window type
    string windowType;
};

#endif