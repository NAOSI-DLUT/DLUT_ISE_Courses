#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

template <class T>
class BinaryTree
{
private:
	//Binary Tree's root
	BinaryTreeNode<T>* root;

public:
	//several functions that need to be implemented
	//tree-search(x, k)
	BinaryTreeNode<T>* treeSearch(BinaryTreeNode<T>* root, T& value);
	//iterative-tree-search(x, k)
	BinaryTreeNode<T>* iter_treeSearch(T& value);
	//tree-minimum(x)
	BinaryTreeNode<T>* treeMinimum(BinaryTreeNode<T>* targetNode);
	//tree-maximum(x)
	BinaryTreeNode<T>* treeMaximum(BinaryTreeNode<T>* targetNode);
	//tree-successor(x)
	BinaryTreeNode<T>* treeSuccessor(BinaryTreeNode<T> *targetNode);
	//insert
	void insert(T& value);
	//delete by copying
	void deleteByCopy(BinaryTreeNode<T>*& targetNode);

	BinaryTree();
	void initialTree();
	void	 visit(BinaryTreeNode<T>* currentNode);
	BinaryTreeNode<T>* getRoot();
	BinaryTreeNode<T>* getParent(BinaryTreeNode<T>* currentNode);
	
	void inOrder(BinaryTreeNode<T>* root);
	void preOrder(BinaryTreeNode<T>* root);
};

#endif