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
	T  element;			                     //结点的数据域
	BinaryTreeNode<T>* leftChild;            //结点的左孩子结点
	BinaryTreeNode<T>* rightChild;           //结点的右孩子结点
public:
	friend class BinaryTree<T>;              //声明二叉树类为结点类的友元类，以便访问私有数据成员
	//默认构造函数
	BinaryTreeNode()
	{
		element = 0;
		leftChild = NULL;
		rightChild = NULL;
	}
	//给定数据的构造函数
	BinaryTreeNode(const T& ele)
	{
		element = ele;
		leftChild = NULL;
		rightChild = NULL;
	}
	//给定数据值和左右孩子结点的构造函数
	BinaryTreeNode(const T& ele, BinaryTreeNode<T>* l, BinaryTreeNode<T>* r)
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	//返回该结点的左孩子结点
	BinaryTreeNode<T>* getLeftChild() const
	{
		return leftChild;
	}
	//返回该结点的右孩子结点
	BinaryTreeNode<T>* getRightChild() const
	{
		return rightChild;
	}
	//设置该结点的左孩子结点
	void setleftChild(BinaryTreeNode<T>* l)
	{
		leftChild = l;
	}
	//设置该结点的右孩子结点
	void setrightChild(BinaryTreeNode<T>* r)
	{
		rightChild = r;
	}
	//返回该结点的数据值
	T getValue(const T& val)
	{
		val = element;
		return val;
	}
	//设置该结点的数据域的值
	void setValue(const T& val)
	{
		element = val;
	}
	//判断该结点是否是叶子结点，若是，则返回true
	bool isLeaf() const
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
	BinaryTreeNode<T>* root;      	           //二叉树根结点
	BinaryTree()             		           //默认构造函数
	{
		root = NULL;
	}
	~BinaryTree()                              //析构函数
	{
		deleteBinaryTree(root);
	}
	bool isEmpty() const 	                   //判定二叉树是否为空树
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

	BinaryTreeNode<T>* buildPreAndIn(string prestr, string instr);			  //2.1-a 实现由先序、中序序列构造二叉树的算法
	BinaryTreeNode<T>* buildPostAndIn(string poststr, string instr);		  //2.1-b 实现由后序、中序序列构造二叉树的算法
	void levelOrder(BinaryTreeNode<T>* root);                                 //2.1-c 广度优先遍历以root为根结点的子树
	void inOrder(BinaryTreeNode<T>* root);                                    //2.1-d 中序遍历以root为根结点的子树
	void InOrderWithoutRecusion(BinaryTreeNode<T>* root);                     //2.1-e 非递归中序遍历二叉树或其子树
	void deleteBinaryTree(BinaryTreeNode<T>* root);                           //删除以root为根结点的子树                                                          

	void visit(BinaryTreeNode<T>* p)										  //创建一个树实例
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
	//if preOrder or inOrder string is ""
	if (prestr.length() == 0 || instr.length() == 0)
	{
		return NULL;
	}
	//the first char in preOrder is the root node
	int rootIndex = instr.find(prestr[0]);
	//inOrder string is divided into two parts
	//left child tree and right child tree
	string leftInstr = instr.substr(0, rootIndex);
	string rightInstr = instr.substr(rootIndex + 1);
	//preOrder string is divided according to the length of substring
	string leftPrestr = prestr.substr(1, leftInstr.length());
	string rightPrestr = prestr.substr(prestr.length() - rightInstr.length());

	BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>((char)prestr[0]);

	if (root == NULL)
	{
		root = newNode;
	}

	newNode->setleftChild(buildPreAndIn(leftPrestr, leftInstr));
	newNode->setrightChild(buildPreAndIn(rightPrestr, rightInstr));

	return newNode;
}

/*
TODO：2.1-b 实现由后序、中序序列构造二叉树的算法
	  return 树的根结点root
 */
template<class T>
BinaryTreeNode<T>* BinaryTree<T>::buildPostAndIn(string poststr, string instr)
{
	if (poststr.length() == 0 || instr.length() == 0)
	{
		return NULL;
	}
	//the last char of post string is the root node
	int rootIndex = instr.find(poststr[poststr.length() - 1]);

	string leftInstr = instr.substr(0, rootIndex);
	string rightInstr = instr.substr(rootIndex + 1);

	string leftPoststr = poststr.substr(0, leftInstr.length());
	string rightPoststr = poststr.substr(leftInstr.length(), rightInstr.length());

	BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>((char)poststr[poststr.length() - 1]);

	if (root == NULL)
	{
		root = newNode;
	}

	newNode->setleftChild(buildPostAndIn(leftPoststr, leftInstr));
	newNode->setrightChild(buildPostAndIn(rightPoststr, rightInstr));

	return newNode;
}

/*
TODO：2.1-c 广度优先遍历以root为根结点的子树
 */
template<class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	//initialize an assistant queue
	queue<BinaryTreeNode<T>*> treeNodeQueue;
	//a pointer to point to current node
	BinaryTreeNode<T>* currentNode = root;
	//enqueue
	treeNodeQueue.push(currentNode);
	//loop if the queue is not empty
	while (!treeNodeQueue.empty())
	{
		//dequeue and visit
		currentNode = treeNodeQueue.front();
		treeNodeQueue.pop();

		this->visit(currentNode);

		//recursion: left child and right child
		if (currentNode->getLeftChild() != NULL)
		{
			treeNodeQueue.push(currentNode->getLeftChild());
		}
		if (currentNode->getRightChild() != NULL)
		{
			treeNodeQueue.push(currentNode->getRightChild());
		}
	}

}

/*
TODO：2.1-d 递归中序遍历以root为根结点的子树
 */
template<class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root)
{
	if (root != NULL)
	{
		inOrder(root->getLeftChild());
		this->visit(root);
		inOrder(root->getRightChild());
	}
}

/*
TODO：2.1-e 非递归中序遍历二叉树或其子树
 */
template<class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T>* root)
{
	if (root == NULL)
	{
		return;
	}
	//initialize an assistant stack
	stack<BinaryTreeNode<T>*> treeNodeStack;
	//a pointer points to current node
	BinaryTreeNode<T>* currentNode = root;

	while (!treeNodeStack.empty() || currentNode != NULL)
	{
		if (currentNode != NULL)
		{
			//push current node into stack
			treeNodeStack.push(currentNode);
			//turn to its left child 
			currentNode = currentNode->getLeftChild();
		}
		//left sub tree has been visited
		else
		{
			currentNode = treeNodeStack.top();
			treeNodeStack.pop();

			this->visit(currentNode);
			//turn to its right child
			currentNode = currentNode->getRightChild();
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
	root = test.buildPreAndIn(prestr, instr);	//2.1-a 实现由先序、中序序列构造二叉树的算法
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
