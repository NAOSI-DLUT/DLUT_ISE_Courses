#include <iostream>
#include <stack>
#include <fstream>
#include <cstring>
#include <assert.h>
//max size for stack of parked cars
#define MAXSIZE 5

using namespace std;

class Car
{
    private:
        //the number of times the car has been moved 
        int movedTime;
        //license plate of the car 
        string licensePlate;
    public:
        //constructor
        Car();
        //get moved times
        int getMovedTime();
        //set moved times
        void setMovedTime(int);
        //get license plate
        string getLicensePlate();
        //set license plate
        void setLicensePlate(string);
};

//constructor
Car::Car() : movedTime(0)
{
    licensePlate = "";
}
//get moved times
int Car::getMovedTime()
{
    return this->movedTime;
}
//set moved times
void Car::setMovedTime(int movedTime)
{
    this->movedTime = movedTime;
}
//get license plate
string Car::getLicensePlate()
{
    return this->licensePlate;
}
//set license plate
void Car::setLicensePlate(string licensePlate)
{
    this->licensePlate = licensePlate;
}

void parkLotSimulate()
{
    //initialize two stack
    //stack for parked cars
    stack<Car *> parkedCars;
    //stack for moved cars
    stack<Car *> movedCars;
    //file stream to open file and RW
    ifstream fin;
    ofstream fout;
    //current car info
    string curLicensePlate;
    string status;
    //open file 
    fin.open("./Data.txt", ios::in);
    fout.open("./MyOutput.txt", ios::out);
    //error and exit when open failed
    assert(fin.is_open());
    assert(fout.is_open());
    //start read file
    while (!fin.eof())
    {
        //create a temporary current car
        Car *curCar = new Car;

        fin>>curLicensePlate;
        fin>>status;
        //when status is 'arrives'
        if (status == "arrives")
        {
            //if parked stack is full
            if (parkedCars.size() >= MAXSIZE)
            {
                fout<<"Sorry "<<curLicensePlate<<", the lot is full"<<endl;
            }
            //parked stack is not full
            else
            {
                curCar->setLicensePlate(curLicensePlate);
                parkedCars.push(curCar);
            }
        }
        //when status is 'departs'
        //the car must have been in the parked stack
        else if (status == "departs")
        {
            //move other cars out
            curCar = parkedCars.top();
            while (curLicensePlate != curCar->getLicensePlate())
            {
                //pop the top car, and move into moved stack with adding moved time by 1
                parkedCars.pop();
                curCar->setMovedTime(curCar->getMovedTime() + 1);
                movedCars.push(curCar);

                curCar = parkedCars.top();
            }

            //the target car which is going to depart
            fout<<curCar->getLicensePlate()<<" was moved "<<curCar->getMovedTime()
                <<" times while it was here"<<endl;
            
            parkedCars.pop();

            //then move other cars in
            while (!movedCars.empty())
            {
                curCar = movedCars.top();
                movedCars.pop();
                parkedCars.push(curCar);    
            }
        }

        curCar = NULL;
        delete curCar;
    }
    //after having read all the data
    //if parked stack is not empty
    while (!parkedCars.empty())
    {
        //output the moved times of the remain cars in the parked stack
        fout<<parkedCars.top()->getLicensePlate()<<" was moved "<<parkedCars.top()->getMovedTime()
            <<" times while it was here"<<endl;

        parkedCars.pop();
    }
    //close file stream
    fin.close();
    fout.close();

}

int main()
{
    parkLotSimulate();

    system("pause");
    return 0;
}