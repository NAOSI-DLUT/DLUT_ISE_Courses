/*课后习题1.8-d

	d.	设ha和hb分别是两个带头结点的非递减有序单链表的表头指针，试设计一个算法，
		将这两个有序链表合并成一个非递减有序的单链表。要求结果链表仍使用原来两个链表的存储空间，
		不另外占用其他的存储空间。表中允许有重复的数据。

		Node* Merge(Node* a, Node* b)

*/
#include <iostream>
using namespace std;
const int MinNumber = -1000000;
struct Node {
    Node(int x)
    {
        value = x;
        next = NULL;
    }
    int value;
    Node* next;
};

/*
TODO:链表连接,将链表a和链表b进行连接合并，连接合并后结果链表仍使用原来两个链表的存储空间，
不另外占用其他的存储空间，且合并后的是一个非递减有序的单链表。
返回值说明：返回合并后的非递减有序单链表
*/
Node* Merge(Node* a, Node* b)
{
    //mergeList first's value is smaller
    Node* mergeList = a->value <= b->value ? a : b;
    Node* tempList = a->value <= b->value ? b : a;
    //headNode决定以 第一个元素值更小的List 为合并基础，并返回headNode，仍然使用原先的存储空间
    Node* headNode = mergeList;
    //preNode = mergeList's preivous Node
    Node* preNode;

    while (mergeList != NULL && tempList != NULL)
    {
        if (mergeList->value < tempList->value)
        {
            preNode = mergeList;
            mergeList = mergeList->next;

            continue;
        }
        else
        {
            //merge
            preNode->next = tempList;
            preNode = preNode->next;
            tempList = tempList->next;
            preNode->next = mergeList;
        }
    }

    //the condition when tempList is NULL: means mergeList's last value is smaller than tempList
    if (mergeList == NULL)
    {
        //append the tempList directly
        preNode->next = tempList;
    }
    
    return headNode;
}

void print(Node* pNode)
{
    while (pNode != NULL) {
        cout << pNode->value << " ";
        pNode = pNode->next;
    }
    cout << endl;
}

Node* init()
{
    int count;
    cin >> count;
    Node *p = NULL, *q;
    for (int i = 0; i < count; i++) {
        int iValue;
        cin >> iValue;
        if (NULL == p) {
            p = new Node(iValue);
            q = p;
        } else {
            q->next = new Node(iValue);
            q = q->next;
        }
    }
    return p;
}

int main()
{
    Node* ha = init();
    Node* hb = init();
    cout << "List 1: ";
    print(ha);
    cout << "List 2: ";
    print(hb);
    Node* head = Merge(ha, hb);
    cout << "merged List: ";
    print(head);
    system("pause");
    return 0;
}
