//Dijkstra算法
#include <iostream>
using namespace std;

//图的两种存储结构
#define INF 32767               //定义∞
#define MAXV 100                //最大顶点个数
typedef char InfoType;
/*
TODO:定义一个邻接矩阵结构体,其中一个成员为int类型变量no存编号,
另一个为InfoType类型变量info存信息
*/
typedef struct
{
    int no;
    InfoType info;
} VertexType;                   //顶点类型
/*
TODO:定义一个完整的图邻接矩阵类型结构体,
其中一个成员为大小为MAXV*MAXV的二维int数组edges存邻接矩阵,
两个int型变量n,e存定点数边数,一个大小为MAXV的VertexType数组vexs存信息
*/
typedef struct
{
    int edges[MAXV][MAXV];
    int n, e;
    int VertexType[MAXV];
} MatGraph;                     //完整的图邻接矩阵类型

//------------------------------------------------------------
//----邻接矩阵的基本运算算法----------------------------------
//------------------------------------------------------------
void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e) //创建图的邻接矩阵
{
    int i, j;
    g.n = n; g.e = e;
    for (i = 0; i < g.n; i++)
        for (j = 0; j < g.n; j++)
            g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g)    //输出邻接矩阵g
{
    int i, j;
    for (i = 0; i < g.n; i++)
    {
        for (j = 0; j < g.n; j++)
            if (g.edges[i][j] != INF)
                cout << g.edges[i][j] << ' ';
            else
                cout << "∞ ";
        cout << endl;
    }
}
//dist表示路径长度
//path[i]为路径上i的前驱顶点编号
//S[i]=1表示顶点i在S中, S[i]=0表示顶点i在U中 相当于书上的Mark
void Dispath(MatGraph g, int dist[], int path[], int S[], int v)
//输出从顶点v出发的所有最短路径
{
    int i, j, k;
    int apath[MAXV], d;                
    for (i = 0; i < g.n; i++)                  
        if (S[i] == 1 && i != v)
        {
            cout << "从顶点" << v << "到顶点"<<i<<"的路径长度为: "<< dist[i] << " 路径为:";
            d = 0;
            apath[d] = i;          
            k = path[i];
            if (k == -1)                    
                cout << "无路径" << endl;
            else                        
            {
                while (k != v)
                {
                    d++; apath[d] = k;
                    k = path[k];
                }
                d++; apath[d] = v;      
                cout << apath[d];
                for (j = d - 1; j >= 0; j--)   
                    cout << "," << apath[j];
                cout << endl;
            }
        }
}
/*
TODO:完成用Dijkstra算法计算路径的功能.
函数功能:先初始化一些路径值,嵌套循环找出所有顶点最短路径,调用Dispath函数传参初始顶点输出最短路径.
参数说明:g-图的邻接矩阵,v-初始顶点.
返回值说明:无.
*/
void Dijkstra(MatGraph g, int v)    //Dijkstra算法，时间复杂度O(n^2)
{
    int dist[MAXV], path[MAXV], S[MAXV]; 
    for (int i = 0; i < g.n; ++i) dist[i] = INF, path[i] = -1; 
    dist[v] = 0; S[v] = 1;
    for (int cnt = 0; cnt < g.n; ++cnt) { 
        int minp = -1;
        for (int i = 0; i < g.n; ++i) { 
            if (S[i] && (minp == -1 || dist[i] < dist[minp])) minp = i;
        }
        S[minp] = 0;
        for (int i = 0; i < g.n; ++i) { 
            if (dist[minp] + g.edges[minp][i] < dist[i]) { 
                dist[i] = dist[minp] + g.edges[minp][i]; 
                path[i] = minp; 
                S[i] = 1; 
            }
        }
    }
    for (int i = 0; i < g.n; ++i) S[i] = 1; //不知道这个S有啥用
    Dispath(g, dist, path, S, v);
}

int main()
{
    MatGraph g;
    int A[MAXV][MAXV] = {
            {0,4,6,6,INF,INF,INF},
            {INF,0,1,INF,7,INF,INF},
            {INF,INF,0,INF,6,4,INF},
            {INF,INF,2,0,INF,5,INF},
            {INF,INF,INF,INF,0,INF,6},
            {INF,INF,INF,INF,1,0,8},
            {INF,INF,INF,INF,INF,INF,0} };
    int n = 7, e = 12;
    cin >> n;
    CreateMat(g, A, n, e);
    cout << "图G的邻接矩阵:" << endl;
    DispMat(g);                 //输出邻接矩阵
    int v = 0;
    cout << "从" << v << "顶点出发的最短路径如下:" << endl;
    Dijkstra(g, v);
    return 0;
}
