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
    Node* tempList = first;
    Node* tempNode(0);
    Node* headNode = tempList;

    //insert current node at the first position while traverse
    while (tempList->next != NULL)
    {
        tempNode = tempList->next;
        
        if (tempNode->next != NULL)
        {
            tempList->next = tempNode->next;
            tempNode->next = headNode;
            headNode = tempNode;

            //tempList = tempList->next;
        }
        else
        {
            tempList->next = NULL;
            tempNode->next = headNode;
            headNode = tempNode;
        }
    }

    return headNode;
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
    Node* pTemp(0);

    for (int i = 0; i < iNum; i++) {
        int tmp;
        cin >> tmp;
        if (i == 0) {
            a = new Node(tmp);
            pTemp = a;
        }
        else {
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
