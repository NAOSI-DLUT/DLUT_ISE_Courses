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
  Node *L1_index=a;
  Node *L1_suc=a->next;
  Node *L2_index=b;
  Node *L2_suc=b->next;
  Node *L2_head=b;
  while(L1_index != NULL)
  {
    if(L1_index->value < L2_index->value) //Insert and update the head
    {
      L1_index->next=L2_index;
      L2_head=L1_index;
      L1_index=L1_suc;
      L1_suc=L1_suc->next;
      L2_index=L2_head;
      L2_suc=L2_index->next;
      continue;
    }
    while(L2_index->next != NULL and (L1_index->value > L2_index->value && L1_index->value > L2_suc->value)) //Search for insertion point
    {
      L2_index=L2_suc;
      L2_suc=L2_suc->next;
    }

    if(L2_index->next != NULL) //insertion
    {
      L2_index->next=L1_index;
      L1_index->next=L2_suc;
      L1_index=L1_suc;
      if(L1_index != NULL) L1_suc=L1_suc->next;
    }else //When the pending list L1 has reached its end
    {
      L2_index->next=L1_index;
      L1_index->next=NULL; //Avoid deadloops
      break;
    }

    L2_index=L2_head; //reset the head
    L2_suc=L2_index->next;
  }
  return L2_head;
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
    cout << "合并前链表1为:";
    print(ha);
    cout << "合并前链表2为:";
    print(hb);
    Node* head = Merge(ha, hb);
    cout << "合并后的单链表为:";
    print(head);
    return 0;
}
