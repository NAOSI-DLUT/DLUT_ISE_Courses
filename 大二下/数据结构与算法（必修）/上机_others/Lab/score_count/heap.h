//
//  heap.h
//  111
//
//  Created by MEGABOY on 2021-04-13.
//

#ifndef heap_h
#define heap_h
#include <iostream>
#include <fstream>
using namespace std;
template <class T>
class heap
{
public:
    T pool[50];
    int size;
    heap()
    {
        size=-1;
    }
    
    T& max()
    {
        return pool[0];
    }
    
    bool isleaf(int index)
    {
        if(index>size) return false;
        if(index>(size-1)/2) return true;
        return false;
    }
    
    int rightchild(int index)
    {
       // if(index*2+2>size)return -1;
        return(index*2+2);
    }
    
    int leftchild(int index)
    {
       // if(index*2+1>size) return -1;
        return(index*2+1);
    }
    
    int maxnonleaf()
    {
        int i;
        for(i=0;i<=size;i++)
        {
            if(isleaf(i) && i!=0) return i;
        }
        return 0;
    }
    
    int parent(int index)
    {
        return ((index-1)/2);
    }
    
    bool insert(const T& newnode)
    {
        if(size>=1000) return false;
        size++;
        pool[size-1]=newnode;
        int pos=size-1;
        while(pool[pos]>pool[parent(pos)] && pos>0)
        {
            T tmp=pool[pos];
            pool[pos]=pool[parent(pos)];
            pool[parent(pos)]=tmp;
        }
        return true;
    }
    
    bool remove(int pos, T& node)
    {
        T tmp;
        if(pos<0 || pos>size-1) return false;
        node=pool[pos];
        pool[pos]=pool[size-1];
        size--;
        int maxchild;
        if(pool[leftchild(pos)]>pool[rightchild(pos)])
            maxchild=leftchild(pos);
        else maxchild=rightchild(pos);
        while(pool[pos]<pool[maxchild])
        {
            tmp=pool[maxchild];
            pool[maxchild]=pool[pos];
            pool[pos]=tmp;
            pos=maxchild;
            if(pool[leftchild(pos)]>pool[rightchild(pos)])
                maxchild=leftchild(pos);
            else maxchild=rightchild(pos);
        }
        return true;
    }
    
    void siftdown(int left)
    {
        int i=left;
        int j=leftchild(i);
        T temp=pool[i];
        while(j<size)
        {
            if((j<size-1) && (pool[j]<pool[j+1])) j++;
            if(temp<pool[j])
            {
                pool[i]=pool[j];
                i=j;
                j=leftchild(j);
            }
            else break;
        }
        pool[i]=temp;
    }
    
    void siftup(int left)
    {
        T tmp=pool[left];
        while(left>0 && pool[parent(left)]>tmp)
        {
            pool[left]=pool[parent(left)];
            left=parent(left);
        }
        pool[left]=tmp;
    }
    
    void build()
    {
        int i;
        for(i=size/2-1;i>=0;i--) siftdown(i);
    }
};

#endif /* heap_h */
