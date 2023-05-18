#include <iostream>
using namespace std;

/*
TODO:采用直接插入排序法，将Data数组进行不减序排序
 */
template <class T>
void InsertionSort(T Data[], int n)
{ //
    for (int i = 1, j; i < n; ++i) { //1~n-1依次往前插入同时移动
        T temp = Data[i];
        for (j = i - 1; j >= 0; --j) {
            if (Data[j] > temp) Data[j + 1] = Data[j]; //往后移
            else break;
        }
        Data[j + 1] = temp;
    }
}

int main()
{
    int n, num;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> num;
        a[i] = num;
    }
    InsertionSort<int>(a, n); //a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
