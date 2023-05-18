#include <iostream>
using namespace std;

/*
TODO:希尔排序,排序后使得Data中元素为升序排列
 */
template <class T>
void ShellSort(T Data[], int n)
{
    for (int step = n / 2; step >= 1; step >>= 1) { //步长
        for (int i = step, j; i < n; ++i) {
            T temp = Data[i]; //存一下
            for (j = i - step; j >= 0; j -= step) { //类似直接插入排序了但是间隔为step
                if (Data[j] > temp) Data[j + step] = Data[j];
                else break;
            }
            Data[j + step] = temp;
        }
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

    ShellSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
