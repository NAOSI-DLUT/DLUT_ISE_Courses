/*加密程序:由键盘输入明文，通过加密程序转换成密文并输出到屏幕上。 
算法：明文中的字母转换成其后的第4个字母,例如，A变成E(a变成e)，Z变成D,非字母字符不变；
同时将密文每两个字符之间插入一个空格。例如，China转换成密文为G l m r e。
要求：在函数change中完成字母转换，在函数insert中完成增加空格，用指针传递参数。
*/
#include <stdio.h>
#include <stdlib.h>
#define N 100
void change(char *plaintext)
{
    int i;
    for (i=0;plaintext[i]!='\0';i++)
    {
        if (plaintext[i]>='a' && plaintext[i]<='v')
        {
            plaintext[i]+=4;
        }
        else if (plaintext[i]>'A' && plaintext[i]<'V')
        {
            plaintext[i]+=4;
        }
        else if (plaintext[i]>='w' && plaintext[i]<='z')
        {
            plaintext[i]-=22;
        }
        else if (plaintext[i]>='W' && plaintext[i]<='Z')
        {
            plaintext[i]-=22;
        }
        else
        {
            continue;
        }
    }
}
void insert(char *plaintext, char *ciphertext)
{
    int i,j;
    for (i=0,j=0;plaintext[i]!='\0';i++)
    {
        ciphertext[j]=plaintext[i];
        ciphertext[j+1]=' ';
        j+=2;
    }
    ciphertext[j]='\0';
    printf("The ciphertext is: ");
    puts(ciphertext);
}
int main()
{
    char plaintext[N];
    char ciphertext[2*N];
    printf("Input the plaintext: ");
    gets(plaintext);
    change(plaintext);
    insert(plaintext,ciphertext);
    system("pause");
    return 0;
}