/*4.1  折半查找算法*/

#include <iostream>
using namespace std;

/*
TODO:折半查找算法,折半查找过程，Array[0,…,n-1]为待查找的有序数据记录，key为查找的记录
查找成功，返回该元素所在位置,查找不成功，返回-1

 */
template <class T>
int BiSearch(T Array[], T key, int n)
{ 
    int l = 0, r = n - 1; 
    while (l <= r) {
        int mid = (l + r) / 2; 
        if (key < Array[mid]) r = mid - 1; 
        else if (key > Array[mid]) l = mid + 1; 
        else return mid;
    }
    return -1; 
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
