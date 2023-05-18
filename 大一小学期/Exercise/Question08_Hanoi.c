//递归做汉诺塔
#include <stdio.h>
#include <stdlib.h>
/*
moving main function:
x,y,z poles. n disks.
1.Move n-1 disks from x to the y pole;
2.Move 1 disk to the z pole;
3.Move n-1 disks from y to z pole.
*/
void moveDisk(int n, char x, char y, char z)
{
    if(n==1)
    {
        printf("The %d disk: from %c to %c\n",n,x,z);
    }
    else
    {
        moveDisk(n-1,x,z,y);
        printf("The %d disk: from %c to %c\n",n,x,z);
        moveDisk(n-1,y,x,z);
    }

}
int totalStep(int n)
{
    if (n==1)
    {
        return 1;
    }
    else
    {
        return 2*totalStep(n-1)+1;
    }
}
int main()
{
    char pole1 = 'x';
    char pole2 = 'y';
    char pole3 = 'z';
    int n;
    int step_amount;
    printf("Input the number of the disk: ");
    scanf("%d",&n);
    step_amount=totalStep(n);
    printf("You should go %d steps to get disks from x to z pole.\n",step_amount);
    printf("The each step is as follows: \n");
    moveDisk(n,pole1,pole2,pole3);
    system("pause");
    return 0;
}
