//实现模拟彩票的程序设计：随机产生6个数字，与用户输入的数字进行比较，输出它们相同的数字个数（使用动态内存分配）
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
int *lottery_array;
int *customer_array;
void Lottery()
{
    srand(time(0));
    lottery_array=(int*)malloc(N*sizeof(int));
    int i;
    for (i=0;i<N;i++)
    {
        lottery_array[i]=rand()%9+0;
    }
}
void Customer()
{
    srand(time(0));
    customer_array=(int*)malloc(N*sizeof(int));
    printf("Input %d numbers: \n",N);
    int i;
    for (i=0;i<N;i++)
    {
        scanf("%d",&customer_array[i]);
    }
}
void Function()
{
    int count=0;
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=0;j<N;j++)
        {
            if (customer_array[j]==lottery_array[i])
            {
                count++;
            }
        }
    }
    printf("The lottery array is: \n");
    for (i=0;i<N;i++)
    {
        printf("%d ",lottery_array[i]);
    }
    printf("\n");
    printf("The amount the same number between the lottery and the customer's input numbers is: %d\n",count);
    return;
}
int main()
{
    Lottery();
    Customer();
    Function();
    free(lottery_array);
    free(customer_array);
    system("pause");
    return 0;
}