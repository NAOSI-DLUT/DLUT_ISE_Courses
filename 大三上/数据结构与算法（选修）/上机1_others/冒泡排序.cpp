#include <iostream>
using namespace std;

/*
TODO:冒泡排序,排序后Data中元素为升序排列
 */
template <class T>
void BubbleSort(T Data[], int n)
{
    bool flag;
    for (int i = 0; i < n; ++i) {
        flag = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (Data[j + 1] < Data[j]) flag = true, swap(Data[j], Data[j + 1]); //大的下沉
        }
        if (!flag) break;
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
    BubbleSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
