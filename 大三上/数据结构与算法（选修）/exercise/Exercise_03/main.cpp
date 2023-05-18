#include "BinaryTree.cpp"
#include "BinaryTreeNode.cpp"
#include <iostream>
using namespace std;

void mainMenu()
{
	cout << "***** Binary Search Tree *****" << endl;
	cout << "1. Create a BST " << endl;
	cout << "2. Insert " << endl;
	cout << "3. Delete by copying " << endl;
	cout << "4. Inorder and preorder traversal of the BST " << endl;
	cout << "5. Search a node and get its children and parent " << endl;
	cout << "6. Minimum node of a node's sub tree " << endl;
	cout << "7. Maximum node of a node's sub tree " << endl;
	cout << "8. Successor of a node " << endl;
	cout << "0. Exit " << endl;
	cout << ">";
}

void subMenu(string title, int index)
{
	cout << title << endl;

	switch (index)
	{
	case 2:
		cout << "Input a value you want to insert: " << endl;
		break;
	case 3:
		cout << "Input the value you want to delete: " << endl;
		break;
	case 5:
		cout << "Input the value you want to search: " << endl;
		break;
	case 6:
		cout << "Input the node's value you want to find minimum: " << endl;
		break;
	case 7:
		cout << "Input the node's value you want to find maximum: " << endl;
		break;
	case 8:
		cout << "Input the node's value you want to find its successor: " << endl;
		break;
	}
}

void execute()
{
	//the choice
	int index = -1;
	mainMenu();
	cin >> index;
	//if not enter 1, then warning 
	while (index != 1)
	{
		cout << "Please create a BST first! " << endl;
		system("pause");
		system("cls");
		mainMenu();
		cin >> index;
	}
	//enter 1:
	system("cls");
	cout << "Input element type: (int, double, or char) " << endl;
	string elementType;
	cin >> elementType;

	if (elementType == "int")
	{
		BinaryTree<int> BST_int;
		BST_int.initialTree();
		cout << "Succeeded. \nInorder: " << endl;
		BST_int.inOrder(BST_int.getRoot());
		cout << endl;
		system("pause");
		system("cls");

		mainMenu();
		cin >> index;
		//get into loop, 0 to exit
		while (index)
		{
			system("cls");

			switch (index)
			{
			case 2://insert
			{
				int value;
				subMenu("Insert", 2);
				cin >> value;
				BST_int.insert(value);
				cout << "Succeeded. " << endl;
				break;
			}

			case 3://delete
			{
				int value;
				subMenu("Delete", 3);
				cin >> value;
				BinaryTreeNode<int>* targetNode = BST_int.iter_treeSearch(value);
				BST_int.deleteByCopy(targetNode);
				cout << "Succeeded. " << endl;
				break;
			}

			case 4://inorder and preorder
			{
				subMenu("Inorder and preorder", 4);
				cout << "Inorder: " << endl;
				BST_int.inOrder(BST_int.getRoot());
				cout << endl;
				cout << "Preorder: " << endl;
				BST_int.preOrder(BST_int.getRoot());
				cout << endl;
				break;
			}

			case 5://search and get information
			{
				int value;
				subMenu("Search", 5);
				cin >> value;
				BinaryTreeNode<int>* targetNode = BST_int.iter_treeSearch(value);
				if (BST_int.getParent(targetNode) == NULL)
				{
					cout << "No parent because this is the root node. " << endl;
				}
				else
				{
					cout << "Parent: " << BST_int.getParent(targetNode)->getData() << endl;
				}
				if (targetNode->getLChild() == NULL)
				{
					cout << "No left child. " << endl;
				}
				else
				{
					cout << "Left Child: " << targetNode->getLChild()->getData() << endl;
				}
				if (targetNode->getRChild() == NULL)
				{
					cout << "No right child. " << endl;
				}
				else
				{
					cout << "Right Child: " << targetNode->getRChild()->getData() << endl;
				}				
				break;
			}

			case 6://minimum
			{
				int value;
				subMenu("Minimum", 6);
				cin >> value;
				BinaryTreeNode<int>* targetNode = BST_int.iter_treeSearch(value);
				BinaryTreeNode<int>* minNode = BST_int.treeMinimum(targetNode);
				cout << "Minimum is: " << minNode->getData() << endl;
				break;
			}

			case 7://maximum
			{
				int value;
				subMenu("Maximum", 7);
				cin >> value;
				BinaryTreeNode<int>* targetNode = BST_int.iter_treeSearch(value);
				BinaryTreeNode<int>* maxNode = BST_int.treeMaximum(targetNode);
				cout << "Maximum is: " << maxNode->getData() << endl;
				break;
			}

			case 8://successor
			{
				int value;
				subMenu("Successor", 8);
				cin >> value;
				BinaryTreeNode<int>* targetNode = BST_int.iter_treeSearch(value);
				BinaryTreeNode<int>* successorNode = BST_int.treeSuccessor(targetNode);
				if (successorNode == NULL)
				{
					cout << "No successor node. " << endl;
				}
				else
				{
					cout << "Successor is: " << successorNode->getData() << endl;
				}
				break;
			}
			}

			system("pause");
			system("cls");
			mainMenu();
			cin >> index;
		}
	}
	else if (elementType == "double")
	{
		BinaryTree<double> BST_double;
		BST_double.initialTree();
		cout << "Succeeded. Inorder: " << endl;
		BST_double.inOrder(BST_double.getRoot());
		cout << endl;
		system("pause");
		system("cls");

		mainMenu();
		cin >> index;
		//get into loop, 0 to exit
		while (index)
		{
			system("cls");

			switch (index)
			{
			case 2://insert
			{
				double value;
				subMenu("Insert", 2);
				cin >> value;
				BST_double.insert(value);
				cout << "Succeeded. " << endl;
				break;
			}

			case 3://delete
			{
				double value;
				subMenu("Delete", 3);
				cin >> value;
				BinaryTreeNode<double>* targetNode = BST_double.iter_treeSearch(value);
				BST_double.deleteByCopy(targetNode);
				cout << "Succeeded. " << endl;
				break;
			}

			case 4://inorder
			{
				subMenu("Inorder and preorder", 4);
				cout << "Inorder: " << endl;
				BST_double.inOrder(BST_double.getRoot());
				cout << endl;
				cout << "Preorder: " << endl;
				BST_double.preOrder(BST_double.getRoot());
				cout << endl;
				break;
			}

			case 5://search and get information
			{
				double value;
				subMenu("Search", 5);
				cin >> value;
				BinaryTreeNode<double>* targetNode = BST_double.iter_treeSearch(value);
				if (BST_double.getParent(targetNode) == NULL)
				{
					cout << "No parent because this is the root node. " << endl;
				}
				else
				{
					cout << "Parent: " << BST_double.getParent(targetNode)->getData() << endl;
				}
				if (targetNode->getLChild() == NULL)
				{
					cout << "No left child. " << endl;
				}
				else
				{
					cout << "Left Child: " << targetNode->getLChild()->getData() << endl;
				}
				if (targetNode->getRChild() == NULL)
				{
					cout << "No right child. " << endl;
				}
				else
				{
					cout << "Right Child: " << targetNode->getRChild()->getData() << endl;
				}
				break;
			}

			case 6://minimum
			{
				double value;
				subMenu("Minimum", 6);
				cin >> value;
				BinaryTreeNode<double>* targetNode = BST_double.iter_treeSearch(value);
				BinaryTreeNode<double>* minNode = BST_double.treeMinimum(targetNode);
				cout << "Minimum is: " << minNode->getData() << endl;
				break;
			}

			case 7://maximum
			{
				double value;
				subMenu("Maximum", 7);
				cin >> value;
				BinaryTreeNode<double>* targetNode = BST_double.iter_treeSearch(value);
				BinaryTreeNode<double>* maxNode = BST_double.treeMaximum(targetNode);
				cout << "Maximum is: " << maxNode->getData() << endl;
				break;
			}

			case 8://successor
			{
				double value;
				subMenu("Successor", 8);
				cin >> value;
				BinaryTreeNode<double>* targetNode = BST_double.iter_treeSearch(value);
				BinaryTreeNode<double>* successorNode = BST_double.treeSuccessor(targetNode);
				if (successorNode == NULL)
				{
					cout << "No successor node. " << endl;
				}
				else
				{
					cout << "Successor is: " << successorNode->getData() << endl;
				}
				break;
			}
			}

			system("pause");
			system("cls");
			mainMenu();
			cin >> index;
		}
	}
	else if (elementType == "char")
	{
		BinaryTree<char> BST_char;
		BST_char.initialTree();
		cout << "Succeeded. Inorder: " << endl;
		BST_char.inOrder(BST_char.getRoot());
		cout << endl;
		system("pause");
		system("cls");

		mainMenu();
		cin >> index;
		//get into loop, 0 to exit
		while (index)
		{
			system("cls");

			switch (index)
			{
			case 2://insert
			{
				char value;
				subMenu("Insert", 2);
				cin >> value;
				BST_char.insert(value);
				cout << "Succeeded. " << endl;
				break;
			}

			case 3://delete
			{
				char value;
				subMenu("Delete", 3);
				cin >> value;
				BinaryTreeNode<char>* targetNode = BST_char.iter_treeSearch(value);
				BST_char.deleteByCopy(targetNode);
				cout << "Succeeded. " << endl;
				break;
			}

			case 4://inorder
			{
				subMenu("Inorder and preorder", 4);
				cout << "Inorder: " << endl;
				BST_char.inOrder(BST_char.getRoot());
				cout << endl;
				cout << "Preorder: " << endl;
				BST_char.preOrder(BST_char.getRoot());
				cout << endl;
				break;
			}

			case 5://search and get information
			{
				char value;
				subMenu("Search", 5);
				cin >> value;
				BinaryTreeNode<char>* targetNode = BST_char.iter_treeSearch(value);
				if (BST_char.getParent(targetNode) == NULL)
				{
					cout << "No parent because this is the root node. " << endl;
				}
				else
				{
					cout << "Parent: " << BST_char.getParent(targetNode)->getData() << endl;
				}
				if (targetNode->getLChild() == NULL)
				{
					cout << "No left child. " << endl;
				}
				else
				{
					cout << "Left Child: " << targetNode->getLChild()->getData() << endl;
				}
				if (targetNode->getRChild() == NULL)
				{
					cout << "No right child. " << endl;
				}
				else
				{
					cout << "Right Child: " << targetNode->getRChild()->getData() << endl;
				}
				break;
			}

			case 6://minimum
			{
				char value;
				subMenu("Minimum", 6);
				cin >> value;
				BinaryTreeNode<char>* targetNode = BST_char.iter_treeSearch(value);
				BinaryTreeNode<char>* minNode = BST_char.treeMinimum(targetNode);
				cout << "Minimum is: " << minNode->getData() << endl;
				break;
			}

			case 7://maximum
			{
				char value;
				subMenu("Maximum", 7);
				cin >> value;
				BinaryTreeNode<char>* targetNode = BST_char.iter_treeSearch(value);
				BinaryTreeNode<char>* maxNode = BST_char.treeMaximum(targetNode);
				cout << "Maximum is: " << maxNode->getData() << endl;
				break;
			}

			case 8://successor
			{
				char value;
				subMenu("Successor", 8);
				cin >> value;
				BinaryTreeNode<char>* targetNode = BST_char.iter_treeSearch(value);
				BinaryTreeNode<char>* successorNode = BST_char.treeSuccessor(targetNode);
				if (successorNode == NULL)
				{
					cout << "No successor node. " << endl;
				}
				else
				{
					cout << "Successor is: " << successorNode->getData() << endl;
				}
				break;
			}
			}

			system("pause");
			system("cls");
			mainMenu();
			cin >> index;
		}
	}

	//jump out of while loop: index == 0
	cout << "Bye! " << endl;
}

int main()
{
	execute();
	system("pause");
	return 0;
}