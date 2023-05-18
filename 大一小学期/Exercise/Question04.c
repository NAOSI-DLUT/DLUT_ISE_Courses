/*有5个字符串，
首先将它们按照字符串中的字符个数由小到大排列，
再分别取出每个字符串的第三个字母合并成一个新的字符串输出（若少于三个字符的输出空格）。
要求：利用字符串指针和指针数组实现。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
char *str1=(char *)"China";
char *str2=(char *)"America";
char *str3=(char *)"Japan";
char *str4=(char *)"Russia";
char *str5=(char *)"England";
void function()
{
    char *str_array[N]={str1, str2, str3, str4, str5};
    int i,j;
    for (i=0;i<N-1;i++)
    {
        for (j=0;j<N-1-i;j++)
        {
            if (strlen(str_array[j])>strlen(str_array[j+1]))
            {
                char *temp;
                temp=str_array[j];
                str_array[j]=str_array[j+1];
                str_array[j+1]=temp;
            }
        }
    }
    printf("Output the strings by their's length from short to long: \n");
    for (i=0;i<N;i++)
    {
        printf("%s\n",str_array[i]);
    }
    char new_array[N+1];
    for (i=0;i<N;i++)
    {
        char *temp=str_array[i];
        char temp_char=temp[2];
        new_array[i]=temp_char;
    }
    new_array[N]='\0';
    printf("Pick up the third letter from the sorted strings...\n");
    printf("The new string is: \n%s\n",new_array);
}
int main()
{
    function();
    system("pause");
    return 0;
}