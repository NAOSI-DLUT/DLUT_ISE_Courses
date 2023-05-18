#include "bankwindow.h"
#include "user.h"
using namespace std;

BankWindow::BankWindow()
{
    this->client = NULL;
    this->isBusy = false;
    this->id = -1;
    this->windowType = "";
}

int BankWindow::getId()
{
    return this->id;
}

void BankWindow::setId(int id)
{
    this->id = id;
}

string BankWindow::getWindowType()
{
    return this->windowType;
}

void BankWindow::setWindowType(string windowType)
{
    this->windowType = windowType;
}

bool BankWindow::getIsBusy()
{
    return this->isBusy;
}

void BankWindow::setIsBusy(bool isBusy)
{
    this->isBusy = isBusy;
}

User *BankWindow::getClient()
{
    return this->client;
}

void BankWindow::setClient(User *client)
{
    this->client = client;
}
