#include <stdio.h>
#include <string.h>
#define N 50        //叶子结点数
#define M 2*N-1        //树中结点总数

/*
TODO:定义一个结构体,
  第一个成员为char型数组大小为5,存结点值,
  第二个成员为int型变量weight，存权重,
  第三个成员为int型变量parent，存双亲结点,
  第四个成员为int型变量lchild，存左孩子结点,
  第五个成员为int型变量rchild，存右孩子结点
*/
typedef struct
{
    char data[5];
    int weight;
    int parent;
    int lchild;
    int rchild;
} HTNode;

/*
TODO:定义一个结构体,
  第一个成员为char型数组cd大小为N,存放哈夫曼码
  第二个成员为int型变量start，做标记
*/
typedef struct
{
    char cd[N];
    int start;
} HCode;

/*
TODO:完成由ht的叶子结点构造完整的哈夫曼树的功能.
函数功能:利用结点值数组判断比较每个元素对应数据并进行重新赋值生成哈夫曼树.
参数说明:ht-结点数组,n-结点数.
返回值说明:无.
*/
void CreateHT(HTNode ht[],int n)  //由ht的叶子结点构造完整的哈夫曼树
{
    int i,j,s1,s2,min1,min2;
    const int m=2*n-1;
    for(i=0;i<m;i++)
    {
        ht[i].parent=-1;
        ht[i].lchild=-1;
        ht[i].rchild=-1;
    }
    for(i=n;i<m;i++)
    {
        min1=2147483647;
        min2=2147483647;
        s1=-1;
        s2=-1;
        for(j=0;j<=i-1;j++)
        {
            if(ht[j].parent==-1)
            {
                if(ht[j].weight<min1)
                {
                    min2=min1;
                    s2=s1;
                    min1=ht[j].weight;
                    s1=j;
                }
                else if(ht[j].weight<min2)
                {
                    min2=ht[j].weight;
                    s2=j;
                }
            }
        }
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].weight=ht[s1].weight+ht[s2].weight;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
    }
}

/*
TODO:完成根据哈夫曼树构造所有叶子结点的哈夫曼编码的功能.
函数功能:循环遍历霍夫曼树,根据哈夫曼树构造所有叶子结点的哈夫曼编码,
   嵌套循环直到树根结点,处理左右孩子结点,结束内循环start指向哈夫曼编码最开始字符.
参数说明:ht-结点数组,hcd-编码数组,n-结点数.
返回值说明:无.
*/
void CreateHCode(HTNode ht[],HCode hcd[],int n)    //由哈夫曼树ht构造哈夫曼编码hcd
{
    int i,f,c;
    HCode hc;
    for(i=0;i<n;i++)
    {
        hc.start=n;
        c=i;
        f=ht[i].parent;
        while(f!=-1)
        {
            if(ht[f].lchild==c)
                hc.cd[hc.start]='0';
            else hc.cd[hc.start]='1';
            hc.start--;
            c=f;
            f=ht[f].parent;
        }
        hc.start++;
        hcd[i]=hc;
    }
}


void DispHCode(HTNode ht[],HCode hcd[],int n)    //输出哈夫曼编码
{
        int i,k;
        int sum=0,m=0,j;
        printf("输出哈夫曼编码:\n");
        for (i=0;i<n;i++)
        {
                j=0;
                printf("      %s: ",ht[i].data);
                for (k=hcd[i].start;k<=n;k++)
                {
                        printf("%c",hcd[i].cd[k]);
                        j++;
                }
                m+=ht[i].weight;
                sum+=ht[i].weight*j;
                printf("\n");
        }
        printf("平均长度=%g\n",1.0*sum/m);
}

int main()
{
        int n=15,i;
        char sss1[] = "The";
        char sss2[] = "of";
        char sss3[] = "a";
        char sss4[] = "to";
        char sss5[] = "and";
        char sss6[] = "in";
        char sss7[] = "that";
        char sss8[] = "he";
        char sss9[] = "is";
        char sss10[] = "at";
        char sss11[] = "on";
        char sss12[] = "for";
        char sss13[] = "His";
        char sss14[] = "are";
        char sss15[] = "be";
        char *str[]={sss1,sss2,sss3,sss4,sss5,sss6,sss7,sss8,sss9,sss10,sss11,sss12,sss13,sss14,sss15};
        int fnum[]={1192,677,541,518,462,450,242,195,190,181,174,157,138,124,123};
        scanf("%d", &fnum[14]);
        HTNode ht[M];
        HCode hcd[N];
        
        /*
        TODO:for循环i从0开始到n（i自增1）,调用strcpy函数，传参ht[i].data、str[i]，做复制操作,
                fnum[i]赋给ht[i].weight,结束循环
         调用CreateHT函数，传参ht、n，创建哈夫曼树
             调用CreateHCode函数，传参ht、hcd、n，由哈夫曼树ht构造哈夫曼编码hcd
         调用DispHCode函数，传参ht、hcd、n，显示哈夫曼编码和平均长度
        */
    for(i=0;i<n;i++)
    {
        strcpy(ht[i].data, str[i]);
        ht[i].weight=fnum[i];
    }
    CreateHT(ht, n);
    CreateHCode(ht, hcd, n);
    DispHCode(ht, hcd, n);
        return 0;
}

