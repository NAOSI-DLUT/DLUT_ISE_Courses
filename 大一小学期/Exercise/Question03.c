#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10//set 10 competitors
struct Person
{
    int Id;
    double Score_first;
    double Score_final;
    double Sum;
};
struct Person competitor[N];//struct array
void initial_first()
{
    srand(time(0));
    int i;
    for (i=0;i<N;i++)
    {
        competitor[i].Id=i+1;
        competitor[i].Score_first=rand()%20+80;
    }
}
void bubblesort()
{
    int i,j;
    for (i=0;i<N-1;i++)
    {
        for (j=0;j<N-i-1;j++)
        {
            if (competitor[j].Score_first<competitor[j+1].Score_first)
            {
                struct Person temp;
                temp=competitor[j];
                competitor[j]=competitor[j+1];
                competitor[j+1]=temp;
            }
        }
    }
}
void display_byFirst()
{
    int i;
    printf("Output the first score from high to low: \n");
    for (i=0;i<N;i++)
    {
        printf("No.%2d competitor ranks %2d, first score is: %lf", competitor[i].Id, i+1, competitor[i].Score_first);
        printf("\n");
    }
}
void initial_final()
{
    srand(time(0));
    int i;
    for (i=0;i<N;i++)
    {
        competitor[i].Score_final=rand()%30+70;
        competitor[i].Sum=competitor[i].Score_first+competitor[i].Score_final;
    }
}
void selectsort()
{
    int i,j;
    for (i=0;i<N;i++)
    {
        for (j=i+1;j<N;j++)
        {
            if (competitor[j].Sum>competitor[i].Sum)
            {
                struct Person temp;
                temp=competitor[j];
                competitor[j]=competitor[i];
                competitor[i]=temp;
            }
        }
    }
}
void display_bySum()
{
    int i;
    printf("Output the final score from high to low: \n");
    for (i=0;i<N;i++)
    {
        printf("No.%2d competitor ranks %2d, final score is: %lf", competitor[i].Id, i+1, competitor[i].Sum);
        printf("\n");
    }
}
int main()
{
    initial_first();
    bubblesort();
    printf("\n*************************FIRST SCORE*************************\n");
    display_byFirst();
    initial_final();
    selectsort();
    printf("\n*************************FINAL SCORE*************************\n");
    display_bySum();
    system("pause");
    return 0;
}