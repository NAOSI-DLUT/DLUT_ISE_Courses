#include <iostream>
using namespace std;

/*
TODO:实现对data[left]到data[right]的分割操作，并返回划分后轴元素对应的位置,返回轴元素的形恢茫迪址种?
*/
template <class T>
int Partition1(T Data[], int left, int right)
{
    swap(Data[left], Data[rand() % (right - left + 1) + left]); //随机选轴元素
    T temp = Data[left]; //存一下
    int i = left, j = right;
    while (i < j) {
        while (i < j && Data[j] >= temp) --j;
        Data[i] = Data[j]; //找到小的交换
        while (i < j && Data[i] <= temp) ++i;
        Data[j] = Data[i]; //找到大的交换
    }
    Data[i] = temp; //放进去
    return i;
}

/*
TODO:用分治法实现快速排序算法,排序后Data中元素按升序排列
 */
template <class T>
void QuickSort(T Data[], int left, int right)
{
    if (left < right) { //大于1
        int mid = Partition1(Data, left, right); //获取位置
        QuickSort(Data, left, mid - 1); //左右快排
        QuickSort(Data, mid + 1, right);
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
    QuickSort<int>(a, 0, n - 1); //a为待排序的数组，0为数组的第一个位置，n-1为数组的最后一个位置
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
