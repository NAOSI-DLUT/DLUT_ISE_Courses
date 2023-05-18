/*课后习题1.8-b
	b.	给定一个不带头结点的单链表，写出将链表倒置的算法
		Node* Reverse(Node* first)
*/
#include <iostream>
using namespace std;
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
TODO:链表倒置的算法
 */
Node* Reverse(Node* first)
{
  Node* tail;
  Node* tail_orig=first;
  Node* tail_pre;
  while(tail_orig->next != NULL) tail_orig=tail_orig->next; //Backup the original tail

  while(first->next != NULL) //Check if reversing is completed
  {
    tail=first;
    while(tail->next != NULL) //Get the current tail
    {
      tail_pre=tail;
      tail=tail->next;
    }
    tail->next=tail_pre; //Connect the tail to its preior
    tail_pre->next=NULL; //Set the new tail
  }
  return tail_orig;
}
void print(Node* node)
{
    while (NULL != node) {
        cout << node->value << " ";
        node = node->next;
    }
}
int main()
{
    int iNum;
    cin >> iNum;
    Node* a = NULL;
    Node* pTemp;

    for (int i = 0; i < iNum; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            a = new Node(tmp);
            pTemp = a;
        } else {
            pTemp->next = new Node(tmp);
            pTemp = pTemp->next;
        }
    }

    cout << "倒置前为：";
    print(a);
    cout << endl;
    Node* r = Reverse(a);
    cout << "倒置后为：";
    print(r);
    cout << endl;
    return 0;
}
