//
//  main.cpp
//  999
//
//  Created by MEGABOY on 2021-04-06.
//

#include <iostream>
using namespace std;
struct BST
{
public:
    BST *left;
    BST *right;
    int data;
    BST()
    {
        left=NULL;
        right=NULL;
        data=0;
    }
};

BST *root;

BST* find_nonrecv(int keyword)
{
    BST *index=root;
    if(index->data == keyword) return index;
    while(index!=NULL && keyword!=index->data)
    {
        if(keyword< index->data) index=index->left;
        else if(keyword> index->data) index=index->right;
    }
    if(index!=NULL) return index;
    else return NULL;
}

BST* minval(BST *root)
{
    BST *index=root;
    while(index->left!=NULL) index=index->left;
    return index;
}

BST* maxval(BST *root)
{
    BST *index=root;
    while(index->right!=NULL) index=index->right;
    return index;
}

BST *find_recv(BST *root,int keyword)
{
    if(root==NULL) return NULL;
    if(root->data==keyword) return root;
    if(root->data>keyword && root!=NULL) return find_recv(root->left, keyword);
    else return find_recv(root->right, keyword);
}

void insert(const int value)
{
    BST *index=root;
    BST *prev;
    if(root == NULL)
    {
        root=new BST;
        root->data=value;
        return;
    }
    while(index !=NULL)
    {
        prev=index;
        if(index->data < value) index=index->right;
        else index=index->left;
    }
    if(prev->data < value)
    {
        prev->right=new BST;
        prev->right->data=value;
    }
    else
    {
        prev->left=new BST;
        prev->left->data=value;
    }
}


BST *parents(BST *root,BST *node)
{
    BST *tmp=NULL;
    if(root!=NULL)
    {
        if(root==node) return NULL;
        else if(root->left==node || root->right==node)
            return root;
        else
        {
            tmp= parents(root->left, node);
            if(tmp == NULL)
            tmp=parents(root->right, node);
        }
    }
    return tmp;
}

void create()
{
    int v;
    cout << "Please input a series of integers end with 0" <<endl;
    cin >> v;
    while (v!=0)
    {
        insert(v);
        cin >> v;
    }
}
void show(BST *root)
{
    if(root == NULL) return;
    cout << root->data << " ";
    show(root->left);
    show(root->right);
}

bool del(BST *node)
{
    BST *index=root;
    BST *parent=NULL;
    if(node == NULL) return false;
    while(index!=NULL)
    {
        if(index->data == node->data) break;
        if(node->data > index->data)
        {
            parent=index;
            index=index->right;
        }
        else
        {
            parent=index;
            index=index->left;
        }
    }
        if(index==NULL) return false;
        
        if(index->right == NULL)
        {
            if(index == root)
                root=index->right;
            else
            {
                if(index == parent->right)
                    parent->right=index->right;
                else parent->left=index->right;
            }
        }
        else if(index->left == NULL)
        {
            if(index ==  root)
                root=index->right;
            else
            {
                if(index == parent->right)
                    parent->right=index->right;
                else parent->left=index->right;
            }
        }
        else 
        {
            BST *tmp=index->right;
            parent=index;
            while(tmp->left != NULL)
            {
                parent=tmp;
                tmp=tmp->left;
            }
            index->data=tmp->left->data;
            if(tmp==parent->left)
                parent->left=tmp->right;
            else parent->right=tmp->left;
            index=tmp;
        }
        delete index;
    return true;
}

BST *successor(BST *root,BST *x)
{
    BST  *y;
    if(x!=NULL && x->right != NULL) return minval(x->right);
    else y=parents(root, x);
    while(y!=NULL && x==y->right)
    {
        x=y;
        y=parents(root, y);
    }
    return y;
}

int main()
{
    create();
    cout <<"Showing the tree" << endl;
    show(root);
    cout << endl;
    cout << "MAX=" << maxval(root)->data << endl << "MIN=" << minval(root)->data << endl;
    
    cout<< "Search for" <<endl;
    int s;
    cin >> s;
    
    BST *c=find_nonrecv(s);
    if(c!= NULL)
    cout << "Found " << c->data << " in the tree using the non-recursive mode" << endl;
    else cout << "Not Found" <<endl;
    
    c=find_recv(root, s);
    if(c!=NULL)
    cout << "Found " << c->data << " in the tree using the recursive mode" << endl;
    else cout << "Not Found" <<endl;
    if (parents(root, c)!=NULL) cout <<"Its parent is " << parents(root, c)->data << endl; else cout <<"It is the root" <<endl;
    if (successor(root, c)!=NULL) cout << "The successor is " << successor(root, c)->data << endl; else cout <<"The successor doesn't exist" <<endl;
    
    cout <<"Delete from" <<endl;
    cin >> s;
    if(del(find_recv(root, s))) cout << "Deleted" <<endl;
    else cout <<"Failed. Not found" << endl;
    show(root); cout <<endl;
    return 0;
}
