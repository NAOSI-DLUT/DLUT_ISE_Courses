#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template <class T>
class Edge {
public:
    int start, end, weight;
    Edge() // 两种类的初始化方式
    {
        start = 0;
        end = 0;
        weight = 0;
    }
    Edge(int st, int en, int w)
    {
        start = st;
        end = en;
        weight = w;
    }
    void showEdge() //打印
    {
        cout << "start: " << start << " end：" << end << " weight：" << weight << endl;
    }
};

template <class T>
class Graph {
public:
    int vertexNum; //图的顶点数目
    int edgeNum; //图的边数目
    int* Mark;
    Graph()//
    {
        vertexNum = 0;
        edgeNum = 0;
        Mark = NULL;
    }
    Graph(int verticesNum) //顶点的数量
    {
        vertexNum = verticesNum;
        edgeNum = 0;
        Mark = new int[vertexNum]; //定义一个顶点数量的数组
        for (int i = 0; i < vertexNum; i++) // 然后初始化为0
            Mark[i] = 0;
    }
    ~Graph()
    {
        delete[] Mark;
    }
    virtual Edge<T> FirstEdge(int oneVertex) = 0;
    virtual Edge<T> NextEdge(Edge<T> oneEdge) = 0;
    int VerticesNum() { return vertexNum; }
    int EdgesNum() { return edgeNum; }
    int StartVertex(Edge<T> oneEdge) { return oneEdge.start; }
    int EndVertex(Edge<T> oneEdge) { return oneEdge.end; }
    int Weight(Edge<T> oneEdge) { return oneEdge.weight; }
    virtual void setEdge(int start, int end, int weight) = 0;
    virtual void delEdge(int start, int end) = 0;
};

template <class T>
class AdjGraph : public Graph<T> {
private:
    int** matrix;

public:
    AdjGraph(int verticesNum)
    {
        int i, j;
        this->vertexNum = verticesNum;
        this->edgeNum = 0;
        this->Mark = new int[verticesNum];
        for (int i = 0; i < verticesNum; i++)//对Mark的初始化
            this->Mark[i] = 0;
        matrix = (int**)new int* [this->vertexNum];
        for (i = 0; i < this->vertexNum; i++)
            matrix[i] = new int[this->vertexNum];
        for (i = 0; i < this->vertexNum; i++)
            for (j = 0; j < this->vertexNum; j++)
                matrix[i][j] = 0;
    }
    ~AdjGraph()
    {
        for (int i = 0; i < this->vertexNum; i++)
            delete[] matrix[i];
        delete[] matrix;
    }

    bool isEdge(Edge<T> oneEdge)
    {
        if (oneEdge.weight > 0 && oneEdge.end >= 0)
            return true;
        else
            return false;
    }

    Edge<T> FirstEdge(int oneVertex)
    {
        Edge<T> tempEdge;
        tempEdge.start = oneVertex;
        for (int i = 0; i < this->vertexNum; i++) {
            if (matrix[oneVertex][i] != 0) {
                tempEdge.end = i;
                tempEdge.weight = matrix[oneVertex][i];
                break;
            }
        }
        return tempEdge;
    }

    Edge<T> NextEdge(Edge<T> oneEdge)
    {
        Edge<T> tempEdge;
        tempEdge.start = oneEdge.start;
        for (int i = oneEdge.end + 1; i < this->vertexNum; i++) {
            if (matrix[oneEdge.start][i] != 0) {
                tempEdge.end = i;
                tempEdge.weight = matrix[oneEdge.start][i];
                break;
            }
        }
        return tempEdge;
    }

    void setEdge(int start, int end, int weight)
    {
        if (start < this->vertexNum && end < this->vertexNum && weight >= 0 && start != end) {
            if (matrix[start][end] == 0) {
                this->edgeNum++;
            }
            matrix[start][end] = weight;
        }
        else
            cout << "非法输入" << endl;
    }
    void delEdge(int start, int end)
    {
        if (start < this->vertexNum && end < this->vertexNum) {
            if (matrix[start][end] != 0)
                this->edgeNum--;
            matrix[start][end] = 0;
        }
        else
            cout << "非法输入" << endl;
    }

    void DFS1(int v)
    {
        this->Mark[v] = 1; //标记该顶点已访问
        cout << v + 1 << " "; //访问该顶点：顶点0设为1
        for (Edge<T> e = FirstEdge(v); isEdge(e); e = NextEdge(e)) { //由该点所关联的边进行深度优先搜索
            if (this->Mark[e.end] == 0) //访问V邻接到的未被访问过的顶点，并递归地进行深度优先搜索
                DFS1(e.end);
        }
    }
    	/*
	TODO:a  深度优先搜索（DFS）：递归,对所有顶点的标志位初始化,检查图是否有未访问的顶点，
	如果有则从该顶点开始深度优先搜索,对未访问的顶点调用DFS1
	*/
    void DFSTraverse()//递归
    {
        for (int i = 0; i < this->vertexNum; i++)//对所有顶点的标志位初始化
        {
            this->Mark[i] = 0;
        }
        for (int i = 0; i < this->vertexNum; i++)//检查图是否有未访问的顶点，如果有则从该顶点开始深度优先搜索
        {
            if (this->Mark[i] == 0)
                DFS1(i);//对未访问的顶点调用DFS1函数
        }
    }
    	/*
	TODO:a  深度优先搜索（DFS）：非递归.对所有顶点的标志位初始化
	检查图是否有未访问的顶点，如果有则从该顶点开始深度优先搜索。
	当遇到未访问的顶点时，需要输出打印cout << u + 1 << " "; 。比如当this->Mark[i] == 0;且要
	处理它时，则通过打印语句cout << i + 1 << " ";将其位置打印出来。 具体可参考测试用例。
	*/
    void DFSNoReverse()//非递归，用栈的方式
    {
        int i, v;
        stack<int> s;
        for (i = 0; i < this->vertexNum; i++) 
        {
            this->Mark[i] = 0; //对所有顶点的标志位初始化
        }
        for (i = 0; i < this->vertexNum; i++) //检查图是否有未访问的顶点，如果有则从该顶点开始深度优先搜索。
        {
            if (this->Mark[i] == 0) 
            {   //如果这个点没有被访问，入栈继续
                s.push(i);
                this->Mark[i] = 1;
                cout << i + 1 << " ";//当遇到未访问的顶点时，需要输出打印cout << u + 1 << " "; 
                while (!s.empty())  //循环条件：栈不为空
                {
                    v = s.top();  //取栈顶元素
                    Edge<T> e;
                    for (e = FirstEdge(v); isEdge(e); e = NextEdge(e)) 
                    { //遍历以v为起点的边
                        if (this->Mark[e.end] == 0) 
                        {   //有没被访问的邻接结点
                            s.push(e.end); //入栈
                            this->Mark[e.end] = 1;
                            cout << e.end + 1 << " ";
                            break;
                        }
                    }
                     s.pop(); 
                }
            }
        }
    }
    	/*
	TODO:BFS1算法，访问顶点V，并将其标志位置为已访问，访问该顶点： 打印cout << v + 1 << " ";
	访问其它未被访问的顶点时，也打印cout << u + 1 << " ";其中，u是被访问的顶点
 	*/
        void BFS1(int v) //从顶点开始的BFS，用队列实现广度优先遍历
        {
            queue<int> q;//创建一个队列q
            this->Mark[v] = 1; //标识为已访问
            cout << v + 1 << " ";//访问顶点V，并将其标志位置为已访问，访问该顶点： 打印cout << v + 1 << " ";
            q.push(v);
            while (!q.empty()) {//队列不为空时
                v = q.front();//取队首字母给v
                q.pop();//将其取出并删除值
                for (Edge<T> e = FirstEdge(v); isEdge(e); e = NextEdge(e))  //与e关联的所有边
                {
                    int u = e.end; //关联的结点
                    if (this->Mark[e.end] == 0) //关联的节点没有被访问过
                    {
                        this->Mark[e.end] = 1; //访问
                        cout << u + 1 << " ";//访问其它未被访问的顶点时，也打印cout << u + 1 << " ";其中，u是被访问的顶点
                        q.push(u); //入队
                    }
                }
            }
        }
        /*
	TODO:b.	广度优先搜索（BFS）,对所有顶点的标志位初始化.
	检查图中是否有未访问的顶点，如果有则从该顶点开始调用BFS1进行广度优先搜索
	*/
        void BFSTraverse()//图的BFS算法，
        {
            for (int i = 0; i < this->vertexNum; i++)//对所有顶点的标志位初始化
            {
                this->Mark[i] = 0;
            }
            for (int i = 0; i < this->vertexNum; i++)//检查图中是否有未访问的顶点，如果有则从该顶点开始调用BFS1进行广度优先搜索
            {
                if (this->Mark[i] == 0)
                    BFS1(i);
            }
        }
        void showGraph()
        {
            cout << "图有" << this->edgeNum << "条边" << endl;
            cout << "图的信息为:" << endl;
            for (int i = 0; i < this->vertexNum; i++) {
                for (int j = 0; j < this->vertexNum; j++)
                    cout << matrix[i][j] << " "; //直接应用邻接矩阵
                cout << endl;
            }
        }
    };

    int main()
    {
        Edge<int> tempEdge;
        int count, start, end, weight;
        cin >> count;
        AdjGraph<int> adp(5); //count为图的顶点数目
        for (size_t i = 0; i < count; i++) {
            cin >> start >> end >> weight;
            adp.setEdge(start, end, weight);
        }
		adp.setEdge(2, 1, 2);
		adp.setEdge(1, 3, 1);
		adp.setEdge(1, 4, 3);
		adp.setEdge(3, 1, 1);
		adp.setEdge(2, 3, 1);
        adp.showGraph();
        cout << "DFSTraverse: ";
        adp.DFSTraverse();
        cout << endl;
        cout << "DFSNoReverse: ";
        adp.DFSNoReverse();
        cout << endl;
        cout << "BFSTraverse: ";
        adp.BFSTraverse();
        cout << endl;
        return 0;
    }