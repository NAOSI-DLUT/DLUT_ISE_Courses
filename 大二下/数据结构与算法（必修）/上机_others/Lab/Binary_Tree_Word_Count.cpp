//
//  main.cpp
//  xxx
//
//  Created by MEGABOY on 2021-03-30.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
struct Tree
{
public:
    char *word;
    int count;
    Tree *left,*right;
    Tree()
    {
        word=new char(128);
        count=1;
        left=NULL;right=NULL;
    }
    ~Tree()
    {
        delete word;
    }
};

ofstream output;
ifstream input;

bool traverse(Tree *root)
{
    if(root == NULL) return true;
    output << root->count << " " << root->word << endl;
    traverse(root->left);
    traverse(root->right);
    
    return true;
}

bool prenon(Tree *root)
{
    stack<Tree*> nodes;
    Tree *pointer = root;
    while(!nodes.empty() || pointer != NULL)
    {
        if(pointer !=NULL)
        {
            output << pointer->count << " " << pointer->word << endl; //visit
            if(pointer->right != NULL)
                nodes.push(pointer->right);
            pointer=pointer->left;
        }
        else {
            pointer = nodes.top();
            nodes.pop();
        }
    }
    return true;
}

bool innon(Tree *root)
{
    stack<Tree*> nodes;
    Tree *pointer = root;
    while(!nodes.empty() || pointer != NULL)
    {
        if(pointer != NULL)
        {
            nodes.push(pointer);
            pointer=pointer->left;
        }
        else {
            pointer=nodes.top();
            output << pointer->count << " " << pointer->word << endl; //visit
            pointer=pointer->right;
            nodes.pop();
        }
    }
    return true;
}

bool postnon(Tree *root)
{
    stack<Tree*> nodes;
    Tree *pointer = root;
    Tree *pre=root;
    while(pointer != NULL)
    {
        for(;pointer->left !=NULL;pointer=pointer->left)
        nodes.push(pointer);
        while(pointer!= NULL && (pointer->right == NULL || pointer->right==pre))
        {
            output << pointer->count << " " << pointer->word << endl; //visit
            pre=pointer;
            if(nodes.empty()) return true;
            pointer=nodes.top();
            nodes.pop();
        }
        nodes.push(pointer);
        pointer=pointer->right;
    }
    return true;
}

bool inorder(Tree *root)
{
    if(root == NULL) return true;
    inorder(root->left);
    output << root->count << " " << root->word << endl;
    inorder(root->right);
    return true;
}

bool postorder(Tree *root)
{
    if(root == NULL) return true;
    postorder(root->left);
    postorder(root->right);
    output << root->count << " " << root->word << endl;
    return true;
}

int append(Tree **root,char *text)
{
    queue<Tree*> Nodes;
    bool flag=false; //check if text already exists in the tree
    Tree *pointer = *root;
    Tree *tmp;
    if(*root == NULL)
    {
        *root=new Tree;
        (*root)->word=text;
        return 0;
    }
    if(pointer!=NULL)
        Nodes.push(pointer);
    
    while(!Nodes.empty())
    {
        pointer=Nodes.front();
        if(strcmp(pointer->word,text)==0)
        {
            pointer->count=pointer->count+1;
            flag=true;
        }
        Nodes.pop();
        if(pointer->left !=NULL) Nodes.push(pointer->left);
        if(pointer->right !=NULL) Nodes.push(pointer->right);
    }
    
    pointer = *root;
    if(pointer!=NULL)
        Nodes.push(pointer);
    
    while(!Nodes.empty())
    {
        pointer=Nodes.front();
        Nodes.pop();
        if(pointer->left !=NULL) Nodes.push(pointer->left);
            else if(!flag)
            {
                tmp=new Tree;
                tmp->word=text;
                pointer->left=tmp;
                flag=true;
            }
        if(pointer->right !=NULL) Nodes.push(pointer->right);
            else if(!flag)
            {
                tmp=new Tree;
                tmp->word=text;
                pointer->right=tmp;
                flag=true;
            }
    }
    return 0;
}

bool isalphabet(const char ch)
{
    return((ch >='a' && ch <='z') || (ch >='A' && ch <='Z'));
}

void tolowercase(char *text)
{
    int i;
    for(i=0;i<=strlen(text)-1;i++)
    {
        if(text[i] >='A' && text[i] <='Z') text[i]=text[i]-'A'+'a';
    }
}

int main(int argc, const char * argv[])
{
    output.open(argv[1]);
    int i;
    Tree *words=NULL;
    char *txt;
    for(i=2;i<=argc;i++)
    {
        input.open(argv[i]);
        if(input.is_open())
        {
            while(!input.eof())
            {
                txt=new char(128);
                input >> txt;
                tolowercase(txt); //TO lower case;
                while (!isalphabet(txt[strlen(txt)-1])) txt[strlen(txt)-1]='\0';
                append(&words,txt);
                if(words == NULL) cout << "ERROR" <<endl;
            }
            input.close();
            cout << argv[i] << " is loaded" << endl;
        }
    }
    output << "PREORDER" <<endl;
    traverse(words);
    output <<endl << "NONREC" <<endl;
    prenon(words);
    
    output << endl <<"INORDER" <<endl;
    inorder(words);
    output <<endl << "NONREC" <<endl;
    innon(words);
    
    output << endl <<"POSTORDER" <<endl;
    postorder(words);
    output <<endl << "NONREC" <<endl;
    postnon(words);
    
    output.close();
    return 0;
}
