#include <iostream>
using namespace std;

/*
TODO:用来保持以结点i为根的最大堆的性质，n是所有元素的个数,找到i结点的两个孩子的媳?
和左子结点进行比较;和右子结点进行比较;判断是否需要进行调整;递归对子结点进行调整
 */
template <class T>
void SiftDown(T Data[], int i, int n)
{
    T temp = Data[i]; //存一下
    int p = i, son = 2 * i + 1; //p是当前节点，son是p的左儿子
    while (son < n) { //有左儿子的话
        if (son + 1 < n && Data[son + 1] > Data[son]) ++son; //右儿子更大就选右儿子
        if (temp < Data[son]) Data[p] = Data[son]; //如果根结点更小就下沉，也就是儿子节点赋值给父节点
        else break; //否则退出循环
        p = son; //p往下走
        son = 2 * p + 1; //取左儿子
    }
    Data[p] = temp; //temp赋值给最终位置
}
/*
TODO:建立一个最大堆，求出非叶子结点的最大媳?循环调用SiftDown函数，保持最大堆的性质
 */
template <class T>
void BuildHeap(T Data[], int n)
{
    //最后一个非终端结点倒着下沉
    for (int i = (n + 1) / 2 - 1; i >= 0; --i)
        SiftDown(Data, i, n);
}

/*
TODO: 进行堆排序，首先建立一个最大堆，进行循环，次取出最大元素后不断调整最大堆
 排序完成后，使得Data中元素按升序排列
 */
template <class T>
void HeapSort(T Data[], int n)
{
    BuildHeap(Data, n); //建堆
    for (int i = n - 1; i > 0; --i) {
        swap(Data[0], Data[i]); //最大的跟最后一个位置交换
        SiftDown(Data, 0, i); //堆的大小减一，根节点下沉
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
    HeapSort<int>(a, n); //a为待排序的数组，n为数组的大小
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
