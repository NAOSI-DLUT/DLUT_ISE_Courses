#include "BinaryTree.h"
#include <typeinfo>
using namespace std;

template <class T>
BinaryTree<T>::BinaryTree()
{
	this->root = NULL;
}

template <class T>
void BinaryTree<T>::initialTree()
{
	//initialize a tree by insert(value)
	T value;
	//the if value == check, then stop
	cout << "Input: (stop when enter 0)" << endl;
	cin >> value;
	
	if (typeid(value) == typeid(int))
	{
		auto check = 0;

		while (value != check)
		{
			//initialize a tree by insert(value)
			this->insert(value);

			cin >> value;
		}
	}
	else if (typeid(value) == typeid(double))
	{
		auto check = 0.0;

		while (value != check)
		{
			//initialize a tree by insert(value)
			this->insert(value);

			cin >> value;
		}
	}
	else if (typeid(value) == typeid(char))
	{
		auto check = '0';

		while (value != check)
		{
			//initialize a tree by insert(value)
			this->insert(value);

			cin >> value;
		}
	}
}

template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T>* currentNode)
{
	cout << currentNode->getData() << " ";
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getRoot()
{
	return this->root;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::getParent(BinaryTreeNode<T>* currentNode)
{
	//current node == root
	if (currentNode == this->root)
	{
		return NULL;
	}
	//while loop to traverse the binary tree
	BinaryTreeNode<T>* tempNode = this->root;
	BinaryTreeNode<T>* parentNode = NULL;

	while (tempNode != NULL && (currentNode->getData() != tempNode->getData()))
	{
		//<
		if (currentNode->getData() < tempNode->getData())
		{
			//go to left child
			parentNode = tempNode;
			tempNode = tempNode->getLChild();
		}
		//>
		else
		{
			//go to right child
			parentNode = tempNode;
			tempNode = tempNode->getRChild();
		}
	}
	//case1: empty tree
	//case2: not found
	if (tempNode == NULL)
	{
		return NULL;
	}
	else
	{
		return parentNode;
	}
}

template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T>* root)
{
	if (root != NULL)
	{
		inOrder(root->getLChild());
		visit(root);
		inOrder(root->getRChild());
	}
}

template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T>* root)
{
	if (root != NULL)
	{
		visit(root);
		preOrder(root->getLChild());
		preOrder(root->getRChild());
	}
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::treeSearch(BinaryTreeNode<T>* root, T& value)
{
	if (root == NULL || value == root->getData())
	{
		return root;
	}
	//<
	if (value < root->getData())
	{
		return treeSearch(root->getLChild(), value);
	}
	//>
	else
	{
		return treeSearch(root->getRChild(), value);
	}
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::iter_treeSearch(T& value)
{
	//while loop to traverse the binary tree
	BinaryTreeNode<T>* tempNode = this->root;

	while (tempNode != NULL && (value != tempNode->getData()))
	{
		//<
		if (value < tempNode->getData())
		{
			//go to left child
			tempNode = tempNode->getLChild();
		}
		//>
		else
		{
			//go to right child
			tempNode = tempNode->getRChild();
		}
	}
	//case1: empty tree
	//case2: not found
	return tempNode;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::treeMinimum(BinaryTreeNode<T>* targetNode)
{
	BinaryTreeNode<T>* minNode = targetNode;

	while (minNode->getLChild() != NULL)
	{
		minNode = minNode->getLChild();
	}

	return minNode;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::treeMaximum(BinaryTreeNode<T>* targetNode)
{
	BinaryTreeNode<T>* maxNode = targetNode;

	while (maxNode->getRChild() != NULL)
	{
		maxNode = maxNode->getRChild();
	}

	return maxNode;
}

template <class T>
BinaryTreeNode<T>* BinaryTree<T>::treeSuccessor(BinaryTreeNode<T>* targetNode)
{
	//has right sub tree
	if (targetNode->getRChild() != NULL)
	{
		return treeMinimum(targetNode->getRChild());
	}
	//has no right sub tree
	else
	{
		//1. parent's left child, then successor is parent
		if (targetNode->getData() < getParent(targetNode)->getData())
		{
			return getParent(targetNode);
		}
		//2. parent's right child, then successor maybe parent's parent
		else if ((targetNode->getData() > getParent(targetNode)->getData()) 
			&& (targetNode->getData() < getParent(getParent(targetNode))->getData()))
		{
			return getParent(getParent(targetNode));
		}
		else
		{
			return NULL;
		}
	}
}

template <class T>
void BinaryTree<T>::insert(T& value)
{
	//new node
	BinaryTreeNode<T>* newNode = new BinaryTreeNode<T>(value);
	//point to the current node
	BinaryTreeNode<T>* currentNode = this->root;
	//point to the previous node
	BinaryTreeNode<T>* parentNode = NULL;

	while (currentNode != NULL)
	{
		//move previous node
		parentNode = currentNode;
		if (value < currentNode->getData())
		{
			currentNode = currentNode->getLChild();
		}
		else
		{
			currentNode = currentNode->getRChild();
		}
	}
	//when quit the while loop, it means that:
	//1. root is NULL.
	//2. currentNode is the position that 'value' should to be
	if (this->root == NULL)
	{
		this->root = newNode;
	}
	else if (parentNode != NULL && (value < parentNode->getData()))
	{
		parentNode->setLChild(newNode);
	}
	else if (parentNode != NULL && (value >= parentNode->getData()))
	{
		parentNode->setRChild(newNode);
	}
}

template <class T>
void BinaryTree<T>::deleteByCopy(BinaryTreeNode<T>*& targetNode)
{
	//temp node 
	BinaryTreeNode<T>* tempNode = targetNode;
	//previous node
	BinaryTreeNode<T>* parentNode = this->getParent(targetNode);
	//3 cases:
	//1. only left child exists (include the case that is a leaf node)
	if (targetNode->getRChild() == NULL && parentNode != NULL)
	{
		//set previous node's child:
		targetNode->getData() < parentNode->getData() ?
			//node is left child:
			parentNode->setLChild(targetNode->getLChild()) :
			//node is right child:
			parentNode->setRChild(targetNode->getLChild());
	}
	//2. only right child exists (include the case that is a leaf node)
	else if (targetNode->getLChild() == NULL && parentNode != NULL)
	{
		//set previous node's child:
		targetNode->getData() < parentNode->getData() ?
			//node is left child:
			parentNode->setLChild(targetNode->getLChild()) :
			//node is right child:
			parentNode->setRChild(targetNode->getLChild());
	}
	//3. both children exist
	else
	{
		//to search to largest node in the left sub tree
		parentNode = tempNode;
		tempNode = tempNode->getLChild();

		while (tempNode->getRChild() != NULL)
		{
			parentNode = tempNode;
			tempNode = tempNode->getRChild();
		}
		//break when tempNode's right child == NULL, meaning tempNode is largest node in left
		//copy: 
		targetNode->setData(tempNode->getData());
		//if previous node is just the target node that need to be deleted
		//父节点刚好是要删除的结点时：
		if (parentNode == targetNode)
		{
			parentNode->setLChild(tempNode->getLChild());
		}
		else
		{
			parentNode->setRChild(tempNode->getLChild());
		}
	}
	//delete the tempNode
	delete tempNode;
}