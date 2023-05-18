#include <iostream>
#include <string.h>

using namespace std;

/*
 * TODO：求模式T的next值
 * 功能描述：使用蛮力法求模式T的next值
 * 参数说明：T[]: 模式T
 *          next[]: 任意两个数组
 * 返回值说明：空
*/
void GetNext(char T[], int next[])
{
    int len=strlen(T);
    next[0]=0;
    int i,k;
    for(i=1;i<len;i++)
    {
        k=next[i-1];
        while(k>0 && T[i]!=T[k])
        {
            k=next[k-1];
        }
        if(T[i]==T[k])
        {
            next[i]=k+1;
        }else next[i]=0;
    }
}

/*
 * TODO：串匹配KMP算法
 * 功能描述：输入主串S，以及模式T，返回T在S中的位置, 使用串匹配KMP算法求解该问题。
            调用GetNext方法求解时假定模式最长为80个字符。
 * 参数说明：S[]: 主串S
 *           T[]: 模式T
 * 返回值说明：返回匹配的开始位置（下标+1）
 * 举例说明：查找模式T：abcacc在主串S：abcabcabcaccb中的位置是：7
*/
int KMP(char S[],char T[])
{
    int lastindex=strlen(S)-strlen(T);
    int i,j=0;
    int *next=new int[strlen(S)+1];
    GetNext(T,next);
    for(i=0;i<strlen(S);i++)
    {
        while(T[j]!=S[i] && j>0)
        {
            j=next[j-1];
        }
        if(T[j]==S[i])
        {
            j++;
        }
        if(j==strlen(T))
        {
   //         delete(next);
            return i-j+2;
        }
    }
   // delete(next);
    return 0;
}

int main()
{

    const int size = 20;
    char S[size];
    char T[size];
    //串匹配BF算法
    //输入： 主串S, 模式T
    cout<<"请输入主串S:"<<endl;
    cin>>S;
    cin.get();
    cout<<"请输入查找模式T:"<<endl;
    cin>>T;
    cin.get();
    //串匹配KMP算法
    //输入： 主串S, 模式T
    int index = KMP(S,T);
    //输出： T在S中的位置
    for (int i = 1; i < index; i++)
        cout<<" ";
    cout<<T<<"在"<<endl;
    cout<<S<<"中的位置是："<<index<<endl;
    return 0;
}
