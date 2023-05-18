#include "simulater.h"
using namespace std;

Simulater::Simulater()
{
    // initialize the bank window
    for (int i = 0; i < NORMAL_BW; i++)
    {
        normalBWArray[i].setId(i + 1);
        normalBWArray[i].setWindowType("normal");
    }
    for (int i = 0; i < VIP_BW; i++)
    {
        VIPBWArray[i].setId(i + 1);
        VIPBWArray[i].setWindowType("VIP");
    }
    for (int i = 0; i < OFFICIAL_BW; i++)
    {
        officialBWArray[i].setId(i + 1);
        officialBWArray[i].setWindowType("official");
    }
}

void Simulater::customerEnter(User *newUser, int &timePoint)
{
    //set new client's arrive time
    newUser->setArriveTime(timePoint * 2);
    
    // push new user into the correspond queue
    if (newUser->getUserType() == "normal")
    {
        normalUserQueue.push(newUser);
    }
    else if (newUser->getUserType() == "VIP")
    {
        VIPUserQueue.push(newUser);
    }
    else if (newUser->getUserType() == "official")
    {
        officialUserQueue.push(newUser);
    }
}

// simulate the customer's enter process, and get their id
void Simulater::simulateCustomerEnter(int &currentId, int &timePoint)
{
    // at the same time, push each kind of user into the correspond queue
    for (int normalNum = 0; normalNum < userEnterMatrix[timePoint][0]; normalNum++)
    {
        User *newNormalUser = new User;
        // distribute the id to the user
        newNormalUser->setId(currentId++);
        newNormalUser->setUserType("normal");

        customerEnter(newNormalUser, timePoint);
    }
    for (int VIPNum = 0; VIPNum < userEnterMatrix[timePoint][1]; VIPNum++)
    {
        User *newVIPUser = new User;
        // distribute the id to the user
        newVIPUser->setId(currentId++);
        newVIPUser->setUserType("VIP");

        customerEnter(newVIPUser, timePoint);
    }
    for (int officialNum = 0; officialNum < userEnterMatrix[timePoint][2]; officialNum++)
    {
        User *newOfficialUser = new User;
        // distribute the id to the user
        newOfficialUser->setId(currentId++);
        newOfficialUser->setUserType("official");

        customerEnter(newOfficialUser, timePoint);
    }
}

// simulate the calling process of customers
void Simulater::simulateCallCustomer()
{
    // traverse 3 bank windows, if is busy, then service time ++, when reachs TIME_SERVICE, reset
    // normal bank window:
    for (int i = 0; i < NORMAL_BW; i++)
    {
        if (normalBWArray[i].getIsBusy() && normalBWArray[i].getClient()->getServeTime() == TIME_SERVICE)
        {
            normalBWArray[i].setClient(NULL);
            normalBWArray[i].setIsBusy(false);
        }

        // is busy
        if (normalBWArray[i].getIsBusy())
        {
            normalBWArray[i].getClient()->setServeTime(normalBWArray[i].getClient()->getServeTime() + 2);
        }
        // is not busy and the queue is not empty, call (no interval time)
        else if (normalBWArray[i].getIsBusy() == false && normalUserQueue.empty() == false)
        {
            // set as busy
            normalBWArray[i].setIsBusy(true);
            // set client
            normalBWArray[i].setClient(normalUserQueue.front());
            // dequeue
            normalUserQueue.pop();
            // go to the bank window
            cout << "No." << normalBWArray[i].getClient()->getId()
                 << ", please go to No." << normalBWArray[i].getId() << " normal bank window" << endl;

            //now begin the service
            normalBWArray[i].getClient()->getServed();
            // service time add
            normalBWArray[i].getClient()->setServeTime(normalBWArray[i].getClient()->getServeTime() + 2);
        }
    }

    // VIP bank window:
    for (int i = 0; i < VIP_BW; i++)
    {
        if (VIPBWArray[i].getIsBusy() && VIPBWArray[i].getClient()->getServeTime() == TIME_SERVICE)
        {
            VIPBWArray[i].setClient(NULL);
            VIPBWArray[i].setIsBusy(false);
        }

        // is busy
        if (VIPBWArray[i].getIsBusy())
        {
            VIPBWArray[i].getClient()->setServeTime(VIPBWArray[i].getClient()->getServeTime() + 2);
        }
        // 1. is not busy and the VIP queue is not empty
        else if (VIPBWArray[i].getIsBusy() == false && VIPUserQueue.empty() == false)
        {
            // set as busy
            VIPBWArray[i].setIsBusy(true);
            // set client
            VIPBWArray[i].setClient(VIPUserQueue.front());
            // dequeue
            VIPUserQueue.pop();
            // go to the bank window
            cout << "No." << VIPBWArray[i].getClient()->getId()
                 << ", please go to No." << VIPBWArray[i].getId() << " VIP bank window" << endl;

            //now begin the service
            VIPBWArray[i].getClient()->getServed();
            // service time add
            VIPBWArray[i].getClient()->setServeTime(VIPBWArray[i].getClient()->getServeTime() + 2);
        }

        // 2. is not busy and the VIP queue is empty but normal queue is not empty
        else if (VIPBWArray[i].getIsBusy() == false && normalUserQueue.empty() == false)
        {
            // set as busy
            VIPBWArray[i].setIsBusy(true);
            // set client
            VIPBWArray[i].setClient(normalUserQueue.front());
            // dequeue
            normalUserQueue.pop();
            // go to the bank window
            cout << "No." << VIPBWArray[i].getClient()->getId()
                 << ", please go to No." << VIPBWArray[i].getId() << " VIP bank window" << endl;
            
            //now begin the service
            VIPBWArray[i].getClient()->getServed();
            // service time add
            VIPBWArray[i].getClient()->setServeTime(VIPBWArray[i].getClient()->getServeTime() + 2);
        }
    }

    // official bank window:
    for (int i = 0; i < OFFICIAL_BW; i++)
    {
        if (officialBWArray[i].getIsBusy() && officialBWArray[i].getClient()->getServeTime() == TIME_SERVICE)
        {
            officialBWArray[i].setClient(NULL);
            officialBWArray[i].setIsBusy(false);
        }
        
        // is busy
        if (officialBWArray[i].getIsBusy())
        {
            officialBWArray[i].getClient()->setServeTime(officialBWArray[i].getClient()->getServeTime() + 2);
        }
        // 1. is not busy and the official queue is not empty
        else if (officialBWArray[i].getIsBusy() == false && officialUserQueue.empty() == false)
        {
            // set as busy
            officialBWArray[i].setIsBusy(true);
            // set client
            officialBWArray[i].setClient(officialUserQueue.front());
            // dequeue
            officialUserQueue.pop();
            // go to the bank window
            cout << "No." << officialBWArray[i].getClient()->getId()
                 << ", please go to No." << officialBWArray[i].getId() << " official bank window" << endl;
            
            //now begin the service
            officialBWArray[i].getClient()->getServed();
            // service time add
            officialBWArray[i].getClient()->setServeTime(officialBWArray[i].getClient()->getServeTime() + 2);
        }

        // 2. is not busy and the official queue is empty but normal queue is not empty
        else if (officialBWArray[i].getIsBusy() == false && normalUserQueue.empty() == false)
        {
            // set as busy
            officialBWArray[i].setIsBusy(true);
            // set client
            officialBWArray[i].setClient(normalUserQueue.front());
            // dequeue
            normalUserQueue.pop();
            // go to the bank window
            cout << "No." << officialBWArray[i].getClient()->getId()
                 << ", please go to No." << officialBWArray[i].getId() << " official bank window" << endl;

            //now begin the service
            officialBWArray[i].getClient()->getServed();
            // service time add
            officialBWArray[i].getClient()->setServeTime(officialBWArray[i].getClient()->getServeTime() + 2);
        }
    }
}

void Simulater::simulate()
{
    // current id number
    int currentId = 1;
    // traverse the customer enter matrix
    for (int timePoint = 0; timePoint < 7; timePoint++)
    {
        // simulate custom enter function
        simulateCustomerEnter(currentId, timePoint);

        cout << "**************************" << endl;
        cout << "At " << timePoint * 2 << " s: " << endl;

        // simulate call customer function
        simulateCallCustomer();
        cout << endl;

        // print out at current time point, the window's status:
        // normal bank window:
        for (int i = 0; i < NORMAL_BW; i++)
        {
            // the bank window is busy, show the client's information
            if (normalBWArray[i].getIsBusy() == true)
            {
                cout << "Normal Bank Window No." << normalBWArray[i].getId() << " is in service:" << endl
                     << "Client's type: " << normalBWArray[i].getClient()->getUserType() << endl
                     << "Client's arrive time: " << normalBWArray[i].getClient()->getArriveTime() << endl
                     << "Client's serve time: " << normalBWArray[i].getClient()->getServeTime() << endl
                     << "Client's Id: " << normalBWArray[i].getClient()->getId() << endl;
            }
            // the bank window is not busy
            else
            {
                cout << "Normal Bank Window No." << normalBWArray[i].getId() 
                     << " is not busy at present." << endl;
            }
        }
        // VIP bank window:
        for (int i = 0; i < VIP_BW; i++)
        {
            // the bank window is busy, show the client's information
            if (VIPBWArray[i].getIsBusy() == true)
            {
                cout << "VIP Bank Window No." << VIPBWArray[i].getId() << " is in service:" << endl
                     << "Client's type: " << VIPBWArray[i].getClient()->getUserType() << endl
                     << "Client's arrive time: " << VIPBWArray[i].getClient()->getArriveTime() << endl
                     << "Client's serve time: " << VIPBWArray[i].getClient()->getServeTime() << endl
                     << "Client's Id: " << VIPBWArray[i].getClient()->getId() << endl;
            }
            // the bank window is not busy
            else
            {
                cout << "VIP Bank Window No." << VIPBWArray[i].getId() << " is not busy at present." << endl;
            }
        }
        // official bank window:
        for (int i = 0; i < VIP_BW; i++)
        {
            // the bank window is busy, show the client's information
            if (officialBWArray[i].getIsBusy() == true)
            {
                cout << "official Bank Window No." << officialBWArray[i].getId() << " is in service:" << endl
                     << "Client's type: " << officialBWArray[i].getClient()->getUserType() << endl
                     << "Client's arrive time: " << officialBWArray[i].getClient()->getArriveTime() << endl
                     << "Client's serve time: " << officialBWArray[i].getClient()->getServeTime() << endl
                     << "Client's Id: " << officialBWArray[i].getClient()->getId() << endl;
            }
            // the bank window is not busy
            else
            {
                cout << "official Bank Window No." << officialBWArray[i].getId() 
                     << " is not busy at present." << endl;
            }
        }
    }
}

int main()
{
    Simulater bankWindowSimulater;
    bankWindowSimulater.simulate();

    system("pause");
    return 0;
}