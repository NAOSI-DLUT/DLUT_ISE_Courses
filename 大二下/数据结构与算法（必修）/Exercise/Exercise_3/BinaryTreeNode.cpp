#include "BinaryTreeNode.h"
using namespace std;

template <class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
	this->data = 0;
	this->lChild = NULL;
	this->rChild = NULL;
}

template <class T>
BinaryTreeNode<T>::BinaryTreeNode(T data, BinaryTreeNode<T>* lChild, BinaryTreeNode<T>* rChild)
{
	this->data = data;
	this->lChild = lChild;
	this->rChild = rChild;
}

template <class T>
void BinaryTreeNode<T>::setData(T data)
{
	this->data = data;
}

template <class T>
void BinaryTreeNode<T>::setLChild(BinaryTreeNode<T> *newLChild)
{
	this->lChild = newLChild;
}

template <class T>
void BinaryTreeNode<T>::setRChild(BinaryTreeNode<T>* newRChild)
{
	this->rChild = newRChild;
}

template <class T>
T BinaryTreeNode<T>::getData()
{
	return this->data;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getLChild()
{
	return this->lChild;
}

template <class T>
BinaryTreeNode<T>* BinaryTreeNode<T>::getRChild()
{
	return this->rChild;
}