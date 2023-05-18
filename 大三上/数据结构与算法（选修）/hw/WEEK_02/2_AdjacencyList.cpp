/*3.2  邻接表

        a.	为图设置边，即新增一条边
            void setEdge(int start, int end, int weight)
        b.	返回与顶点v相关联的第一条边
            Edge<T> FirstEdge(int oneVertex)
        c.	返回与边e有相同起点的下一条边
            Edge<T> NextEdge(Edge<T> oneEdge)
        d.	删除一条起始点为start，终止点为end的边
            void delEdge(int start, int end)

*/

#include <iostream>
using namespace std;

template <class T>
class listData //邻接表边结点的数据部分定义
{
public:
    int vertex; //边的终点
    int weight; //边的权
};

template <class T>
class Edge
{
public:
    int start, end, weight;
    Edge()
    {
        start = 0;
        end = 0;
        weight = 0;
    }
    Edge(int st, int en, int wt)
    {
        start = st;
        end = en;
        weight = wt;
    }
    void showEdge()
    {
        cout << "start:" << start << " end:" << end << " weight:" << weight << endl;
    }
};

template <class T> //定义边结点
class ListNode
{
public:
    listData<T> element; //边结点的数据
    ListNode<T> *next;   //边结点指针，指向下一个边结点
    ListNode(listData<T> elemval, ListNode<T> *nextval = NULL)
    {
        element = elemval;
        next = nextval;
    }
    ListNode(ListNode<T> *nextval = NULL) 
    { 
        next = nextval; 
    }
};

template <class T>
class EdgeList //每个顶点所关联的边表
{
public:
    ListNode<T> *head; // head指针
    EdgeList()
    {
        head = new ListNode<T>();
    }
    void removeall() //释放边表所有边结点占据的空间
    {
        ListNode<T> *temp;
        while (head != NULL) //逐步释放每个边结点占据的空间
        {
            temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~EdgeList()
    {
        removeall();
    }
};

template <class T>
class Graph //Abstract class
{
public:
    int vertexNum; //图的顶点数目
    int edgeNum;   //图的边数目
    int *Mark;
    Graph()
    {
        vertexNum = 0;
        edgeNum = 0;
        Mark = NULL;
    }
    Graph(int verticesNum)
    {
        this.vertexNum = verticesNum;
        this.edgeNum = 0;
        Mark = new int[vertexNum];
        for (int i = 0; i < vertexNum; i++)
        {
            Mark[i] = 0;
        }
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
class ListGraph : public Graph<T> //图的邻接表表示
{
private:
    EdgeList<listData<T>> *graList;

public:
    ListGraph(int verticesNum)
    {
        this->vertexNum = verticesNum;
        this->edgeNum = 0;
        this->Mark = new int[verticesNum];
        for (int i = 0; i < verticesNum; i++)
            this->Mark[i] = 0;
        graList = new EdgeList<listData<T>>[this->vertexNum]; //申请空间，有vertexNum个顶点则有vertexNum个边表
    }
    ~ListGraph()
    {
        delete[] graList;
    }
    /*
    TODO:b.	返回与顶点v相关联的第一条边
    返回值说明：如果顶点oneVertex的第一条边存在，则返回那条边。
    否则，返回的边的起点为oneVertex，终点和权重为0
    */
    Edge<T> FirstEdge(int oneVertex)
    {
        if (oneVertex > this->vertexNum)
        {
            return Edge<T>(oneVertex, 0, 0);
        }
        if (graList[oneVertex].head) //first edge exists
        {
            return Edge<T>(oneVertex, graList[oneVertex].head->next->element.vertex, 
                            graList[oneVertex].head->next->element.weight);
        }
        else
        {
            return Edge<T>(oneVertex, 0, 0);
        }
    }
    /*
    TODO:c.	返回与边e有相同起点的下一条边,
    返回值说明：如果找到，则返回对应边的信息，否则，返回的边的起点为oneEdge的起点，终点和权重均为0.
     */
    Edge<T> NextEdge(Edge<T> oneEdge)
    {
        ListNode<listData<T>> *temp = graList[oneEdge.start].head->next;
        while (temp != NULL)
        {
            if (temp->element.vertex == oneEdge.end && temp->next != NULL)
            {
                return Edge<T>(oneEdge.start, temp->next->element.vertex, temp->next->element.weight);
            }
            
            temp = temp->next;
        }
        
        return Edge<T>(oneEdge.start, 0, 0);
    }
    /*
    TODO:a.	为图设置边，即新增一条边
    参数说明：start:为边的起点，
             end:为边的终点,
             weight:为边的权重。
    重要说明：如果输入的数非法，则输出打印cout << "非法输入" << endl;
     */
    void setEdge(int start, int end, int weight)
    {
        if (start > this->vertexNum)
        {
            cout << "非法输入" << endl;
        }
        //create two ListNodes
        listData<listData<T>> newEdge_data;
        newEdge_data.vertex = end;
        newEdge_data.weight = weight;
        ListNode<listData<T>> *newEdge_node = new ListNode<listData<T>>(newEdge_data, NULL);
        //insert into the list of edge
        ListNode<listData<T>> *temp = graList[start].head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEdge_node;
    }
    /*
    TODO:d.	删除一条起始点为start，终止点为end的边
    */
    void delEdge(int start, int end)
    {
        if (start > this->vertexNum)
        {
            return;
        }
        ListNode<listData<T>> *temp = graList[start].head->next;
        ListNode<listData<T>> *previous = graList[start].head;
        
        while (temp != NULL)
        {
            if (temp->element.vertex == end)
            {
                previous->next = temp->next;
                delete temp; 

                break;
            }
            temp = temp->next;
            previous = previous->next;
        }
    }

    void showGraph()
    {
        for (int i = 0; i < this->vertexNum; i++)
        {
            ListNode<listData<T>> *temp = graList[i].head;
            temp = temp->next;
            cout << i << " ";
            while (temp != NULL)
            {
                cout << temp->element.vertex << ":" << temp->element.weight << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main()
{
    Edge<int> tempEdge, tempEdge2;
    int count; //图的顶点数目
    cin >> count;
    int start, end, weight;

    ListGraph<int> lg(count); // 5为图的顶点数目
    for (size_t i = 0; i < count; i++)
    {
        cin >> start >> end >> weight;
        lg.setEdge(start, end, weight);
    }

    //lg.setEdge(1, 0, 2); // 1,0,2  其中1为边的起点，0为边的终点，2为边的权重。
    // lg.setEdge(0, 2, 1);
    // lg.setEdge(0, 3, 3);
    // lg.setEdge(3, 2, 1);
    // lg.setEdge(3, 4, 1);
    lg.showGraph();
    cin >> start;
    tempEdge = lg.FirstEdge(start);
    tempEdge.showEdge();
    tempEdge2 = lg.NextEdge(tempEdge);
    tempEdge2.showEdge();
    cin >> start >> end;
    lg.delEdge(start, end);
    lg.showGraph();
    
    system("pause");
    return 0;
}
