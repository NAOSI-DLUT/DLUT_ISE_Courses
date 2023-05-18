/*5.2  交换排序

		a.	冒泡排序
			void BubbleSort(T Data[], int n)
*/
#include <iostream>
using namespace std;

/*
TODO:冒泡排序,排序后Data中元素为升序排列
 */
template <class T>
void BubbleSort(T Data[], int n)
{
    bool flag;
    for (int a = 0; a < n; ++a) 
    {
        flag = false;
        for (int b = 0; b < n - a - 1; ++b) //每一次循环，大的放在最后
        {
            if (Data[b + 1] < Data[b]) 
                {
                    flag = true, swap(Data[b], Data[b + 1]); //大的下沉
                }
        }
        if (!flag) 
        {
            break;
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
    BubbleSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
