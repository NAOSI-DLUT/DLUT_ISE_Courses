#include <iostream>
#include <math.h>

using namespace std;

// 结点类模板
template <class ElemType>
struct Node
{
    // 数据成员:
    ElemType data;				// 数据域
    Node<ElemType>* next;		// 指针域

// 构造函数模板:
    Node();						// 无参数的构造函数模板
    Node(ElemType item, Node<ElemType>* link = NULL);	// 已知数据元素值和指针建立结构
};

// 结点类模板的实现部分
template<class ElemType>
Node<ElemType>::Node()
// 操作结果：构造指针域为空的结点
{
    next = NULL;
}

template<class ElemType>
Node<ElemType>::Node(ElemType item, Node<ElemType>* link)
// 操作结果：构造一个数据域为item和指针域为link的结点
{
    data = item;
    next = link;
}

// 线性链表类模板
template <class ElemType>
class LinkList
{
protected:
    //  链表实现的数据成员:
    Node<ElemType>* head;				// 头结点指针
    mutable int curPosition;			// 当前位置的序号
    mutable Node<ElemType>* curPtr;	// 指向当前位置的指针
    int count;							// 元素个数

// 辅助函数模板:
    Node<ElemType>* GetElemPtr(int position) const;	// 返回指向第position个结点的指针

public:
    //  抽象数据类型方法声明及重载编译系统默认方法声明:
    LinkList();							// 无参数的构造函数模板
    virtual ~LinkList();				// 析构函数模板
    int Length() const;				    // 求线性表长度
    bool Empty() const;					// 判断线性表是否为空
    void Clear();						// 将线性表清空
    void Traverse(void (*visit)(const ElemType&)) const;	// 遍历线性表
    int GetCurPosition() const;								// 返回当前位置
    bool GetElem(int position, ElemType& e) const;			// 求指定位置的元素
    bool SetElem(int position, const ElemType& e);			// 设置指定位置的元素值
    bool Delete(int position, ElemType& e);					// 删除元素
    bool Insert(int position, const ElemType& e);			// 插入元素
    LinkList(const LinkList<ElemType>& copy);				// 复制构造函数模板
    LinkList<ElemType>& operator =(const LinkList<ElemType>& copy); // 重载赋值运算符
};


// 链表类模板的实现部分

template<class ElemType>
Node<ElemType>* LinkList<ElemType>::GetElemPtr(int position) const
// 操作结果：返回指向第position个结点的指针
{
    if (curPosition > position)
    {	// 当前位置在所查找位置之后,只能从表头开始操作
        curPosition = 0;
        curPtr = head;
    }

    for (; curPosition < position; curPosition++)
        curPtr = curPtr->next;			// 查找位置position

    return curPtr;
}

template <class ElemType>
LinkList<ElemType>::LinkList()
// 操作结果：构造一个空链表
{
    head = new Node<ElemType>;		// 构造头指针
    curPtr = head;	curPosition = 0;// 初始化当前位置
    count = 0;						// 初始化元素个数
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
// 操作结果：销毁线性表
{
    Clear();			// 清空线性表
    delete head;		// 释放头结点所指空间
}

template <class ElemType>
int LinkList<ElemType>::Length() const
// 操作结果：返回线性表元素个数
{
    return count;
}

template <class ElemType>
bool LinkList<ElemType>::Empty() const
// 操作结果：如线性表为空，则返回true，否则返回false
{
    return head->next == NULL;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
// 操作结果：清空线性表
{

    ElemType tmpElem;	// 临时元素值
    while (!Empty())
    {	// 表性表非空，则删除第1个元素
        Delete(1, tmpElem);
    }
}

template <class ElemType>
void LinkList<ElemType>::Traverse(void (*visit)(const ElemType&)) const
// 操作结果：依次对线性表的每个元素调用函数(*visit)
{
    for (Node<ElemType>* tmpPtr = head->next; tmpPtr != NULL; tmpPtr = tmpPtr->next)
    {	// 用tmpPtr依次指向每个元素
        (*visit)(tmpPtr->data);	// 对线性表的每个元素调用函数(*visit)
    }
}

template <class ElemType>
int LinkList<ElemType>::GetCurPosition() const
// 操作结果：返回当前位置
{
    return curPosition;
}

template <class ElemType>
bool LinkList<ElemType>::GetElem(int position, ElemType& e) const
// 操作结果：当线性表存在第position个元素时，用e返回其值，返回true,
//	否则返回false
{
    if (position < 1 || position > Length())
    {	// position范围错
        return false;					// 元素不存在
    }
    else
    {	// position合法
        Node<ElemType>* tmpPtr;
        tmpPtr = GetElemPtr(position);	// 取出指向第position个结点的指针
        e = tmpPtr->data;				// 用e返回第position个元素的值
        return true;
    }
}

template <class ElemType>
bool LinkList<ElemType>::SetElem(int position, const ElemType& e)
// 操作结果：将线性表的第position个位置的元素赋值为e,
//	position的取值范围为1≤position≤Length(),
//	position合法时返回true,否则返回false
{
    if (position < 1 || position > Length())
    {	// position范围错
        return false;
    }
    else
    {	// position合法
        Node<ElemType>* tmpPtr;
        tmpPtr = GetElemPtr(position);	// 取出指向第position个结点的指针
        tmpPtr->data = e;				// 设置第position个元素的值
        return true;
    }
}

template <class ElemType>
bool LinkList<ElemType>::Delete(int position, ElemType& e)
// 操作结果：删除线性表的第position个位置的元素, 并用e返回其值, position的取值
//	范围为1≤position≤Length(),position合法时返回true,否则返回false
{
    if (position < 1 || position > Length())
    {	// position范围错
        return false;
    }
    else
    {	// position合法
        Node<ElemType>* tmpPtr;
        tmpPtr = GetElemPtr(position - 1);		// 取出指向第position-1个结点的指针
        Node<ElemType>* nextPtr = tmpPtr->next;	// nextPtr为tmpPtr的后继
        tmpPtr->next = nextPtr->next;			// 删除结点
        e = nextPtr->data;						// 用e返回被删结点元素值
        if (position == Length())
        {	// 删除尾结点,当前结点变为头结点
            curPosition = 0;					// 设置当前位置的序号
            curPtr = head;						// 设置指向当前位置的指针
        }
        else
        {	// 删除非尾结点,当前结点变为第position个结点
            curPosition = position;				// 设置当前位置的序号
            curPtr = tmpPtr->next;				// 设置指向当前位置的指针
        }
        count--;								// 删除成功后元素个数减1
        delete nextPtr;							// 释放被删结点
        return true;
    }
}

template <class ElemType>
bool LinkList<ElemType>::Insert(int position, const ElemType& e)
// 操作结果：在线性表的第position个位置前插入元素e, position的取值范围
//	为1≤position≤Length()+1,position合法时返回true, 否则返回false
{
    if (position < 1 || position > Length() + 1)
    {	// position范围错
        return false;						// 位置不合法
    }
    else
    {	// position合法
        Node<ElemType>* tmpPtr;
        tmpPtr = GetElemPtr(position - 1);	// 取出指向第position-1个结点的指针
        Node<ElemType>* newPtr;
        newPtr = new Node<ElemType>(e, tmpPtr->next);// 生成新结点
        tmpPtr->next = newPtr;				// 将tmpPtr插入到链表中
        curPosition = position;				// 设置当前位置的序号
        curPtr = newPtr;					// 设置指向当前位置的指针
        count++;							// 插入成功后元素个数加1
        return true;
    }
}

template <class ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType>& copy)
// 操作结果：由线性表copy构造新线性表——复制构造函数模板
{
    ElemType e;

    head = new Node<ElemType>;		// 构造头指针
    curPtr = head;	curPosition = 0;// 初始化当前位置
    count = 0;						// 初始化元素个数

    for (int pos = 1; pos <= copy.Length(); pos++)
    {	// 复制数据元素
        copy.GetElem(pos, e);			// 取出第pos个元素
        Insert(Length() + 1, e);		// 将e插入到当前线性表
    }
}

template <class ElemType>
LinkList<ElemType>& LinkList<ElemType>::operator =(const LinkList<ElemType>& copy)
// 操作结果：将线性表copy赋值给当前线性表——重载赋值运算符
{
    if (&copy != this)
    {
        ElemType e;
        Clear();							// 清空当前线性表

        for (int pos = 1; pos <= copy.Length(); pos++)
        {	// 复制数据元素
            copy.GetElem(pos, e);			// 取出第pos个元素
            Insert(Length() + 1, e);		// 将e插入到当前线性表
        }
    }
    return *this;
}

/*
TODO:完成分配线性表数组分配的功能.
函数功能:利用库函数pow求值做初始值进行循环,计算插入位置值，调用函数对线性表插入.
参数说明:lem-元素数组,n-元素个数,r-基数,d-关键字位数,i-循环基数,list-线性表数组
返回值说明:无
*/
template <class ElemType>
void Distribute(ElemType elem[], int n, int r, int d, int i, LinkList<ElemType> list[])
// 初始条件: r为基数,d为关键字位数,list[0 .. r - 1]为被分配的线性表数组
// 操作结果: 进行第i趟分配
{
    ElemType temp;
    for (int j = 0; j < n; j++)
    {
        temp = elem[j];
        for (int k = 1; k < i; k++)
        {
            temp = elem[j] / r;
        }
        temp = temp % r;
        list[temp].Insert(list[temp].GetCurPosition() + 1, elem[j]);
    }
}

/*
TODO:完成分配线性表数组收集的功能.
函数功能:循环遍历进行分配,当线性表不空时调用函数进行删除,重新赋值元素.
参数说明:lem-元素数组,n-元素个数,r-基数,d-关键字位数,i-循环基数,list-线性表数组
返回值说明:无
*/
template <class ElemType>
void Colect(ElemType elem[], int n, int r, int d, int i, LinkList<ElemType> list[])
// 初始条件: r为基数,d为关键字位数,list[0 .. r - 1]为被分配的线性表数组
// 操作结果: 进行第i趟收集
{
    int j = 0;
    int ith = 0;
    for (ith = 0; ith < n; NULL)
    {
        if (!list[j].Empty())
        {
            while (!list[j].Empty())
            {
                list[j].Delete(1, elem[ith]);
                ith++;
            }
        }
        else if(j < r)
        {
            j++;
        }
    }
}

/*
TODO:完成对elem进行基数排序的功能.
函数功能:定义用于存储被分配的线性表数组并分配相应空间,
循环遍历调用函数进行分配和收集,最后释放线性表空间.
参数说明:lem-元素数组,n-元素个数,r-基数,d-关键字位数
返回值说明:无
*/
template <class ElemType>
void RadixSort(ElemType elem[], int n, int r, int d)
// 初始条件: r为基数,d为关键字位数
// 操作结果: 对elem进行基数排序
{
    LinkList<ElemType>* list = new LinkList<ElemType>[r];
    for (int i = 1; i <= d; i++)
    {
        Distribute(elem, n, r, d, i, list);
        Colect(elem, n, r, d, i, list);
    }
}

template<class ElemType>
void Show(ElemType elem[], int n)
// 操作结果: 显示数组elem的各数据元素值
{
    for (int i = 0; i < n; i++)
        cout << elem[i] << "  ";	// 显示数组elem
    cout << endl;					// 换行
}

int main(void)
{
    int a[6];

    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    int n = 6, r = 10, d = 2;
    cout << "排序前:";
    // TODO: 调用函数显示数组元素值,然后进行基数排序排序
    Show(a, 6);
    RadixSort(a, n, r, d);
    cout << "排序后:";
    // TODO: 调用函数显示数组元素值
    Show(a, 6);
    return 0;						// 返回值0, 返回操作系统
}