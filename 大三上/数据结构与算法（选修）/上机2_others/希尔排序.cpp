/*5.1  插入排序
	
	c.	希尔排序
		void ShellSort(T Data[], int n)
		
*/
#include <iostream>
using namespace std;

/*
TODO:希尔排序,排序后使得Data中元素为升序排列
 */
template <class T>
void ShellSort(T Data[], int n)
{
    for (int step = n / 2; step >= 1; step >>= 1) 
    { //步长
        for (int a = step, b; a < n; ++a) 
        {
            T temp = Data[a]; //存一下
            for (b = a - step; b >= 0; b -= step) 
            { //类似直接插入排序了但是间隔为step
                if (Data[b] > temp) 
                {
                    Data[b + step] = Data[b];
                }
                else break;
            }
            Data[b + step] = temp;
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
