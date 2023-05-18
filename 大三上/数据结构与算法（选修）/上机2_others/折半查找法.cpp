/*4.1  折半查找算法*/

#include <iostream>
using namespace std;

/*
TODO:折半查找算法,折半查找过程，Array[0,⋯,n-1]为待查找的有序数据记录，key为查找的记录
查找成功，返回该元素所在位置,查找不成功，返回-1

 */
template <class T>
int BiSearch(T Array[], T key, int n)
{ //折半查找过程，Array[0,⋯,n-1]为待查找的有序数据记录，key为查找的记录
    int left =0;//第一个，最左端
    int right = n-1;//最后一个，最右端
    int mid;中间位
    while(left <= right)
    {
        mid = (left + right)/2;
        if(key < Array[mid])//若关键值小于中间位
        {
            right = mid - 1;
        }
        else if(key > Array[mid])//若关键值大于中间位
        {
            left = mid + 1;
        }
        else//相等
            return mid;
    }
    return -1;//left>right,查找失败
}

int main()
{
    int n, num;
    cin >> n;
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    } //输入应为有序的顺序表
    cin >> num;
    int index = BiSearch<int>(A, num, n);
    if (index == -1) {
        cout << "查找不成功" << endl;
    } else {
        cout << num << " 的位置为： " << index;
    }
    return 0;
}