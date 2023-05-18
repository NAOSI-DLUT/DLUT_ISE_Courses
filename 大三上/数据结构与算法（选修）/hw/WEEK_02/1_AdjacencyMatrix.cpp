#include <iostream>
using namespace std;

template <class T>
class Edge {
public:
    int start, end, weight;
    Edge()
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
    void showEdge()
    {
        cout << "start: " << start << " end:" << end << " weight:" << weight << endl;
    }
};

template <class T>
class Graph {
public:
    int vertexNum; //图的顶点数目
    int edgeNum; //图的边数目
    int* Mark;
    Graph()
    {
        vertexNum = 0;
        edgeNum = 0;
        Mark = NULL;
    }
    Graph(int verticesNum)
    {
        vertexNum = verticesNum;
        edgeNum = 0;
        Mark = new int[vertexNum];
        for (int i = 0; i < vertexNum; i++)
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
    int** matrix; //指向邻接矩阵的指针
public:
    AdjGraph(int verticesNum)
    {
        int i, j;
        this->vertexNum = verticesNum;
        this->edgeNum = 0;
        this->Mark = new int[verticesNum];
        for (int i = 0; i < verticesNum; i++)
            this->Mark[i] = 0;
        matrix = (int**)new int*[this->vertexNum]; //申请vertexNum大小的matrix数组
        for (i = 0; i < this->vertexNum; i++) //申请matrix数组行的存储空间
            matrix[i] = new int[this->vertexNum];
        for (i = 0; i < this->vertexNum; i++) //初始化邻接矩阵的元素
            for (j = 0; j < this->vertexNum; j++)
                matrix[i][j] = 0;
    }
    ~AdjGraph()
    {
        for (int i = 0; i < this->vertexNum; i++) //释放每个matrix[i]申请的空间
            delete[] matrix[i];
        delete[] matrix; //释放matrix指针指向的空间
    }

    bool isEdge(Edge<T> oneEdge)
    {
        if (oneEdge.weight > 0 && oneEdge.end >= 0)
            return true;
        else
            return false;
    }
    /*
    TODO:b. 返回与顶点oneVertex相关联的第一条边
    返回值说明：若找到，则返回找到的边信息，否则，返回的边中信息，起点为oneVertex，终点和权重均为0。
    */
    Edge<T> FirstEdge(int oneVertex)
    {
        for (int j = 0; j < this->vertexNum; j++) 
            if (matrix[oneVertex][j] != 0) 
                return Edge<T>(oneVertex, j, matrix[oneVertex][j]);
        return Edge<T>(oneVertex, 0, 0); 
    }

    /*
    TODO:c. 
    返回值说明：若找到，则返回找到的边信息，否则，返回的边中信息，起点为oneEdge的起点，终点和权重均为0。
    */
    Edge<T> NextEdge(Edge<T> oneEdge)
    {
        for (int j = oneEdge.end + 1; j < this->vertexNum; j++) 
            if (matrix[oneEdge.start][j] != 0) 
                return Edge<T>(oneEdge.start, j, matrix[oneEdge.start][j]);
        return Edge<T>(oneEdge.start, 0, 0); 
    }
    /*
    TODO:a. 
    参数说明：start:为边的起点，
             end:为边的终点,
             weight:为边的权重。
    重要说明：如果输入的数非法，则输出打印cout << "非法输入" << endl;
     */
    void setEdge(int start, int end, int weight)
    {
       
        if (start < 0 || start >= this->vertexNum || end < 0 || end >= this->vertexNum || weight < 0)
            cout << "非法输入" << endl;
        else {
            
            if (matrix[start][end] == 0 && weight != 0) ++this->edgeNum;
            matrix[start][end] = weight;
        }
    }
    /*
    TODO：d.删除一条起始点为start，终止点为end的边
    重要说明：如果输入的数字非法，输出打印cout << "非法输入" << endl;
    */
    void delEdge(int start, int end)
    {
        
        if (start < 0 || start >= this->vertexNum || end < 0 || end >= this->vertexNum)
            cout << "非法输入" << endl;
       
        else if (matrix[start][end] != 0) --this->edgeNum, matrix[start][end] = 0;
    }

    void showGraph()
    {
        cout << "共有" << this->edgeNum << "条边" << endl;
        cout << "图的信息为:" << endl;
        for (int i = 0; i < this->vertexNum; i++) {
            for (int j = 0; j < this->vertexNum; j++)
                cout << matrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main()
{
    Edge<int> tempEdge;
    int num; //图的顶点数目
    int start, end, weight;
    cin >> num;
    AdjGraph<int> adp(num); //num为图的顶点数目
    // adp.setEdge(1, 0, 2); //1,0,2  其中1为边的起点，0为边的终点，2为边的权重。
    for (size_t i = 0; i < num; i++) {

        cin >> start >> end >> weight;
        adp.setEdge(start, end, weight);
    }
    // adp.setEdge(0, 2, 1);
    // adp.setEdge(0, 3, 3);
    // adp.setEdge(3, 2, 1);
    // adp.setEdge(3, 4, 1);
    adp.showGraph();
    int oneVertex; // 一边的开始位置
    cin >> oneVertex;
    tempEdge = adp.FirstEdge(oneVertex);
    tempEdge.showEdge();
    tempEdge = adp.NextEdge(tempEdge);
    tempEdge.showEdge();
    cin >> start >> end;
    adp.delEdge(start, end);
    adp.showGraph();
    return 0;
}
