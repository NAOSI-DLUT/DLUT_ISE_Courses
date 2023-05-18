#pragma once
#ifndef BINARYTREENODE_H
#define BINARYTREENODE_H
#include <iostream>
using namespace std;

template <class T>
class BinaryTreeNode
{
private:
	//data, left child, right child
	T data;
	BinaryTreeNode<T>* lChild;
	BinaryTreeNode<T>* rChild;

public:
	//constructor overriding
	BinaryTreeNode();
	//set default children as NULL
	BinaryTreeNode(T data, BinaryTreeNode<T> *lChild = NULL, BinaryTreeNode<T> *rChild = NULL);
	
	void setData(T data);
	T getData();
	void setLChild(BinaryTreeNode<T>* newLChild);
	BinaryTreeNode<T>* getLChild();
	void setRChild(BinaryTreeNode<T>* newRChild);
	BinaryTreeNode<T>* getRChild();
};

#endif