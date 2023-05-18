//
//  student.h
//  111
//
//  Created by MEGABOY on 2021-04-13.
//

#ifndef student_h
#define student_h
#include <iostream>
#include <fstream>
using namespace std;
struct student
{
public:
    int value;
    string name;
    student()
    {
        value=0;
        name="";
    }
    student(int value,string name)
    {
        this->value=value;
        this->name=name;
    }
    bool operator>(student sec)
    {
        if(this->value > sec.value) return true;
        else return false;
    }
    bool operator<(student sec)
    {
        if(this->value < sec.value) return true;
        else return false;
    }
    void print()
    {
        cout << name << " " << value << endl;
    }
};


#endif /* student_h */
