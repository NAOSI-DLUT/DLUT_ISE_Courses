#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

template<class T>

class BinaryTree;

template<class T>

class BinaryTreeNode
{
private:
    T  element;                                 //结点的数据域
    BinaryTreeNode<T>* leftChild;            //结点的左孩子结点
    BinaryTreeNode<T>* rightChild;           //结点的右孩子结点
public:
    friend class BinaryTree<T>;              //声明二叉树类为结点类的友元类，以便访问私有数据成员
    BinaryTreeNode()                          //默认构造函数
    {
        element = 0;
        leftChild = NULL;
        rightChild = NULL;
    }
    BinaryTreeNode(const T& ele)             //给定数据的构造函数
    {
        element = ele;
        leftChild = NULL;
        rightChild = NULL;
    }
    BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r) //给定数据值和左右孩子结点的构造函数
    {
        element = ele;
        leftChild = l;
        rightChild = r;
    }
    BinaryTreeNode<T>* getLeftChild() const  //返回该结点的左孩子结点
    {
        return leftChild;
    }
    BinaryTreeNode<T>* getrightChild() const //返回该结点的右孩子结点
    {
        return rightChild;
    }
    void setleftChild(BinaryTreeNode<T>* l)  //设置该结点的左孩子结点
    {
        leftChild = l;
    }
    void setrightChild(BinaryTreeNode<T>* r) //设置该结点的右孩子结点
    {
        rightChild = r;
    }
    T getValue(T& val)                 //返回该结点的数据值
    {
        val = element;
        return val;
    }
    void setValue(const T& val)              //设置该结点的数据域的值
    {
        element = val;
    }
    bool isLeaf() const                      //判断该结点是否是叶子结点，若是，则返回true
    {
        if (rightChild == NULL && leftChild == NULL)
            return true;
        else
            return false;
    }
    void showEle()
    {
        cout << element << ' ';
    }
};

template <class T>

class BinaryTree
{
public:
    BinaryTreeNode<T>* root;                     //二叉树根结点
    BinaryTree()                                //默认构造函数
    {
        root = NULL;
    }
    ~BinaryTree()                              //析构函数
    {
        deleteBinaryTree(root);
    }
    bool isEmpty() const                        //判定二叉树是否为空树
    {
        if (root == NULL)
            return true;
        else
            return false;
    }
    BinaryTreeNode<T>* Root()                   //返回二叉树的根结点
    {
        return root;
    }

    BinaryTreeNode<T>* buildPreAndIn(string prestr, string instr);              //2.1-a 实现由先序、中序序列构造二叉树的算法
    BinaryTreeNode<T>* buildPostAndIn(string poststr, string instr);          //2.1-b 实现由后序、中序序列构造二叉树的算法
    void levelOrder(BinaryTreeNode<T>* root);                                 //2.1-c 广度优先遍历以root为根结点的子树
    void inOrder(BinaryTreeNode<T>* root);                                    //2.1-d 中序遍历以root为根结点的子树
    void InOrderWithoutRecusion(BinaryTreeNode<T>* root);                     //2.1-e 非递归中序遍历二叉树或其子树
    void deleteBinaryTree(BinaryTreeNode<T>* root);                           //删除以root为根结点的子树

    void visit(BinaryTreeNode<T>* p)                                          //创建一个树实例
    {
        p->showEle();
    }
    BinaryTreeNode<T>* setTree()
    {
        T ch;
        cin >> ch;
        BinaryTreeNode<T>* treeroot = NULL;
        if (ch == 0 || ch == '0')
            return NULL;
        else
        {
            treeroot = new BinaryTreeNode<T>;
            treeroot->element = ch;
            treeroot->leftChild = setTree();
            treeroot->rightChild = setTree();
            return treeroot;
        }
    }
};

/*
TODO：2.1-a 实现由先序、中序序列构造二叉树的算法
      return 树的根结点root
 */
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::buildPreAndIn(string prestr, string instr)
{
    if(prestr.length()==0) return NULL;
    char rootNode=prestr[0];
    int index=instr.find(rootNode);
    string l_instr=instr.substr(0,index);
    string r_instr=instr.substr(index+1);
    int l_len=l_instr.length();
    int r_len=r_instr.length();
    string l_prestr=prestr.substr(1,l_len);
    string r_prestr=prestr.substr(l_len+1);
    BinaryTreeNode<T> *tmp=new BinaryTreeNode<T>;
    if(tmp !=NULL)
    {
        tmp->setValue(rootNode);
        tmp->setleftChild(buildPreAndIn(l_prestr, l_instr));
        tmp->setrightChild(buildPreAndIn(r_prestr, r_instr));
    }
    return tmp;
}

/*
TODO：2.1-b 实现由后序、中序序列构造二叉树的算法
      return 树的根结点root
 */
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::buildPostAndIn(string poststr, string instr)
{
    if(poststr.length()==0) return NULL;
    char rootNode=poststr[poststr.length()-1];
    int index=instr.find(rootNode);
    string l_instr=instr.substr(0,index);
    string r_instr=instr.substr(index+1);
    int l_len=l_instr.length();
    int r_len=r_instr.length();
    string l_poststr=poststr.substr(0,l_len);
    string r_poststr=poststr.substr(l_len,poststr.length()-1-l_len);
    BinaryTreeNode<T> *tmp=new BinaryTreeNode<T>;
    if(tmp !=NULL)
    {
        tmp->setValue(rootNode);
        tmp->setleftChild(buildPostAndIn(l_poststr, l_instr));
        tmp->setrightChild(buildPostAndIn(r_poststr, r_instr));
    }
    return tmp;
}

/*
TODO：2.1-c 广度优先遍历以root为根结点的子树
 */
template<class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* root)
{
    queue<BinaryTreeNode<T>*> nodes;
    BinaryTreeNode<T> *pointer=root;
    if(pointer!=NULL)
        nodes.push(pointer);
    while (!nodes.empty()) {
        pointer=nodes.front();
        pointer->showEle();
        nodes.pop();
        if(pointer->getLeftChild()!=NULL) nodes.push(pointer->getLeftChild());
        if(pointer->getrightChild()!=NULL) nodes.push(pointer->getrightChild());
    }
}

/*
TODO：2.1-d 递归中序遍历以root为根结点的子树
 */
template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root)
{
    if(root!=NULL)
    {
        inOrder(root->getLeftChild());
        root->showEle();
        inOrder(root->getrightChild());
    }
}

/*
TODO：2.1-e 非递归中序遍历二叉树或其子树
 */
template<class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>* root)
{
    stack<BinaryTreeNode<T> *> nodes;
    BinaryTreeNode<T> *pointer=root;
    while(!nodes.empty() || pointer!=NULL)
    {
        if(pointer!=NULL)
        {
            nodes.push(pointer);
            pointer=pointer->getLeftChild();
        }
        else
        {
            pointer=nodes.top();
            pointer->showEle();
            pointer=pointer->getrightChild();
            nodes.pop();
        }
    }
}

template<class T>

void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T>* root)
{
    if (root == NULL)
        return;
    BinaryTreeNode<T>* temp = NULL;
    queue<BinaryTreeNode<T>*> node_queue;
    if (root->leftChild)
        node_queue.push(root->leftChild);
    if (root->rightChild)
        node_queue.push(root->rightChild);
    delete root;
    while (!node_queue.empty())
    {
        temp = node_queue.front();
        node_queue.pop();
        if (temp->leftChild != NULL)
            node_queue.push(temp->leftChild);
        if (temp->rightChild != NULL)
            node_queue.push(temp->rightChild);
        delete temp;
    }
    root = NULL;
}

int main()
{
    BinaryTree<char> test;
    BinaryTreeNode<char>* root = NULL, * root2 = NULL;
    string prestr, instr, poststr;
    getline(cin, prestr);
    getline(cin, instr);
    getline(cin, poststr);
    root = test.buildPreAndIn(prestr, instr);    //2.1-a 实现由先序、中序序列构造二叉树的算法
    root2 = test.buildPostAndIn(poststr, instr);//2.1-b 实现由后序、中序序列构造二叉树的算法

    cout << "PreAndIn:" << endl;
    cout << "inOrder: ";
    test.inOrder(root);
    cout << endl;

    cout << "levelOrder: ";
    test.levelOrder(root);
    cout << endl;

    cout << "InOrderWithoutRecusion: ";
    test.InOrderWithoutRecusion(root);
    cout << endl;

    cout << "PostAndIn:" << endl;
    cout << "inOrder: ";
    test.inOrder(root2);
    cout << endl;

    cout << "levelOrder: ";
    test.levelOrder(root2);
    cout << endl;

    cout << "InOrderWithoutRecusion: ";
    test.InOrderWithoutRecusion(root2);
    cout << endl;
    return 0;
}
