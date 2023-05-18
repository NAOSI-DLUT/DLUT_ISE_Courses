//一条1百万节点的单向链表
//链表所有节点是按value字段从小到大的顺序链接
//试设计程序：针对各个group(0-->9)，根据value字段排序，输出各组top   10的节点。（top10是从小到大，取后面的大值top10.）     
//要求：尽量减少计算复杂度、遍历次数，不允许大量的辅助内存  
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000
typedef struct node_t
{
    int value;
    int group;//from 0~9
    struct node_t *pnext;
}node_t;
node_t *head;//head node of the list
node_t *initial_list()  //initialize the list(no bug)
{
    printf("Start initializing the list...\n");
    srand(time(0));
    node_t *head_temp=0,*temp_temp,*tail_temp=0;
    int i;
    for (i=0;i<N;i++)
    {
        temp_temp=(node_t *)malloc(sizeof(node_t));
        temp_temp->value=i;
        temp_temp->group=rand()%10+0;
        temp_temp->pnext=0;
        if (!head_temp)
        {
            head_temp=tail_temp=temp_temp;
        }
        else
        {
            tail_temp->pnext=temp_temp;
            tail_temp=temp_temp;
        }
    }
    printf("List has been initialized. \n");
    free(temp_temp);
    return head_temp;
}
void traverse(node_t *Head)//(no bug)
{
    int count=0;
    int tab=0;//use tab to change the row while traversing and printing the list
    while (Head)
    {
        printf(" group: %d  ",Head->group);
        printf(" value: %3d ",Head->value);
        Head=Head->pnext;
        count++;
        tab++;
        if (tab==3)
        {
            printf("\n");
            tab=0;
        }
        if (count==N)
        {
            break;
        }
    }
    printf("\n");
}
//sort by the 'group', and order by the 'value'.
//design a new struct for the array which is used to save the node_t->value
typedef struct
{
    int value;
}new_node;
new_node node_array[10][10];
void print_array(int n)
{
    int i,j;
    printf("****************************************************************************\n");
    if (n==0)
    {
        printf("Initial array:\n");
    }
    if (n==1)
    {
        printf("Array after bubblesort: \n");
    }
    for (i=0;i<10;i++)
    {
        for (j=0;j<10;j++)
        {
            printf("%d\t",node_array[i][j].value);
        }
        printf("\n");
    }
    printf("\n");
}
void function(node_t *Head)
{
    int i,j,m;
    node_t *Temp=Head;
    for (i=0;i<10;i++)
    {
        j=0;
        while (Temp)
        {
            if (Temp->group==i)
            {
                node_array[i][j].value=Temp->value;
                j++;
                if (j==10)
                {
                    break;
                }
            }
            Temp=Temp->pnext;
        }
    }
    //traverse
    print_array(0);
    //bubblesort on the node_array
    for (m=0;m<10;m++)
    {
        for (i=0;i<9;i++)
        {
            for (j=0;j<9-i;j++)
            {
                if (node_array[m][j].value>node_array[m][j+1].value)
                {
                    new_node exchange;
                    exchange=node_array[m][j];
                    node_array[m][j]=node_array[m][j+1];
                    node_array[m][j+1]=exchange;
                }
            }
        }
    }
    //traverse
    print_array(1);
    for (i=0;i<10;i++)
    {
        printf("The top10 value of %d group is: \n",i);
        printf("value: %d\n",node_array[i][9].value);
    }
}
int main()
{
    head=initial_list();
    //traverse(head);
    function(head);
    system("pause");
    return 0;
}