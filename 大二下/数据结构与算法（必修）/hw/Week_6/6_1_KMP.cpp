/*1.7-b,c KMP模式匹配算法

	//1.7-b.	计算字符串特征向量的算法，返回特征向量的数组。
	int* next(string P)

	//1.7-c.	KMP模式匹配算法，返回子串第一次出现的位置，若不存在，返回-1
	int KMPStrMatching(string T, string P, int* N, int startIndex)

*/
#include <assert.h>
#include <iostream>
#include <sstream>
#include <string.h>

using namespace std;

/*
TODO:计算字符串p的特征向量的算法，返回特征向量的数组。
功能描述：定义int型变量m，初始值为P的长度；
		 调用函数assert传参 m>0 判断；
		 定义int型指针变量N，初始化为int型数组，长度为m;
		 调用函数assert传参 N != 0 判断；
		 N[0]赋值0；
		 for循环，循环变量i从1开始到小于m的长度结束，
		   定义int型变量k，初始值为N[i - 1]
		   while循环，循环条件：k不等于0 并且 P[i]不等于P[k]
					  循环体：k = next[k - 1]
		   while循环结束后，
		   如果变量i大于0 并且 P[i]等于P[k] 时，N[i]赋值为k+1，
		   否则，N[i]赋值为0
		for循环结束后，返回N
参数说明：P-要计算特征向量的字符串
返回值说明：指向特征向量的指针
 */
int* next(string P)
{
	//调用函数assert传参 m > 0 判断
	assert(P.length());
	//定义int型指针变量next，初始化为int型数组，长度为m
	int* next = new int[P.length()];
	//调用函数assert传参 next != 0 判断
	assert(next != 0);

	next[0] = 0;
	/*for循环，循环变量i从1开始到小于m的长度结束，
		   定义int型变量k，初始值为N[i - 1]
		   while循环，循环条件：k不等于0 并且 P[i]不等于P[k]
					  循环体：k = next[k - 1]
		   while循环结束后，
		   如果变量i大于0 并且 P[i]等于P[k] 时，N[i]赋值为k+1，
		   否则，N[i]赋值为0
		for循环结束后，返回N
	*/
	for (int i = 1; i < P.length(); i++)
	{
		int k = next[i - 1];
		
		while (k != 0 && P[i] != P[k])
		{
			k = next[k - 1];
		}
		
		if (i > 0 && P[i] == P[k])
		{
			next[i] = k + 1;
		}
		else
		{
			next[i] = 0;
		}
	}

	return next;
}

/*
TODO:KMP模式匹配算法，返回子串第一次出现的位置
功能描述：定义int型变量lastIndex，初始值为T的长度减P的长度；
		如果lastIndex减startIndex 小于 0，返回-1；
		定义int型变量i；定义int型变量j，初始值为0；
		for循环，循环变量i从0开始到小于T的长度结束，
		  while循环，循环条件：P[j]不等于T[i] 并且 j大于0，
			  循环体：j赋值为N[j - 1]
		  while循环结束后，
		  如果P[j]等于T[i]，j累加1；
		  如果j等于P的长度，返回(i - j + 1)；
		for循环结束后，返回-1
参数说明：T-原始字符串，P-子串，N-字符串P的特征向量
返回值说明：查找到则返回子串第一次出现的位置；没有查找到，返回-1
*/
int KMPStrMatching(string T, string P, int* N, int startIndex)
{
	int lastIndex = T.length() - P.length();
	
	if (lastIndex < startIndex)
	{
		return -1;
	}

	int i = 0;
	int j = 0;

	for (; i < T.length(); i++)
	{
		while (j > 0 && T[i] != P[j])
		{
			j = N[j - 1];
		}

		if (P[j] == T[i])
		{
			j++;
		}

		if (j == P.length())
		{
			return (i - j + 1);
		}
	}

	return -1;
}

int main()
{
	string p; //要查找的字符串
	string q; //原始字符串
	getline(cin, p);
	getline(cin, q);
	int* N;
	N = next(p);
	for (int i = 0; i < p.length(); i++)
		cout << N[i] << " ";
	cout << endl;
	cout << KMPStrMatching(q, p, N, 0) << endl;
}
