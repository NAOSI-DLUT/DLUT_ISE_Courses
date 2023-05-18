#include<stack>
#include<fstream>
#include<iostream>
#include<cstring>
using namespace std;

class Car{
public:
  char *license_plate;
  int moved;
  Car() //Initialization
  {
    license_plate=new char[10];
    moved=0;
  }
  ~Car()
  {
    delete license_plate;
  }
};

stack<Car*> parked_cars; //Stack to store information of parked cars
stack<Car*> moved_cars; //Stack to store information of moved cars

fstream input;
ofstream output;

bool isfull()
{
  return(parked_cars.size() >= 5);
}

int main()
{
  char plate[10];
  char ready_to_leave[10];
  char status[10];
  Car cars[100];
  Car *temp;
  int index=0;
  input.open("./data.txt",ios::in);
  output.open("./output.txt",ios::out);
  while(!input.eof())
  {
    input >> plate; //Current Car
    input >> status;

    if(status[0]=='a') //arrival
    {
      if(isfull()) output << "Sorry " << plate << ", the lot is full" << endl;
      else //Allow Parking
     {
        index++;
        strcpy(cars[index].license_plate,plate);
        parked_cars.push(&cars[index]);
      }
    }

    if(status[0]=='d') //departure
    {
      strcpy(ready_to_leave,plate);

      while(strcmp(ready_to_leave,parked_cars.top()->license_plate)!=0) //Moving other cars out
      {
        temp=parked_cars.top();
        parked_cars.pop();
        temp->moved=temp->moved+1;
        moved_cars.push(temp);
      }

      temp=parked_cars.top();
      output << temp->license_plate << " was moved " << temp->moved << " times while it was here" << endl;
      parked_cars.pop();

      while(!moved_cars.empty()) //Moving other cars in
      {
        temp=moved_cars.top();
        moved_cars.pop();
        parked_cars.push(temp);
      }
    }
  }

  while(!parked_cars.empty()) //Show cars that are still parked
  {
    temp=parked_cars.top();
    output << temp->license_plate << " was moved " << temp->moved << " times while it was here" << endl;
    parked_cars.pop();
  }
  input.close();
  output.close();
  return 0;
}
