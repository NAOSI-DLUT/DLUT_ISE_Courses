/*2.4最大堆
 *
 * void BuildHeap();    //2.4-a 最大堆构建
 * void SiftDown(int left);    //2.4-b SiftDown函数从left向下调整堆，使序列成为堆
 * void SiftUp(int pos);    //2.4-c SiftUp函数从position向上调整堆，使序列成为堆
 * bool Remove(int pos, T& node);    //2.4-d 删除给定下标的元素
 * bool Insert(const T& newNode);    //2.4-e 从堆中插入新元素newNode
 *
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

template <class T>
class MaxHeap {
private:
    T* heapArray;
    int CurrentSize; /* 当前堆元素个数 */
    int MaxSize; /* 堆中能存放的最大元素个数 */
public:
    MaxHeap(T* array, int num, int max)
    {
        this->heapArray = array;
        this->CurrentSize = num;
        this->MaxSize = max;
    }

    virtual ~MaxHeap(){};
    bool isLeaf(int pos) const;
    int leftchild(int pos) const;
    int rightchild(int pos) const;
    int parent(int pos) const;
    void BuildHeap(); /* 2.4-a 最大堆构建 */
    void SiftDown(int left); /* 2.4-b SiftDown函数从left向下调整堆，使序列成为堆 */
    void SiftUp(int pos); /* 2.4-c SiftUp函数从position向上调整堆，使序列成为堆 */
    bool Remove(int pos, T& node); /* 2.4-d 删除给定下标的元素 */
    bool Insert(const T& newNode); /* 2.4-e 从堆中插入新元素newNode */
    T& RemoveMax(); /* 2.4-f 从堆顶删除最大值 */
    void visit();
};

/*
 * TODO:2.4-a 最大堆构建
 */
template <class T>
void MaxHeap<T>::BuildHeap()
{
    int i=CurrentSize/2-1;
    for(;i>=0;i--) SiftDown(i);
}

template <class T>
bool MaxHeap<T>::isLeaf(int pos) const
{
    if (pos >= CurrentSize) {
        cout << "越界" << endl;
        return (false);
    } else if (pos > (CurrentSize - 1) / 2)
        return (true);
    else
        return (false);
}

template <class T>
int MaxHeap<T>::leftchild(int pos) const
{
    return (2 * pos + 1);
}

template <class T>
int MaxHeap<T>::rightchild(int pos) const
{
    return (2 * pos + 2);
}

template <class T>
int MaxHeap<T>::parent(int pos) const
{
    return ((pos - 1) / 2);
}

/*
 * TODO:2.4-d 删除给定下标的元素，并将该元素的值赋值给node变量。
 * 返回值说明：如果删除成功，则返回true，否则返回false
 * 重要说明：如果当前堆为空，则输出打印cout << "空堆" << endl;并返回false
 */
template <class T>
bool MaxHeap<T>::Remove(int pos, T& node)
{
    int tmp;
    if(pos<0 || pos>CurrentSize-1) return false;
    node=heapArray[pos];
    heapArray[pos]=heapArray[CurrentSize-1];
    CurrentSize--;
    int maxchild;
    if(heapArray[leftchild(pos)]>heapArray[rightchild(pos)]) maxchild=leftchild(pos);
    else maxchild=rightchild(pos);
    while(heapArray[pos]<heapArray[maxchild])
    {
        tmp=heapArray[maxchild];
        heapArray[maxchild]=heapArray[pos];
        heapArray[pos]=tmp;
        pos=maxchild;
        if(heapArray[leftchild(pos)]>heapArray[rightchild(pos)]) maxchild=leftchild(pos);
        else maxchild=rightchild(pos);
    }
    return true;
}

/*
 * TODO:2.4 - b SiftDown函数从left向下调整堆，使序列成为堆
 */
template <class T>
void MaxHeap<T>::SiftDown(int left)
{
    int i=left;
    int j=2*i+1;
    T tmp=heapArray[i];
    while(j<CurrentSize)
    {
        if((j<CurrentSize-1) && (heapArray[j]<heapArray[j+1])) j++;
        if(tmp<heapArray[j])
        {
            heapArray[i]=heapArray[j];
            i=j;
            j=2*j+1;
        }
        else break;
    }
    heapArray[i]=tmp;
}

/*
 * TODO:2.4-c SiftUp函数从pos向上调整堆，使序列成为堆
 */
template <class T>
void MaxHeap<T>::SiftUp(int pos)
{
    T tmp=heapArray[pos];
    while(pos>0 && heapArray[parent(pos)]> tmp)
    {
        heapArray[pos]=heapArray[parent(pos)];
        pos=parent(pos);
    }
    heapArray[pos]=tmp;
}

/*
 * TODO:2.4-e 从堆中插入新元素newNode, 如果插入成功，返回true，否则返回false。
 * 重要说明：如果堆中元素超过堆中元素最大个数值，则输出打印cout << "堆满" << endl;并返回false
 */
template <class T>
bool MaxHeap<T>::Insert(const T& newNode)
{
    if(CurrentSize>=MaxSize)
    {
        cout << "堆满" << endl;
        return false;
    }
    CurrentSize++;
    heapArray[CurrentSize-1]=newNode;
    int pos=CurrentSize-1;
    while(heapArray[pos]>heapArray[parent(pos)] && pos>0)
    {
        int tmp=heapArray[pos];
        heapArray[pos]=heapArray[parent(pos)];
        heapArray[parent(pos)]=tmp;
        pos=parent(pos);
    }
    return true;
}

template <class T>
void MaxHeap<T>::visit()
{
    for (int i = 0; i < CurrentSize; i++)
        cout << heapArray[i] << " ";
    cout << endl;
}

/*
 * TODO:2.4-f 从堆顶删除最大值. 如果堆栈为空堆，则输出打印cout << "空堆" << endl;然后退出程序，退出码为1.
 * 否则，从堆顶删除最大值，并将其作为返回值进行返回。
 */
template <class T>
T& MaxHeap<T>::RemoveMax()
{
    T tmp=1;
    if(CurrentSize<0)
    {
        cout << "空堆" << endl;
        return tmp;
    }
    Remove(0, tmp);
    return tmp;
}

int main()
{
    /* int a[10] = { 20,12,35,15,10,80,30,17,2,1 }; */
    int count, maxSize; /* 初始化堆中元素个数 */
    cin >> count >> maxSize;
    int iValue;
    int* a = new int[count];
    for (int i = 0; i < count; i++) {
        cin >> iValue;
        a[i] = iValue;
    }

    /* MaxHeap<int> maxheap(a, 10, 20); */
    MaxHeap<int> maxheap(a, count, maxSize);
    int temp;
    maxheap.BuildHeap();
    cout << "构建堆后为:";
    maxheap.visit();
    cin >> iValue; /* 输入一个整数，判断它是否是堆上的叶子节点 */
    if (maxheap.isLeaf(iValue))
        cout << "位置" << iValue << "是叶结点" << endl;
    else
        cout << "位置" << iValue << "不是叶结点" << endl;
    maxheap.visit();
    maxheap.RemoveMax();
    cout << "移除最大值后:";
    maxheap.visit();
    cin >> iValue; /* 输入一个整数，移除该下标所在的元素 */
    maxheap.Remove(iValue, temp);
    cout << "删除下标为" << iValue << "的元素之后为:";
    maxheap.visit();
    cout << "删除下标为" << iValue << "的元素为" << temp << endl;
    cin >> iValue; /* 输入一个整数，移除该下标所在的元素 */
    maxheap.Insert(iValue);
    cout << "插入" << iValue << "后为:";
    maxheap.visit();
    return (0);
}

