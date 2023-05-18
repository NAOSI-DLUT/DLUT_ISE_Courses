/*定义一个动态数组
长度为变量n
用随机数给数组各元素赋值，然后对数组各单元排序
定义swap函数交换数据单元，要求参数使用指针传递*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
int *dynamic_array;
void initial_array()
{
    dynamic_array=(int*)malloc(n*sizeof(int));
    srand(time(0));
    int i;
    for (i=0;i<n;i++)
    {
        dynamic_array[i]=rand()%100+0;
    }
}
void sort()
{
    int i,j;
    for (i=0;i<n-1;i++)
    {
        for (j=0;j<n-1-i;j++)
        {
            if (dynamic_array[j]>dynamic_array[j+1])
            {
                int temp;
                temp=dynamic_array[j];
                dynamic_array[j]=dynamic_array[j+1];
                dynamic_array[j+1]=temp;
            }
        }
    }
}
void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void display()
{
    int i;
    printf("The dynamic array is: ");
    for (i=0;i<n;i++)
    {
        printf("%d ",dynamic_array[i]);
    }
    printf("\n");
}
int main()
{
    initial_array();
    sort();
    display();
    swap(&dynamic_array[0],&dynamic_array[1]);
    printf("Swap the first val and the second val: \n");
    display();
    free(dynamic_array);
    system("pause");
    return 0;
}