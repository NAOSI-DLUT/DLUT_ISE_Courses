/*1.1 顺序表

	bool Insert(const int p, const T value);        //1.1-b 在位置p插入元素value,表的长度增加1
	bool Delete(const int p);                       //1.1-d 删除位置p处的元素，表的长度减1
	int GetPos(const T x);					    	//1.1-c 返回值为x的元素的位置

*/
#include <iostream>
using namespace std;

#pragma once
template <class T>
class List {
public:
    void Clear(); //置空线性表
    bool IsEmpty(); //线性表为空时，返回true
    bool Append(const T value); //在表尾添加元素value，表的长度增加1
    bool Insert(const int p, const T value); //在位置p插入元素value,表的长度增加1
    bool Delete(const int p); //删除位置p处的元素，表的长度减1
    int GetPos(const T x); //把值为x的元素的位置返回到变量p中
};

template <class T> //线性表的元素类型为T
class ArrayList : public List<T> //定义顺序表ArrayList
{
public: //顺序表的运算集
    ArrayList(const int size) //创建顺序表，表长为最大长度
    {
        maxSize = size;
        arrayList = new T[maxSize];
        curLen = 0;
        position = 0;
    }
    ~ArrayList() //析构函数，消除ArrayList的实例
    {
        delete[] arrayList;
    }
    void clear() //清空顺序表
    {
        delete[] arrayList;
        curLen = 0;
        position = 0;
        arrayList = new T[maxSize];
    }

    int Length(); //顺序表的长度
    bool Append(const T value); //在表尾添加元素value，表的长度增加1

    bool Insert(const int p, const T value); //1.1-b 在位置p插入元素value,表的长度增加1
    bool Delete(const int p); //1.1-d 删除位置p处的元素，表的长度减1
    int GetPos(const T x); //1.1-c 返回值为x的元素的位置
    void PrintArray(); //输出顺序表内容
private:
    T* arrayList; //存储顺序表的实例
    int maxSize; //顺序表实例的最大长度
    int curLen; //顺序表实例的当前长度
    int position; //当前处理位置
};

template <class T>
int ArrayList<T>::Length()
{
    return curLen;
}

//在表尾添加元素value，表的长度增加1
template <class T>
bool ArrayList<T>::Append(const T value)
{
    if (curLen >= maxSize) //检查顺序表是否溢出
    {
        cout << "The List is overflow" << endl;
        return false;
    }

    arrayList[curLen] = value; //表尾处插入新元素
    curLen++; //表的实际长度增加1
    return true;
}

/*
TODO:1.1-b 在位置p插入元素value,表的长度增加1，p为要插入的位置下标值。比如：p=0，表示在顺序表的表头插入元素。
返回值说明：插入成功，返回true，否则返回false
注意事项：1）检查顺序表是否溢出，若溢出,则打印cout << "The List is overflow" << endl;返回false
          2）检查插入位置是否合法，若不合法，则cout << "Insertion point is illegal" << endl; 返回false
*/
template <class T>
bool ArrayList<T>::Insert(const int p, const T value)
{
    int i;
    if (curLen >= maxSize) //检查顺序表是否溢出
    {
      cout << "The List is overflow" << endl;
      return false;
    }
    if(p>curLen || p<0)
    {
      cout << "Insertion point is illegal" << endl;
      return false;
    }
    for(i=curLen-1;i>=p;i--)
    {
      arrayList[i+1]=arrayList[i];
    }
    arrayList[i+1]=value;
    curLen++;
    return true;
}

/*
TODO:1.1-d 删除位置p处的元素，表的长度减1，p为元素所在的下标值
返回值说明：删除成功，返回true，否则返回false
注意事项：1）如果顺序表中没有元素了，则打印cout << "No element to delete" << endl;并返回false
          2）如果删除的位置p非法，即p位置处无元素，则打印cout << "Deletion is illegal" << endl;并返回false
*/
template <class T>
bool ArrayList<T>::Delete(const int p)
{
  int i;
  if(curLen<=0)
  {
    cout << "No element to delete" << endl;
    return false;
  }
  if(p>=curLen)
  {
    cout << "Deletion is illegal" << endl;
    return false;
  }
  for(i=p;i<curLen-1;i++)
  {
    arrayList[i]=arrayList[i+1];
  }
  curLen--;
  return true;
}

/*
TODO:1.1-c 返回值顺序表中第一个值为x的结点位置下标
返回值说明：如果在顺序表中从头到尾找到x元素，则立刻返回x元素所在的位置下标。即：假如x在顺序表中第一个位置，则返回0，以此类推
            如果找不到x元素，则返回-1
*/
template <class T>
int ArrayList<T>::GetPos(const T x)
{
  int i;
  for(i=0;i<=curLen-1;i++)
  if(arrayList[i]==x) return i;
  return -1;
}

//输出顺序表内容
template <class T>
void ArrayList<T>::PrintArray()
{
    for (int i = 0; i < curLen; i++) {
        cout << arrayList[i] << " ";
    }
    cout << endl;
}
int main()
{
    int maxsize, pos0, pos1, value0, value1;
    cin >> maxsize >> pos0 >> pos1 >> value0 >> value1;
    ArrayList<int> arr(maxsize);
    int p;
    for (int i = 0; i < 5; i++) {
        arr.Append(i);
    }
    arr.PrintArray();
    arr.Insert(pos0, value0); //位置pos0处插入value0
    arr.PrintArray();
    arr.Delete(pos1); //删除位置pos1处的元素
    arr.PrintArray();
    p = arr.GetPos(value1); //获得值为value1的结点位置
    cout << p << endl;
    return 0;
}
