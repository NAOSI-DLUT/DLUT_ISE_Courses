#include <stdio.h>
#include <string.h>
#define N 50		//叶子结点数
#define M 2*N-1		//树中结点总数
#include <iostream>
using namespace std;

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
	//第一个成员为char型数组大小为5,存结点值
	char data[5];
	//第二个成员为int型变量weight，存权重
	int weight = -1;
	//第三个成员为int型变量parent，存双亲结点
	int parent = -1;
	//第四个成员为int型变量lchild，存左孩子结点
	int lchild = -1;
	//第五个成员为int型变量rchild，存右孩子结点
	int rchild = -1;
}HTNode;

/*
TODO:定义一个结构体,
  第一个成员为char型数组cd大小为N,存放哈夫曼码
  第二个成员为int型变量start，做标记
*/
typedef struct 
{
	//第一个成员为char型数组cd大小为N,存放哈夫曼码
	char cd[N];
	//第二个成员为int型变量start，做标记
	int start = -1;
}HCode;


/*
TODO:完成由ht的叶子结点构造完整的哈夫曼树的功能.
函数功能:利用结点值数组判断比较每个元素对应数据并进行重新赋值生成哈夫曼树.
参数说明:ht-结点数组,n-结点数.
返回值说明:无.
*/
void CreateHT(HTNode ht[], int n)//构造哈夫曼树
{
	int i, k, lnode, rnode;
	int min1, min2;//设置权重最小的两个节点
	for (i = 0; i < 2 * n - 1; i++)//所有节点的相关域设置初始值为-1
	{
		ht[i].parent = ht[i].lchild = ht[i].rchild = -1;
	}
	for (i = n; i < 2 * n - 1; i++)//构造哈夫曼树
	{                      //n前面的空间给输入的值，树的其他节点给算出来的权重和
		min1 = min2 = 32767;//min1为第一个最小的权重，min2为第二个最小的权重
		lnode = rnode = -1;//lnode和rnode为最小权重的两个节点位置
		for (k = 0; k <= i - 1; k++)
			if (ht[k].parent == -1)//只在尚未构造二叉树的节点中查找
			{
				if (ht[k].weight < min1)//找权重最小的两个节点
				{
					min2 = min1; rnode = lnode;//把min1的下标值给了min2,原左孩子的下标lnode给右孩子的下标rnode
					min1 = ht[k].weight; lnode = k;//把权重最小的下标赋给lnode
				}
				else if (ht[k].weight < min2)
				{
					min2 = ht[k].weight;
					rnode = k;//把权重第二最小的下标赋给rnode
				}
			}
		ht[lnode].parent = i; ht[rnode].parent = i;//将当前权重最小的两个的双亲节点设为下标为i的节点
		ht[i].weight = ht[lnode].weight + ht[rnode].weight;//下标为i的节点的权重为两个子女的权重和
		ht[i].lchild = lnode; ht[i].rchild = rnode;//设置下标为i的节点的孩子为下标为lnode和rnode
	}
}

/*
TODO:完成根据哈夫曼树构造所有叶子结点的哈夫曼编码的功能.
函数功能:循环遍历霍夫曼树,根据哈夫曼树构造所有叶子结点的哈夫曼编码,
   嵌套循环直到树根结点,处理左右孩子结点,结束内循环start指向哈夫曼编码最开始字符.
参数说明:ht-结点数组,hcd-编码数组,n-叶子结点数.
返回值说明:无.
*/
void CreateHCode(HTNode ht[], HCode hcd[], int n)	//由哈夫曼树ht构造哈夫曼编码hcd
{
	for (int i = 0; i < n; i++)
	{
		int currentNode = i;
		int currentParent = ht[currentNode].parent;
		for (int k = n; currentParent != -1; k--)
		{
			if (ht[currentParent].lchild == currentNode)
			{
				hcd[i].cd[k] = '0';
			}
			else
			{
				hcd[i].cd[k] = '1';
			}

			hcd[i].start = k;
			currentNode = currentParent;
			currentParent = ht[currentNode].parent;
		}
	}
}


void DispHCode(HTNode ht[], HCode hcd[], int n)	//输出哈夫曼编码
{
	int i, k;
	int sum = 0, m = 0, j;
	printf("输出哈夫曼编码:\n");
	for (i = 0; i < n; i++)
	{
		j = 0;
		printf("      %s: ", ht[i].data);
		for (k = hcd[i].start; k <= n; k++)
		{
			printf("%c", hcd[i].cd[k]);
			j++;
		}
		m += ht[i].weight;
		sum += ht[i].weight * j;
		printf("\n");
	}
	printf("平均长度=%g\n", 1.0 * sum / m);
}

void print(HTNode ht[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "data: " << ht[i].data << endl;
		cout << "weight: " << ht[i].weight << endl;
		cout << "parent: " << ht[i].parent << endl;
		cout << "lchild: " << ht[i].lchild << endl;
		cout << "rchild: " << ht[i].rchild << endl;
	}
}

int main()
{
	//n是叶子结点数
	int n = 15;
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
	char* str[] = { sss1,sss2,sss3,sss4,sss5,sss6,sss7,sss8,sss9,sss10,sss11,sss12,sss13,sss14,sss15 };
	int fnum[] = { 1192,677,541,518,462,450,242,195,190,181,174,157,138,124,123 };
	scanf_s("%d", &fnum[14]);
	HTNode *ht = new HTNode[M];
	HCode *hcd = new HCode[N];

	/*
	TODO:for循环i从0开始到n（i自增1）,调用strcpy函数，传参ht[i].data、str[i]，做复制操作,
			fnum[i]赋给ht[i].weight,结束循环
	 调用CreateHT函数，传参ht、n，创建哈夫曼树
		 调用CreateHCode函数，传参ht、hcd、n，由哈夫曼树ht构造哈夫曼编码hcd
	 调用DispHCode函数，传参ht、hcd、n，显示哈夫曼编码和平均长度
	*/
	for (int i = 0; i < n; i++)
	{
		strcpy_s(ht[i].data, str[i]);
		ht[i].weight = fnum[i];
	}

	CreateHT(ht, n);
	CreateHCode(ht, hcd, n);
	DispHCode(ht, hcd, n);
	//print(ht, n);

	return 0;
}

