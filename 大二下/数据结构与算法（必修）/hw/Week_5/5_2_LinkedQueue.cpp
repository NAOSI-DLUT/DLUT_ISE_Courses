#include <iostream>
using namespace std; // 标准库包含在命名空间std中

// 结点类模板
/*
TODO:定义一个模板结构体,包含:一个模板类型变量data存数据,
一个该结构体指针类型变量next作为后继结点指针,一个无参构造函数,
一个带数据和指针形参的构造函数
*/
template <class ElemType>
struct Node
{
        ElemType data;
        Node<ElemType> *next;
        //no parameter constructor
        Node();
        //constructor with parameter
        Node(ElemType, Node<ElemType> *);

};

// 结点类模板的实现部分

/*
TODO:定义无参构造函数
函数功能:初始化结构体成员,next置为空
参数说明:无
返回值说明:无
*/
template <class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
    this->next = NULL;
}

/*
TODO:定义带参构造函数
函数功能:使用形参初始化结构体成员.
参数说明:item-数据,link-后继指针
返回值说明:无
*/
template <class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType> *link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
    this->data = item;
    this->next = link;
}

// 链队列类模板

template <class ElemType>
class LinkQueue
{
    /*
TODO:定义protected类型成员:两个模板类Node指针变量front, rear存队首队尾,
int型变量count存元素个数
*/
protected:
    //queue front
    Node<ElemType> *front;
    //queue rear
    Node<ElemType> *rear;
    //number of elements
    int count;

public:
    //  抽象数据类型方法声明及重载编译系统默认方法声明:
    LinkQueue();                     // 无参数的构造函数模板
    virtual ~LinkQueue();            // 析构函数模板
    bool Empty() const;              // 判断队列是否为空
    void Clear();                    // 将队列清空
    bool OutQueue(ElemType &e);      // 出队操作
    bool InQueue(const ElemType &e); // 入队操作
};

// 链队列类模板的实现部分

/*
TODO:构造一个空队列
函数功能:初始化类成员，生成头结点，空队列元素个数为0
参数说明:无
返回值说明:无
*/
template <class ElemType>
LinkQueue<ElemType>::LinkQueue()
// 操作结果：构造一个空队列
{
    front = new Node<ElemType>;
    rear = new Node<ElemType>;
     
    front->next = NULL;
    rear->next = NULL;
    //rear point to the same as front
    rear = front;

    count = 0;
}

/*
TODO:完成定义析构函数的功能
函数功能:调用函数释放存储空间.
参数说明:无
返回值说明:无
*/
template <class ElemType>
LinkQueue<ElemType>::~LinkQueue()
// 操作结果：销毁队列
{

}

/*
TODO:判断队列是否为空
函数功能:判断队列是否为空;如果队列中元素个数为0,则返回true;否则返回false.
参数说明:无
返回值说明:如果队列为空则返回true,否则返回false
*/
template <class ElemType>
bool LinkQueue<ElemType>::Empty() const
// 操作结果：如队列为空，则返回true，否则返回false
{
    //count != 0
    if (count != 0)
    {
        return true;
    }
    //count == 0
    return false;
}

/*
TODO:清空队列
函数功能:当队列不空时循环调用函数出队列.
参数说明:无
返回值说明:无
*/
template <class ElemType>
void LinkQueue<ElemType>::Clear()
// 操作结果：清空队列
{
    //to store the deleted element
    ElemType topElem;
    while (count != 0)
    {
        OutQueue(topElem);
    }
}

/*
TODO:完成获取出队列的第一元素功能
函数功能:如果队列空直接返回失败,否则利用临时变量取出队头元素,释放出队的结点,
个数减少1.
参数说明:e-存放出队列的第一个元素的变量
返回值说明:如队列非空,用e返回出队列第一个的元素,返回true,否则返回false
*/
template <class ElemType>
bool LinkQueue<ElemType>::OutQueue(ElemType &e)
// 操作结果：如果队列非空，那么删除队头元素，并用e返回其值，返回true,
//	否则返回false，
{
    //is empty
    if (count == 0)
    {
        return false;
    }
    //is not empty
    e = front->data;
    front = front->next;
    count --;
    
    return true;
}

/*
TODO:完成将一个元素值插进队列的功能
函数功能:生成新结点,新结点追加在队尾,rear指向新队尾,元素个数自加1.
参数说明:e-存放进队列的元素的变量
返回值说明:返回truee
*/
template <class ElemType>
bool LinkQueue<ElemType>::InQueue(const ElemType &e)
// 操作结果：插入元素e为新的队尾，返回true
{
    //create a new node
    Node<ElemType> *newNode = new Node<ElemType>(e, NULL);
    //when the queue is empty
    if (count == 0)
    {
        //let front point to this new node
        front = newNode;
        rear = front;
        count ++;
        
        return true;
    }
    //when the queue is not empty
    rear->next = newNode;
    rear = rear->next;
    count ++;
    
    return true;
}

template <class ElemType>
void Show(const ElemType &e)
// 操作结果: 显示数据元素
{
    cout << e << "  "; // 输出e
}

int main(void)
{
    LinkQueue<double> sa;
    double x;
    for (int i = 0; i < 6; i++)
    {
        cin >> x;
        /*
        TODO:sa调用InQueue传参x进队列
        */
       sa.InQueue(x);
    }
    cout << "out queue:";
    while (sa.OutQueue(x))
    {
        cout << x << " ";
    }

    system("pause");
    return 0;
}