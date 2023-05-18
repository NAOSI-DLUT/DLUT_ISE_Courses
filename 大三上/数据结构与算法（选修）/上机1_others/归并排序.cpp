#include <iostream>
using namespace std;

template <class T>
/*
TODO:函数Merge，参数Data是待归并数组，其中对Data[start,mid]和Data[mid+1, end]
  之间的数据进行归并
*/
void Merge(T Data[], int start, int mid, int end)
{
    T *temp = new T[end - start + 1]; //临时数组
    int i = start, j = mid + 1, p = 0; //分别指向前半段，后半段，临时数组
    while (i <= mid && j <= end) {
        if (Data[i] < Data[j]) temp[p++] = Data[i++];
        else temp[p++] = Data[j++];
    }
    while (i <= mid) temp[p++] = Data[i++];
    while (j <= end) temp[p++] = Data[j++];
    for (i = start, p = 0; i <= end; ++i, ++p) Data[i] = temp[p]; //移回Data
}

/*
TODO:对Data[start]-Data[end]之间的序列进行归并排序,排序后使得Data中元素升序排列
 */
template <class T>
void MergeSort(T Data[], int start, int end)
{ //对Data[start]-Data[end]之间的序列进行归并排序
    if (start < end) { //长度大于1
        int mid = (start + end) / 2;
        MergeSort(Data, start, mid); //前一半归并排序
        MergeSort(Data, mid + 1, end); //后一半归并排序
        Merge(Data, start, mid, end); //前后合并
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
    MergeSort<int>(a, 0, n - 1); //a为待排序的数组，0为数组的第一个位置，n-1为数组的最后一个位置
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
