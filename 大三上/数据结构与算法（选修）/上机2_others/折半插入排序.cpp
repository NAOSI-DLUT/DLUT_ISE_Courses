/*5.1  插入排序

		b.	折半插入排序
			void BinaryInsertionSort(T Data[], int n)
			
*/
#include <iostream>
using namespace std;

/*
TODO:折半插入排序,使得排序后Data中的数据按递增排序
 */
template <class T>
void BinaryInsertionSort(T Data[], int n) //参数：待排序数据和待排序元
    //素个数
{
    for (int a = 1; a < n; ++a) 
    {
        int l = 0, r = a - 1;
        while (l <= r) 
        { //二分寻找插入位置
            int m = (l + r) / 2;
            if (Data[m] < Data[a]) l = m + 1;
            else r = m - 1;
        }
        //最终l一定是正确的且是最靠前的插入位置
        T temp = Data[a]; //保存一下
        //循环移动就可
        for (int b = a - 1; b >= l; --b) 
        {
            Data[b + 1] = Data[b];
        }
        Data[l] = temp;
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

    BinaryInsertionSort<int>(a, n); //a为待排序的数组，10为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}