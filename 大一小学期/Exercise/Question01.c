#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 128
typedef struct 
{
    int cmd_no;//该命令的命令号，唯一识别一个命令
    int version;//产生该命令的程序的版本
    int detail_len;//变产内容的实际长度
    char *content;//指向变产内容的指针
}command_head_t;
command_head_t sender;//send command
command_head_t recipient[64];//64 recipient to receive command
char command_content[]="Command sended.";
void function()
{
    srand(time(0));
    int i;
    for (i=0;i<N;i++)
    {
        sender.cmd_no=rand()%128+1;
        sender.version=i;
        sender.detail_len=strlen(command_content);
        sender.content=command_content;
        recipient[rand()%63+0]=sender;
    }
}
void print_info()
{
    int i;
    printf("Recipient: \n");
    for (i=0;i<64;i++)
    {
        printf("cmd_no: %d\n", recipient[i].cmd_no);
        printf("version: %d\n", recipient[i].version);
        printf("detail_len: %d\n", recipient[i].detail_len);
        if (recipient[i].content)
        {
            printf("content: %s\n", recipient[i].content);
        }
        else
        {
            printf("content: No content. \n");
        }
    }
    printf("\n");
}
int main()
{
    function();
    print_info();
    system("pause");
    return 0;
}