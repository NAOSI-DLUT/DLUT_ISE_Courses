//
//  main.cpp
//  333
//
//  Created by MEGABOY on 2021-04-12.
//

#include <iostream>
#include <fstream>
#include "student.h"
#include "heap.h"
using namespace std;
int isnumber(string str)
{
    int i,sum=0,mult=1;
    for(i=str.length()-1;i>=0;i--)
    {
        if(str[i]-'0' >= 10 || str[i]-'0' <0) return -1;
        sum+=mult*(str[i]-'0');
        mult*=10;
    }
    return sum;
}
heap<student> data;
int main(int argc, const char * argv[])
{
    ifstream input;
    int f;
    int i=-1;
    
    for(f=1;f<=argc;f++)
    {
        input.open(argv[f]);
        if(!input.is_open())
        {
            cout << "READ FILE ERROR" <<endl;
            return -1;
        }
        while(!input.eof())
        {
            string dt;
            int val;
            input >> dt;
            val=isnumber(dt);
            if(val >=0)
            {
                i++;
                data.pool[i].value=val;
            }
            else if(dt != "")
            {
                if(data.pool[i].name != "") data.pool[i].name+=" ";
                data.pool[i].name+=dt;
            }
        }
    }
    
    data.size=i-1;
    input.close();
    data.build();
    cout << "Number of Students :" << data.size+1 << endl;
    if(data.size >= 2)
    {
        cout << "Top 3 Scores:" <<endl;
        data.pool[0].print();
        data.pool[1].print();
        data.pool[2].print();
    }
    else if(data.size==1)
    {
        data.pool[0].print();
        data.pool[1].print();
        cout << "Top 2 Scores:" <<endl;
    }
    else if(data.size==0)
    {
        data.pool[0].print();
        cout << "Top 1 Score:" <<endl;
    }
    else cout << "NO DATA AVAILABLE" << endl;
    return 0;
}
